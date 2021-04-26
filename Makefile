SHELL=cmd.exe

LIB = .\lib
BIN = .\bin
SRC = .\src

EXE = ${BIN}\eyeTrack

LIB_TOBII = ${LIB}\tobii_stream_engine.dll
CONDITION = -lwsock32

SRC_CONNECT = ${SRC}\connect.cpp
SRC_SERVER = ${SRC}\server.cpp
SRC_SAVE_DATA = ${SRC}\save_data.cpp
SRC_GLOBAL = ${SRC}\global.cpp
SRC_MAIN = .\main.cpp

O_CONNECT = ${BIN}\connect.o
O_SERVER = ${BIN}\server.o
O_SAVE_DATA = ${BIN}\save_data.o
O_GLOBAL = ${BIN}\global.o
O_MAIN = ${BIN}\main.o

all: eyeTrack

eyeTrack:
	@echo "============START COMPILE============"
	g++ -c ${SRC_MAIN} -o ${O_MAIN}
	g++ -c ${SRC_GLOBAL} -o ${O_GLOBAL} ${CONDITION}
	g++ -c ${SRC_SERVER} -o ${O_SERVER} ${CONDITION}
	g++ -c ${SRC_CONNECT} -o ${O_CONNECT}
	g++ -c ${SRC_SAVE_DATA} -o ${O_SAVE_DATA}
	@echo "=============END  COMPILE============"

	@echo "=============START LINK=============="
	g++ -o ${EXE} ${LIB_TOBII} ${O_GLOBAL} ${O_CONNECT} ${O_SAVE_DATA} ${O_SERVER} ${O_MAIN} ${CONDITION}
	@echo "==============END  LINK==============="

