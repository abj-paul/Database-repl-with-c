#include "prepare_statement.h"

PrepareResult prepare_statement(InputBuffer* input_buffer, Statement* statement){
  if(strncmp(input_buffer->buffer, "insert", 6)==0){
    //printf("Converting '%s' to bytecode.\n", input_buffer->buffer);
    int args_assigned = sscanf(
	input_buffer->buffer, "insert %d %s %s", &(statement->row_to_insert.id),
	statement->row_to_insert.username, statement->row_to_insert.email
	);
    if(args_assigned<3) return PREPARE_SYNTAX_ERROR;
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
