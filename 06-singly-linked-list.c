#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct student {
  long long ph;
  int sem;
  char name[15];
  char USN[15];
  char branch[8];
  struct student *next;
} STUDENT;

STUDENT *head = NULL, *tail = NULL, *temp = NULL;

int count = 0;

void insert_head(char na[], char u[], char brn[], int s, long long p);
void insert_tail(char na[], char u[], char brn[], int s, long long p);
void delete_head();
void delete_tail();
void display();

int main(void) {
  long long ph;
  int sem;
  char name[15], USN[15], branch[8];

  int choice;
  printf("Press:\n\
          1. Insert from head\n\
          2. Insert from tail\n\
          3. Delete from head\n\
          4. Delete from tail\n\
          5. Display all\n\
          6. Exit");

  while (1) {
    printf("\nEnter your choice: ");
    scanf("%d", &choice);
    switch (choice) {
    case 1:
      printf(
          "Enter the name, usn, branch, sem and phone number respectively: ");
      scanf("%s%s%s%d%lld", name, USN, branch, &sem, &ph);
      insert_head(name, USN, branch, sem, ph);
      break;
    case 2:
      printf(
          "Enter the name, usn, branch, sem and phone number respectively: ");
      scanf("%s%s%s%d%lld", name, USN, branch, &sem, &ph);
      insert_tail(name, USN, branch, sem, ph);
      break;
    case 3:
      delete_head();
      break;
    case 4:
      delete_tail();
      break;
    case 5:
      display();
      break;
    case 6:
      exit(0);
    default:
      printf("Invalid option\n");
      break;
    }
  }
}

void insert_head(char na[], char u[], char brn[], int s, long long p) {
  temp = (STUDENT *)malloc(sizeof(STUDENT));
  strcpy(temp->name, na);
  strcpy(temp->USN, u);
  strcpy(temp->branch, brn);
  temp->sem = s;
  temp->ph = p;
  temp->next = head;
  head = temp;
  count++;
  // temp = NULL;
}
void insert_tail(char na[], char u[], char brn[], int s, long long p) {
  temp = (STUDENT *)malloc(sizeof(STUDENT));
  strcpy(temp->name, na);
  strcpy(temp->USN, u);
  strcpy(temp->branch, brn);
  temp->sem = s;
  temp->ph = p;
  temp->next = NULL;
  tail = temp;
  count++;
  // temp = NULL;
}
void delete_head() {
  temp = head;
  if (temp == NULL)
    printf("List is empty\n");
  else {
    head = head->next;
    printf("Deleted node is:\n\
            Name: %s\n\
            USN: %s\n\
            Branch: %s\n\
            Sem: %d\n\
            PhoneNo: %lld\n",
           temp->name, temp->USN, temp->branch, temp->sem, temp->ph);
  }
  free(temp);
}
void delete_tail() {
  temp = tail;
  if (temp == NULL)
    printf("List is empty\n");
  else {
    tail = head;
    while (tail->next != temp)
      tail = tail->next;
    printf("Deleted node is:\n\
            Name: %s\n\
            USN: %s\n\
            Branch: %s\n\
            Sem: %d\n\
            PhoneNo: %lld\n",
           temp->name, temp->USN, temp->branch, temp->sem, temp->ph);
  }
  free(temp);
}
void display() {
  temp = head;
  if (temp == NULL) {
    printf("List is empty\n");
    return;
  }
  while (temp != NULL) {
    printf("\
            Name: %s\n\
            USN: %s\n\
            Branch: %s\n\
            Sem: %d\n\
            PhoneNo: %lld\n",
           temp->name, temp->USN, temp->branch, temp->sem, temp->ph);
    temp = temp->next;
  }
  printf("Count: %d", count);
}
