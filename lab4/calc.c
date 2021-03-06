// include parts of the C standard library
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include<math.h>
#include<string.h>

// type declaration for stack of doubles
  struct double_stack {
    double * items;
    int max_size;
    int top;
  };

// create a new empty stack
  struct double_stack * double_stack_new(int max_size){
    struct double_stack * result;

    // allocate space for the stack header
    result = malloc(sizeof(struct double_stack));
    result->max_size = max_size;
    result->top = 0;

    // allocate space for the data stored in the stack
    result->items = malloc(sizeof(double)*max_size);

    // return a pointer to the newly-allocated stack
    return result;
  }

// push a value onto the stack
void double_stack_push(struct double_stack * this, double value){
	if(this->top == this->max_size) // Checking Array is full or not.
  {
		printf("There is an overflow.\n");
	}
	else
	{
		this->items[this->top] = value;
		this->top++;
	}
	return;
}

// pop a value from the stack
double double_stack_pop(struct double_stack * this){
	double value;
	if(this->top == 0) // Checking Array is empty or not.
	{
		printf("The stack is empty.\n");
		return -1;
	}
	value = this->items[this->top -1];
	this->top -= 1; //	top = top - 1
	return value;
}

double evaluate_postfix_expression(char ** postfix_expression, int size){

  char current_value;
	double result;
	double tmp_v1, tmp_v2;

  struct double_stack* postfix_stack = double_stack_new(size);

  for (int i = 0 ; i < size; i++){
    current_value = postfix_expression[i][0];
    if (((strlen(postfix_expression[i]) == 1)) && (current_value == '+' || current_value == '-' || current_value == 'x' || current_value == 'X' || current_value == '/' || current_value == '^'))
		{
			tmp_v1 = double_stack_pop(postfix_stack);
			tmp_v2 = double_stack_pop(postfix_stack);

			switch (current_value) /* ch is an operator */
			{
				case 'x':
				result = tmp_v2 * tmp_v1;
				break;
				
				case 'X':
				result = tmp_v2 * tmp_v1;
				break;

				case '/':
				result = tmp_v1 / tmp_v2;
				break;

				case '+':
				result = tmp_v2 + tmp_v1;
				break;

				case '-':
				result = tmp_v2 - tmp_v1;
				break;

				case '^':
				result = pow(tmp_v1, tmp_v2);
				break;
			}

			/* push the value obtained above onto the stack */
			double_stack_push(postfix_stack, result);
		}
	else {
		 current_value = atof(postfix_expression[i]);
			double_stack_push(postfix_stack, current_value);
	}

  }
	return double_stack_pop(postfix_stack);
}

// main function for a simple bench calculator with command
// line inputs
int main(int argc, char ** argv) {
  if ( argc == 1 ) {
    // command line contains only the name of the program
    printf("Error: No command line parameters provided\n");
    printf("Usage: %s postfix|infix <expression>\n", argv[0]);
    exit(1);
  }
  else if ( argc == 2 ) {
    // command line contains name of prog and one other parameter
    printf("Error: No expression to evaluate provided\n");
    printf("Usage: %s postfix|infix <expression>\n", argv[0]);
    exit(1);
  }
  else {
    // command line has enough parameters for an expression
    double result;
    if ( strcmp(argv[1], "postfix") == 0 ) {
      // pass the command line parameters, but with the first two removed
      result = evaluate_postfix_expression(argv+2, argc-2);
      printf("Result is %lf\n", result);
    }
    else if ( strcmp(argv[1], "infix") == 0 ) {
      // pass the command line parameters, but with the first two removed
     // result = evaluate_infix_expression(argv+2, argc-2);
      printf("Result is %lf\n", result);
    }
    else {
      printf("Error: You must specify whether the expression is infix or postfix\n");
      printf("Usage: %s postfix|infix <expression>\n", argv[0]);
      exit(1);
    }

  return 0;
  }
}
