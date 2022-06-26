FLAGS = -g -c --std=c++17

all:
	mkdir -p bin
	g++ $(FLAGS) src/producto.cpp -o bin/producto.o
	g++ $(FLAGS) src/tienda.cpp -o bin/tienda.o
	g++ $(FLAGS) src/main.cpp -o bin/main.o
	g++ -g -o bin/tarea3 bin/producto.o bin/tienda.o bin/main.o

test:
	mkdir -p bin
	g++ $(FLAGS) src/producto.cpp -o bin/producto.o
	g++ $(FLAGS) src/tienda.cpp -o bin/tienda.o
	g++ $(FLAGS) tests/producto_tests.cpp -o bin/producto_tests.o
	g++ $(FLAGS) tests/tienda_tests.cpp -o bin/tienda_tests.o
	g++ -g -o bin/tarea3_tests bin/producto_tests.o bin/tienda_tests.o bin/producto.o bin/tienda.o -lgtest -lgtest_main -lpthread

clean:
	rm -Rf bin                                                                