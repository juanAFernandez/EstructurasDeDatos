INCLUDE = include
LIB     = lib
OBJ     = obj
SRC = src
BIN = bin
CXX = g++
CPPFLAGS = -Wall -g -c 

all: $(BIN)/pruebatraductor
$(BIN)/pruebatraductor : $(OBJ)/pruebatraductor.o $(LIB)/libtraductor.a
	$(CXX) -o $(BIN)/pruebatraductor $(OBJ)/pruebatraductor.o -I$(INCLUDE) -L$(LIB) -ltraductor

#Construcción de la librería. Se reunen bajo un mismo nombre los ficheros objetos ya compilados.
$(LIB)/libtraductor.a : $(OBJ)/palabra.o $(OBJ)/traductor.o
	ar rvs $(LIB)/libtraductor.a $(OBJ)/palabra.o $(OBJ)/traductor.o

#Construcción del fichero objeto palabra.
$(OBJ)/palabra.o : $(SRC)/palabra.cpp
	$(CXX) $(CPPFLAGS)  -o $(OBJ)/palabra.o $(SRC)/palabra.cpp -I$(INCLUDE)

#Construcción del objeto traductor
$(OBJ)/traductor.o : $(SRC)/traductor.cpp
	$(CXX) $(CPPFLAGS)  -o $(OBJ)/traductor.o $(SRC)/traductor.cpp -I$(INCLUDE)

#Construcción del objeto pruebatraductor.cpp
$(OBJ)/pruebatraductor.o : $(SRC)/pruebatraductor.cpp
	$(CXX) $(CPPFLAGS)  -o $(OBJ)/pruebatraductor.o $(SRC)/pruebatraductor.cpp -I$(INCLUDE)

#Construcción del objeto usoPalabra.cpp
$(OBJ)/usoPalabra.o : $(SRC)/usoPalabra.cpp
	$(CXX) $(CPPFLAGS)  -o $(OBJ)/usoPalabra.o $(SRC)/usoPalabra.cpp -I$(INCLUDE)


# ************ Generación de documentación ******************
#documentacion:
documentacion : 
	doxygen doc/doxygen/configuracionDoxygen


# ************ Limpieza ************
clean :
	-rm $(OBJ)/* $(SRC)/*~ $(INC)/*~ ./*~

mrproper : clean
	-rm $(BIN)/* doc/html/*
