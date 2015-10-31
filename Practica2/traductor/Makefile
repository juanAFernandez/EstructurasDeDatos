INCLUDE = include
LIB     = lib
OBJ     = obj
SRC = src
BIN = bin
CXX = g++
CPPFLAGS = -Wall -g -c


# ************ Compilación de módulos ************

#compilamos el binario usando la librería traductor que incluye Palabra y Traductor
#$(BIN)/usoPalabra : $(OBJ)/usoPalabra.o $(LIB)/libtraductor.a
#	$(CXX) -o $(BIN)/usoPalabra $(OBJ)/usoPalabra.o -I$(INCLUDE) -L$(LIB) -ltraductor

$(BIN)/pruebaTraductor : $(OBJ)/pruebaTraductor.o $(LIB)/libtraductor.a
	$(CXX) -o $(BIN)/pruebaTraductor $(OBJ)/pruebaTraductor.o -I$(INCLUDE) -L$(LIB) -ltraductor


#Creación de una librería, que contendrá los objetos palabra y traductor.
$(LIB)/libtraductor.a : $(OBJ)/Palabra.o $(OBJ)/Traductor.o
	ar rvs $(LIB)/libtraductor.a $(OBJ)/Palabra.o $(OBJ)/Traductor.o

#Compilando el fichero objeto para el objeto de tipo Palabra
$(OBJ)/Palabra.o : $(SRC)/Palabra.cpp
	$(CXX) $(CPPFLAGS)  -o $(OBJ)/Palabra.o $(SRC)/Palabra.cpp -I$(INCLUDE)

#Compilando el fichero objeto para el objeto de tipo Palabra
$(OBJ)/Traductor.o : $(SRC)/Traductor.cpp
	$(CXX) $(CPPFLAGS)  -o $(OBJ)/Traductor.o $(SRC)/Traductor.cpp -I$(INCLUDE)


#Compilando a fichero objeto el ejemplo de uso de la clase Palabra
$(OBJ)/usoPalabra.o : $(SRC)/usoPalabra.cpp
	$(CXX) $(CPPFLAGS)  -o $(OBJ)/usoPalabra.o $(SRC)/usoPalabra.cpp -I$(INCLUDE)

$(OBJ)/pruebaTraductor.o : $(SRC)/pruebatraductor.cpp
	$(CXX) $(CPPFLAGS)  -o $(OBJ)/pruebaTraductor.o $(SRC)/pruebatraductor.cpp -I$(INCLUDE)


# ************ Generación de documentación ******************
documentacion:
	doxygen doc/doxys/Doxyfile


# ************ Limpieza ************
clean :
	-rm $(OBJ)/* $(SRC)/*~ $(INC)/*~ ./*~

mrproper : clean
	-rm $(BIN)/* doc/html/*

# ************ Hace correr el programa ********** #
runPalabra:
	$(BIN)/usoPalabra
runTraductor:
	$(BIN)/pruebaTraductor datos/spanish_english
