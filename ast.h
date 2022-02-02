#include <stdio.h>
#include <stdlib.h>

enum core_nodes_types {
    N_OPRELCOMP   = 4000,
    N_FUNCTION_CALL = 4001,
    N_SYMBOLREF   = 4002,
    N_IF          = 4003,
    N_WHILE       = 4004,
    N_FOR         = 4005,
    N_ASSIGN      = 4006,
    N_NUMBER      = 4007,
    N_INSTRUCTION = 4008,
    N_FUNC        = 4009,
    N_FUNC_LIST   = 4010,
    N_EXPR_LIST   = 4011,
    N_TAB         = 4012,
    N_IDENT       = 4013,
    N_SWITCH      = 4014,
    N_CASE        = 4015,
    s_DEFAULT     = 9997
};


enum op_rel_comp_operator {
    op_PLUS = 5000,
    op_MOINS = 5001,
    op_MUL = 5002,
    op_DIV = 5003,
    op_LSHIFT = 5004,
    op_RSHIFT = 5005,
    op_BAND = 5006,
    op_BOR = 5007,
    op_LAND = 5008,
    op_LOR = 5009,
    op_LT = 5010,
    op_GT = 5011,
    op_GEQ = 5012,
    op_LEQ = 5013,
    op_EQ = 5014,
    op_NEQ = 5015,
    op_NOT = 5016
};

enum jump_operator {
    op_BREAK = 5100,
    op_RETURN = 5101
};

/*******************************************************
 *******************  NODES  **************************
 ******************************************************/

struct symbol_node
{
    char *name;

    double value;

    struct ast_node *function;
};

struct ast_node
{
  int node_type;

  struct ast_node * left;

  struct ast_node * right;
};

struct ast_func_list
{
    int node_type;
    struct ast_node *current;
    struct ast_node *next;
};


struct ast_func_node
{
    int node_type;

    char* returnType;
    char* functionName;
    struct ast_instruction_node *instructions;
};

struct ast_instruction_node
{
    int node_type;

    struct ast_node *current;
    struct ast_node *next;
};

struct ast_expr_list_node
{
    int node_type;

    struct ast_node *current;
    struct ast_node *next;
};

struct ast_op_rel_comp_node // Pour les opérateurs relationnels et d'égalité
{
  int node_type;

  int operator;

  struct ast_node * left;

  struct ast_node * right;
};

struct ast_tab_node {
    int node_type;

    struct ast_node *index;
    struct ast_node *variable;
};

struct ast_function_node { // Pour les appels de fonctions
    int node_type;
    struct ast_node *arguments;
    struct symbol_node *symbol;
};

struct ast_symbol_reference_node { // Pour les références aux identificateurs
    int node_type;
    struct symbol_node *symbol;
    char *symbolName;
    struct ast_node *symbolNode;
};

struct ast_switch_node {
    int node_type;

    struct ast_node *value;
    struct ast_node *switch_branch;
};

struct ast_case_node {
    int node_type;

    int value;
    struct ast_node *case_branch;
};

struct ast_if_node { // Pour les if/else
    int node_type;
    struct ast_node *condition;
    struct ast_node *if_branch;
    struct ast_node *else_branch;
};

struct ast_for_node { // Pour les boucles for
    int node_type;
    struct ast_node *initAffectation;
    struct ast_node *condition;
    struct ast_node *finalAffectation;
    struct ast_node *for_branch;
};

struct ast_while_node { // Pour les boucles whiles
    int node_type;
    struct ast_node *condition;
    struct ast_node *while_branch;
};

struct ast_assignment_node { // Pour les assignements de valeurs
    int node_type;
    struct symbol_node *symbol;
    struct ast_node *value;
    char *symbolName;
    struct ast_node *symbolNode;
};

struct ast_number_node { // Pour les nombres
    int node_type;
    int value;
};

struct ast_identificator_node { // Pour les nombres
    int node_type;
    char* value;
};

struct ast_jump_node {
    int node_type;
    struct ast_node *expr;
};

/******************************************************
 ****************  CREATION DE NODES  *****************
 ******************************************************/
char* enum_to_string(int enumValue);
char* operator_to_string(int enumValue);

struct ast_node* new_ast_node(int node_type, struct ast_node *left, struct ast_node *right);
struct ast_node* new_ast_func_list_node(struct ast_node *currentNode, struct ast_node *nextNode);
struct ast_node* new_ast_func_node(char* returnType, char* functionName, struct ast_instruction_node *instructions);
struct ast_node* new_ast_instruction_node(struct ast_node *currentNode, struct ast_node *nextNode);
struct ast_node* new_ast_expr_list_node(struct ast_node *currentNode, struct ast_node *nextNode);
struct ast_node* new_ast_op_rel_comp_node(int operator, struct ast_node *left, struct ast_node *right);
struct ast_node* new_ast_tab_node(struct ast_node *index, struct ast_node *variable);
struct ast_node* new_ast_function_reference_node(struct symbol_node *symbol, struct ast_node *arguments);
struct ast_node* new_ast_symbol_reference_node(struct symbol_node *symbol);
struct ast_node* new_ast_if_node(struct ast_node *condition, struct ast_node *if_branch, struct ast_node *else_branch);
struct ast_node* new_ast_for_node(struct ast_node *init, struct ast_node *condition, struct ast_node *fin, struct ast_node *for_branch);
struct ast_node* new_ast_while_node(struct ast_node *condition, struct ast_node *while_branch);
struct ast_node *new_ast_assignment_node (struct symbol_node * symbol, struct ast_node * value);
struct ast_node* new_ast_number_node(double value);
struct ast_node* new_ast_identificator_node(char* value);
struct ast_node* new_ast_identificator_node(char* value);
struct ast_node* new_ast_jump_node(int node_type, struct ast_node *ast_node);
struct ast_node* new_ast_switch_node(struct ast_node *value, struct ast_node *switch_branch);
struct ast_node* new_ast_case_node(int value, struct ast_node *case_branch);


void makeDot(FILE* fp);
int generateFunctionDot(FILE* fp, int currentIndex, struct ast_node *func);
void createFunctionDotNode(FILE* fp, int index, char* functionName, char* returnType);
void createDotNode(FILE* fp, int index, char* label);
void createDotNodeWithShape(FILE* fp, int index, char* label, char* shape);
void createDotNodeWithShapeAndColor(FILE* fp, int index, char* label, char* shape, char* color);
void createNodeDependancy(FILE* fp, int parent, int children);