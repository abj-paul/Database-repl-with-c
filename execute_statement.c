#include "execute_statement.h"

ExecuteResult execute_statement(Statement* statement, Table* table){
  switch((*statement).type){
  case STATEMENT_INSERT:
    return execute_insert(statement, table);
  case STATEMENT_SELECT:
    return execute_select(statement, table);
  default:
    printf("Unknown bytecode for '%d' statement.\n",statement->type);
    return EXECUTE_FAILURE;
  }
}

ExecuteResult execute_insert(Statement* statement, Table* table){
  if(table->num_rows >= TABLE_MAX_ROWS){
    return EXECUTE_TABLE_FULL;
  }
  Row* row_to_insert = &(statement->row_to_insert);
  serialize_row(row_to_insert, row_slot(table, table->num_rows));
  table->num_rows++;
  return EXECUTE_SUCCESS;
}

ExecuteResult execute_select(Statement* statement, Table* table){
  Row row;
  for(uint32_t i=0; i<table->num_rows; i++){
    //printf("Offset - %d - %d - %d\n",ID_OFFSET,USERNAME_OFFSET,EMAIL_OFFSET);
    //printf("Size - %d - %d - %d\n",ID_SIZE,USERNAME_SIZE,EMAIL_SIZE);
    deserialize_row(row_slot(table, i), &row);
    print_row(&row);
  }
  return EXECUTE_SUCCESS;
}
