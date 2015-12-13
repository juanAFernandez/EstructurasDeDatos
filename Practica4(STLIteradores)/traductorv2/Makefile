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

$(BIN)/programaTraductor : $(OBJ)/programaTraductor.o $(LIB)/libtraductor.a
	$(CXX) -o $(BIN)/programaTraductor $(OBJ)/programaTraductor.o -I$(INCLUDE) -L$(LIB) -ltraductor

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

$(OBJ)/programaTraductor.o : $(SRC)/programatraductor.cpp
	$(CXX) $(CPPFLAGS)  -o $(OBJ)/programaTraductor.o $(SRC)/programatraductor.cpp -I$(INCLUDE)


# ************ Generación de documentación ******************
documentacion:
	doxygen doc/doxys/Doxyfile


# ************ Limpieza ************
clean :
	-rm $(OBJ)/* $(SRC)/*~ $(INC)/*~ ./*~

mrproper : clean
	-rm $(BIN)/* doc/html/*

# ************ Hace correr el programa ********** #
runUsoPalabra:
	$(CXX) $(CPPFLAGS)  -o $(OBJ)/usoPalabra.o $(SRC)/usoPalabra.cpp -I$(INCLUDE)
	$(CXX) -o $(BIN)/usoPalabra $(OBJ)/usoPalabra.o -I$(INCLUDE) -L$(LIB) -ltraductor
	$(BIN)/usoPalabra
runUsoTraductor:
	$(CXX) $(CPPFLAGS)  -o $(OBJ)/usoTraductor.o $(SRC)/usoTraductor.cpp -I$(INCLUDE)
	$(CXX) -o $(BIN)/usoTraductor $(OBJ)/usoTraductor.o -I$(INCLUDE) -L$(LIB) -ltraductor
	$(BIN)/usoTraductor
runTraductor:
	$(BIN)/programaTraductor datos/spanish_english
runPruebasContenedores:
	$(CXX) -o $(BIN)/pruebaNuevosContenedores $(SRC)/pruebaNuevosContenedores.cpp
	$(BIN)/pruebaNuevosContenedores
runTraductorInverso:
	$(CXX) $(CPPFLAGS)  -o $(OBJ)/traductor_inverso.o $(SRC)/traductor_inverso.cpp -I$(INCLUDE)
	$(CXX) -o $(BIN)/traductor_inverso $(OBJ)/traductor_inverso.o -I$(INCLUDE) -L$(LIB) -ltraductor
	$(BIN)/traductor_inverso datos/spanish_english
runConcatenar:
	$(CXX) $(CPPFLAGS)  -o $(OBJ)/concatenar.o $(SRC)/concatenar.cpp -I$(INCLUDE)
	$(CXX) -o $(BIN)/concatenar $(OBJ)/concatenar.o -I$(INCLUDE) -L$(LIB) -ltraductor
	$(BIN)/concatenar datos/spanish_english datos/english_french datos/spanish_french
runInterseccion:
	$(CXX) $(CPPFLAGS)  -o $(OBJ)/interseccion.o $(SRC)/interseccion.cpp -I$(INCLUDE)
	$(CXX) -g -o $(BIN)/interseccion $(OBJ)/interseccion.o -I$(INCLUDE) -L$(LIB) -ltraductor
	$(BIN)/interseccion datos/spanish_english datos/french_english datos/inter_spanishfrench_english
