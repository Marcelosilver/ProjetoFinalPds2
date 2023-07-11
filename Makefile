CC:=g++
CFLAGS:=-std:=c++17 -Wall
TARGET:=vpl_execution

BUILD_DIR    := ./build
SRC_DIR    := ./src
INCLUDE_DIR  := ./include

./${TARGET}: ${BUILD_DIR}/deck.o ${BUILD_DIR}/jogador.o ${BUILD_DIR}/dealer.o ${BUILD_DIR}/main.o
	${CC} ${CFLAGS} -o ${TARGET} ${BUILD_DIR}/*.o

${BUILD_DIR}/deck.o: ${INCLUDE_DIR}/carta.hpp 

${BUILD_DIR}/deck.o: ${INCLUDE_DIR}/deck.hpp ${SRC_DIR}/entidades/deck.cpp
    ${CC} ${CFLAGS} -I ${INCLUDE_DIR}/ -c ${SRC_DIR}/entidades/deck.cpp -o ${BUILD_DIR}/deck.o

${BUILD_DIR}/jogador.o: ${INCLUDE_DIR}/jogador.hpp ${SRC_DIR}/entidades/jogador.cpp
	${CC} ${CFLAGS} -I ${INCLUDE_DIR}/ -c ${SRC_DIR}/entidades/jogador.cpp -o ${BUILD_DIR}/jogador.o

${BUILD_DIR}/dealer.o: ${INCLUDE_DIR}/dealer.hpp ${SRC_DIR}/entidades/dealer.cpp
	${CC} ${CFLAGS} -I ${INCLUDE_DIR}/ -c ${SRC_DIR}/entidades/dealer.cpp -o ${BUILD_DIR}/dealer.o

${BUILD_DIR}/main.o: ${INCLUDE_DIR}/carta.hpp ${INCLUDE_DIR}/deck.hpp ${INCLUDE_DIR}/jogador.hpp ${SRC_DIR}/entidades/dealer.cpp ${SRC_DIR}/main.cpp
	${CC} ${CFLAGS} -I ${INCLUDE_DIR}/ -c ${SRC_DIR}/main.cpp -o ${BUILD_DIR}/main.o

# Limpeza de arquivos build
clean:
	rm -f ${BUILD_DIR}/*
