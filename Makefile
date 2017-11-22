# make  - to compile normal run
# make test - to compile for unit testing 

#use this if googletest locally installed
#ifdef LOCAL
GTEST_DIR=~/embedded_dev/gtest/googletest/googletest
GTEST_INCLUDE=-I $(GTEST_DIR)/include
GTEST_LIB=libgtest.a
#else
#GTEST_DIR=
#GTEST_INCLUDE=
#GTEST_LIB=-lgtest
#endif


COPTS=-Wall -Wshadow -fpermissive
COPTS_COV=$(COPTS) -fprofile-arcs -ftest-coverage
LDFLAGS=-fprofile-arcs -ftest-coverage
COV_OUTPUT=./cov_output

PROJ=linkedlist

######### Main targets ##########
main: main.o $(PROJ).o
	gcc main.o $(PROJ).o -o main $(LDFLAGS)

test: Gtest_main.o test_case.o $(PROJ)_test.o  $(GTEST_LIB) libgtest.a
	g++  $(LDFLAGS) -pthread $(PROJ)_test.o test_case.o Gtest_main.o $(GTEST_LIB) -o test


########## Normal ###########

$(PROJ).o: $(PROJ).c
	gcc  -c $(COPTS_COV) $(PROJ).c

main.o: main.c
	gcc -c $(COPTS) main.c

########## Unit test ########

Gtest_main.o: 
	g++ -c Gtest_main.c $(GTEST_INCLUDE)

$(PROJ)_test.o: $(PROJ).c
	g++  -c $(PROJ).c -o $(PROJ)_test.o

test_case.o: test_case.c
	g++ -c $(COPTS) test_case.c $(GTEST_INCLUDE)

########## Google Test framework ############
libgtest.a:
	g++ -isystem $(GTEST_DIR)/include -I $(GTEST_DIR) -pthread -c $(GTEST_DIR)/src/gtest-all.cc
	ar -rv libgtest.a gtest-all.o
	
env:gtest-all.o
	ar -rv libgtest.a gtest-all.o
gtest-all.o:
	$(CC) $(CFLAGS) $(DIR)/include -I${DIR} -pthread -c $(DIR)/src/gtest-all.cc

########### Coverage analysis ############

report:

	lcov -rc lcov_branch_coverage=1 -c -i -d . -o .coverage.base
	lcov -rc lcov_branch_coverage=1 -c -d . -o .coverage.run
	lcov -rc lcov_branch_coverage=1 -d . -a .coverage.base -a .coverage.run -o .coverage.total
	genhtml --branch-coverage -o $(COV_OUTPUT) .coverage.total
	rm -f .coverage.base .coverage.run .coverage.total

clean:
	rm -f *.o test $(GTEST_LIB)
