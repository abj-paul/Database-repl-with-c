#include "prepare_statement.h"

PrepareResult prepare_statement(InputBuffer* input_buffer, Statement* statement){
  if(strncmp(input_buffer->buffer, "insert", 6)==0){
    //printf("Converting '%s' to bytecode.\n", input_buffer->buffer);
    statement->type = STATEMENT_INSERT;
    return PREPARE_SUCCESS;
  }
  else if(strcmp(input_buffer->buffer, "select")==0){
    statement->type = STATEMENT_SELECT;
    //printf("Converting '%s' to bytecode.\n", input_buffer->buffer);
    return PREPARE_SUCCESS;
  }
  else return PREPARE_UNRECOGNIZED_STATEMENT;
}
