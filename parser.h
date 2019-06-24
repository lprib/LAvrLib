/*
* parser.h
*
* Created: 6/04/2019 9:21:43 AM
*  Author: liam
*/


#ifndef PARSER_H_
#define PARSER_H_

#include <stdlib.h>
#include <stdbool.h>

//temporary
typedef struct ParserState ParserState;
typedef struct ParserState {
	//points to full program
	char* program;
	
	//not including terminator
	size_t program_length;
	
	int current_program_index;
	
	void* ast_buffer;
	size_t current_ast_buffer_index;
} ParserState;

bool consume_alpha(ParserState* state, char* out_consumed_char);
bool consume_ident(ParserState* state, char* out_consumed_ident, size_t* out_num_consumed_chars);
bool consume_number(ParserState* state, int* out_consumed_number);

typedef struct Expr Expr;
typedef struct BinaryOperation BinaryOperation;
typedef struct FuncCall FuncCall;
typedef struct FuncDef FuncDef;
typedef struct Block Block;
typedef struct ProgramAST ProgramAST;

struct Block {
	Expr* expression_list;
	size_t expression_list_len;
};


enum ExprType {
	BinaryOperationType
};


struct Expr {
	enum ExprType type;
	union {
		BinaryOperation* a;
	} data;
};

enum BinaryOperationType {
	ADD, SUB
};

struct BinaryOperation {
	enum BinaryOperationType type;
	Expr* left;
	Expr* right;
};


struct FuncCall {
	char* ident;
	Expr* args;
	size_t args_len;
};


struct FuncDef {
	char* ident;
	char** arg_names;
	Block expressions;
};


struct ProgramAST {
	Block expressions;
};


ProgramAST* parse(char* program, void* ast_buffer, size_t ast_buffer_size);

#endif /* PARSER_H_ */