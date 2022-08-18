# homework 4: graph, queues,stacks and search
## Purpose
The purpose of "graph, queues,stacks and search" in order to search graphs and determine a path using depth first search and depth first search.

## Layout/Structure

### LLPath eneuquepath

adds path to queue

### LLPath dequepath

removes path from queue

### LLPath push

adds path to pop

### LLPath pop

removes path from queue

### graph_find_path_bfs

gets nearest vertice, checks if its on the way to the target, and keeps track of path

### graph_find_path_dfs

gets nearest vertice, checks if target is on the line, and keeps track of path

## Pseudocode(graphsearch.c) 
```
LLPath *enqueue_path(LLPath *q, Path path) {
create newnode = calloc(nodesize)
newnode->val = path;
if q is empty
	return newdode
current node = q
while next node is not null
	set cur to next
set cur-> next to newnode
return q
}
bool dequeue_path(LLPath **q, Path *ret) {
if q is empty
	return false
set ret to q->val
temp = q
q = q->next
free(temp)
 return true;
}
LLPath *push(LLPath *q, Path path) {
create newnode = calloc(nodesize)
newnode->val = path;
if q is empty
	return newdode
newnode->next = q
return newnode
}
bool pop(LLPath **q, Path *ret) {
if q is empty
	return false
else{
	*ret = (q->val);
	LLPath d = q
	q= next q
	free(d)
	return true
}
}
Path graph_find_path_bfs(Graph *g, int i, int j) {
.visted = null
tovisit=null
tovisit = enque(to_visit,i)
Path p = path extend(p,i)
if (i==j){
	return path with I in visited
}
while(tovisit isnt null)
	deque(visit and current)
	if current = j
		return true
	 add to visited(visited and current)
	 for (n<vertices)
		 if (graphedge(g current height)and set doesnt have visited and neighbor)
			 tovisit = eneuqe(tovisit and neighbor)
			 Path n1 = path_extend(current,neighbor);
			 tovisit = enque(tovisit and n1);
 return empty path;
}
// Depth-first search!
Path graph_find_path_dfs(Graph *g, int i, int j) {
.visted = null
tovisit=null
tovisit = push(to_visit,i)
while(tovisit isnt null)
	pop(visit and current)
	if current = j
		return true
	 add to visited(visited and current)
	 for (n<vertices)
		 if (graphedge(g current height)and set doesnt have visited and neighbor)
			 tovisit = eneuqe(tovisit and neighbor)
			 Path n1 = path_extend(current,neighbor);
			 tovisit = push(tovisit and n1);
 return empty path;
}
```

