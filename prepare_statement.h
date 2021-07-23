#ifndef PREPARE_STATEMENT_HEADER_GUARD
#define PREPARE_STATEMENT_HEADER_GUARD
//We use input_buffer and Row.
#include "auxiliary_functions.h"
#include "table_properties.h"

typedef enum{
  STATEMENT_INSERT,
  STATEMENT_SELECT
} StatementType;

typedef struct{
  StatementType type;
  Row row_to_insert; //only used by insert statement
}Statement;

typedef enum{
  PREPARE_SUCCESS,
  PREPARE_SYNTAX_ERROR,
  PREPARE_UNRECOGNIZED_STATEMENT,
  PREPARE_STRING_TOO_LONG,
  PREPARE_NEGATIVE_ID
} PrepareResult;


PrepareResult prepare_statement(InputBuffer* input_buffer, Statement* statement);

#endif
