3. Write and Implement the reverse traversal algorithm in the the linked list. Write main() to demonstrate the use of the function.


ANSWER:


The program uses a singly linked list to store data:
Node Structure

struct Node: This structure represents each element in the linked list. It contains two parts:

int data: Stores the integer value for the node.
struct Node* next: A pointer that points to the next node in the list. If it's the last node, this points to NULL.



List Pointer

struct Node* list: A pointer to the first node (head) of the linked list. It starts as NULL to indicate an empty list.

Functions Implemented
1. struct Node* createNode(int value)
This function creates a new node for the linked list. It allocates memory for the node, sets its data to the given value, and initializes the next pointer to NULL. It returns the pointer to the newly created node.
2. void addNode(struct Node** head, int value)
This function adds a new node at the end of the linked list. It first creates a new node using createNode(). If the list is empty, the new node becomes the head. Otherwise, it traverses to the last node and attaches the new node there.
3. void printList(struct Node* head)
This function prints the linked list in normal order (from first to last). It uses a loop to traverse through each node, printing the data and moving to the next node until it reaches the end.
4. void printReverse(struct Node* head)
This is the main function that prints the linked list in reverse order. It uses recursion to achieve this. The function calls itself with the next node until it reaches the end of the list (NULL). Then, as the recursive calls return, it prints each node's data, which results in reverse order printing.
Main Method Organization
The main function demonstrates the reverse traversal algorithm:

1. A linked list pointer is initialized to NULL, creating an empty list.
2. Five nodes with values 10, 20, 30, 40, and 50 are added to the list using addNode().
3. The original list is printed in normal order using printList() to show the initial state.
4. The list is then printed in reverse order using printReverse() to demonstrate the reverse traversal algorithm.
5. The program ends by returning 0.
**Input/Output**

![alt text](../Output/OUTPUT3.png)

