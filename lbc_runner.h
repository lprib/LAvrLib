/*
* lbc_runner.h
*
* Created: 5/04/2019 8:33:55 AM
*  Author: liam
*/


#ifndef LBC_RUNNER_H_
#define LBC_RUNNER_H_

typedef unsigned int stackval_t;


typedef struct {
	unsigned char* bytecode;
	stackval_t* stack_bottom;
	stackval_t* stack_ptr;
} ExecutionContext;

void execute_function(ExecutionContext context, int function_index);

stackval_t next_bytecode_int(ExecutionContext* context, int* instruction_pointer);

stackval_t stack_pop(ExecutionContext* context);

void stack_push(ExecutionContext* context, stackval_t value);

#endif /* LBC_RUNNER_H_ */