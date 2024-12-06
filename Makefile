all:
	g++ -std=c++17 ./Main.cpp -lmingw32 -o bin/cpf

run: 
	./bin/cpf