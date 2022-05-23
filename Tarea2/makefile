FLAGS = -g -c --std=c++17

all:
	mkdir -p bin
	g++ $(FLAGS) src/empleado.cpp -o bin/empleado.o
	g++ $(FLAGS) src/organizacion.cpp -o bin/organizacion.o
	g++ $(FLAGS) src/main.cpp -o bin/main.o
	g++ -g -o bin/tarea2 bin/empleado.o bin/organizacion.o bin/main.o

test:
	mkdir -p bin
	g++ $(FLAGS) src/empleado.cpp -o bin/empleado.o
	g++ $(FLAGS) src/organizacion.cpp -o bin/organizacion.o
	g++ -g -o bin/tarea2_tests bin/empleado.o -lgtest -lgtest_main -lpthread

clean:
	rm -Rf bin