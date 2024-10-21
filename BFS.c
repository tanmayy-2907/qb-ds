#include<stdio.h>
#define MAX 10
int graph[MAX][MAX], queue[MAX], varray[MAX], n, front=-1,rear=-1;

int isFull()
{
    if(rear==MAX -1)
        return 1;
    else
        return 0;
}
int isEmpty()
{
    if(front==-1 || front>rear)
        return 1;
    else
        return 0;
}
void enqueue(int value)
{
    if(isFull())
        printf("queue is full\n");
    else
    {
        queue[++rear]=value;
        if(front==-1)
            front=0;
    }
}
int dequeue()
{
    if(isEmpty())
        printf("queue is empty\n");
    else
    {
        printf("%c\n",queue[front]+65);
        return(queue[front++]);
    }
}

void BFS()
{
    int start,i,j;
    printf("Enter the node to begin BFS from: ");
    scanf("%d",&start);
    enqueue(start);
    varray[start]=1;
    i = dequeue();
    do
    {
        for(j=0;j<n;j++)
        {
            if(graph[i][j]==1 && varray[j]==0)
            {
                enqueue(j);
                varray[j]=1;
            }

        }
        i=dequeue();
    }while(!isEmpty());

}

void main()
{
    int i,j,x;
    printf("Enter the number of nodes: ");
    scanf("%d",&n);
    for(i=0;i<n;i++)
        varray[i]=0;
    printf("Enter the adjacency matrix\n");
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
            scanf("%d",&graph[i][j]);
    }
    BFS();
}
