#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the structure for Employee Data
struct Employee {
    char ssn[20];
    char name[50];
    char dept[30];
    float salary;
    char phno[15];
    struct Employee *prev;
    struct Employee *next;
};

typedef struct Employee NODE;

// Function to create a new node
NODE* createNode() {
    NODE* newNode = (NODE*)malloc(sizeof(NODE));
    if (newNode == NULL) {
        printf("\nMemory allocation failed!");
        return NULL;
    }
    printf("Enter SSN: ");
    scanf("%s", newNode->ssn);
    printf("Enter Name: ");
    scanf(" %[^\n]s", newNode->name);
    printf("Enter Dept: ");
    scanf("%s", newNode->dept);
    printf("Enter Salary: ");
    scanf("%f", &newNode->salary);
    printf("Enter Phone No: ");
    scanf("%s", newNode->phno);
    
    newNode->prev = NULL;
    newNode->next = NULL;
    return newNode;
}

// a & d. Insert at Front
NODE* insertFront(NODE* head) {
    NODE* newNode = createNode();
    if (head == NULL) return newNode;
    
    newNode->next = head;
    head->prev = newNode;
    return newNode;
}

// c. Insert at End
NODE* insertEnd(NODE* head) {
    NODE* newNode = createNode();
    if (head == NULL) return newNode;
    
    NODE* temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
    newNode->prev = temp;
    return head;
}

// d. Delete from Front
NODE* deleteFront(NODE* head) {
    if (head == NULL) {
        printf("\nList is Empty.");
        return NULL;
    }
    NODE* temp = head;
    head = head->next;
    if (head != NULL) head->prev = NULL;
    
    printf("\nDeleted Employee SSN: %s\n", temp->ssn);
    free(temp);
    return head;
}

// c. Delete from End
NODE* deleteEnd(NODE* head) {
    if (head == NULL) {
        printf("\nList is Empty.");
        return NULL;
    }
    if (head->next == NULL) {
        printf("\nDeleted Employee SSN: %s\n", head->ssn);
        free(head);
        return NULL;
    }
    NODE* temp = head;
    while (temp->next != NULL) temp = temp->next;
    
    temp->prev->next = NULL;
    printf("\nDeleted Employee SSN: %s\n", temp->ssn);
    free(temp);
    return head;
}

// b. Display and Count
void display(NODE* head) {
    int count = 0;
    if (head == NULL) {
        printf("\nDLL is empty. Count = 0\n");
        return;
    }
    printf("\n--- Employee Details ---\n");
    printf("SSN\t\tNAME\t\tDEPT\tSALARY\tPH.NO\n");
    NODE* temp = head;
    while (temp != NULL) {
        printf("%s\t%s\t%s\t%.2f\t%s\n", temp->ssn, temp->name, temp->dept, temp->salary, temp->phno);
        temp = temp->next;
        count++;
    }
    printf("\nTotal number of nodes: %d\n", count);
}

int main() {
    NODE* head = NULL;
    int choice, n, i;

    while (1) {
        printf("\n--- DLL MENU ---");
        printf("\n1. Create DLL of N Employees (Front Insertion)");
        printf("\n2. Display DLL & Count");
        printf("\n3. Insertion at End");
        printf("\n4. Deletion at End");
        printf("\n5. Insertion at Front");
        printf("\n6. Deletion at Front");
        printf("\n7. Exit");
        printf("\nEnter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter number of employees: ");
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
