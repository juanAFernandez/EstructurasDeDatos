# makefile muy simple
#autor: Juan Antonio

compilar:

	#Compilamos el objeto palabra:
	g++ -c -o obj/palabra.o src/palabra.cpp -I./include

	#Compilamos el objeto pruebaPalabra:
	g++ -c -o obj/pruebaPalabra.o src/pruebaPalabra.cpp -I./include

	#Por último enlazamos:
	g++ -o bin/pruebaPalabra obj/pruebaPalabra.o obj/palabra.o

	#Ejecutamos el programa:
	./bin/pruebaPalabra

ejecutar:

	./bin/pruebaPalabra
