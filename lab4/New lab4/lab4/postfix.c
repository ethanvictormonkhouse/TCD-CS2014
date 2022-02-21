#include "postfix.h"

// evaluate expression stored as an array of string tokens
double evaluate_postfix_expression(char ** args, int nargs) {
  double current_value;
  char operator;
  double result;
  double tmp_v1, tmp_v2;

   struct double_stack* postfix_stack = double_stack_new(nargs);

   for (int i = 0 ; i < nargs; i++) {
     current_value = args[i][0];
     operator = args[i][0];
     if (((strlen(args[i]) == 1)) && (current_value == '+' || current_value == '-' || current_value == 'x' || current_value == 'X' || current_value == '/' || current_value == '^')) {
 		    tmp_v1 = double_stack_pop(postfix_stack);
 			  tmp_v2 = double_stack_pop(postfix_stack);

 			  switch (operator){

     				case 'x':
     				result = tmp_v2 * tmp_v1;
     				break;

     				case 'X':
     				result = tmp_v2 * tmp_v1;
     				break;

     				case '/':
     				result = tmp_v2 / tmp_v1;
     				break;

     				case '+':
     				result = tmp_v2 + tmp_v1;
     				break;

     				case '-':
     				result = tmp_v2 - tmp_v1;
     				break;

     				case '^':
     				result = pow(tmp_v2, tmp_v1);
     				break;
     		}

 			   double_stack_push(postfix_stack, result);
 		  }
 	  else {
 		  current_value = atof(args[i]);
 			double_stack_push(postfix_stack, current_value);
 	  }

  }
 	return double_stack_pop(postfix_stack);
}
