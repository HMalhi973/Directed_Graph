# Homework 4 - Graph

> Due: 12-3-2023 11:59:59 PM

**Topics**: Graph, BFS, Shortest Path, DFS, and Topological Sort

## Table of Contents

- [Homework 4 - Graph](#homework-4---graph)
  - [Table of Contents](#table-of-contents)
  - [Homework Spec](#homework-spec)
    - [Grading](#grading)
    - [DirectedGraph](#directedgraph)
    - [Breath First Search](#breath-first-search)
    - [Depth First Search](#depth-first-search)
    - [Submission](#submission)
  - [Setup](#setup)
    - [Option 1: VS Code with Local Dev Container](#option-1-vs-code-with-local-dev-container)
    - [Option 2: VS Code with Remote Dev](#option-2-vs-code-with-remote-dev)
    - [Option 3: Terminal](#option-3-terminal)
  - [Run/Debug](#rundebug)
    - [Run tests using VS Code](#run-tests-using-vs-code)
    - [Run tests using Terminal](#run-tests-using-terminal)

> ⚠️ DO NOT change files marked with
>
> ```cpp
> // DO NOT CHANGE THIS FILE
> ```

## Homework Spec

In this homework, you will write one data structure **Directed Graph**,
and then build two algorithms **Breath First Search (BFS)**
and **Depth First Search (DFS)** on the graph.

You will implement `Graph` first and then implement `BFS` and `DFS`
and their related functions.

> In reality, a adjacent list does not require order,
> so a better way to implement them is to use `unordered_map`
> and `unordered_set` (or just dynamic array).
> In this homework assignment, we keep the order for easier testing.
>
> The reason to keep a `Map<NodeValue, Node>` is to utilize the
> textbook pseudocode and definition that modifies the fields of the node.
> In reality we can just use some array or unordered_set to keep track
> of which vertices are visited instead of changing its color.

### Grading

You will be graded only on the same (hidden) test cases your TAs created.

We provided some tests cases in [./tests](./tests). Feel free to modify and add more test cases, but the [./tests](./tests) in your submission will not be
graded. However, you will be able to see the results for your submitted test cases on Gradescope.

- `DirectedGraph` implementation - 30%
- `BFS` function - 35%
- `DFS` function - 35%

> **NOTE:** If you are running out of time to implement all methods (or just want to see the project can be compiled), please at least provide a syntactically valid empty method definition for each method in `lib/*.cpp`.

### DirectedGraph

- Check the definition for `GraphNode` in [lib/GraphNode.hpp](./lib/GraphNode.hpp).
- Check the definition for `Graph` in [lib/Graph.hpp](./lib/Graph.hpp).
- Create test cases in [tests/TestGraph.cpp](./tests/TestGraph.cpp).

**NOTE**
When updating the edges or vertices,
both `_adjList` and `_vertices` should be updated.

### Breath First Search

- Implement `std::vector<T> BFS(T start);` defined in [lib/Graph.hpp](./lib/Graph.hpp).
  - For the queue used in `BFS`, please use C++ standard library by `#include <queue>`.
- Implement `int shortestPath(T start, T end)` defined in [lib/Graph.hpp](./lib/Graph.hpp).
  - You can assume `BFS` is never called before calling `shortestPath`.
- Create test cases in [tests/TestBFS.cpp](./tests/TestBFS.cpp).
- For formal definitions, please refer to textbook 20.2.
- We provide the example graph (Figure 20.3) in [test/TestBFS.cpp](./tests/TestBFS.cpp) for you to test your code.

### Depth First Search

- Implement `std::vector<T> DFS();` defined in [lib/Graph.hpp](./lib/Graph.hpp).
- Create test cases in [tests/TestDFS.cpp](./tests/TestDFS.cpp).
- For formal definitions, please refer to textbook 20.3.
- We provide the example graph (Figure 20.4) in [test/TestDFS.cpp](./tests/TestDFS.cpp) for you to test your code.
- You can implement `void DFS_visit(const T &u, int &time, std::list<T> &record);` to help add the `Node.value` to a `record` vector.

### Submission

Use `./generate_submission.sh` and submit `hw4-submission.zip` on Gradescope.

## Setup

Use one of the following options to set up your environment.

> ⚠️ If you're a student, **DO NOT FORK** this repository because you cannot
> change the visibility of a forked repo to private. If you plan to use Git for
> version control (which is encouraged), run `rm -rf .git && git init` (or change remote) after
> setting up using one of the options below and push to your **private**
> repository. Any public repository containing part of this homework solution
> will be reported to SJA.

### Option 1: VS Code with Local Dev Container

- If Docker is not running, start Docker.

- Click the following button to set up the environment.

  [![Setup Local Dev Container](https://img.shields.io/static/v1?label=Local%20Dev%20Container&message=Setup&color=blue&logo=visualstudiocode)](https://vscode.dev/redirect?url=vscode://ms-vscode-remote.remote-containers/cloneInVolume?url=https://github.com/ecs36c-fq2023/hw4)

- When asked for selecting a Kit to configure CMake, choose **GCC**.

### Option 2: VS Code with Remote Dev

- Connect VS Code to the remote host.

- Install **C/C++ Extension Pack** on Remote Server (if not already).

- Run the following command inside the integrated terminal.

  `git clone https://github.com/ecs36c-fq2023/hw4 ecs36c-hw4`

- Run `code ./ecs36c-hw4` to open the folder.

- When prompted to configure CMake, confirm and choose **GCC** when prompted for
  kit selection.

### Option 3: Terminal

- Run the following commands

  ```bash
  git clone https://github.com/ecs36c-fq2023/hw4 ecs36c-hw4
  cd ./ecs36c-hw4
  mkdir build
  cd build
  cmake ..
  ```

## Run/Debug

### Run tests using VS Code

Directly Launch via `Run -> start debugging` or `F5` function key.

### Run tests using Terminal

```bash
cd build
cmake ..
make
./run_tests
```
