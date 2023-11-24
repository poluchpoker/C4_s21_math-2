CFLAGS = -Wall -Wextra -Werror -g -std=c11
GCOV = -fprofile-arcs -ftest-coverage -fPIC
FILES = s21*.c
OS = $(shell uname)

ifeq (${OS}, Linux)
	TEST_FLAGS = -lcheck -lcheck_pic -pthread -lrt -lm -lsubunit -L.
else
	TEST_FLAGS = -lcheck
endif

all: gcov_report clean

gcov_report: test 
	@lcov -t test -o rep.info -c -d .
	@genhtml -o report rep.info
	@open ./report/index.html
	# gcovr
	# gcovr --html-details


ifeq (${OS}, Linux)
	cd report && firefox index.html
else
	cd report && open index.html
endif

test: clean s21_math.a
	gcc ./tests/test_math.c -c
	gcc ${CFLAGS} ${GCOV} ${FILES} test_math.o -o test ${TEST_FLAGS}
	./test

s21_math.a : s21_math.o
	ar rc libs21_math.a *.o
	ranlib libs21_math.a
	cp libs21_math.a s21_math.a

s21_math.o: ${FILES}
	gcc ${CFLAGS} -c ${FILES}

style:
	cp ./../materials/linters/.clang-format ./
	clang-format -i *.c *.h tests/*.c tests/*.h
	rm .clang-format

clean:
	rm -rf *.o *.out *.gch *.dSYM *.gcov *.gcda *.gcno *.a test_math *.css *.html vgcore* report *.info *.gz *.log test

rebuild: clean s21_math.a

mini_verter:
	cd ../materials/build && sh run.sh

