#include "infix.h"

// evaluate expression stored as an array of string tokens
double evaluate_infix_expression(char ** args, int nargs) {
  struct double_stack* postfix_stack = double_stack_new(nargs);
  char ** postfix = malloc(sizeof(char*) * nargs);
  int length = -1;

  _Bool double_stack_is_empty(struct double_stack * this){
    if(this -> top == 0){
      return 1;
    }
    return 0;
  }

  _Bool is_operator_of_higher_precendence(char operator){
    if ((operator == '+') || (operator == '-')) return 1;
    else if ((operator == 'X') || (operator == '/')) return 2;
    else if (operator == '^') return 3;
    else return 0;
  }

  for (int i = 0; i < nargs; i++){

    if (*args[i] == '('){
      double_stack_push(postfix_stack, *args[i]);
    }
    else if (*args[i] == ')'){
      while ((!double_stack_is_empty(postfix_stack)) && ((postfix_stack -> items[postfix_stack->top-1]) != '(')) {
        char temp_operator = (char)double_stack_pop(postfix_stack);
        postfix[++length] = malloc(sizeof(temp_operator));
        *postfix[length] = temp_operator;
      }
    }
    else if (((strlen(args[i]) == 1)) && (*args[i] == '+' || *args[i] == '-' || *args[i] == 'x' || *args[i] == 'X' || *args[i] == '/' || *args[i] == '^')){
      while ((!double_stack_is_empty(postfix_stack)) && (is_operator_of_higher_precendence(*args[i]) <= is_operator_of_higher_precendence(postfix_stack -> items[postfix_stack -> top-1]))){
        char temp_operator = (char)double_stack_pop(postfix_stack);
        postfix[++length] = malloc(sizeof(temp_operator));
        *postfix[length] = temp_operator;
      }
      double_stack_push(postfix_stack, *args[i]);
    }
    else {
      postfix[++length] = malloc(sizeof(args[i]));
      postfix[length] = args[i];
    }
  }

  while (!double_stack_is_empty(postfix_stack)){
    char temp_operator = (char)double_stack_pop(postfix_stack);
    postfix[++length] = malloc(sizeof(temp_operator));
    *postfix[length] = temp_operator;
  }

  return evaluate_postfix_expression(postfix, length);
}

