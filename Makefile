CXX = g++
CXXFLAGS = -g -std=c++14 -Wall -MMD -Werror=vla
EXEC = sudoku
SRC = .
SOURCES = $(wildcard *.cc)
OBJECTS = ${SOURCES:.cc=.o}
DEPENDS = ${OBJECTS:.o=.d}

${EXEC}: ${OBJECTS}
	${CXX} ${CXXFLAGS} ${OBJECTS} -o ${EXEC}

-include ${DEPENDS}

.PHONY: clean

clean:
	del ${OBJECTS} ${DEPENDS} ${EXEC} 2>NUL
	rm -f ${OBJECTS} ${DEPENDS} ${EXEC}