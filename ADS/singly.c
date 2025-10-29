#include<stdio.h>
#include<stdlib.h>
struct node{
	int info;
	struct node *next;
};
struct node *start=NULL ,*temp,*head;
int nodecount=0;
void createlist();
//void addtoempty();
void traverse();
void insertp();
void deletenode();
void count();
int main(void){
	int ch;
	createlist();
	do{
	   printf("\n 1.TRAVERSE\t 2.INSERTION\t 3.DELETION\t 4.COUNT\t 5.EXIT\n");
	   printf("Enter your choice\n");
	   scanf("%d", &ch);
	   switch(ch){
		      case 1 : traverse();
	 			break;
		      case 2 : insertp();
	                        break;
		      case 3 : deletenode();
				 break;
		      case 4 : count();
	 			break;
		      case 5 : return(0);
		      default: printf("Invalid choice\n");

	}
      }while(ch!=5);
      return(0);
}

void createlist(){
	int ch=1;
	while(ch){
		if(start==NULL)	{
			head=(struct node*)malloc(sizeof(struct node));
			printf("Enter the data item: ");
			scanf("%d", &head->info);
			head->next=NULL;
			start=head;
			nodecount++;
			}
		else{
			head=new node;
			printf("Enter the data item: ");
			scanf("%d", &head->info);
			temp=start;
			while(temp->next!=NULL) {
				temp=temp->next;
			     }
			temp->next=head;
			head->next=NULL;
			nodecount++;
			}
		printf("Press<0 for exit> <1 for continue>");
		scanf("%d",&ch); 
	}
  }
  
void insertp(){
	int pos;
	printf("Enter the position to insert: ");
	scanf("%d",&pos);
	if(pos>nodecount+1 || pos==0){
		printf("Insertion not possible");
		return;
	}
	temp=start;
	for(int i=1;i<pos-1;i++){
		temp=temp->next;
	}
	head=(struct node*)malloc(sizeof(struct node));
	printf("Enter the data item: ");
	scanf("%d",&head->info);
	head->next=temp->next;
	temp->next = head;
	nodecount++;
  }
  
void traverse(){
	if (start==NULL){
		printf("\n List is Empty");
		return;
	}
	temp=start;
	printf("The Elements are ");
	while(temp!=NULL){
		printf("%d\t",temp->info);
		temp=temp->next;
	}
  }
  
void count(){
	if (start==NULL){
		printf("\n List is Empty");
		return;
	}
	printf("Total No. of Nodes: %d\n",nodecount);
  }
void deletenode(){
	if (start==NULL){
		printf("\n List is Empty");
		return;
	}
	int item;
	printf("Enter the item to delete: ");
	scanf("%d",&item);
	if(start->info==item){
		temp=start;
		start=start->next;
		free(temp);
		nodecount--;
	return;
       }
       temp=start;
       while(temp->next!=NULL){
	 if(temp->next->info==item){
	 head=temp->next;
	 temp->next=head->next;
	 free(head);
	 nodecount--;
	return;
       }
     temp=temp->next;
   }
  printf("\n Item Not Found");
}

