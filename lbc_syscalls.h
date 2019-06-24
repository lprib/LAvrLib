/*
 * lbc_syscalls.h
 *
 * Created: 12/06/2019 10:10:50 PM
 *  Author: liam
 */ 


#ifndef LBC_SYSCALLS_H_
#define LBC_SYSCALLS_H_

#include "lbc_runner.h"

//syscall function pointer
typedef void (*syscall_function_t)(ExecutionContext*);

extern const syscall_function_t syscalls[];

#endif /* LBC_SYSCALLS_H_ */