SRC = src
INC = include
OBJ = obj
BIN = bin
CXX = g++
CPPFLAGS = -Wall -g  -I$(INC) -c


all: $(BIN)/pruebatraductor
$(BIN)/usoRacional : $(OBJ)/usoRacional.o $(LIB)/libracional.a
	$(CXX) -o $(BIN)/usoRacional $(OBJ)/usoRacional.o -I$(INCLUDE) -L$(LIB) -lracional

$(LIB)/libracional.a : $(OBJ)/Racional.o
	ar rvs $(LIB)/libracional.a $(OBJ)/Racional.o

#Construcción del fichero objeto palabra.
$(OBJ)/palabra.o : $(SRC)/palabra.cpp
	$(CXX) $(CPPFLAGS)  -o $(OBJ)/palabra.o $(SRC)/palabra.cpp -I$(INCLUDE)

#Construcción del fichero objeto traductor.
$(OBJ)/traductor.o : $(SRC)/traductor.h
	$(CXX) $(CPPFLAGS)  -o $(OBJ)/palabra.o $(SRC)/palabra.cpp -I$(INCLUDE)

$(OBJ)/usoRacional.o : $(SRC)/usoRacional.cpp
	$(CXX) $(CPPFLAGS)  -o $(OBJ)/usoRacional.o $(SRC)/usoRacional.cpp -I$(INCLUDE)


# ************ Generación de documentación ******************
#documentacion:
#	doxygen doc/doxys/Doxyfile

	
# ************ Compilación de módulos ************
$(BIN)/pruebatraductor:


# ************ Limpieza ************
clean :
	-rm $(OBJ)/* $(SRC)/*~ $(INC)/*~ ./*~

mrproper : clean
	-rm $(BIN)/* doc/html/*
