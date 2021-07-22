#ifndef AUXULIARY_HEADER_GUARD
#define AUXULIARY_HEADER_GUARD

// We add them here because we will include this header file first.
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>


typedef struct{
  char* buffer;
  size_t buffer_length;
  size_t input_length;
}InputBuffer;

void print_prompt();
void read_input(InputBuffer* );
void close_input_buffer(InputBuffer* );
InputBuffer* new_input_buffer();

#endif
