#include <stdio.h>
#include <stdlib.h>

struct Node {
  int data;
  struct Node* next;
};

struct Node* createNode(int value) {
  struct Node* n = (struct Node*)malloc(sizeof(struct Node));
  n->data = value;
  n->next = NULL;
  return n;
}

void addNode(struct Node** head, int value) {
  struct Node* newNode = createNode(value);
  if (*head == NULL) {
    *head = newNode;
  } else {
    struct Node* current = *head;
    while (current->next != NULL) {
      current = current->next;
    }
    current->next = newNode;
  }
}

void printList(struct Node* head) {
  struct Node* current = head;
  while (current != NULL) {
    printf("%d ", current->data);
    current = current->next;
  }
  printf("\n");
}

void printReverse(struct Node* head) {
  if (head == NULL) return;
  printReverse(head->next);
  printf("%d ", head->data);
}

int main() {
  struct Node* list = NULL;
  
  addNode(&list, 10);
  addNode(&list, 20);
  addNode(&list, 30);
  addNode(&list, 40);
  addNode(&list, 50);
  
  printf("Original List: ");
  printList(list);
  
  printf("Reversed List: ");
  printReverse(list);
  printf("\n");
  
  return 0;
}
