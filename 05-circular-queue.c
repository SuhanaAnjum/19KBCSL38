#include <stdio.h>
#include <stdlib.h>

#define SIZE 50

int CQ[SIZE], front = -1, rear = -1;

void insert(void);
void delete (void);
void display(void);

int main(void) {
  printf("Press\n\
          1. Insert\n\
          2. Delete\n\
          3. Display\n\
          4. Exit\n");
  int choice;
  while (1) {
    printf("\nEnter your choice: ");
    scanf("%d", &choice);
    switch (choice) {
    case 1:
      insert();
      break;
    case 2:
      delete ();
      break;
    case 3:
      display();
      break;
    case 4:
      exit(0);
    default:
      printf("Invalid option\n");
      break;
    }
  }

  return 0;
}

void insert(void) {
  int elem;
  printf("Enter an element: ");
  scanf("%d", &elem);

  if ((rear == SIZE - 1 && front == 0) || front == rear + 1) {
    printf("Queue full\n");
    return;
  }

  if (front == -1)
    rear = front = 0;
  else {
    if (rear == SIZE - 1)
      rear = 0;
    else
      rear++;
  }
  CQ[rear] = elem;
}

void delete (void) {
  if (front == -1 && rear == -1) {
    printf("Queue Empty\n");
    return;
  }
  if (front == rear)
    front = rear = -1;
  else {
    if (front == SIZE - 1)
      front = 0;
    else
      front++;
  }
}

void display(void) {
  int f = front, r = rear;
  if (f == -1) {
    printf("Queue Empty\n");
    return;
  }
  printf("Queue elements are: ");
  if (f <= r) {
    while (f <= r)
      printf("%d\t", CQ[f++]);
    printf("\n");
  } else {
    while (f <= SIZE - 1)
      printf("%d\t", CQ[f++]);
    f = 0;
    while (f <= r)
      printf("%d\t", CQ[f++]);
    printf("\n");
  }
}
