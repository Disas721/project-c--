CC=g++
CFLAGS= -Wall -g -fprofile-arcs -ftest-coverage

all: tests
tests.o: tests.cpp
	${CC} -c tests.cpp -o tests.o ${CFLAGS}
queue.o: queue.cpp
	${CC} -c queue.cpp -o queue.o ${CFLAGS}
tests: tests.o queue.o
	${CC} queue.o tests.o -o tests ${CFLAGS}
clean:
	@rm -rf *.o *.gcno *.gcda *.gcov tests 2&>/dev/null
tar:
	tar czvf ../queue_cpp.tgz ../queue_cpp