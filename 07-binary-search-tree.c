#include <stdio.h>
#include <stdlib.h>

typedef struct node {
  int data;
  struct node *left;
  struct node *right;
} NODE;

NODE *node;

NODE *created_tree(NODE *node, int data);
NODE *search(NODE *node, int data);
void in_order(NODE *node);
void pre_order(NODE *node);
void post_order(NODE *node);
NODE *find_min(NODE *node);
NODE *delete (NODE *node, int data);

int main(void) {
  int data, choice, n;
  NODE *root = NULL;
  while (1) {
    printf("\
            1. Insertion in Binary Tree\n\
            2. Search element in BT\n\
            3. Delete element in BT\n\
            4. Inorder\n\
            5. Preorder\n\
            6. Postorder\n\
            7. Exit");
    printf("\nEnter you choice: ");
    scanf("%d", &choice);
    switch (choice) {
    case 1:
      printf("Enter the number of elements: ");
      scanf("%d", &n);
      printf("Enter the elements: ");
      for (int i = 0; i < n; i++) {
        scanf("%d", &data);
        root = created_tree(root, data);
      }
      break;
    case 2:
      printf("Enter the element to search: ");
      scanf("%d", &data);
      root = search(root, data);
      break;
    case 3:
      printf("Enter the element to be deleted: ");
      scanf("%d", &data);
      root = delete (root, data);
      break;
    case 4:
      in_order(root);
      break;
    case 5:
      pre_order(root);
      break;
    case 6:
      post_order(root);
      break;
    case 7:
      exit(0);
      break;
    default:
      printf("Invalid choice\n");
      break;
    }
  }
}

NODE *created_tree(NODE *node, int data) {
  if (node == NULL) {
    NODE *temp = (NODE *)malloc(sizeof(NODE));
    temp->data = data;
    temp->left = temp->right = NULL;
    return temp;
  }
  if (data < (node->data))
    node->left = created_tree(node->left, data);
  else if (data > (node->data))
    node->right = created_tree(node->right, data);
  return node;
}

NODE *search(NODE *node, int data) {
  if (node == NULL)
    printf("Element not found\n");
  else if (data < node->data)
    node->left = search(node->left, data);
  else if (data > node->data)
    node->right = search(node->right, data);
  else
    printf("Element found\n");
  return node;
}

void in_order(NODE *node) {
  if (node != NULL) {
    in_order(node->left);
    printf("%d\t", node->data);
    in_order(node->right);
  }
}

void pre_order(NODE *node) {
  if (node != NULL) {
    printf("%d\t", node->data);
    pre_order(node->left);
    pre_order(node->right);
  }
}

void post_order(NODE *node) {
  if (node != NULL) {
    post_order(node->left);
    post_order(node->right);
    printf("%d\t", node->data);
  }
}

NODE *find_min(NODE *node) {
  if (node == NULL)
    return NULL;
  if (node->left)
    return find_min(node->left);
  else
    return node;
}

NODE *delete (NODE *node, int data) {
  NODE *temp = (NODE *)malloc(sizeof(NODE));
  if (node == NULL)
    printf("Element not found\n");
  else if (data < node->data)
    node->left = delete (node->left, data);
  else if (data > node->data)
    node->right = delete (node->right, data);
  else {
    if (node->right && node->left) {
      temp = find_min(node->right);
      node->data = temp->data;
      node->right = delete (node->right, temp->data);
    } else {
      temp = node;
      if (node->left == NULL)
        node = node->right;
      else if (node->right == NULL)
        node = node->left;
      free(temp);
    }
  }
  return node;
}
