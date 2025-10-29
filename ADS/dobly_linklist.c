#include <stdio.h>
#include <stdlib.h>

// Define the node structure
typedef struct Node {
    int data;
    struct Node* prev;
    struct Node* next;
} Node;
Node* head = NULL;
// Function to create a new node
Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->prev = NULL;
    newNode->next = NULL;
    return newNode;
}

// Insert at the front
void insertFront( int data) {
    Node* newNode = createNode(data);
    if (head == NULL) {
        head = newNode;
        return;
    }
    newNode->next = head;
    (head)->prev = newNode;
    head = newNode;
}

// Insert at the end
void insertEnd( int data) {
    Node* newNode = createNode(data);
    if (head == NULL) {
        head = newNode;
        return;
    }
    Node* temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
    newNode->prev = temp;
}

// Delete from front
void deleteFront() {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }
    Node* temp = head;
   head = (head)->next;
    if (head != NULL)
        (head)->prev = NULL;
    free(temp);
}

// Delete from end
void deleteEnd() {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }
    Node* temp =head;
    if (temp->next == NULL) {
        // Only one element
        free(temp);
       head = NULL;
        return;
    }
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->prev->next = NULL;
    free(temp);
}

// Display the list forward
void displayForward() {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }
    Node* temp = head;
    printf("List (forward): ");
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

// Display the list backward
void displayBackward() {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }
    Node* temp = head;
    // Move to the last node
    while (temp->next != NULL) {
        temp = temp->next;
    }
    printf("List (backward): ");
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->prev;
    }
    printf("\n");
}
//count//
int countNodes() {
    int count = 0;
    Node* temp = head;
    while (temp != NULL) {
        count++;
        temp = temp->next;
    }
    return count;
}
void Displayboth(){
    displayBackward(head);
    displayForward(head);
}



// Main function to test the operations
int main() {
    
     int choice, data;

    while (1) {
        printf("\n--- Doubly Linked List Menu ---\n");
        printf("1. Insert at front\n");
        printf("2. Insert at end\n");
        printf("3. Delete from front\n");
        printf("4. Delete from end\n");
        printf("5. Display forward\n");
        printf("6. Display backward\n");
        printf("7. Count nodes\n");
        printf("8. display both way\n");
        printf("9. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter data to insert at front: ");
                scanf("%d", &data);
                insertFront( data);
                break;
            case 2:
                printf("Enter data to insert at end: ");
                scanf("%d", &data);
                insertEnd( data);
                break;
            case 3:
                deleteFront();
                break;
            case 4:
                deleteEnd();
                break;
            case 5:
                displayForward();
                break;
            case 6:
                displayBackward();
                break;
            case 7:
                printf("Number of nodes: %d\n", countNodes());
                break;
            case 8:
                Displayboth();
                break;  
            case 9:
                printf("Exiting program.\n");
                // Free memory before exit
                while (head != NULL) {
                    deleteFront();
                }
                exit(0);
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }

    return 0;
}

   
