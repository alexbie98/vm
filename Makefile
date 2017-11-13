CXX = g++
CXXFLAGS = -std=c++14 -Wall -MMD -g
BUILDDIR = build
SRCDIR = src
EXEC = bin/vm.out
OBJECTS = ${addprefix ${BUILDDIR}/, main.o}
DEPENDS = ${OBJECTS:.o=.d}

${EXEC}: ${OBJECTS}
	${CXX} ${OBJECTS} -o ${EXEC}

${BUILDDIR}/%.o: ${SRCDIR}/%.cc
	${CXX} ${CXXFLAGS} -c -o $@ $<

-include ${DEPENDS}

.PHONY: clean

clean:
	rm ${OBJECTS} ${DEPENDS} ${EXEC}
