all: main.o auxiliary_functions.o prepare_statement.o execute_statement.o meta_statement.o
	@echo '*Compiling program from object files.'
	@gcc -o launcher.run main.o auxiliary_functions.o prepare_statement.o execute_statement.o meta_statement.o
main.o: main.c
	@echo '*Compiling main.'
	@gcc -c main.c
auxiliary_functions.o: auxiliary_functions.c
	@echo '*Compiling auxiliary_functions.'
	@gcc -c auxiliary_functions.c
prepare_statement.o: prepare_statement.c
	@echo 'Compiling prepare_statement.'
	@gcc -c prepare_statement.c
execute_statement.o: execute_statement.c
	@echo '*Compiling execute_statement.'
	@gcc -c execute_statement.c
meta_statement.o: meta_statement.c
	@echo '*Compiling meta_statement.'
	@gcc -c meta_statement.c
clean:
	@echo 'Cleaning object files.'
	@rm *.o
