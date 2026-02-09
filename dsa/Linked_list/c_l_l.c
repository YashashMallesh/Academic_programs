#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};
struct Node *NODE;
 NODE* tail = NULL;

void insertAtBegin(int val) {
    NODE* newNode = (NODE*)malloc(sizeof(NODE));
    newNode->data = val;

    if (tail == NULL) {
        tail = newNode;
        newNode->next = tail;
    } else {
        newNode->next = tail->next;
        tail->next = newNode;
    }
}


void deleteNode() {
    if (tail == NULL) return; // List is empty

    NODE* temp = tail->next;

    if (temp == tail) { // Only one node in the list
        tail = NULL;
        free(temp);
    } else {
        tail->next = temp->next;
        free(temp);
    }
}

void display() {
    if (tail == NULL) return;

    NODE* temp = tail->next; // Start at the head
    do {
        printf("%d -> ", temp->data);
        temp = temp->next;
    } while (temp != tail->next);
    printf("(back to start)\n");
}

void main(){
  int val;
  printf("Enter the value to be entered");
  scanf("%d",&val);
  insertAtBegin(val);
  display();
  printf("Value after deleteing a node:");
  deleteNode();
  display();
}
