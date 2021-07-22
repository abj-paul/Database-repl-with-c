#ifndef META_STATEMENT_HEADER_GUARD
#define META_STATEMENT_HEADER_GUARD

typedef enum{
  META_COMMAND_SUCCESS,
  META_COMMAND_UNRECOGNIZED_COMMAND
} MetaCommandResult;

// We need InputBuffer datatype.
#include "auxiliary_functions.h"

MetaCommandResult do_meta_command(InputBuffer* );

#endif
