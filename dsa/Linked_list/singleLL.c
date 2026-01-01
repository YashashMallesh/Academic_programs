#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Student {
    char usn[20];
    char name[50];
    char programme[30];
    int sem;
    char phno[15];
    struct Student *next;
};

typedef struct Student NODE;

NODE* createNode() {
    NODE* newNode = (NODE*)malloc(sizeof(NODE));
    if (newNode == NULL) {
        printf("\nMemory allocation failed!");
        return NULL;
    }
    printf("Enter USN: ");
    scanf("%s", newNode->usn);
    printf("Enter Name: ");
    scanf(" %[^\n]s", newNode->name);
    printf("Enter Programme: ");
    scanf("%s", newNode->programme);
    printf("Enter Sem: ");
    scanf("%d", &newNode->sem);
    printf("Enter Phone No: ");
    scanf("%s", newNode->phno);
    newNode->next = NULL;
    return newNode;
}
NODE* insertFront(NODE* head) {
    NODE* newNode = createNode();
    newNode->next = head;
    return newNode;
}
NODE* insertEnd(NODE* head) {
    NODE* newNode = createNode();
    if (head == NULL) return newNode;
    NODE* temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
    return head;
}
NODE* deleteFront(NODE* head) {
    if (head == NULL) {
        printf("\nList is Empty (Underflow).");
        return NULL;
    }
    NODE* temp = head;
    head = head->next;
    printf("\nDeleted Student USN: %s\n", temp->usn);
    free(temp);
    return head;
}
NODE* deleteEnd(NODE* head) {
    if (head == NULL) {
        printf("\nList is Empty (Underflow).");
        return NULL;
    }
    if (head->next == NULL) {
        printf("\nDeleted Student USN: %s\n", head->usn);
        free(head);
        return NULL;
    }
    NODE *curr = head, *prev = NULL;
    while (curr->next != NULL) {
        prev = curr;
        curr = curr->next;
    }
    prev->next = NULL;
    printf("\nDeleted Student USN: %s\n", curr->usn);
    free(curr);
    return head;
}
void display(NODE* head) {
    int count = 0;
    if (head == NULL) {
        printf("\nSLL is empty. Count = 0\n");
        return;
    }
    printf("\n--- Student Details ---\n");
    printf("USN\t\tNAME\t\tPROG\tSEM\tPH.NO\n");
    NODE* temp = head;
    while (temp != NULL) {
        printf("%s\t%s\t%s\t%d\t%s\n", temp->usn, temp->name, temp->programme, temp->sem, temp->phno);
        temp = temp->next;
        count++;
    }
    printf("\nTotal number of students: %d\n", count);
}

int main() {
    NODE* head = NULL;
    int choice, n, i;

    while (1) {
        printf("\n--- SLL MENU ---");
        printf("\n1. Create SLL of N students (Front Insertion)");
        printf("\n2. Display SLL & Count");
        printf("\n3. Insertion at End");
        printf("\n4. Deletion at End");
        printf("\n5. Insertion at Front");
        printf("\n6. Deletion at Front");
        printf("\n7. Exit");
        printf("\nEnter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter number of students: ");
                scanf("%d", &n);
                for (i = 0; i < n; i++) head = insertFront(head);
                break;
            case 2: display(head); break;
            case 3: head = insertEnd(head); break;
            case 4: head = deleteEnd(head); break;
            case 5: head = insertFront(head); break;
            case 6: head = deleteFront(head); break;
            case 7: exit(0);
            default: printf("Invalid choice!");
        }
    }
    return 0;
}
