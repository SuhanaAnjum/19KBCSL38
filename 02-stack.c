#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 5

int stack[MAX_SIZE];
int top = -1, item;

void push(void);
void pop(void);
void display(void);

int main(void) {
  printf("Press:\n\
          1. Push\n\
          2. Pop\n\
          3. Display\n\
          4. Exit");
  int choice;
  while (1) {
    printf("\nEnter your choice: ");
    scanf("%d", &choice);
    switch (choice) {
    case 1:
      push();
      break;
    case 2:
      pop();
      break;
    case 3:
      display();
      break;
    case 4:
      exit(0);
    default:
      printf("Invalid Choice\n");
      break;
    }
  }
}

void push(void) {
  if (top == (MAX_SIZE - 1))
    printf("Stack overflow\n");
  else {
    printf("Enter the element to be inserted: ");
    scanf("%d", &stack[++top]);
  }
}

void pop(void) {
  if (top == -1)
    printf("Stack Underflow\n");
  else
    printf("The popped Element is %d", stack[top--]);
}

void display(void) {
  if (top == -1)
    printf("Stack is Empty\n");
  else {
    printf("The stack elements are: ");
    for (int i = top; i >= 0; i--)
      printf("%d\t", stack[i]);
  }
}
