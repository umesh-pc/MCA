#include<stdio.h>
#include<stdlib.h>
# define size 5
int queue[size];
int front=-1,rear=-1;

int isfull(){
    return(front==(rear+1)%size);
}

int isempty(){
    return(front==-1);
}

void enqueue(int value){
    if(isfull()){
        printf("the queue is full,can't insert the value %d \n",value);
        return;
    }
    if(isempty()){
        front=rear=0;
    }
    else{
        rear=(rear+1)%size;
    }
    queue[rear]=value;
    printf("the value %d is inserted\n",value);
}

int dequeue(){
    if(isempty()){
        printf("the queue is empty,can't dequeue\n");
        return 0;
    }
    int value=queue[front];
    if(front==rear){
    front=rear=-1;
    }
    else{
        front=(front+1)%size;
    }
    printf(" dequeue %d from the queue\n",value);
    return value;
}
void display(){
    if(isempty()){
        printf("the queue is empty,can't dequeue\n");
        return;
    }
    printf("the elements of queue :\n");
    int i;
    i=front;
    while(1){
        printf("%d ",queue[i]);
        if(i==rear){
            break;
        }
        i=(i+1)%size;
    }
    printf("\n");
}

void count(){
     if(isempty()){
        printf("the queue is empty,can't dequeue\n");
        return ;
    }
    int count=0,i;
    i=front;
    while(1){
        count++;
        if(i==rear){
            break;
        }
        i=(i+1)%size;
    }
    printf("the no of element is : %d \n",count);
}

int main()
{
    int choice;
    int value;
    while (1) {
        printf("\n----- Circular Queue Menu -----\n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Display\n");
        printf("4. count\n");
        printf("4. exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the value to enqueue: ");
                scanf("%d", &value);
                enqueue(value);
                break;

            case 2:
                dequeue();
                break;

            case 3:
                display();
                break;
            case 4:
                count();
                break;
            case 5:
                printf("Exiting program.\n");
                exit(0);

            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;

}
