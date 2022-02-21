#include "infix.h"

// evaluate expression stored as an array of string tokens
double evaluate_infix_expression(char ** args, int nargs) {
  struct double_stack * stack = double_stack_new(nargs); char * postfix[nargs]; char * length = 0;
  char current_value;

  for (int i = 0; i < nargs; i ++){
    current_value = args[i];

    if(isDigit(current_value)){
      postfix[length] = current_value;
      length++;
    }

    else if (current_value == '('){
      double_stack_push(stack, current_value);
    }

    else if(((strlen(args[i]) == 1)) && (current_value == '+' || current_value == '-' || current_value == 'x' || current_value == 'X' || current_value == '/' || current_value == '^')) {
      while(!stack == null){
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

    else if (current_value == ')'){
      int top = double_stack_pop(stack);
      while (top != '('){
        postfix[length] = top;
        length++;
        top = double_stack_pop(stack);
      }
    }
  }

  while (stack != null){
    postfix[length] = double_stack_pop(stack);
    length++
  }

  return evaluate_postfix_expression(postfix[], length);
}
