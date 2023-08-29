build: main.o solver_equation.o input_output.o test_equation.o
	g++ main.o solver_equation.o input_output.o test_equation.o -o solver_square
main_user.o: main.cpp solver_equation.h colors.h input_output.h
	g++ -c main.cpp
solver_equation.o: solver_equation.cpp solver_equation.h colors.h input_output.h
	g++ -c solver_equation.cpp
input_output.o: input_output.cpp solver_equation.h colors.h input_output.h
	g++ -c input_output.cpp
test_equation.o: test_equation.cpp solver_equation.h colors.h test_equation.h input_output.h my_assert.h
	g++ -c test_equation.cpp

.PHONY: clean
clean:
	rm -rf *.o
	rm -rf solver_square.exe



















