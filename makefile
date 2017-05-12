TESTS=test/test_vector.cpp test/test_matrix.cpp

.PHONY: test
test:
	g++ ${TESTS} -lgtest -lgtest_main -lpthread -I./ -std=c++14;
	./a.out;
	rm ./a.out
