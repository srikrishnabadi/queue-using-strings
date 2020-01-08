/* A program for circular queue of strings using an array */
#include<stdlib.h>
#include<stdio.h>
#include<string.h>
#define MAX 10

typedef struct Q
{
	int R,F;
	char *data[MAX];
}Q;

void initialise(Q *P);
int empty(Q *P);
int full(Q *P);
void enqueue(Q *P,char *x);
char * dequeue(Q *P);
void print(Q *P);
int main()
{	Q q;
       int op;
       char x[40],*y;
     initialise(&q);
        do{
	printf("\n1)Insert\n2)Delete\n3)Print\n4)Quit");
	printf("\nEnter Your Choice:");
	scanf("%d",&op);
	switch(op)
	 { case 1: printf("\nEnter string: ");

		    fflush(stdin);
		    scanf("%s",x);
		    if(!full(&q))
			{
				y=(char*)malloc(strlen(x)+1);
				strcpy(y,x);
				enqueue(&q,y);
			}
		    else
			printf("\nQueue is full !!!!");


		   break;
	   case 2:if(!empty(&q))
		    {
			y=dequeue(&q);
			printf("\nDeleted Data=%s",y);
		    }
		   else
			printf("\nQueue is empty !!!!");
		   break;
	   case 3: print(&q);
	   break;
	}
      }while(op!=4);
}

void initialise(Q *P)
{
	int i;
	for(i=0;i<MAX;i++)
		P->data[i]=NULL;
	P->R=-1;
	P->F=-1;
}

int empty(Q *P)
{
	if(P->R==-1)
		return(1);
	return(0);
}

int full(Q *P)
{
	if((P->R+1)%MAX==P->F)
		return(1);
	return(0);
}

void enqueue(Q *P,char *x)
{
	if(P->R==-1)
	{
		P->R=P->F=0;
		if(P->data[P->R]!=NULL)
			free(P->data[P->R]);
		P->data[P->R]=x;
	}
	else
	{
		P->R=(P->R+1)%MAX;
		if(P->data[P->R]!=NULL)
			free(P->data[P->R]);
		P->data[P->R]=x;
	}
}

char * dequeue(Q *P)
{
	char *x;
	x=P->data[P->F];
	if(P->R==P->F)
	{
		P->R=-1;
		P->F=-1;
	}
	else
		P->F=(P->F+1)%MAX;
	return(x);
}

void print(Q *P)
{
	int i;
	if(!empty(P))
	{
		printf("\n");
		for(i=P->F;i!=P->R;i=(i+1)%MAX)
			printf("%s\t",P->data[i]);
	}
       printf("%s\t\n",P->data[i]);
}
