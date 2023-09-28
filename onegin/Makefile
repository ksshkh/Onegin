build: main.o sort.o read_file.o comparators.o output_result.o
	g++ main.o sort.o read_file.o comparators.o output_result.o -o sort_onegin
main.o: main.cpp sort.h
	g++ -c main.cpp
sort.o: sort.cpp sort.h
	g++ -c sort.cpp
read_file.o: read_file.cpp read_file.h
	g++ -c read_file.cpp
comparators.o: comparators.cpp comparators.h
	g++ -c comparators.cpp
output_result.o: output_result.cpp output_result.h
	g++ -c output_result.cpp

.PHONY: clean
clean:
	rm -rf *.o
	rm -rf sort_onegin.exe
