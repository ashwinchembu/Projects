# homework 4: graphs, queues, stacks and search!

**Due date: Monday, 14 February 2022, 11:59pm**

## introduction
In this homework, we are continuing the work we started in class, representing
directed graphs and doing searches over them, with breadth-first and depth-first
search algorithms.

You may want to review
[the demos we built in class](https://git.ucsc.edu/ajrudnic/cse-13s-demos-winter-2022/-/tree/master/graphs), 
wherein we implemented *checking for the existence* of a path between two nodes
in a graph. Notably, our implementation from class does not actually tell us
what that path is, just that one exists!

So for this homework, we will add some bookkeeping that allows us to find out
not just that a path exists, but show the user what that path is.

## Representing and Searching Graphs

Our program for this homework reads a *graph search problem* from a text file,
where a graph search problem consists of a representation of a directed graph,
and a search that we want to perform.
The first line of the text file contains a number, telling us how many vertices
will be in the graph. The second line tells us the starting vertex and the
ending vertex for our search problem -- the goal of the program is to find a
path through the directed graph from *start* to *end*. Every subsequent line in
the file adds a directed edge in the graph.  See `hw4.c` for how this is
implemented.

Graph 1, stored in `graph1.txt`, looks like this:

![graph 1](graph1.dot.png "graph 1")

This is the same as the example we drew on paper during class. For this search
problem, we are trying to find a path from vertex 0 to vertex 3. Visually, you
can see that this path should be 0->1->7->3, and that is the only available
path, so any working search algorithm should find that same path.

For some contrast, consider the following, Graph 2. Here we want to find a path
from vertex 0 to vertex 5. This problem is stored in `graph2.txt`.

![graph 2](graph2.dot.png "graph 2")

Here you can see that there are many possible paths to get from vertex 0 to
vertex 5. You could travel along 0->3->4->5. You could travel along
0->1->2->3->4->5. Or there are a few more possibilities!

In any case, in code, we are representing directed graphs with the `Graph`
struct, defined in `graphsearch.h`. It is the same as the `Graph` struct that we
developed in class -- it contains dynamically allocated adjacency matrix, where
we put a `1` in cell `matrix[i][j]` when the graph contains edge *(i, j)*.

### Searching with Breadth-First Search

Like we talked about in class, we can build the [breadth-first search
algorithm](https://en.wikipedia.org/wiki/Breadth-first_search)
around the idea of keeping a *queue* of vertices that we would like to explore,
and enqueuing the neighbors of the current vertex. You should draw some pictures
on paper and convince yourself that this behavior will first explore all of the
nodes that can be reached by traversing 1 edge, and then all of the nodes that
can be reached by traversing 2 edges, and so on.

The pseudocode for our breadth-first search approach looks something like:

* keep a set of vertices that we have visited
* keep a queue of vertices that we want to visit
* put the starting vertex into the queue
* while there are more places to visit in the queue:
  * dequeue the next place to visit
  * see if it is our intended destination -- if it is, return success!
  * otherwise, make sure it is in the set of visited nodes
  * enqueue each of its neighbors that have not been visited
* return false if the queue becomes empty (we ran out of options)

This was what we implemented in class. What you need to adapt here, and this may
take some thought, is keeping track of *paths* through the graph, sequences of
visited vertices, rather than just individual vertices. There is a conveniently
included `Path` struct that you can use for this purpose, which will be
discussed shortly.

Your new version of breadth-first search should return a Path showing how to go
from the specified starting node to the specified destination node, if such a
path exists. And it should find a path that takes the minimum number of edges
(preferring to take edges to lower-indexed vertices, in the case of ties).

For example, when searching the Graph 2 problem, your BFS algorithm should find
the path 0->4->5.

### Searching with Depth-First Search

It turns out that we can adapt our algorithm for breadth-first search into
[depth-first search](https://en.wikipedia.org/wiki/Depth-first_search), simply
by replacing the queue in the previous algorithm with a stack. This will have
the behavior that, rather than gradually radiating outward from our starting
point, the search will *plumb the depths* of all of the paths reachable for the
*first child* of the current vertex, before backing up to consider all of the
paths reachable from the current vertex's *second child*, and so on.

Why would you want such behavior? For large graphs with a high branching factor,
this can often use less memory and execute faster, at the cost of possibly
finding a longer path.

Note that to make this work, you are going to have to design and implement stack
behavior for Paths. Make sure to write about it in your design doc!

In any case, your implementation of Depth-First Search should return the
(longer) path 0->1->2->3->4->5, on the Graph 2 problem.

## Representing Paths
In `graphsearch.h`, we see the `Path` struct, which contains an int `steps`, the
number of vertices along the path, and an array `vertices_visited`, in which we
will record each of the vertices along the path.

For each of the elements of a path from 0 up to the `steps` field,
`vertices_visited[i]` represents the *i*th vertex visited along a path.  You can
look at the code for `path_extend` for an example of how to work with these
structs.

## Cleaning up our messes

For this homework, we are allocating a lot of dynamic data structures, with
`malloc` or `calloc`.

**As part of your design**, you need to think about the dynamic data structures
that we are allocating, and come up with a plan for `free`-ing them. Which parts
of the code will allocate? How can you make sure every allocated pointer gets
`free`d?

In order to find out whether your code is cleaning up its messes, you should use
a tool called Valgrind.

If you have not yet installed Valgrind on your Linux system, you can install it
like so:
```
sudo apt install valgrind
```

You can run Valgrind to find out whether your program is leaking memory with the
following command:

```
valgrind --leak-check=full  ./hw4 graph1.txt
```

(or, clearly, you could run on some graph other than `graph1.txt`)

Valgrind will then tell you whether you are successfully cleaning up all of the
allocated memory, or whether your program has leaks.

## Pieces to implement

Most of the shell of this program has already been created for you, but there
are a number of functions that are commented with "YOUR CODE HERE", which you
will need to fill out in order to get a working implementation.

Additionally, you will likely want to add more functions, for cleaning up your
memory allocations. How can you free a linked list? How can you free a set? What
else will you need to free?

## HARD MODE: a more elegant `Path`
This part is completely optional. We will be impressed if you do it, but you do
not have to do it unless you feel like it.

You might notice that our `Path` struct has a fixed-size array as one of its
elements. This is both wasteful and limiting! It is wasteful, in that we will
often allocate an array that is bigger than necessary, if the graph is smaller
than `MAX_GRAPH_SIZE`.

But more interestingly, it is *limiting*. What if we want to search on large
graphs?

How could you make a dynamically-sized Path struct, that would allow us to
search over arbitrarily-large graphs? What would you need to change about the
rest of the program? Can you do this without leaking memory? Give it a shot if
you want to do HARD MODE!

## main function

For exercising our code, the main function (mostly written for you) load a graph
search problem from a text file and then calls BFS and DFS to solve that graph
search problem.

You do not need to make this program robust to bad graph text files, or graphs
larger than the baked-in size limit in `graphsearch.h`.

You can execute the homework code like so:

```
./hw4 graph1.txt
```

(and obviously, substitute `graph1.txt` with some other graph search problem
text file, to try those)

## deliverables

All of your deliverables for this homework should be checked in to a directory
called `hw4` in your CSE13s gitlab repository. Remember -- *add, commit, push*.

The resources you need are available in this directory.

  * By **Friday, 11 February 2022**, you should have written your `DESIGN.md`,
    containing your thoughts and plans and pseudocode for this assignment.
  * `graphsearch.c` -- most of your completed code goes here.
  * `graphsearch.h` -- you may want to change the header file, in order to add
    more functions, such as for cleaning up your allocated memory.
  * `hw4.c` -- you *may* need to change this, although it's possible that you
    can leave it as-is.
  * Makefile -- make sure that you use the standard flags for the class in your
    Makefile.

## reading

You should read...
  * _The C Programming Language_ by Kernighan & Ritchie, Chapters 5 (Pointers
    and Arrays) and 6 (Structures).
  * _The C Programming Language_ by Kernighan & Ritchie, Chapter 7 (to
    understand the I/O happening here).
