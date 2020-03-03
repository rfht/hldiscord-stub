LBITS := $(shell getconf LONG_BIT)

UNAME := $(shell uname)

CFLAGS = -Wall -O2 -fPIC -I /usr/local/include

CFLAGS += -std=c++0x

LFLAGS = -lhl -lstdc++ -L /usr/local/lib

all:
	${CC} ${CFLAGS} -c -Wall -fPIC src/hldiscord.cpp
	${CC} ${CFLAGS} -shared -o hldiscord.hdll src/hldiscord.cpp ${LFLAGS}


clean:
	rm -f src/*.o
	rm -f hldiscord.hdll

