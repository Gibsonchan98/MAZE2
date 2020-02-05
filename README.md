# Maze

Goals: Understand recursion and solve a maze

This project takes any maze.txt file and finds the path around it. 
It then prints out the path it took to reach the exit. 

```shell
20 7
0 18
xxxxxxxxxxxxxxxxxx x
x     x       xxxx x
x xxxxx xxxxx   xx x
x xxxxx xxxxxxx xx x
x x          xx xx x
x xxxxxxxxxx xx    x
xxxxxxxxxxxxxxxxxxxx
```

Solution:
`*` shows the final path to exit

`+` shows areas explored but not part of the final path

```shell
Path: EEENNNEEEEEESEESSSEEENNNNN
xxxxxxxxxxxxxxxxxx*x
x     x*******xxxx*x
x xxxxx*xxxxx***xx*x
x xxxxx*xxxxxxx*xx*x
x x+****+++++xx*xx*x
x xxxxxxxxxx+xx****x
xxxxxxxxxxxxxxxxxxxx
```

## Included Files

- `CMakeLists.txt`: For complex projects, `cmake CMakeLists.txt` will
  generate a `Makefile`. We can then use `make` to compile the
  project. Optional for a small project like this, but included as an
  example.

- `maze.cpp` and `maze.h`: 
##Functions Included 
```shell
Functions Included :
explicit Maze(const string& fileName);
    *Checks if space is clear
        - bool isClear(int row, int col) const;
    *Marks path with "*"
        -void markAsPath(int row, int col);
    * Marks path as visited "+" 
        -void markAsVisited(int row, int col);
    *Returns the row where the exit is 
        -int getExitRow() const;
    *Returns the column where the exit is 
        -int getExitColumn() const;
    *returns maze's height
        -int getHeight() const;
    *returns maze's width
        -int getWidth() const;
```

- `creature.cpp` and `creature.h`: 
##Functions Included 
```shell
 *Shows location of creature
  - Creature(int row, int col);
 *returns path as string such as "NNEE.." and solves the given maze
    - string solve(Maze& maze);
 *checks if creatture is at exit 
    - bool atExit(const Maze& maze) const;
 *makes the creature go north
    - string goNorth(Maze& maze);
 *makes creauture go South
    - string goSouth(Maze& maze);
 *makes creature go east
    - string goEast(Maze& maze);
 * makes the creature go west 
    - string goWest(Maze& maze); 

```

- `main.cpp`: Runs all tests

- `output.txt`: Output from `./simple.compile.sh > output.txt 2>&1`
showing how the program is compiled and run.

- `simplecompile.sh`: Unix bash script file to compile, run 
and then delete the executable. Can be used to create an output.txt file

## Compile and Run

```shell
./simplecompile.sh
```

### Style Explanation

These options are defined in `.clang-tidy` file.

Perform all check except the following:

- fuchsia-* do not need specific checks for "fuchsia" a modular, capability-based operating system
- cppcoreguidelines-pro-bounds-array-to-pointer-decay: do not give warnings on assert
- cppcoreguidelines-pro-bounds-constant-array-index: enable using non constant array subscript indicies
- google-runtime-references: enable passing non-const references
- google-build-using-namespace: for simplicity allow `using namespace std;`
- google-readability-braces-around-statements: allow compact code without `{`
- readability-braces-around-statements: allow compact code without `{` This option is not available in CSS Linux lab under LLVM 3.8.1, but is needed on my PC when using 9.0.0
- hicpp-no-array-decay need to use assert
- modernize-use-trailing-return-type: not ready yet for `auto func() -> int` format
- hicpp-braces-around-statements: allow compact code without `{` (this option
- cppcoreguidelines-pro-bounds-pointer-arithmetic,
- llvm-header-guard: not using full directory name
- google-global-names-in-headers: for simplicity allow `using namespace std;`
- cppcoreguidelines-special-member-functions: not defining move operator
- hicpp-special-member-functions: not defining move operator
- cppcoreguidelines-owning-memory: not using gsl

## Misc

This file is part of a repository located at
[https://github.com/jdelliot342/maze](https://github.com/jdelliot342/maze)
