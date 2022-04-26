all:
	mkdir -p bin
	g++ -g -c --std=c++17 src/envio.cpp -o bin/envio.o
	g++ -g -c --std=c++17 src/main.cpp -o bin/main.o
	g++ -g -o bin/tarea1 bin/envio.o bin/main.o


version_release:
	mkdir -p bin
	g++ -c --std=c++17 src/envio.cpp -o bin/envio.o
	g++ -c --std=c++17 src/main.cpp -o bin/main.o
	g++ -o bin/tarea1 bin/envio.o bin/main.o 

clean:
	rm -Rf bin