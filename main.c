#include "auxiliary_functions.h"
#include "table_properties.h"
#include "prepare_statement.h"
#include "execute_statement.h"
#include "meta_statement.h"

int main(void){
  Table* table = new_table();

  while(true){
    InputBuffer* input_buffer = new_input_buffer();
    print_prompt();
    read_input(input_buffer);

    // Its a meta command if it starts with a dot(.)
    if(input_buffer->buffer[0]=='.'){
      switch(do_meta_command(input_buffer)){
      case (META_COMMAND_SUCCESS):
        printf("Meta command '%s' executed successfully.\n",input_buffer->buffer);
        continue;
      case META_COMMAND_UNRECOGNIZED_COMMAND:
        printf("Unrecognized meta command '%s'\n",input_buffer->buffer);
        continue;
      }
    }else{
      // Prepare bytecode from the given command
      Statement statement;
      switch(prepare_statement(input_buffer, &statement)){
      case PREPARE_SUCCESS:
        break;
      case PREPARE_UNRECOGNIZED_STATEMENT:
        printf("Failed to convert to bytecode, Unrecognized command '%s'\n",input_buffer->buffer);
        continue;
      case PREPARE_SYNTAX_ERROR:
        printf("Failed to convert to bytecode, Syntax error in command '%s'\n",input_buffer->buffer);
        continue;
      case PREPARE_STRING_TOO_LONG:
        printf("Too long String!\n");
        continue;
      case PREPARE_NEGATIVE_ID:
        printf("Student ID can't be negative!\n");
        continue;
      }

      // Now execute the bytecode.
      switch(execute_statement(&statement, table)){
      case EXECUTE_SUCCESS:
        break;
      case EXECUTE_FAILURE:
        printf("Failed to execute the bytecode %d.\n",statement.type);
        continue;
      case EXECUTE_TABLE_FULL:
        printf("No more entry possible! The table is full.\n");
        continue;
      }
    }
  }
  return 0;
}
