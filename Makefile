CXX = g++
CXXFLAGS = -std=c++14 -Wall -MMD -g 
BUILDDIR = build
SRCDIR = src
EXEC = bin/vm
OBJECTS = ${addprefix ${BUILDDIR}/, main.o, Editor.o, State.o, StateViewable.o, View.o, CursesView.o, Controller.o, CursesController.o, CursesWindow.o, CursesInstance.o}
DEPENDS = ${OBJECTS:.o=.d}

${EXEC}: ${OBJECTS}
	${CXX} ${OBJECTS} -lncurses -o ${EXEC}

${BUILDDIR}/%.o: ${SRCDIR}/%.cc
	${CXX} ${CXXFLAGS} -I/src -c -o $@ $<

-include ${DEPENDS}

.PHONY: clean

clean:
	rm ${OBJECTS} ${DEPENDS} ${EXEC}
