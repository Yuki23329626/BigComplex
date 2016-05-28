all: 
	g++ main.cpp rational.cpp bigint.cpp complex.cpp -o main
clean:
	rm -r main
