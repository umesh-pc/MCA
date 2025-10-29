#include <stdio.h>
#include <stdlib.h>


struct Node {
    int data;
    struct Node* next;
};

struct Node* top = NULL;


void push(int value) {
    struct Node* newNode = (struct Node*) malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Stack Overflow!\n");
        return;
    }
    newNode->data = value;
    newNode->next = top;
    top = newNode;
    printf("Pushed %d onto the stack.\n", value);
}


void pop() {
    if (top == NULL) {
        printf("Stack Underflow! Cannot pop from an empty stack.\n");
        return;
    }
    struct Node* temp = top;
    printf("Popped %d from the stack.\n", top->data);
    top = top->next;
    free(temp);
}


int count() {
    int cnt = 0;
    struct Node* temp = top;
    while (temp != NULL) {
        cnt++;
        temp = temp->next;
    }
    return cnt;
}


void traverse() {
    if (top == NULL) {
        printf("Stack is empty.\n");
        return;
    }
    struct Node* temp = top;
    printf("Stack elements (top to bottom): ");
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}


int main() {
    int choice, value;

    while (1) {
        printf("\n--- Stack Menu ---\n");
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Count\n");
        printf("4. Traverse\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to push: ");
                scanf("%d", &value);
                push(value);
                break;

            case 2:
                pop();
                break;

            case 3:
                printf("Total elements in stack: %d\n", count());
                break;

            case 4:
                traverse();
                break;

            case 5:
                printf("Exiting program.\n");
                exit(0);

            default:
                printf("Invalid choice! Please try again.\n");
        }
    }

    return 0;
}

