

FLAGS = 

main : ./debug/src/main.o 
	g++ ./debug/src/main.o  -o ./debug/main

./debug/src/main.o: src/main.cpp

	g++ -std=c++20 ./src/main.cpp -o ./debug/src/main.o -c $(FLAGS) 


clean:
	rm -d -r debug
	mkdir debug
	mkdir debug/src

