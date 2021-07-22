#include "execute_statement.h"

void execute_statement(Statement* statement){
  switch((*statement).type){
  case STATEMENT_INSERT:
    printf("Executing bytecode of 'insert' command.\n");
    break;
  case STATEMENT_SELECT:
    printf("Executing bytecode of 'select' command.\n");
    break;
  default:
    printf("Unknown bytecode for '%s' statement.\n",statement->type);
    break;
  }
}
