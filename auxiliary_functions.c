#include "auxiliary_functions.h"

void print_prompt(){
  printf("adb > ");
}

void read_input(InputBuffer* input_buffer){
  size_t bytes_read = getline(&(input_buffer->buffer), &(input_buffer->buffer_length), stdin);
  if(bytes_read<=0){
    printf("Error reading input.\n");
    exit(EXIT_FAILURE);
  }
  // get rid of the trailing newline character;
  input_buffer->buffer[bytes_read-1]='\0';
  input_buffer->input_length = bytes_read - 1;
}

InputBuffer* new_input_buffer(){
  InputBuffer* input_buffer = (InputBuffer*)malloc(sizeof(InputBuffer));
  input_buffer->buffer = NULL;
  input_buffer->input_length = 0;
  input_buffer->buffer_length = 0;
  return input_buffer;
}

void close_input_buffer(InputBuffer* input_buffer){
  free(input_buffer->buffer);
  free(input_buffer);
  return;
}
