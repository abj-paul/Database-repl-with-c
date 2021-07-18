#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<string.h>

typedef struct {
  char* buffer;
  size_t buffer_legth;
  ssize_t input_length;
}InputBuffer;

// For meta commands. We parse them separately, outside VM
typedef enum{
  META_COMMAND_SUCCESS,
  META_COMMAND_UNRECOGNIZED_COMMAND
}MetaCommandResult;

// our statements from frontend that we will convert to bytecode
typedef enum{
  STATEMENT_SELECT,
  STATEMENT_INSERT
}StatementType;

// Success in Convert the statement into bytecode?
typedef enum{
  PREPARE_SUCCESS,
  PREPARE_UNRECOGNIZED_STATEMENT
}PrepareResult;

InputBuffer* new_input_buffer(){
  InputBuffer* input_buffer = (InputBuffer*)malloc(sizeof(InputBuffer));
  input_buffer->buffer = NULL;
  input_buffer->buffer_legth = 0;
  input_buffer->input_length = 0;

  return input_buffer;
}
void print_prompt(){printf("ajp >");}

void read_input(InputBuffer* input_buffer){
  size_t bytes_read = getline(&(input_buffer->buffer), &(input_buffer->buffer_legth), stdin);
  if(bytes_read<=0){
    printf("Error reading input.\n");
    exit(EXIT_FAILURE);
  }
  // Getting rid of the trailing newline character.
  input_buffer->buffer[bytes_read-1] = '\0';
  input_buffer->input_length = bytes_read - 1;
}

void close_input_buffer(InputBuffer* input_buffer){
  free(input_buffer->buffer);
  free(input_buffer);
}

MetaCommandResult do_meta_command(InputBuffer* input_buffer){
  if(strcmp(input_buffer->buffer, ".exit")==0){
    close_input_buffer(input_buffer);
    exit(EXIT_SUCCESS);
  }
  return META_COMMAND_UNRECOGNIZED_COMMAND;
}

PrepareResult prepare_statement(InputBuffer* input_buffer, StatementType* statement){
  if(strncmp(input_buffer->buffer, "insert", 6)==0){
    *statement = STATEMENT_INSERT;
    printf("Converting '%s' to bytecode.\n", input_buffer->buffer);
    return PREPARE_SUCCESS;
  }
  if(strcmp(input_buffer->buffer, "select")==0){
    *statement = STATEMENT_SELECT;
    printf("Converting '%s' to bytecode.\n",input_buffer->buffer);
    return PREPARE_SUCCESS;
  }
  return PREPARE_UNRECOGNIZED_STATEMENT;
}

void execute_statement(StatementType* statement){
  switch(*statement){
  case (STATEMENT_INSERT):
    printf("Executing bytecode in VM.\n");
    break;
  case STATEMENT_SELECT:
    printf("Executing bytecode in VM.\n");
    break;
  }
}

int main(){

  while(true){
    InputBuffer* input_buffer = new_input_buffer();
    print_prompt();
    read_input(input_buffer);
    if(input_buffer->buffer[0]=='.'){
      switch(do_meta_command(input_buffer)){
      case META_COMMAND_SUCCESS:
        continue;
      case META_COMMAND_UNRECOGNIZED_COMMAND:
        printf("Unrecognized meta command '%s'\n",input_buffer->buffer);
        continue;
      }
    }

    StatementType statement;
    switch(prepare_statement(input_buffer, &statement)){
    case PREPARE_SUCCESS:
      break;
    case PREPARE_UNRECOGNIZED_STATEMENT:
      printf("Converting '%s' to bytecode ended in failure.\n", input_buffer->buffer);
      continue;
    }
    execute_statement(&statement);
  }

  return 0;
}
