#include<stdio.h>
#include<stdlib.h>
struct node{
	int info;
	struct node *next;
	};
struct node *temp,*head,*top;
int nodecount=0;
void createstack();
void push();
void pop();
void traverse();
void count();
int main(){
	int ch;
	createstack();
	do{
	    printf("\n 1.TRAVERSE\t 2.PUSH\t 3.POP\t 4.COUNT\t 5.EXIT\n");
	    printf("Enter your choice: ");
	    scanf("%d", &ch);
	    switch(ch){
	    	        case 1: traverse();
	    	        	break;
	    	        case 2: push();
	    	        	break;
	    	        case 3: pop();
	    	        	break;
	    	        case 4: count();
	    	        	break;
	    	        case 5: return 0;
	    	        default: printf("\n Invalid Choice\n");
	    	      }
		}
	     while(ch!=5);
	     return 0;	
       }
void createstack(){
		top=NULL;
		printf("Stack created succcessfully.\n");		
	     }
void traverse(){
	       if(top==NULL){
	       		    printf("\n List is empty.\n");
	       		    return;
	       }
	        temp = top;
	        printf("The Elements are ");
	        while(temp!=NULL){
	        		 printf("%d\t",temp->info);
	        		 temp=temp->next;
	        	      }	
	        	      printf("\n");
	}
void push(){
	head=(struct node *)malloc(sizeof(struct node));
	printf("Enter the data item: ");
	scanf("%d", &head->info);
	head->next=top;
	top=head;
	nodecount++;	
  }
void pop(){
	  if(top==NULL){
	  		printf("\n List is Empty");
	  		return;
	  	}
	  	int item;
	  	temp=top;
	  	item=top->info;
	  	top=top->next;
	  	free(temp);
	  	nodecount--;
	  	printf("%d deleted successfully.\n",item);
	  }
void count(){
	    if(top==NULL){
	    		printf("\n List is empty");
	    		return;
	    	   }
	    	   printf("Total number of nodes:%d\n",nodecount);
	   }
	

