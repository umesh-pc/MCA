#include <stdio.h>
#include <stdlib.h>

// ------------------ Node Structure ------------------
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

// ------------------ Queue Structure ------------------
#define SIZE 100

struct Queue {
    int front, rear;
    struct Node* arr[SIZE];
};

void initQueue(struct Queue* q) {
    q->front = q->rear = -1;
}

int isEmpty(struct Queue* q) {
    return q->front == -1;
}

void enqueue(struct Queue* q, struct Node* node) {
    if (q->rear == SIZE - 1) return;
    if (isEmpty(q)) q->front = 0;
    q->arr[++q->rear] = node;
}

struct Node* dequeue(struct Queue* q) {
    if (isEmpty(q)) return NULL;
    struct Node* temp = q->arr[q->front];
    if (q->front == q->rear)
        q->front = q->rear = -1;
    else
        q->front++;
    return temp;
}

// ------------------ Node Creation ------------------
struct Node* createNode(int data) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = data;
    node->left = node->right = NULL;
    return node;
}

// ------------------ Level Order Insertion ------------------
void insert(struct Node** root, int data) {
    struct Node* newNode = createNode(data);
    if (*root == NULL) {
        *root = newNode;
        return;
    }

    struct Queue q;
    initQueue(&q);
    enqueue(&q, *root);

    while (!isEmpty(&q)) {
        struct Node* temp = dequeue(&q);

        if (!temp->left) {
            temp->left = newNode;
            break;
        } else {
            enqueue(&q, temp->left);
        }

        if (!temp->right) {
            temp->right = newNode;
            break;
        } else {
            enqueue(&q, temp->right);
        }
    }
}

// ------------------ In-order Traversal ------------------
void inorder(struct Node* root) {
    if (root != NULL) {
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}
void preorder(struct Node*node){
    if(node!=NULL){
        printf("%d ",node->data);
        preorder(node->left);
        preorder(node->right);
    }
}
void postorder(struct Node*node){
    if(node!=NULL){
        postorder(node->left);
        postorder(node->right);
        printf("%d ",node->data);
    }
}

// ------------------ Delete a Node by Value ------------------
void deleteNode(struct Node** root, int key) {
    if (*root == NULL) return;

    struct Queue q;
    initQueue(&q);
    enqueue(&q, *root);

    struct Node *keyNode = NULL, *temp, *lastNode = NULL, *parentOfLast = NULL;

    while (!isEmpty(&q)) {
        temp = dequeue(&q);

        if (temp->data == key)
            keyNode = temp;

        if (temp->left) {
            parentOfLast = temp;
            enqueue(&q, temp->left);
        }

        if (temp->right) {
            parentOfLast = temp;
            enqueue(&q, temp->right);
        }

        lastNode = temp;
    }

    if (keyNode) {
        keyNode->data = lastNode->data;

        if (parentOfLast->right == lastNode) {
            free(parentOfLast->right);
            parentOfLast->right = NULL;
        } else if (parentOfLast->left == lastNode) {
            free(parentOfLast->left);
            parentOfLast->left = NULL;
        }
    } else {
        printf("Value %d not found in the tree.\n", key);
    }
}

// ------------------ Main ------------------
int main() {
    struct Node* root = NULL;
    int choice, value;

    while (1) {
        printf("\n--- Binary Tree Menu ---\n");
        printf("1. Insert\n");
        printf("2. In-order Traversal\n");
        printf("3. pre-order Traversal\n");
        printf("4. post-order Traversal\n");
        printf("5. Delete Node by Value\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to insert: ");
                scanf("%d", &value);
                insert(&root, value);
                break;

            case 2:
                printf("In-order traversal: ");
                inorder(root);
                printf("\n");
                break;
            case 3:
                printf("pre-order traversal: ");
               preorder(root);
                printf("\n");
                break;
            case 4:
                printf("post-order traversal: ");
                postorder(root);
                printf("\n");
                break;

            case 5:
                printf("Enter value to delete: ");
                scanf("%d", &value);
                deleteNode(&root, value);
                break;

            case 6:
                exit(0);

            default:
                printf("Invalid choice.\n");
        }
    }

    return 0;
}
