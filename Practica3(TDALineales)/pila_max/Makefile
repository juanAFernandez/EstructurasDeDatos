SRC = src
INC = include
LIB = lib
OBJ = obj
BIN = bin
CXX = g++
CPPFLAGS = -Wall -g  -I$(INC) -c

#all: $(BIN)/usocolas

#$(BIN)/usocolas: $(OBJ)/usocolas.o
#	$(CXX) -o $(BIN)/usocolas $(OBJ)/usocolas.o
#$(OBJ)/usocolas.o: $(INC)/cola.h $(SRC)/usocolas.cpp
#	$(CXX) $(CPPFLAGS)  $(SRC)/usocolas.cpp  -o $(OBJ)/usocolas.o -I$(INC)

all: $(BIN)/pruebaLista $(BIN)/pruebaVector $(BIN)/usopilas_max $(BIN)/usopila $(BIN)/usoColaMax

$(BIN)/pruebaLista : $(OBJ)/pruebaLista.o $(LIB)/libpractica3.a
	$(CXX) -o $(BIN)/pruebaLista $(OBJ)/pruebaLista.o -I$(INC) -L$(LIB) -lpractica3

$(BIN)/pruebaVector : $(OBJ)/pruebaVector.o $(LIB)/libpractica3.a
	$(CXX) -o $(BIN)/pruebaVector $(OBJ)/pruebaVector.o -I$(INC) -L$(LIB) -lpractica3

$(BIN)/usopilas_max : $(OBJ)/usopilas_max.o $(LIB)/libpractica3.a
	$(CXX) -o $(BIN)/usopilas_max $(OBJ)/usopilas_max.o -I$(INC) -L$(LIB) -lpractica3

$(BIN)/usopila : $(OBJ)/usopila.o $(LIB)/libpractica3.a
	$(CXX) -o $(BIN)/usopila $(OBJ)/usopila.o -I$(INC) -L$(LIB) -lpractica3

$(BIN)/usoColaMax : $(OBJ)/usoColaMax.o $(LIB)/libpractica3.a
	$(CXX) -o $(BIN)/usoColaMax $(OBJ)/usoColaMax.o -I$(INC) -L$(LIB) -lpractica3

#Creación de una librería, que contendrá los objetos de todos los tipos de datos que usemos.
#ar es un empaquetador al estilo de tar o zip, sólo se juntan ficheros no se compila nada
$(LIB)/libpractica3.a : $(OBJ)/Lista.o $(OBJ)/Vector.o $(OBJ)/pila_max_lista.o $(OBJ)/pila_max_vd.o $(OBJ)/pila_max_cola.o $(OBJ)/cola_max.o
	ar rvs $(LIB)/libpractica3.a $(OBJ)/Lista.o $(OBJ)/Vector.o $(OBJ)/pila_max_lista.o $(OBJ)/pila_max_vd.o $(OBJ)/pila_max_cola.o $(OBJ)/cola_max.o

#Compilando el fichero objeto para el objeto de tipo Lista
$(OBJ)/Lista.o : $(SRC)/Lista.cpp
	$(CXX) $(CPPFLAGS)  -o $(OBJ)/Lista.o $(SRC)/Lista.cpp -I$(INC)

#Compilando el fichero objeto para el objeto de tipo Vector
$(OBJ)/Vector.o : $(SRC)/Vector.cpp
	$(CXX) $(CPPFLAGS)  -o $(OBJ)/Vector.o $(SRC)/Vector.cpp -I$(INC)

#Compilando el fichero objeto para el objeto de tipo pila_max_lista
$(OBJ)/pila_max_lista.o : $(SRC)/pila_max_lista.cpp
	$(CXX) $(CPPFLAGS)  -o $(OBJ)/pila_max_lista.o $(SRC)/pila_max_lista.cpp -I$(INC)

#Compilando el fichero objeto para el objeto de tipo pila_max_vd
$(OBJ)/pila_max_vd.o : $(SRC)/pila_max_vd.cpp
	$(CXX) $(CPPFLAGS)  -o $(OBJ)/pila_max_vd.o $(SRC)/pila_max_vd.cpp -I$(INC)

#Compilando el fichero objeto para el objeto de tipo pila_max_cola
$(OBJ)/pila_max_cola.o : $(SRC)/pila_max_cola.cpp
	$(CXX) $(CPPFLAGS)  -o $(OBJ)/pila_max_cola.o $(SRC)/pila_max_cola.cpp -I$(INC)

#Compilando el fichero objeto para el objeto de tipo cola_max
$(OBJ)/cola_max.o : $(SRC)/cola_max.cpp
	$(CXX) $(CPPFLAGS)  -o $(OBJ)/cola_max.o $(SRC)/cola_max.cpp -I$(INC)

#Compilando el fichero objeto del programa de prueba de Lista
$(OBJ)/pruebaLista.o : $(SRC)/pruebaLista.cpp
	$(CXX) $(CPPFLAGS)  -o $(OBJ)/pruebaLista.o $(SRC)/pruebaLista.cpp -I$(INC)

#Compilando el fichero objeto del programa de prueba de Lista
$(OBJ)/pruebaVector.o : $(SRC)/pruebaVector.cpp
	$(CXX) $(CPPFLAGS)  -o $(OBJ)/pruebaVector.o $(SRC)/pruebaVector.cpp -I$(INC)

#Compilando el fichero objeto del programa de prueba de la pila con máximo
$(OBJ)/usopilas_max.o : $(SRC)/usopilas_max.cpp
	$(CXX) $(CPPFLAGS)  -o $(OBJ)/usopilas_max.o $(SRC)/usopilas_max.cpp -I$(INC)

#Compilando el fichero objeto del programa de prueba deL TDA PIla
$(OBJ)/usopila.o : $(SRC)/usopila.cpp
	$(CXX) $(CPPFLAGS)  -o $(OBJ)/usopila.o $(SRC)/usopila.cpp -I$(INC)

#Compilando el fichero objeto del programa de prueba del TDA Cola con Máximo
$(OBJ)/usoColaMax.o : $(SRC)/usoColaMax.cpp
	$(CXX) $(CPPFLAGS)  -o $(OBJ)/usoColaMax.o $(SRC)/usoColaMax.cpp -I$(INC)


# ************ Generación de documentación ******************
documentacion:
	doxygen doc/doxys/Doxyfile

# ************ Ejecución ***********

#Programa con el que probar el TDA Lista usando templates.
runPruebaLista:
	$(BIN)/pruebaLista

#Programa con el que probar el TDA Vector usando templates.
runPruebaVector:
	$(BIN)/pruebaVector

#Programa con el que probar los TDAs PilaMaxCola, PilaMaxLista y PilaMaxVector
runUsoPilaMaximo:
	$(BIN)/usopilas_max

#Programa con el que probar el TDA Pila
runUsoPila:
	$(BIN)/usopila

#Programa con el que probar el TDA cola_max
runUsoColaMax:
	$(BIN)/usoColaMax

# ************ Limpieza ************
clean :
	-rm $(OBJ)/* $(SRC)/*~ $(INC)/*~ ./*~

mrproper : clean
	-rm $(BIN)/* doc/html/*
