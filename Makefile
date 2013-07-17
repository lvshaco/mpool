.PHONY: test clean

test: test.c mpool.c mpool.h
	gcc -g -Wall -o $@ $^

clean:
	rm -f test *.o
