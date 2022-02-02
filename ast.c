#include "ast.h"

struct ast_node* new_ast_node(int node_type, struct ast_node *left, struct ast_node *right)
{
    struct ast_node *ast_node = malloc(sizeof(struct ast_node));
    
    ast_node->node_type = node_type;

    ast_node->left = left;
    ast_node->right = right;

    return ast_node;
}

struct ast_node* new_ast_func_list_node(struct ast_node *currentNode, struct ast_node *nextNode)
{
    struct ast_func_list *ast_node = malloc(sizeof(struct ast_func_list));

    ast_node->node_type = N_FUNC_LIST;

    ast_node->current = currentNode;
    ast_node->next = nextNode;

    return (struct ast_node *) ast_node;
}

struct ast_node* new_ast_func_node(char* returnType, char* functionName, struct ast_instruction_node *instructions)
{
    struct ast_func_node *ast_node = malloc(sizeof(struct ast_func_node));

    ast_node->node_type = N_FUNC;

    ast_node->functionName = functionName;
    ast_node->returnType = returnType;
    ast_node->instructions = instructions;

    return (struct ast_node *) ast_node;
}

struct ast_node* new_ast_instruction_node(struct ast_node *currentNode, struct ast_node *nextNode)
{
    struct ast_instruction_node *ast_node = malloc(sizeof(struct ast_instruction_node));

    ast_node->node_type = N_INSTRUCTION;

    ast_node->current = currentNode;
    ast_node->next = nextNode;

    return (struct ast_node *) ast_node;
}

struct ast_node* new_ast_tab_node(struct ast_node *index, struct ast_node *variable)
{
    struct ast_tab_node *ast_node = malloc(sizeof(struct ast_tab_node));

    ast_node->node_type = N_TAB;

    ast_node->index = index;
    ast_node->variable = variable;

    return (struct ast_node *) ast_node;
}

struct ast_node* new_ast_expr_list_node(struct ast_node *currentNode, struct ast_node *nextNode)
{
    struct ast_expr_list_node *ast_node = malloc(sizeof(struct ast_expr_list_node));

    ast_node->node_type = N_EXPR_LIST;

    ast_node->current = currentNode;
    ast_node->next = nextNode;

    return (struct ast_node *) ast_node;
}


struct ast_node* new_ast_op_rel_comp_node(int operator, struct ast_node *left, struct ast_node *right) 
{
    struct ast_op_rel_comp_node *ast_node = malloc(sizeof(struct ast_op_rel_comp_node));

    ast_node->node_type = N_OPRELCOMP;

    ast_node->operator = operator;
    ast_node->left = left;
    ast_node->right = right;

    return (struct ast_node *) ast_node;
}

struct ast_node* new_ast_function_reference_node(struct symbol_node *symbol, struct ast_node *arguments)
{
    struct ast_function_node *ast_node = malloc(sizeof(struct ast_function_node));

    ast_node->node_type = N_FUNCTION_CALL;

    ast_node->symbol = symbol;
    ast_node->arguments = arguments;

    return (struct ast_node *) ast_node;
}

struct ast_node* new_ast_symbol_reference_node(struct symbol_node *symbol)
{
    struct ast_symbol_reference_node *ast_node = malloc(sizeof(struct ast_symbol_reference_node));

    ast_node->node_type = N_SYMBOLREF;

    ast_node->symbol = symbol;
    ast_node->symbolName = symbol;
    ast_node->symbolNode = symbol;

    return (struct ast_node *) ast_node;
}

struct ast_node* new_ast_switch_node(struct ast_node *value, struct ast_node *switch_branch)
{
    struct ast_switch_node *ast_node = malloc(sizeof(struct ast_switch_node));

    ast_node->node_type = N_SWITCH;
    
    ast_node->value = value;
    ast_node->switch_branch = switch_branch;

    return (struct ast_node *) ast_node;
}

struct ast_node* new_ast_case_node(int value, struct ast_node *case_branch)
{
    struct ast_case_node *ast_node = malloc(sizeof(struct ast_case_node));

    ast_node->node_type = N_CASE;
    
    ast_node->value = value;
    ast_node->case_branch = case_branch;

    return (struct ast_node *) ast_node;
}

struct ast_node* new_ast_if_node(struct ast_node *condition, struct ast_node *if_branch, struct ast_node *else_branch)
{
    struct ast_if_node *ast_node = malloc(sizeof(struct ast_if_node));

    ast_node->node_type = N_IF;
    
    ast_node->condition = condition;
    ast_node->if_branch = if_branch;
    ast_node->else_branch = else_branch;

    return (struct ast_node *) ast_node;
}

struct ast_node* new_ast_for_node(struct ast_node *init, struct ast_node *condition, struct ast_node *fin, struct ast_node *for_branch)
{
    struct ast_for_node *ast_node = malloc(sizeof(struct ast_for_node));

    ast_node->node_type = N_FOR;

    ast_node->initAffectation = init;
    ast_node->condition = condition;
    ast_node->finalAffectation = fin;
    ast_node->for_branch = for_branch;

    return (struct ast_node *) ast_node;
}

struct ast_node* new_ast_while_node(struct ast_node *condition, struct ast_node *while_branch)
{
    struct ast_while_node *ast_node = malloc(sizeof(struct ast_while_node));

    ast_node->node_type = N_WHILE;
    
    ast_node->condition = condition;
    ast_node->while_branch = while_branch;

    return (struct ast_node *) ast_node;
}

struct ast_node *new_ast_assignment_node (struct symbol_node * symbol, struct ast_node * value)
{
  struct ast_assignment_node *ast_node = malloc (sizeof (struct ast_assignment_node));

  ast_node->node_type = N_ASSIGN;

  ast_node->symbol = symbol;
  ast_node->symbolName = symbol;
  ast_node->value = value;
  ast_node->symbolNode = symbol;

  return (struct ast_node *) ast_node;
}

/*
struct ast_node* new_ast_assignement_node(struct ast_symbol_node *symbol, struct ast_node *value)
{
    struct ast_assignement_node *ast_node = malloc(sizeof(struct ast_assignement_node));

    ast_node->node_type = 'A';
    
    ast_node->symbol = symbol;
    ast_node->value = value;

    return (struct ast_node *) ast_node;
}*/

struct ast_node* new_ast_number_node(double value)
{
    struct ast_number_node *ast_node = malloc(sizeof(struct ast_number_node));

    ast_node->node_type = N_NUMBER;

    ast_node->value = value;

    return (struct ast_node *) ast_node;
}

struct ast_node* new_ast_identificator_node(char* value)
{
    struct ast_identificator_node *ast_node = malloc(sizeof(struct ast_identificator_node));

    ast_node->node_type = N_IDENT;

    ast_node->value = value;

    return (struct ast_node *) ast_node;
}

struct ast_node* new_ast_jump_node(int node_type, struct ast_node *expr)
{
    struct ast_jump_node *ast_node = malloc(sizeof(struct ast_jump_node));

    ast_node->node_type = node_type;

    ast_node->expr = expr;

    return (struct ast_node *) ast_node;
}


char* enum_to_string(int enumValue)
{
    switch(enumValue)
    {
        case N_OPRELCOMP: return "N_OPRELCOMP"; break;
        case N_FUNCTION_CALL: return "N_FUNCTION_CALL"; break;
        case N_SYMBOLREF: return "N_SYMBOLREF"; break;
        case N_IF: return "N_IF"; break;
        case N_WHILE: return "N_WHILE"; break;
        case N_FOR: return "N_FOR"; break;
        case N_ASSIGN: return "N_ASSIGN"; break;
        case N_NUMBER: return "N_NUMBER"; break;
        case N_INSTRUCTION: return "N_INSTRUCTION"; break;
        case N_FUNC: return "N_FUNC"; break;
        case N_FUNC_LIST: return "N_FUNC_LIST"; break;
        case N_EXPR_LIST: return "N_EXPR_LIST"; break;
        case N_TAB: return "N_TAB"; break;
        case N_CASE: return "N_CASE"; break;
        case N_SWITCH: return "N_SWITCH"; break;
        case op_PLUS: return "op_PLUS"; break;
        case op_MOINS: return "op_MOINS"; break;
        case op_MUL: return "op_MUL"; break;
        case op_DIV: return "op_DIV"; break;
        case op_LSHIFT: return "op_LSHIFT"; break;
        case op_RSHIFT: return "op_RSHIFT"; break;
        case op_BAND: return "op_BAND"; break;
        case op_BOR: return "op_BOR"; break;
        case op_LAND: return "op_LAND"; break;
        case op_LOR: return "op_LOR"; break;
        case op_LT: return "op_LT"; break;
        case op_GT: return "op_GT"; break;
        case op_GEQ: return "op_GEQ"; break;
        case op_LEQ: return "op_LEQ"; break;
        case op_EQ: return "op_EQ"; break;
        case op_NEQ: return "op_NEQ"; break;
        case op_NOT: return "op_NOT"; break;
        case op_BREAK: return "op_BREAK"; break;
        case op_RETURN: return "op_RETURN"; break;
        default: return "op_UNKNOWN";    
    }
}

char* enum_to_string_for_dot(int enumValue)
{
    switch(enumValue)
    {
        case N_OPRELCOMP: return "OPRELCOMP"; break;
        case N_FUNCTION_CALL: return "FUNCTION_CALL"; break;
        case N_SYMBOLREF: return "SYMBOLREF"; break;
        case N_IF: return "IF"; break;
        case N_WHILE: return "WHILE"; break;
        case N_FOR: return "FOR"; break;
        case N_ASSIGN: return "ASSIGN"; break;
        case N_NUMBER: return "NUMBER"; break;
        case N_INSTRUCTION: return "INSTRUCTION"; break;
        case N_FUNC: return "FUNC"; break;
        case N_FUNC_LIST: return "FUNC_LIST"; break;
        case N_EXPR_LIST: return "EXPR_LIST"; break;
        case N_TAB: return "TAB"; break;
        case N_CASE: return "CASE"; break;
        case N_SWITCH: return "SWITCH"; break;
        case op_PLUS: return "PLUS"; break;
        case op_MOINS: return "MOINS"; break;
        case op_MUL: return "MUL"; break;
        case op_DIV: return "DIV"; break;
        case op_LSHIFT: return "LSHIFT"; break;
        case op_RSHIFT: return "RSHIFT"; break;
        case op_BAND: return "BAND"; break;
        case op_BOR: return "BOR"; break;
        case op_LAND: return "LAND"; break;
        case op_LOR: return "LOR"; break;
        case op_LT: return "LT"; break;
        case op_GT: return "GT"; break;
        case op_GEQ: return "GEQ"; break;
        case op_LEQ: return "LEQ"; break;
        case op_EQ: return "EQ"; break;
        case op_NEQ: return "NEQ"; break;
        case op_NOT: return "NOT"; break;
        case op_BREAK: return "BREAK"; break;
        case op_RETURN: return "RETURN"; break;
        default: return "UNKNOWN";    
    }
}

char* operator_to_string(int enumValue)
{
    switch(enumValue)
    {
        case op_PLUS: return "+"; break;
        case op_MOINS: return "-"; break;
        case op_MUL: return "*"; break;
        case op_DIV: return "/"; break;
        case op_LSHIFT: return "<<"; break;
        case op_RSHIFT: return ">>"; break;
        case op_BAND: return "&"; break;
        case op_BOR: return "|"; break;
        case op_LAND: return "&&"; break;
        case op_LOR: return "||"; break;
        case op_LT: return "<"; break;
        case op_GT: return ">"; break;
        case op_GEQ: return ">="; break;
        case op_LEQ: return "<="; break;
        case op_EQ: return "=="; break;
        case op_NEQ: return "!="; break;
        case op_NOT: return "!"; break;
        case N_ASSIGN: return ":="; break;
        default: return "op_UNKNOWN";    
    }
}


void makeDot(FILE* fp)
{
    
}

int generateCaseDotAst(FILE* fp, int blocIndex, int instructionIndex, struct ast_case_node *node)
{
    int idx = instructionIndex;
    int caseIndex = idx++;

    if(node->value == s_DEFAULT) {
        createDotNode(fp, caseIndex, "DEFAULT");
    }
    else {
        char str[12];
        sprintf(str, "%d", node->value);
        createDotNode(fp, caseIndex, str);
    }


    if(node->case_branch != NULL) {
        if(node->case_branch->node_type == N_INSTRUCTION) {
            int blocCaseIndex = idx++;
            createDotNode(fp, blocCaseIndex, "BLOC");
            createNodeDependancy(fp, caseIndex, blocCaseIndex);
            idx = processIntructionsRec(fp, blocCaseIndex, idx, node->case_branch);
        }
        else {
            idx = generateDotFromRandomAst(fp, caseIndex, idx, node->case_branch);
        }    
    }

    createNodeDependancy(fp, blocIndex, instructionIndex);
    return idx;
}

int generateSwitchDotAst(FILE* fp, int blocIndex, int instructionIndex, struct ast_switch_node *node)
{
    int idx = instructionIndex;
    int switchIndex = idx++;

    createDotNode(fp, switchIndex, enum_to_string_for_dot(node->node_type));
    idx = generateDotFromRandomAst(fp, switchIndex, idx, node->value);


    if(node->switch_branch != NULL) {
        if(node->switch_branch->node_type == N_INSTRUCTION) {
            idx = processIntructionsRec(fp, switchIndex, idx, node->switch_branch);
        }
    }

    createNodeDependancy(fp, blocIndex, instructionIndex);
    return idx;
}

int generateWhileDotAst(FILE* fp, int blocIndex, int instructionIndex, struct ast_while_node *node)
{
    int idx = instructionIndex;
    int whileIndex = idx++;
    int indexAfterCond = idx;
    int indexAfterWhileBranch = idx;

    createDotNode(fp, whileIndex, enum_to_string_for_dot(node->node_type));
    if(node->condition != NULL) {
        indexAfterCond = generateDotFromRandomAst(fp, whileIndex, idx, node->condition);
    }
    if(node->while_branch != NULL) {
        if(node->while_branch->node_type == N_INSTRUCTION) {
            int blocWhileIndex = indexAfterCond++;
            createDotNode(fp, blocWhileIndex, "BLOC");
            createNodeDependancy(fp, whileIndex, blocWhileIndex);
            indexAfterWhileBranch = processIntructionsRec(fp, blocWhileIndex, blocWhileIndex+1, node->while_branch);
        }
        else {
            indexAfterWhileBranch = generateDotFromRandomAst(fp, whileIndex, indexAfterCond, node->while_branch);
        }    
    }

    if(indexAfterWhileBranch == idx)
        indexAfterWhileBranch = indexAfterCond;

    createNodeDependancy(fp, blocIndex, instructionIndex);
    return indexAfterWhileBranch;
}

int generateIfDotAst(FILE* fp, int blocIndex, int instructionIndex, struct ast_if_node *node)
{
    int idx = instructionIndex;
    int ifIndex = idx++;
    int indexAfterCond = idx;
    int indexAfterIfBranch = idx;
    int indexAfterElseBranch = idx;

    createDotNodeWithShape(fp, ifIndex, enum_to_string_for_dot(node->node_type), "diamond");
    if(node->condition != NULL) {
        indexAfterCond = generateDotFromRandomAst(fp, ifIndex, idx, node->condition);
    }
    if(node->if_branch != NULL) {
        if(node->if_branch->node_type == N_INSTRUCTION) {
            int blocIfIndex = indexAfterCond++;
            createDotNode(fp, blocIfIndex, "BLOC");
            createNodeDependancy(fp, ifIndex, blocIfIndex);
            indexAfterElseBranch = processIntructionsRec(fp, blocIfIndex, blocIfIndex + 1, node->if_branch);
        }
        else {
            indexAfterIfBranch = generateDotFromRandomAst(fp, ifIndex, indexAfterCond, node->if_branch);
        }    
    }
    indexAfterElseBranch = indexAfterIfBranch;
    if(node->else_branch != NULL) {
        if(node->else_branch->node_type == N_INSTRUCTION) {
            int blocElseIndex = indexAfterIfBranch++;
            createDotNode(fp, blocElseIndex, "BLOC");
            createNodeDependancy(fp, ifIndex, blocElseIndex);
            indexAfterElseBranch = processIntructionsRec(fp, blocElseIndex, blocElseIndex + 1, node->else_branch);
        }
        else {
            indexAfterElseBranch = generateDotFromRandomAst(fp, ifIndex, indexAfterElseBranch, node->else_branch);
        }    
    }

    if(indexAfterElseBranch == idx)
        indexAfterElseBranch = indexAfterIfBranch;

    createNodeDependancy(fp, blocIndex, instructionIndex);
    return indexAfterElseBranch;
}

int generateForDotAst(FILE* fp, int blocIndex, int instructionIndex, struct ast_for_node *node)
{
    int idx = instructionIndex;
    int forIndex = idx++;
    int indexAfterInit = idx;
    int indexAfterCond = idx;
    int indexAfterFinal = idx;
    int indexAfterBranch = idx;

    createDotNode(fp, forIndex, enum_to_string_for_dot(node->node_type));
    if(node->initAffectation != NULL) {
        indexAfterInit = generateDotFromRandomAst(fp, forIndex, idx, node->initAffectation);
    }
    indexAfterCond = indexAfterInit;
    if(node->condition != NULL) {
        indexAfterCond = generateDotFromRandomAst(fp, forIndex, indexAfterCond, node->condition);
    }
    indexAfterFinal = indexAfterCond;
    if(node->finalAffectation != NULL) {
        indexAfterFinal = generateDotFromRandomAst(fp, forIndex, indexAfterFinal, node->finalAffectation);
    }
    indexAfterBranch = indexAfterFinal;
    if(node->for_branch != NULL) {
        if(node->for_branch->node_type == N_INSTRUCTION) {
            int blocForIndex = indexAfterBranch++;
            createDotNode(fp, blocForIndex, "BLOC");
            createNodeDependancy(fp, forIndex, blocForIndex);
            indexAfterBranch = processIntructionsRec(fp, blocForIndex, blocForIndex + 1, node->for_branch);
        }
        else {
            indexAfterBranch = generateDotFromRandomAst(fp, forIndex, indexAfterBranch, node->for_branch);
        }    
    }

    createNodeDependancy(fp, blocIndex, instructionIndex);
    return indexAfterBranch;
}


int generateFunctionCallDotAst(FILE* fp, int blocIndex, int instructionIndex, struct ast_function_node *node)
{
    int idx = instructionIndex;

    int functionIndex = idx++;
    int indexAfterArgument = idx;
    createDotNodeWithShape(fp, functionIndex, node->symbol, "septagon");
    if(node->arguments != NULL) {
        if(node->arguments->node_type == N_EXPR_LIST) {
            indexAfterArgument = processExprListRec(fp, functionIndex, idx, node->arguments);
        }
        else {
            indexAfterArgument = generateDotFromRandomAst(fp, functionIndex, idx, node->arguments);
        }    
    }

    createNodeDependancy(fp, blocIndex, instructionIndex);
    return indexAfterArgument;
}

int generateNumberDotAst(FILE* fp, int blocIndex, int instructionIndex, struct ast_number_node *node)
{
    int idx = instructionIndex;

    char str[12];
    sprintf(str, "%d", node->value);

    createDotNode(fp, idx++, str);

    createNodeDependancy(fp, blocIndex, instructionIndex);
    return idx;
}

int generateSymbolReferenceDotAst(FILE* fp, int blocIndex, int instructionIndex, struct ast_symbol_reference_node *node)
{
    int idx = instructionIndex;

    if(node->symbolNode->node_type == N_IDENT)
    {
        struct ast_identificator_node *idtPtr = (struct ast_identificator_node *) node->symbolNode;
        createDotNode(fp, idx++, idtPtr->value);
        createNodeDependancy(fp, blocIndex, instructionIndex);
    }
    else if(node->symbolNode->node_type == N_TAB) {
        struct ast_tab_node *tabPtr = (struct ast_tab_node *) node->symbolNode;
        idx = generateTabDotAst(fp, blocIndex, idx, tabPtr);
    }
    // createDotNode(fp, idx++, node->symbolName);
    
    //createNodeDependancy(fp, blocIndex, instructionIndex);
    return idx;
}

int generateOprelcompDotAst(FILE* fp, int blocIndex, int instructionIndex, struct ast_op_rel_comp_node *node)
{
    int idx = instructionIndex;
    int operatorIndex = idx++;
    int indexAfterLeft = idx;
    
    createDotNode(fp, operatorIndex, operator_to_string(node->operator));
    if(node->left != NULL) {
        indexAfterLeft = generateDotFromRandomAst(fp, operatorIndex, idx, node->left);
    }
    int indexAfterRight = indexAfterLeft;
    if(node->right != NULL) {
        indexAfterRight = generateDotFromRandomAst(fp, operatorIndex, indexAfterRight, node->right);
    }

    createNodeDependancy(fp, blocIndex, instructionIndex);
    return indexAfterRight;
}

int generateAssignDotAst(FILE* fp, int blocIndex, int instructionIndex, struct ast_assignment_node *node)
{
    int idx = instructionIndex;
    int assignIndex = idx++;
    int symbolIndex = idx;
    int indexAfterRight = idx;

    createDotNode(fp, assignIndex, operator_to_string(node->node_type));
    if(node->symbolNode->node_type == N_IDENT) {
        struct ast_identificator_node *idtPtr = (struct ast_identificator_node *) node->symbolNode;
        createDotNode(fp, symbolIndex, idtPtr->value);
        createNodeDependancy(fp, assignIndex, symbolIndex);
        idx++;
    }
    else if(node->symbolNode->node_type == N_TAB) {
        struct ast_tab_node *tabPtr = (struct ast_tab_node *) node->symbolNode;
        idx = generateTabDotAst(fp, assignIndex, idx, tabPtr);
    }
    else {
        printf("MERDE\n");
    }
    //createDotNode(fp, symbolIndex, node->symbolName);
    
    indexAfterRight = idx;
    if(node->value != NULL) {
        indexAfterRight = generateDotFromRandomAst(fp, assignIndex, indexAfterRight, node->value);
    }

    createNodeDependancy(fp, blocIndex, instructionIndex);
    return indexAfterRight;
}

int generateTabDotAst(FILE *fp, int blocIndex, int instructionIndex, struct ast_tab_node *node) 
{
    int idx = instructionIndex;
    int tabIndex = idx++;

    createDotNode(fp, tabIndex, "TAB");
    createNodeDependancy(fp, blocIndex, tabIndex);

    idx = processTabRec(fp, tabIndex, idx, node);

    return idx;
}

int processTabRec(FILE *fp, int blocIndex, int instructionIndex, struct ast_node *node) {
    int index = instructionIndex;

    if(node->node_type == N_TAB) {
        struct ast_tab_node *tabPtr = (struct ast_tab_node *) node;
        index = processTabRec(fp, blocIndex, index, tabPtr->variable);
        
        index = generateDotFromRandomAst(fp, blocIndex, index, tabPtr->index);
    }
    else if(node->node_type == N_IDENT) {
        struct ast_identificator_node *idtPtr = (struct ast_identificator_node *) node;
        createDotNode(fp, index++, idtPtr->value);
        createNodeDependancy(fp, blocIndex, index - 1);
    }

    return index;
}

int generateDotReturnAst(FILE* fp, int blocIndex, int instructionIndex, struct ast_jump_node *node)
{
    int idx = instructionIndex;

    createDotNodeWithShapeAndColor(fp, idx++, enum_to_string_for_dot(node->node_type), "trapezium", "blue");
    if(node->expr != NULL) {
        idx = generateDotFromRandomAst(fp, instructionIndex, idx, node->expr);
    }

    createNodeDependancy(fp, blocIndex, instructionIndex);
    return idx;
}

int generateDotBreakAst(FILE* fp, int blocIndex, int instructionIndex, struct ast_jump_node *node)
{
    int idx = instructionIndex;

    createDotNodeWithShape(fp, idx++, enum_to_string_for_dot(node->node_type), "box");
    if(node->expr != NULL) {
        idx = generateDotFromRandomAst(fp, instructionIndex, idx, node->expr);
    }

    createNodeDependancy(fp, blocIndex, instructionIndex);
    return idx;
}

int generateDotFromRandomAst(FILE* fp, int blocIndex, int instructionIndex, struct ast_node *node)
{
    fprintf(fp, "\n");
    //printf("%s\n", enum_to_string(node->node_type));
    switch(node->node_type)
    {
        /*case N_FOR:
            return generateDotForAst(fp, int blocIndex, int instructionIndex, (struct ast_for_node *) node);
            break;
        case N_IF:
            return generateDotIfAst(fp, int blocIndex, int instructionIndex, (struct ast_if_node *) node);
            break;*/
        case N_SWITCH:
            return generateSwitchDotAst(fp, blocIndex, instructionIndex, (struct ast_switch_node *) node);
            break;
        case N_CASE:
            return generateCaseDotAst(fp, blocIndex, instructionIndex, (struct ast_case_node *) node);
            break;
        case N_TAB:
            return generateTabDotAst(fp, blocIndex, instructionIndex, (struct ast_tab_node *) node);
            break;
        case N_WHILE:
            return generateWhileDotAst(fp, blocIndex, instructionIndex, (struct ast_while_node *) node);
            break;
        case N_IF:
            return generateIfDotAst(fp, blocIndex, instructionIndex, (struct ast_if_node *) node);
            break;
        case N_ASSIGN:
            return generateAssignDotAst(fp, blocIndex, instructionIndex, (struct ast_for_node *) node);
            break;
        case N_FOR:
            return generateForDotAst(fp, blocIndex, instructionIndex, (struct ast_for_node *) node);
            break;
        case N_FUNCTION_CALL:
            return generateFunctionCallDotAst(fp, blocIndex, instructionIndex, (struct ast_function_node *) node);
            break;
        case N_SYMBOLREF:
            return generateSymbolReferenceDotAst(fp, blocIndex, instructionIndex, (struct ast_symbol_reference_node *) node);
            break;
        case N_NUMBER:
            return generateNumberDotAst(fp, blocIndex, instructionIndex, (struct ast_number_node *) node);
            break;
        case N_OPRELCOMP:
            return generateOprelcompDotAst(fp, blocIndex, instructionIndex, (struct ast_op_rel_comp_node *) node);
        case op_BREAK:
            return generateDotBreakAst(fp, blocIndex, instructionIndex, (struct ast_jump_node *) node);
            break;
        case op_RETURN:
            return generateDotReturnAst(fp, blocIndex, instructionIndex, (struct ast_jump_node *) node);
            break;
        default:
            return instructionIndex;
    }
}

int processExprListRec(FILE* fp, int blocIndex, int expressionIndex, struct ast_expr_list_node *exprsPtr)
{
    int index = expressionIndex;

    if(exprsPtr->current != NULL || exprsPtr->current != 0) {
        if(exprsPtr->next != NULL || exprsPtr->next != 0) {
            index = processExprListRec(fp, blocIndex, index, (struct ast_expr_list_node *) exprsPtr->next);
        }
        // createDotNode(fp, index, enum_to_string(instrPtr->current->node_type));
        // createNodeDependancy(fp, blocIndex, index);
        // index++;

        return generateDotFromRandomAst(fp, blocIndex, index, exprsPtr->current);
    }
    return index;
}

int processIntructionsRec(FILE* fp, int blocIndex, int instructionIndex, struct ast_instruction_node *instrPtr)
{
    int index = instructionIndex;

    if(instrPtr->current != NULL || instrPtr->current != 0) {
        if(instrPtr->next != NULL || instrPtr->next != 0) {
            index = processIntructionsRec(fp, blocIndex, index, (struct ast_instruction_node *) instrPtr->next);
        }
        // createDotNode(fp, index, enum_to_string(instrPtr->current->node_type));
        // createNodeDependancy(fp, blocIndex, index);
        // index++;

        return generateDotFromRandomAst(fp, blocIndex, index, instrPtr->current);
    }
    return index;
}

int generateFunctionDot(FILE* fp, int currentIndex, struct ast_node *func)
{
    struct ast_func_node *funcPtr = (struct ast_func_node *) func;
    struct ast_instruction_node *instrPtr = funcPtr->instructions;

    int functionIndex = ++currentIndex;
    int blocIndex = ++currentIndex;
    
    
    createFunctionDotNode(fp, functionIndex, funcPtr->functionName, funcPtr->returnType);
    createDotNode(fp, blocIndex, "BLOC");
    createNodeDependancy(fp, functionIndex, blocIndex);
    
    int instrBeginning = ++currentIndex;
    currentIndex = processIntructionsRec(fp, blocIndex, instrBeginning, instrPtr);
    
    return currentIndex;
}

void createDotNode(FILE* fp, int index, char* label)
{
    fprintf(fp, "node_%d [label=\"%s\"]\n", index, label);
} 

void createFunctionDotNode(FILE* fp, int index, char* functionName, char* returnType)
{
    fprintf(fp, "node_%d [label=\"%s, %s\" shape=invtrapezium color=blue]\n", index, functionName, returnType);
}

void createDotNodeWithShape(FILE* fp, int index, char* label, char* shape)
{
    fprintf(fp, "node_%d [label=\"%s\" shape=%s]\n", index, label, shape);
}

void createDotNodeWithShapeAndColor(FILE* fp, int index, char* label, char* shape, char* color)
{
    fprintf(fp, "node_%d [label=\"%s\" shape=%s color=%s]\n", index, label, shape, color);
}

void createNodeDependancy(FILE *fp, int parent, int children)
{
    fprintf(fp, "node_%d -> node_%d\n", parent, children);
}