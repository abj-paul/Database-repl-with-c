#ifndef EXECUTE_STATEMENT_HEADER_GUARD
#define EXECUTE_STATEMENT_HEADER_GUARD

// We need Statement datatype in some functions, (because we execute statement/bytecode)
#include "prepare_statement.h"
typedef enum{
  EXECUTE_SUCCESS,
  EXECUTE_FAILURE,
  EXECUTE_TABLE_FULL
}ExecuteResult;

ExecuteResult execute_insert(Statement* , Table* );
ExecuteResult execute_select(Statement* , Table* );
ExecuteResult execute_statement(Statement* , Table* );

#endif
