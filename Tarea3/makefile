FLAGS = -g -c --std=c++17 -fPIC

all:
	mkdir -p obj
	mkdir -p bin
	g++ $(FLAGS) src/producto.cpp -o obj/producto.o
	g++ $(FLAGS) src/tienda.cpp -o obj/tienda.o
	g++ -shared -o bin/libtienda.so obj/producto.o obj/tienda.o
	mkdir -p bin/include
	cp src/tienda.h ./bin/include
	cp src/producto.h ./bin/include
	cp src/excepcionCantidadDeCaracteresProducto.h ./bin/include
	cp src/excepcionCantidadDeCaracteresTienda.h ./bin/include
	cp src/excepcionNumeroNegativo.h ./bin/include

test:
	mkdir -p obj
	mkdir -p bin
	g++ $(FLAGS) src/producto.cpp -o obj/producto.o
	g++ $(FLAGS) src/tienda.cpp -o obj/tienda.o
	g++ $(FLAGS) tests/producto_tests.cpp -o obj/producto_tests.o
	g++ $(FLAGS) tests/tienda_tests.cpp -o obj/tienda_tests.o
	g++ -g -o bin/tarea3_tests obj/producto_tests.o obj/tienda_tests.o obj/producto.o obj/tienda.o -lgtest -lgtest_main -lpthread

clean:
	rm -Rf bin                                                                
	rm -Rf obj  