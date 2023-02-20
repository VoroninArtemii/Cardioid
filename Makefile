test: header.cpp test.cpp
	clang++ -c header.cpp
	ar rc libheader.a header.o
	ranlib libheader.a
	clang++ -Wall test.cpp -L. -lheader -o test -lgtest
main: header.cpp main.cpp
	clang++ -c header.cpp
	ar rc libheader.a header.o
	ranlib libheader.a
	clang++ -Wall main.cpp -L. -lheader -o main
clean:
	rm -rf main test *.o *.out *.a
