#ifndef META_STATEMENT_HEADER_GUARD
#define META_STATEMENT_HEADER_GUARD
// We need InputBuffer datatype.
#include "auxiliary_functions.h"

typedef enum{
  META_COMMAND_SUCCESS,
  META_COMMAND_UNRECOGNIZED_COMMAND
}MetaCommandResult;

MetaCommandResult do_meta_command(InputBuffer* );

#endif
