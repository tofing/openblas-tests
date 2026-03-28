CC = gcc
CFLAGS = -Wall -O2 -I/usr/local/openblas/include
LDFLAGS = -L/usr/local/openblas/lib -lopenblas -lpthread -lm

TESTS = tests/test_cblas_level1

all: $(TESTS)

tests/test_cblas_level1: tests/test_cblas_level1.c
$(CC) $(CFLAGS) -o $@ $< $(LDFLAGS)

clean:
rm -f $(TESTS)

run: all
@echo ""
./tests/test_cblas_level1

.PHONY: all clean run
