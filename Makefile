CXX = g++
CXXFLAGS = -std=c++14 -Wall -MMD -g
BUILDDIR = build
SRCDIR = src
EXEC = bin/vm.out
OBJECTS = ${addprefix ${BUILDDIR}/, main.o Editor.o curses/CursesWindow.o curses/CursesInstance.o view/CursesView.o controller/CursesController.o controller/CursesInput.o state/State.o action/Action.o}
DEPENDS = ${OBJECTS:.o=.d}

${EXEC}: ${OBJECTS}
	${CXX} ${OBJECTS} -lncurses -o ${EXEC}

${BUILDDIR}/%.o: ${SRCDIR}/%.cc
	${CXX} ${CXXFLAGS} -Isrc -c -o $@ $<

-include ${DEPENDS}

.PHONY: clean

clean:
	rm ${OBJECTS} ${DEPENDS} ${EXEC}
