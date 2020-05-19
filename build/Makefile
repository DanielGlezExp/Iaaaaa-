CC=g++
SRC=../src/

OBJS = ../src/main.o $(SRC)DataBase/DataBase.o $(SRC)Registro/Registro.o $(SRC)Titulo/Titulo.o $(SRC)Token/Token.o $(SRC)Tokenizer/Tokenizer.o $(SRC)Vocabulario/Vocabulario.o

all: ${OBJS}
	$(CC) -o cebo_ejecutable ${OBJS}

clean:
	rm -rf ${OBJS} cebo_ejecutable
