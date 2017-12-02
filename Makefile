CXX = g++
CXXFLAGS = -std=c++14 -Wall -MMD -g
BUILDDIR = build
SRCDIR = src
EXEC = bin/vm.out
OBJECTS = ${addprefix ${BUILDDIR}/, Editor.o action/Action.o action/CopyAction.o action/DeleteAction.o action/DirectionalMovementAction.o action/MovementModifiableAction.o controller/CursesController.o controller/KeyInput.o curses/CursesInstance.o curses/CursesWindow.o main.o state/File.o state/LineIterator.o state/State.o state/mode/CommandMode.o state/mode/CommandModeInputParser.o state/mode/InsertMode.o state/mode/Mode.o state/mode/TerminalMode.o util/FileReader.o util/FileWriter.o view/CursesView.o} 
DEPENDS = ${OBJECTS:.o=.d}

${EXEC}: ${OBJECTS}
	${CXX} ${OBJECTS} -lncurses -o ${EXEC}

${BUILDDIR}/%.o: ${SRCDIR}/%.cc
	${CXX} ${CXXFLAGS} -Isrc -I/usr/local/opt/ncurses/include -c -o $@ $<

-include ${DEPENDS}

.PHONY: clean

clean:
	rm ${OBJECTS} ${DEPENDS} ${EXEC}
