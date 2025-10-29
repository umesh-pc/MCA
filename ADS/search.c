#include<stdio.h>

int n; //size of array

void bsearch(int *a,int item,int l,int h)
{
	if(l>h)
	{
		printf("Element not Found !!");
		return;
	}
	int m=(l+h)/2;
	if(a[m]==item)
		printf("Element at Found %d position!!",m+1);
	else if(a[m]>item)
		bsearch(a,item,l,m-1);
	else if(a[m]<item)
		bsearch(a,item,m+1,h);
}

void lsearch(int *a,int item)
{
	for(int i=0;i<n;i++)
		if(a[i]==item)
		{
			printf("Element at Found %d position !!",i+1);
			return;
		}
		
	printf("Element NOT Found!!");
}

void read(int *a)
{
	printf("Enter size of your array followed by the elements :");
	scanf("%d",&n);
	for(int i=0;i<n;i++)
		scanf("%d",&a[i]);
}

void main()
{
	int c=1,a[20],x;
	while(c)
	{
		printf("\n==================\nEnter your choice :\n1.Binary Search\n2.Linear Search\n0.Exit\n?:");
		scanf("%d",&c);
		switch(c)
		{
			case 1: printf("Enter Array in Sorted Order\n");
				read(a);
				printf("Search Elemet ?:");
				scanf("%d",&x);
				bsearch(a,x,0,n);
				break;
			case 2:read(a);
				printf("Search Elemet ?:");
				scanf("%d",&x);
				lsearch(a,x);
				break;
		}
	}
}
