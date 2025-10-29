#include <stdlib.h>

// Node structure
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

// Create new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode-&gt;data = data;
    newNode-&gt;left = newNode-&gt;right = NULL;
    return newNode;
}

// Queue for level order
#define MAX 100
struct Node* queue[MAX];
int front = -1, rear = -1;

void enqueue(struct Node* node) {
    if (rear == MAX - 1) return;
    queue[++rear] = node;
    if (front == -1) front = 0;
}

struct Node* dequeue() {
    if (front == -1 || front &gt; rear) return NULL;
    return queue[front++];
}

int isQueueEmpty() {
    return front == -1 || front &gt; rear;
}

// Insert node in level order
void insert(struct Node** root, int data) {
    struct Node* newNode = createNode(data);
    if (*root == NULL) {
        *root = newNode;
        return;
    }

    // Reset queue
    front = rear = -1;
    enqueue(*root);

    while (!isQueueEmpty()) {
        struct Node* temp = dequeue();

        if (temp-&gt;left == NULL) {
            temp-&gt;left = newNode;
            return;
        } else {
            enqueue(temp-&gt;left);
        }

        if (temp-&gt;right == NULL) {
            temp-&gt;right = newNode;
            return;
        } else {
            enqueue(temp-&gt;right);
        }
    }
}

// Traversals
void inorder(struct Node* root) {
    if (root == NULL) return;
    inorder(root-&gt;left);
    printf("%d ", root-&gt;data);
    inorder(root-&gt;right);
}

void preorder(struct Node* root) {
    if (root == NULL) return;
    printf("%d ", root-&gt;data);
    preorder(root-&gt;left);
    preorder(root-&gt;right);
}

void postorder(struct Node* root) {
    if (root == NULL) return;
    postorder(root-&gt;left);
    postorder(root-&gt;right);
    printf("%d ", root-&gt;data);
}

void printMenu() {
    printf("\n--- Binary Tree Operations ---\n");
    printf("1. Insert Node\n");
    printf("2. Inorder Traversal\n");
    printf("3. Preorder Traversal\n");
    printf("4. Postorder Traversal\n");
    printf("5. Exit\n");
    printf("Enter your choice: ");
}

int main() {
    struct Node* root = NULL;
    int choice, val;

    while (1) {
        printMenu();
        scanf("%d", &amp;choice);

        switch (choice) {
            case 1:
                printf("Enter value to insert: ");
                scanf("%d", &amp;val);
                insert(&amp;root, val);
                printf("Node inserted.\n");
                break;

            case 2:
                printf("Inorder Traversal: ");
                inorder(root);
                printf("\n");
                break;

            case 3:
                printf("Preorder Traversal: ");
                preorder(root);
                printf("\n");
                break;

            case 4:
                printf("Postorder Traversal: ");
                postorder(root);
                printf("\n");
                break;

            

            case 5:
                printf("Exiting...\n");
                exit(0);

            default:
                printf("Invalid choice! Try again.\n");
        }
    }

    return 0;
}