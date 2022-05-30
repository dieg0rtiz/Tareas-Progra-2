FLAGS = -g -c --std=c++17

all:
	mkdir -p bin
	g++ $(FLAGS) src/empleado.cpp -o bin/empleado.o
	g++ $(FLAGS) src/empleadoAsalariado.cpp -o bin/empleadoAsalariado.o
	g++ $(FLAGS) src/empleadoPorHoras.cpp -o bin/empleadoPorHoras.o
	g++ $(FLAGS) src/organizacion.cpp -o bin/organizacion.o
	g++ $(FLAGS) src/main.cpp -o bin/main.o
	g++ -g -o bin/tarea2 bin/empleado.o bin/empleadoAsalariado.o bin/empleadoPorHoras.o bin/organizacion.o bin/main.o

test:
	mkdir -p bin
	g++ $(FLAGS) src/empleado.cpp -o bin/empleado.o
	g++ $(FLAGS) src/empleadoAsalariado.cpp -o bin/empleadoAsalariado.o
	g++ $(FLAGS) src/empleadoPorHoras.cpp -o bin/empleadoPorHoras.o
	g++ $(FLAGS) src/organizacion.cpp -o bin/organizacion.o
	g++ $(FLAGS) tests/empleado_tests.cpp -o bin/empleado_tests.o
	g++ $(FLAGS) tests/organizacion_tests.cpp -o bin/organizacion_tests.o
	g++ -g -o bin/tarea2_tests bin/empleado_tests.o bin/organizacion_tests.o bin/empleado.o bin/empleadoAsalariado.o bin/empleadoPorHoras.o bin/organizacion.o -lgtest -lgtest_main -lpthread

clean:
	rm -Rf bin