build: main.o solver_equation.o interactive_solver.o test_equation.o
	g++ main.o solver_equation.o interactive_solver.o test_equation.o -o solver_square
main_user.o: main.cpp solver_equation.h colors.h interactive_solver.h
	g++ -c main.cpp
solver_equation.o: solver_equation.cpp solver_equation.h colors.h interactive_solver.h
	g++ -c solver_equation.cpp
interactive_solver.o: interactive_solver.cpp solver_equation.h colors.h interactive_solver.h
	g++ -c interactive_solver.cpp
test_equation.o: test_equation.cpp solver_equation.h colors.h test_equation.h interactive_solver.h my_assert.h
	g++ -c test_equation.cpp

.PHONY: clean
clean:
	rm -rf *.o
	rm -rf solver_square.exe
