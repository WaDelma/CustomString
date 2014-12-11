f?=
default: String.o main.o
	g++ $(f) -std=c++11 -o app.o main.o String.o

main.o: main.cpp String.hpp assert.hpp
	g++ $(f) -c -std=c++11 main.cpp String.hpp assert.hpp

String.o: String.cpp String.hpp assert.hpp
	g++ $(f) -c -std=c++11 String.cpp String.hpp assert.hpp
