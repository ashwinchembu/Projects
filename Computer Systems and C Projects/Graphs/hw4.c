#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "graphsearch.h"

#define BUFSIZE 512

void check_vertex(int vertex, int n_vertices) {
    if ((vertex >= n_vertices) || (vertex < 0)) {
      fprintf(stderr, "no such vertex %d\n", vertex);
      exit(1);
    }
}

int main(int argc, char **argv) {
  char buf[BUFSIZE];
  FILE* infile;

  if (argc != 2) {
    fprintf(stderr, "usage: ./hw4 <input_graph.txt>\n");
    exit(1);
  }
  infile=fopen(argv[1], "r");

  Graph *g;
  int start, end;
  int n_vertices;

  int line = 0;
  while((fgets(buf, BUFSIZE, infile) != NULL)) {
    if (line == 0) {
      sscanf(buf, "%d", &n_vertices);
      if (n_vertices > MAX_GRAPH_SIZE) {
        fprintf(stderr, "Can't create graph larger than %d\n", MAX_GRAPH_SIZE);
        exit(1);
      }
      g = graph_create(n_vertices);
    } else if (line == 1) {
      sscanf(buf, "%d %d", &start, &end);
      check_vertex(start, n_vertices);
      check_vertex(end, n_vertices);
    } else  {
      int i, j;
      sscanf(buf, "%d %d", &i, &j);
      check_vertex(i, n_vertices);
      check_vertex(j, n_vertices);
      graph_add_edge(g, i, j);
    }
    line++;
  }

  Path path;
  printf("searching with BFS from %d to %d\n", start, end);
  path = graph_find_path_bfs(g, start, end);
  print_path(path);

  printf("searching with DFS from %d to %d\n", start, end);
  path = graph_find_path_dfs(g, start, end);
  print_path(path);
  graph_destroy(&g);
  fclose(infile);

  return 0;
}
