#include <ctype.h>
#include <math.h>
#include <stdio.h>

#define SIZE 50

int s[SIZE];
int top = -1;

void push(int x) { s[++top] = x; }

int pop(void) { return s[top--]; }

int main(void) {
  char pofx[SIZE], *ch;
  printf("Enter the postfix expression: ");
  scanf("%s", pofx);

  ch = pofx;

  while (*ch != '\0') {
    if (isdigit(*ch))
      push(*ch - '0');
    else {
      int op1 = pop();
      int op2 = pop();
      switch (*ch) {
      case '+':
        push(op1 + op2);
        break;
      case '-':
        push(op1 - op2);
        break;
      case '*':
        push(op1 * op2);
        break;
      case '/':
        push(op1 / op2);
        break;
      case '^':
      case '$':
        push(pow(op1, op2));
        break;
      }
    }
    ch++;
  }

  printf("Given Postfix expression is: %s\n", pofx);
  printf("After evaluation: %d\n", s[top]);

  return 0;
}
