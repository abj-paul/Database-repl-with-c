#ifndef PREPARE_STATEMENT_HEADER_GUARD
#define PREPARE_STATEMENT_HEADER_GUARD

typedef enum{
  STATEMENT_INSERT,
  STATEMENT_SELECT
} StatementType;

typedef struct{
  StatementType type;
}Statement;

typedef enum{
  PREPARE_SUCCESS,
  PREPARE_UNRECOGNIZED_STATEMENT
} PrepareResult;

//We use input_buffer in some functions so we need this header file.
#include "auxiliary_functions.h"

PrepareResult prepare_statement(InputBuffer* input_buffer, Statement* statement);

#endif
