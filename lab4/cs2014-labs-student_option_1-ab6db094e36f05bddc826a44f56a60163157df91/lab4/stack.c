#include "stack.h"

struct double_stack * double_stack_new(int max_size) {
}

// push a value onto the stack
void double_stack_push(struct double_stack * this, double value) {
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
double double_stack_pop(struct double_stack * this) {
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
