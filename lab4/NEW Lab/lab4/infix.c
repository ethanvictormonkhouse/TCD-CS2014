#include "infix.h"

// evaluate expression stored as an array of string tokens
double evaluate_infix_expression(char ** args, int nargs) {
  struct double_stack * stack = double_stack_new(nargs);  
  char * postfix[nargs]; 
  int length = 0;
  char current_value;

  for (int i = 0; i < nargs; i ++){
    current_value = args[i][0];

    if (args[i][0] == '('){
      double_stack_push(stack, args[i][0]);
    }

    else if(((strlen(args[i]) == 1)) && (current_value == '+' || current_value == '-' || current_value == 'x' || current_value == 'X' || current_value == '/' || current_value == '^')) {
      while(stack != NULL){
        int top = double_stack_pop(stack);
        if((((strlen(args[i]) == 1)) && (top == '+' || top == '-' || top == 'x' || top == 'X' || top == '/' || top == '^')) && (((top == '^') && (current_value != '^')) || (((top == '^') || (top == '/') || (top == 'x') || (top == 'X')) && ((current_value == '+') || (current_value == '-'))))) {
          postfix[length] = args[top];
          length++;
        }
        else {
          double_stack_push(stack, top);
          break;
        }
      }
      double_stack_push(stack, current_value);
    }

    else if (args[i][0] == ')'){
      int top = double_stack_pop(stack);
      while (top != '('){
        postfix[length] = top;
        length++;
        top = double_stack_pop(stack);
      }
    }
    
    else {
    postfix[length] = current_value;
      length++;
      }
  }

  while (stack != NULL){
    postfix[length] = (char)(double_stack_pop(stack));
    length++;
  }

  printf("%s", postfix);
  return evaluate_postfix_expression(postfix, length);
}
