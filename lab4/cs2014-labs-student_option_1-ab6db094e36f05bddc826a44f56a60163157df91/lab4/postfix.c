#include "postfix.h"

// evaluate expression stored as an array of string tokens
double evaluate_postfix_expression(char ** args, int nargs) {
  char current_value;
 	double result;
 	double tmp_v1, tmp_v2;

   struct double_stack* postfix_stack = double_stack_new(size);

   for (int i = 0 ; i < size; i++) {
     current_value = postfix_expression[i][0];
     if (((strlen(postfix_expression[i]) == 1)) && (current_value == '+' || current_value == '-' || current_value == 'x' || current_value == 'X' || current_value == '/' || current_value == '^')) {
 		    tmp_v1 = double_stack_pop(postfix_stack);
 			  tmp_v2 = double_stack_pop(postfix_stack);

 			  switch (current_value){

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

 			   double_stack_push(postfix_stack, result);
 		  }
 	  else {
 		  current_value = atof(postfix_expression[i]);
 			double_stack_push(postfix_stack, current_value);
 	  }

  }
 	return double_stack_pop(postfix_stack);
}
