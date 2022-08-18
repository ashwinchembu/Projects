#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#include "graphsearch.h"

// dealing with sets of integers. We wrote these in class.
LLint *add_to_set(LLint *set, int val) {
  LLint *newfront = calloc(1, sizeof(LLint));
  newfront->val = val;
  newfront->next = set;

  return newfront;
}

bool set_contains(LLint *set, int val) {
  if (set == NULL) {
    return false;
  } else if (set->val == val) {
    return true;
  } else {
    return set_contains(set->next, val);
  }
}

// Linked lists of paths. You'll need to implement these.

// Returns the new front of the queue, for a queue of Path structs.
// Usually this will be the old front of the queue, but if q is NULL, then it
// will allocate a new linked list node and return that.
//code adapted for enqueue_path from Prof. Rudnick's resources
LLPath *enqueue_path(LLPath *q, Path path) {
  LLPath *newnode = calloc(1,sizeof(LLPath));
  newnode ->val = path;
  if (q==NULL){
      return newnode;
  }
  LLPath *cur = q;
  while(cur->next){
      cur = cur -> next;
  }
  cur->next = newnode;
  return q;
}
//code adapted for dequeue_path from Prof. Rudnick's resources
bool dequeue_path(LLPath **q, Path *ret) {
  if (*q == NULL){
      return false;
  }
  *ret = (*q)->val;
  LLPath *free1 = *q;
  *q = ((*q)->next);
  free(free1);
  return true;
}

//push
LLPath *push(LLPath *q, Path path) {
LLPath *newnode = calloc(1,sizeof(LLPath));
  newnode ->val = path;
  if (q==NULL){
      return newnode;
  }
  newnode->next = q;
  return newnode;
}

//pop
bool pop(LLPath **q, Path *ret){
if (q==NULL){
      //printf("no more");
      return false;
  }
  else{
  *ret = (*q)->val;
  LLPath *d = *q;
  *q = (*q)->next;
  free(d);
  return true;
  }

}

// We wrote these in class.
Graph *graph_create(int vertices) {
  Graph *g = (Graph *)malloc(sizeof(Graph));
  g->vertices = vertices;
  g->matrix = (int **)calloc(vertices, sizeof(int*));
  for (int i=0; i < vertices; i++) {
    g->matrix[i] = (int *)calloc(vertices, sizeof(int));
  }
  return g;
}
//graph_delete

void graph_destroy(Graph **g){
		 
    		
    for (int i=0; i < (*g)->vertices; i++) {
	//for (int j=0; j < (*g)->vertices; j++) {
	//if ((*g)->matrix[i] != NULL){
   	free((*g)->matrix[i]);
   	}
   	free((*g)->matrix);
   	free(*g);
   // }
   // }
   // while(q->next){
     // free(q);
  	//}
  

}

void graph_add_edge(Graph *g, int i, int j) {
  g->matrix[i][j] = 1;
}

bool graph_has_edge(Graph *g, int i, int j) {
  return g->matrix[i][j];
}

// Convenience method for you -- returns a new Path where you have added another
// vertex along the path.
Path path_extend(Path path, int new_vertex) {
  Path out;
  out.steps = path.steps;

  for (int i=0; i < path.steps; i++) {
    out.vertices_visited[i] = path.vertices_visited[i];
  }
  out.vertices_visited[path.steps] = new_vertex;
  out.steps += 1;
  return out;
}

// Print out a path nicely for the user.
void print_path(Path path) {
  if (path.steps == 0) {
    puts("(empty path)"); 
  }
  for (int i=0; i < path.steps; i++) {
    printf("%s%d",
        (i == 0) ? "" : " -> ",
        path.vertices_visited[i]);
  }
  puts("");
}

// Breadth-first search!
//adapted from prof. rudicks's lectures
Path graph_find_path_bfs(Graph *g, int i, int j) {
  // YOUR CODE HERE.
  
  LLint *visited = NULL;
  LLPath *to_visit = NULL;
  Path p;
  p.steps = 0;

  p = path_extend(p,i); 
  to_visit = enqueue_path(to_visit,p);
  if(i==j){
  Path one;
  one.steps = 1;
  one.vertices_visited[0] = i;
  return one;
  }
  while(to_visit != NULL){
      Path current;
      dequeue_path(&to_visit, &(current));
      
      if (current.vertices_visited[current.steps-1] == j){
      while (!(visited==NULL)){
  	LLint *d = visited;
  	visited = (visited)->next;
  	free(d);
  }
          return current;
      }
      visited = add_to_set(visited,current.vertices_visited[current.steps-1]);
     
    for(int neighbor = 0; neighbor < g->vertices; neighbor++) {
      if (graph_has_edge(g, current.vertices_visited[current.steps-1], neighbor) &&
          !set_contains(visited, neighbor)) {
          //printf("neighbor: %d\n",neighbor);
          Path n1;
  	n1 = path_extend(current,neighbor); 
        to_visit = enqueue_path(to_visit, n1);
      }
    }


      }
  while (!(visited==NULL)){
  	LLint *d = visited;
  	visited = (visited)->next;
  	free(d);
  }
  Path empty = {0, {0}};
  return empty;
  }
  


// Depth-first search!
Path graph_find_path_dfs(Graph *g, int i, int j) {
  // YOUR CODE HERE.
  LLint *visited = NULL;
  LLPath *to_visit = NULL;
  Path p;
  p.steps = 0;
  p.vertices_visited[0] = i;
  p = path_extend(p,i); 
  if(i==j){
  Path one;
  one.steps = 1;
  one.vertices_visited[0] = i;
  return one;
  }
  to_visit = push(to_visit,p);
  while(to_visit != NULL){
  Path current;
      pop(&to_visit, &(current));
      
      if (current.vertices_visited[current.steps-1] == j){
      while (!(visited==NULL)){
  	LLint *d = visited;
  	visited = (visited)->next;
  	free(d);
  }
  while (!(to_visit==NULL)){
  	LLPath *d = to_visit;
  	to_visit = (to_visit)->next;
  	free(d);
  }
          return current;
      }
      visited = add_to_set(visited,current.vertices_visited[current.steps-1]);
     
    for(int neighbor = 0; neighbor < g->vertices; neighbor++) {
      if (graph_has_edge(g, current.vertices_visited[current.steps-1], neighbor) &&
          !set_contains(visited, neighbor)) {
          Path n1;
  	n1 = path_extend(current,neighbor); 
        to_visit = push(to_visit, n1);
      }
    }

  }
  
  Path empty = {0, {0}};
  return empty;
  
  }

 

