#include "prepare_statement.h"

PrepareResult prepare_statement(InputBuffer* input_buffer, Statement* statement){
  if(strncmp(input_buffer->buffer, "insert", 6)==0){
    //printf("Converting '%s' to bytecode.\n", input_buffer->buffer);
    /*int args_assigned = sscanf(input_buffer->buffer, "insert %d %s %s", &(statement->row_to_insert.id),statement->row_to_insert.username, statement->row_to_insert.email);
      if(args_assigned<3) return PREPARE_SYNTAX_ERROR;*/
    char* keyword = strtok(input_buffer->buffer, " ");
    char* id_string = strtok(NULL, " ");
    char* username = strtok(NULL, "\"");
    char* email = strtok(NULL, " \n");

    if(id_string==NULL || username==NULL || email==NULL){
      return PREPARE_SYNTAX_ERROR;
    }
    int id = atoi(id_string);
    if(id<0) return PREPARE_NEGATIVE_ID;
    if(strlen(username)>COLUMN_USERNAME_SIZE || strlen(email)>COLUMN_EMAIL_SIZE){
      return PREPARE_STRING_TOO_LONG;
    }
    statement->row_to_insert.id=id;
    strcpy(statement->row_to_insert.username, username);
    strcpy(statement->row_to_insert.email, email);
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
