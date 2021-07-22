#ifndef EXECUTE_STATEMENT_HEADER_GUARD
#define EXECUTE_STATEMENT_HEADER_GUARD

// We need Statement datatype in some functions, (because we execute statement/bytecode)
#include "prepare_statement.h"

void execute_statement(Statement* );

#endif
