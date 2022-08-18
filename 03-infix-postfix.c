#include <ctype.h>
#include <stdio.h>

#define SIZE 50

char s[SIZE];
int top = -1;

void push(char ch) { s[++top] = ch; }

char pop(void) { return s[top--]; }

int priority(char ch) {
  switch (ch) {
  case '#':
    return 0;
  case '(':
    return 1;
  case '+':
  case '-':
    return 2;
  case '*':
  case '/':
  case '%':
    return 3;
  case '^':
  case '$':
    return 4;
  }
}

int main(void) {
  char infx[SIZE], pofx[SIZE];
  printf("Enter the infix expression: ");
  scanf("%s", infx);

  char *ch = infx;
  char *j = pofx;
  while (*ch != '\0') {
    if (*ch == '(')
      push(*ch);
    else if (isalnum(*ch))
      *(j++) = *ch;
    else if (*ch == ')') {
      while (s[top] != '(')
        *(j++) = pop();
      pop();
    } else {
      while (priority(s[top]) >= priority(*ch))
        *(j++) = pop();
      push(*ch);
    }
    ch++;
  }
  while (top != -1)
    *(j++) = pop();

  *j = '\0';
  printf("Given infix expression: %s\nPostfix expression: %s\n", infx, pofx);

  return 0;
}
