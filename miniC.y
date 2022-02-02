%{

#include <stdio.h>
#include <dirent.h> 
#include "miniC.h"
#include "ast.h"

FILE *fp;
int currentDotIndex = 0;


%}



%token <symbol> IDENTIFICATEUR
%token <constante> CONSTANTE
%token VOID INT FOR WHILE IF ELSE SWITCH CASE DEFAULT
%token BREAK RETURN PLUS MOINS MUL DIV LSHIFT RSHIFT BAND BOR LAND LOR LT GT 
%token GEQ LEQ EQ NEQ NOT EXTERN
%left PLUS MOINS
%left MUL DIV
%left LSHIFT RSHIFT
%left BOR BAND
%left LAND LOR
%nonassoc THEN
%nonassoc ELSE
%left OP
%left REL
%start programme
%define parse.error verbose

%type <ast> programme liste_declarations liste_fonctions declaration liste_declarateurs declarateur
%type <ast> fonction type liste_instructions instruction iteration selection saut affectation selectionModifie instructionModifie liste_instructionsModifie
%type <ast> bloc appel variable expression liste_expressions condition binary_op binary_rel binary_comp
%type <ast> expr_list_creator parm_list_creator

%union { 
	struct ast_node *ast;
	struct symbol_node *symbol;
	int constante;
	char* dotFileName;
}

%%

programme	:	
		liste_declarations liste_fonctions
;
liste_declarations	:	
		liste_declarations declaration 
	|	
;
liste_fonctions	:	
		liste_fonctions fonction	{/* $$ = new_ast_func_list_node($2, $1);*/}
|               fonction		
;
declaration	:	
		type liste_declarateurs ';'
;
liste_declarateurs	:	
		liste_declarateurs ',' declarateur
	|	declarateur
;
declarateur	:	
		IDENTIFICATEUR
	|	declarateur '[' CONSTANTE ']'
;
fonction	:	
		type IDENTIFICATEUR '(' liste_parms ')' '{' liste_declarations liste_instructions '}' 	{ 
																									$$ = new_ast_func_node($1, $2, $8); 
																									currentDotIndex = generateFunctionDot(fp, currentDotIndex, $$);
																								}
	|	EXTERN type IDENTIFICATEUR '(' liste_parms ')' ';'
;
type	:	
		VOID	{ $$ = "void"; }
	|	INT		{ $$ = "int"; }
;
liste_parms	:	
		parm_list_creator
	|
;
parm_list_creator	:
		parm_list_creator ',' parm
	| parm
;

parm	:	
		INT IDENTIFICATEUR
;
liste_instructions :	
		liste_instructions instruction									{ $$ = new_ast_instruction_node($2, $1);     }	
	|																	{ $$ = NULL; }
;
liste_instructionsModifie :	
		liste_instructionsModifie instructionModifie							{ $$ = new_ast_instruction_node($2, $1);     }	
	|																	{ $$ = NULL; }
;
instruction	:	
		iteration
	|	saut
	|	selection
	|	affectation ';'
	|	bloc
	|	appel
;
instructionModifie	:	
		iteration
	|	saut
	|	selectionModifie
	|	affectation ';'
	|	bloc
	|	appel

iteration	:	
		FOR '(' affectation ';' condition ';' affectation ')' instruction	{ $$ = new_ast_for_node($3, $5, $7, $9);     			 }
	|	WHILE '(' condition ')' instruction 								{ $$ = new_ast_while_node($3, $5) ;         			 }
;
selection	:	
		IF '(' condition ')' instruction %prec THEN 						{ $$ = new_ast_if_node($3, $5, NULL);        			 }
	|	IF '(' condition ')' instruction ELSE instruction 					{ $$ = new_ast_if_node($3, $5, $7);          			 }
	|	SWITCH '(' expression ')' instruction								{ $$ = new_ast_switch_node($3, $5);                      }
	|	CASE CONSTANTE ':' liste_declarations liste_instructionsModifie		{ $$ = new_ast_case_node($2, $5);                        }
	|	DEFAULT ':' liste_declarations liste_instructionsModifie			{ $$ = new_ast_case_node(s_DEFAULT, $4);                 }
;
selectionModifie	:	
		IF '(' condition ')' instruction %prec THEN 						{ $$ = new_ast_if_node($3, $5, NULL);        			 }
	|	IF '(' condition ')' instruction ELSE instruction 					{ $$ = new_ast_if_node($3, $5, $7);          			 }
	|	SWITCH '(' expression ')' instruction								{ $$ = new_ast_switch_node($3, $5);                      }
;
saut	:	
		BREAK ';'															{ $$ = new_ast_jump_node(op_BREAK, NULL);    			 }
	|	RETURN ';'															{ $$ = new_ast_jump_node(op_RETURN, NULL);   			 }
	|	RETURN expression ';'												{ $$ = new_ast_jump_node(op_RETURN, $2);     			 }
;
affectation	:	
		variable '=' expression												{ $$ = new_ast_assignment_node($1, $3);      			 }  
;
bloc	:	
		'{' liste_declarations liste_instructions '}'						{ $$ = $3;                                   			 }	
;
appel	:	
		IDENTIFICATEUR '(' liste_expressions ')' ';'						{ $$ = new_ast_function_reference_node($1, $3);		 	 }
;
variable	:	
		IDENTIFICATEUR 														{ $$ = new_ast_identificator_node($1);                   }	    
	|	variable '[' expression ']'											{ $$ = new_ast_tab_node($3, $1); 					     }							
;
expression	:	
		'(' expression ')'													{ $$ = $2;                                               }
	|	expression PLUS expression											{ $$ = new_ast_op_rel_comp_node(op_PLUS, $1, $3);        }
	|	expression MOINS expression											{ $$ = new_ast_op_rel_comp_node(op_MOINS, $1, $3);       }
	|	expression DIV expression											{ $$ = new_ast_op_rel_comp_node(op_DIV, $1, $3);         }
	|	expression MUL expression											{ $$ = new_ast_op_rel_comp_node(op_MUL, $1, $3);         }
	|	expression RSHIFT expression										{ $$ = new_ast_op_rel_comp_node(op_RSHIFT, $1, $3);      }
	|	expression LSHIFT expression										{ $$ = new_ast_op_rel_comp_node(op_LSHIFT, $1, $3);      }
	|	expression BAND expression											{ $$ = new_ast_op_rel_comp_node(op_BAND, $1, $3);        }
	|	expression BOR expression											{ $$ = new_ast_op_rel_comp_node(op_BOR, $1, $3);         }
	|	MOINS expression %prec OP													{ $$ = new_ast_op_rel_comp_node(op_MOINS, $2, NULL);     }
	|	CONSTANTE															{ $$ = new_ast_number_node($1);                          }
	|	variable															{ $$ = new_ast_symbol_reference_node($1);                }
	|	IDENTIFICATEUR '(' liste_expressions ')' 							{ $$ = new_ast_function_reference_node($1, $3);          }
;
liste_expressions	:	
		expr_list_creator
	|
;
expr_list_creator	:
		expr_list_creator ',' expression { $$ = new_ast_expr_list_node($3, $1); }
	| expression						 { $$ = new_ast_expr_list_node($1, NULL); }
;

condition	:	
		NOT '(' condition ')'												{ $$ = new_ast_op_rel_comp_node(op_NOT, $3, NULL); }
	|	condition binary_rel condition %prec REL							{ $$ = new_ast_op_rel_comp_node($2, $1, $3);       }
	|	'(' condition ')'													{ $$ = $2;                                         }
	|	expression binary_comp expression									{ $$ = new_ast_op_rel_comp_node($2, $1, $3);       }
;
binary_op	:	
		PLUS																{ $$ = op_PLUS;   }
	|       MOINS															{ $$ = op_MOINS;  }
	|	MUL																	{ $$ = op_MUL;    }
	|	DIV																	{ $$ = op_DIV;    }
	|       LSHIFT															{ $$ = op_LSHIFT; }				
	|       RSHIFT															{ $$ = op_RSHIFT; }
	|	BAND																{ $$ = op_BAND;   }
	|	BOR																	{ $$ = op_BOR;    }
;
binary_rel	:	
		LAND																{ $$ = op_LAND;   }
	|	LOR																	{ $$ = op_LOR;    }
;
binary_comp	:	
		LT																	{ $$ = op_LT;     }
	|	GT																	{ $$ = op_GT;     }
	|	GEQ																	{ $$ = op_GEQ;    }
	|	LEQ																	{ $$ = op_LEQ;    }
	|	EQ																	{ $$ = op_EQ;     }
	|	NEQ																	{ $$ = op_NEQ;    }
;
%%

void yyerror(char *s)
{ fprintf(stderr,"%s \n",s); }

int main(int argc, char *argv[])
{
	if(argc > 1) {
		fp = fopen(argv[1], "w");
		printf("Generating \"%s\"... ", argv[1]);
	}
	else {
		fp = fopen("unamedDotFile.dot", "w");
		printf("Generating \"unamedDotFile.dot\"... ");
	}
	fprintf(fp, "digraph miniC_graph {\n");

	yyparse();

	fprintf(fp, "\n}");
	fclose(fp);
	printf(" Done !\n");
	return 0;
}
