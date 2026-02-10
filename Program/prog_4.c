#include<stdio.h>
#include<stdlib.h>

struct node{
  int data;
  struct node* next;
  struct node* prev;
};

struct node* head = NULL;

void display(){
  struct node* current = head;
  if(current == NULL){
    printf("empty\n");
    return;
  }
  while(current != NULL){
    printf("%d ", current->data);
    current = current->next;
  }
  printf("\n");
}

void insert(int val){
  struct node* newNode = (struct node*)malloc(sizeof(struct node));
  newNode->data = val;
  newNode->next = NULL;
  if(head == NULL){
    newNode->prev = NULL;
    head = newNode;
    return;
  }
  struct node* current = head;
  while(current->next != NULL){
    current = current->next;
  }
  current->next = newNode;
  newNode->prev = current;
}

void insertAfter(struct node* ptr, int val){
  if(ptr == NULL) return;
  struct node* newNode = (struct node*)malloc(sizeof(struct node));
  newNode->data = val;
  newNode->prev = ptr;
  newNode->next = ptr->next;
  if(ptr->next != NULL){
    ptr->next->prev = newNode;
  }
  ptr->next = newNode;
}

void deleteNode(int val){
  if(head == NULL) return;
  struct node* current = head;
  while(current != NULL){
    if(current->data == val){
      if(current->prev != NULL){
        current->prev->next = current->next;
      }else{
        head = current->next;
      }
      if(current->next != NULL){
        current->next->prev = current->prev;
      }
      free(current);
      return;
    }
    current = current->next;
  }
}

int main(){
  insert(10);
  insert(20);
  insert(30);
  display();
  
  insertAfter(head, 15);
  display();
  
  insertAfter(head->next, 25);
  display();
  
  deleteNode(25);
  display();
  
  deleteNode(10);
  display();
  
  return 0;
}
