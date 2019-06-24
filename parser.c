/*
* parser.h
*
* Created: 6/04/2019 9:21:19 AM
*  Author: liam
*/

#include "parser.h"
#include "util.h"

#include <stdbool.h>

char get_current_char(ParserState* state) {
	return state->program[state->current_program_index];
}

bool can_consume_chars(ParserState* state, int num_chars) {
	return (state->current_program_index + num_chars) <= state->program_length;
}

//TODO maybe not needed
//returns if succeeded
bool consume_chars(ParserState* state, int num_chars) {
	if(can_consume_chars(state, num_chars))
	{
		//there are enough program chars left to consume
		state->current_program_index += num_chars;
		return true;
	}
	return false;
}

//need to uber optimize
//returns if succeeded
bool consume_char(ParserState* state, char chr) {
	if((get_current_char(state) == chr) && can_consume_chars(state, 1))
	{
		state->current_program_index ++;
		return true;
	}
	return false;
}

bool consume_whitespace(ParserState* state) {
	int num_consumed = 0;
	while(consume_char(state, ' '))
	{
		num_consumed ++;
	}
	return num_consumed != 0;
}

//on success, returns true and stores consumed char in out_consumed_char pointer
bool consume_alpha(ParserState* state, char* out_consumed_char) {
	char c = get_current_char(state);
	if(c >= 'a' && c <= 'z' && can_consume_chars(state, 1))
	{
		*out_consumed_char = c;
		state->current_program_index ++;
		return true;
	}
	return false;
}

bool consume_ident(ParserState* state, char* out_consumed_ident, size_t* out_num_consumed_chars) {
	size_t 	num_consumed = 0;
	char* out_next_char = out_consumed_ident;
	while(consume_alpha(state, out_next_char))
	{
		out_next_char++;
		num_consumed++;
	}
	
	if(num_consumed != 0)
	{
		*out_num_consumed_chars = num_consumed;
		//add zero terminator
		*out_next_char = 0;
		return true;
	}
	return false;
}

//TODO this is broken/infinite loop somewhere
bool consume_number(ParserState* state, int* out_consumed_number) {
	*out_consumed_number = 0;
	size_t num_chars = 0;
	
	while(get_current_char(state) >= '0' && get_current_char(state) <= '9' && can_consume_chars(state, 1))
	{
		num_chars++;
	}
	
	if(num_chars == 0)
	{
		return false;	
	}
	
	//iterate backwards (least significant to most significant) over digits.
	for(int i = 0; i < num_chars; i++)
	{
		unsigned char digit = state->program[state->current_program_index + num_chars - i - 1];
		*out_consumed_number += digit * int_pow(10, i);
	}
	
	return true;
	
}

ProgramAST* parse(char* program, void* ast_buffer, size_t ast_buffer_size) {
	
}