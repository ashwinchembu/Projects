CC = clang

# Make sure to use the full CFLAGS before turning in. Uncomment this for lax
# checking during development, if you need to.
# CFLAGS =

# You can comment this out and use the above CFLAGS instead if you need to,
# during development.
CFLAGS = -Wall -Wpedantic -Werror -Wextra


all: hw4

hw4: hw4.o graphsearch.o
	$(CC) graphsearch.o hw4.o -o hw4

graphsearch.o: graphsearch.c graphsearch.h
	$(CC) $(CFLAGS) -c graphsearch.c

hw4.o: hw4.c graphsearch.h
	$(CC) $(CFLAGS) -c hw4.c

# use graphviz to generate visualizations of graphs!
# sudo apt install graphviz to make this work
graph1.dot.png: graph1.dot
	dot graph1.dot -O -Tpng

graph2.dot.png: graph2.dot
	dot graph2.dot -O -Tpng

clean:
	rm -f hw4 hw4.o graphsearch.o

format:
	clang-format -i -style=file *.{c,h}
