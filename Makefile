#Niculici Mihai-Daniel 315 CA
# compiler setup
CC = gcc
CFLAGS = -Wall -Wextra -std=c99

# define targets
TARGETS = infinite_product

build: $(TARGETS)

infinite_product: infinite_product.c
	$(CC) $(CFLAGS) infinite_product.c -lm -o infinite_product

pack:
	zip -FSr 315CA_NiculiciMihai-Daniel_Tema1.zip README Makefile *.c *.h

clean:
	rm -f $(TARGETS)

.PHONY: pack clean