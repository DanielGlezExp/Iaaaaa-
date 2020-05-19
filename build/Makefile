CC=g++
SRC=../src/

OBJS = ../src/main.o $(SRC)DataBase/DataBase.o $(SRC)Registro/Registro.o $(SRC)Titulo/Titulo.o $(SRC)Token/Token.o $(SRC)Tokenizer/Tokenizer.o $(SRC)Vocabulario/Vocabulario.o
OBJCLAS = ../src/main_clasificacion.o $(SRC)Registro/Registro.o $(SRC)Titulo/Titulo.o $(SRC)Token/Token.o $(SRC)Tokenizer/Tokenizer.o

all: ${OBJS}
	$(CC) -o aprendizaje_ejecutable ${OBJS}

all: ${OBJCLAS}
	$(CC) -o clasificador ${OBJCLAS}


clean:
	rm -rf ${OBJS} cebo_ejecutable
