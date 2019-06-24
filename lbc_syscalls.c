/*
* lbc_syscalls.c
*
* Created: 12/06/2019 10:10:27 PM
*  Author: liam
*/

#include "lbc_syscalls.h"
#include "lbc_runner.h"
#include "usart.h"

void usart_write(ExecutionContext* context) {
	usart_write_int_line(stack_pop(context));
}

const syscall_function_t syscalls[] = {
	&usart_write
};