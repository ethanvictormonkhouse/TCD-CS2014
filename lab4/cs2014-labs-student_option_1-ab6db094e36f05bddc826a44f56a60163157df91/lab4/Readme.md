# Contents 
```
lab4
    Readme.md
    Makefile
    stack.c
    postfix.c
    infix.c
    stack.h
    postfix.h
    infix.h
└── test_sources
        test_stack.c
        test_postfix_infix.c
└── test_inputs
        test_stack_1.txt
        ...
        test_postfix_1.txt
        ...
        test_infix_1.txt
        ...
└── test_outputs
        test_stack_1.txt
        ...
        test_postfix_1.txt
        ...
        test_infix_1.txt
        ...
```
  
  You have been provided with a Makefile and C main functions to test your code
  as well as test inputs and expected outputs.  **Do not modify the Makefile and
  the source code provided to you.  For the final submission the Makefile and
  main program will be overwritten.**

# Header Files
  Sample header files are given to you.  You can edit the header files however
  you must keep the same function signature to be able to run the automatic
  tests. **Do not delete the function declarations in the .h files.**  
  Include all your ".h" required for your code in their header file and include
  that header file in your .c.
  
## stack.h Snippet

```c
  #include <stdlib.h>
  #include <stdio.h>
  #include <assert.h>
  ...
  function declarations
  ...
```
## stack.c Snippet

```c
  #include "stack.h"
  ...
  function implementation
  ...
```

# Your Source Code

## Lab 2
  You should implement your stack functions for lab 3 in a file called stack.c
### struct double_stack * double_stack_new(int max_size);
    create a new empty stack
### void double_stack_push(struct double_stack * this, double value);
    push a value onto the stack
### double double_stack_pop(struct double_stack * this);
    pop a value from the stack

## Lab 3 and Lab 4
  You should implement your postfix and infix functions in postfix.c and infix.c respectively.

# Evaluation of Your Source Code
  Run the Makefile on macneill or on the machines in LG12.

  Run the command make.
  ```
  make
  ```

  If the command has correctly been executed two new directories "build" and
  "result" should be created under "test_files".  You should find a summary of
  the test results in "test_files/result/results.txt". results.txt will give you an indication of your grades for the lab.  We will run more test for the final evaluation of your code and your final grades.

# Manual Testing

  If you want to run some manual tests, you can still invoke your program as you did for the previous weeks.  The compiler outputs are in test_files/build and are called test_stack, test_postfix and test_infix.

# Submission
  Submit only the your source code (stack.c, postfix.c and infix.c) and header
  files (stack.h, postfix.h, and infix.h). 

  The Makefile can be used to create the submission archive with:

  ```
  make submission_archive
  ```
  
