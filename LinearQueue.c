#include<stdio.h>
#define MAX 5

int queue[MAX];
int front = -1, rear = -1;

int isEmpty(){
	
	if(rear == -1)
		return 1;
		
	else 
		return 0;
		
}

int isFull(){
	
	if(rear == MAX-1)
		return 1;
		
	else
		return 0;
		
}

void enqueue(){
	
	int element;
	
	printf("\nEnter Element to be Enqueued : ");
	scanf("%d", &element);
		
		if(isEmpty()){
			front = rear = 0;
			queue[rear] = element;
		}
		
		else{
			queue[++rear] = element;
		}
			
}

void dequeue(){
	
	int val;
	
	if(front == rear){
		val = queue[front];
		front = rear = -1;
	}
	
	else
		val = queue[front++];
		
	printf("\nValue Dequeued : %d", val);
		
}

int peek(){
	
	return queue[front];
	
}

void display(){
	
	int count = 0, i;
	
		for( i = front; i <= rear; i++){
			
			printf("  %d",queue[i]);
			count++;
			
		}
		printf("\nNo of Elements in Queue : %d ",count);
		
}




int main(){
	
	int choice;
	
	do{
	
		printf("\n\n---MENU---\n\n");
		printf("\n1.Enqueue \n2.Dequeue \n3.Front \n4.Display \n5.IsEmpty \n6.IsFull \n0.Exit\n ");
		printf("\nEnter your choice : ");
		scanf("%d", &choice);
		
			switch(choice){
				
				case 1: if(isFull())
							printf("\Queue Overflow");
						
						else 
							enqueue();
							
						break;
						
				case 2: if(isEmpty())
							printf("\Queue Underflow");
						
						else 
							dequeue();
							
						break;
						
				case 3: if(isEmpty())
							printf("\Queue Underflow");
						
						else{
							int num = peek();
							printf("\nValue at Front : %d",num);
						}
						
						break;
						
				case 4: display();
						break;
							
				case 5: if(isEmpty())
							printf("\nQueue is Empty ");
							
						else
							printf("\nQueue is not Empty ");
							
						break;
							
				case 6: if(isFull())
							printf("\nQueue is Full ");
							
						else
							printf("\nQueue is not Full ");
							
						break;
							
				case 0: printf("Exiting...");
						break;
						
				default: printf("\nInvalid Input " );
						 break;
						 
			}
			
		}while(choice!= 0);
		
	return 0;
	
}
						

