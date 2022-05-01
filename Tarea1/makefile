FLAGS = -g -c --std=c++17

all:
	mkdir -p bin
	g++ $(FLAGS) src/envio.cpp -o bin/envio.o
	g++ $(FLAGS) src/envioServicioPostal.cpp -o bin/envioServicioPostal.o
	g++ $(FLAGS) src/envioFedEX.cpp -o bin/envioFedEX.o
	g++ $(FLAGS) src/main.cpp -o bin/main.o
	g++ -g -o bin/tarea1 bin/envio.o bin/envioServicioPostal.o bin/envioFedEX.o bin/main.o

test:
	mkdir -p bin
	g++ $(FLAGS) src/envio.cpp -o bin/envio.o
	g++ $(FLAGS) src/envioServicioPostal.cpp -o bin/envioServicioPostal.o
	g++ $(FLAGS) src/envioFedEX.cpp -o bin/envioFedEX.o
	g++ $(FLAGS) tests/envio_tests.cpp -o bin/envio_tests.o
	g++ -g -o bin/tarea1_tests bin/envio_tests.o bin/envio.o bin/envioServicioPostal.o bin/envioFedEX.o -lgtest -lgtest_main -lpthread

clean:
	rm -Rf bin