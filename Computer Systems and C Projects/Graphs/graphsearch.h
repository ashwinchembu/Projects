#pragma once

// maximum number of vertices we're willing to have in a graph, for simplicity.
#define MAX_GRAPH_SIZE 128

typedef struct {
  int vertices;  // the set V
  int **matrix;  // the set E
} Graph;

typedef struct LLint {
  int val;
  struct LLint *next;
} LLint;

typedef struct {
  int steps;
  int vertices_visited[MAX_GRAPH_SIZE];
} Path;

typedef struct LLPath {
  Path val;
  struct LLPath *next;
} LLPath;

typedef struct {
  LLPath *top;
} Stack;


LLint *add_to_set(LLint *set, int val);
bool set_contains(LLint *set, int val);

LLPath *enqueue_path(LLPath *q, Path path); 
bool dequeue_path(LLPath **q, Path *ret);

Graph *graph_create(int vertices);
void graph_add_edge(Graph *g, int i, int j) ;
bool graph_has_edge(Graph *g, int i, int j);

Path graph_find_path_bfs(Graph *g, int i, int j);
Path graph_find_path_dfs(Graph *g, int i, int j);

void print_path(Path path);
void graph_destroy(Graph **g);
