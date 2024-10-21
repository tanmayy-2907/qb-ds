#include <stdio.h>
#define MAX 5

int stack[MAX], top=-1;

	void push();
	int pop();
	int peek();
	void display();
	int isFull();
	int isEmpty();
	
	
int main(){
	
	int choice, num;
	
	do{
		printf("\n\n---MENU---\n");
		printf("\n1.Push \n2.Pop \n3.Peek \n4.Display \n5.IsEmpty \n6.IsFull \n0.Exit");
		printf("\n\nEnter Your Choice : ");
		scanf("%d", &choice);
		
		
			switch(choice){
				
				case 0: printf("\nExiting...");
						break;
						
				case 1: if(isFull())
							printf("\nStack Overflow");
							
						else
							push();
							
						break;
						
				case 2: if(isEmpty())
							printf("\nStack Underflow");
							
						else{
							num = pop();
							printf("\nValue Popped from stack : %d ",num);
						}
							
						break;
						
				case 3: if(isEmpty())
							printf("\nStack Underflow");
							
						else{
							
							num = peek();
							printf("\nElement at Top of Stack : %d",num);
							
						}
							
						break;
							
				case 4: if(isEmpty())
							printf("\nStack Underflow");
							
						else
							display();
							
						break;
						
				case 5: if(isEmpty())
							printf("\nStack Underflow");
						
						else
							printf("\nNot Empty");
						
						break;
						
				case 6: if(isFull())
							printf("\nStack Overflow");
						
						else
							printf("\nNot Full");
						
						break;
						
				default: printf("\nInvalid Input");
						 break;
						 
			}
			
	}while(choice!=0);
	

return 0;

}

void push(){
	
	int element;
	
		printf("\nEnter Element to be inserted : ");
		scanf("%d",&element);
		
			stack[++top] = element;
			
}

int pop(){
	
	return stack[top--];
	
}

int peek(){
	
	return stack[top];
	
}

void display(){
	
	printf("\nFollowing Elements are present in Stack : \n");
	
	
	 for(int i = top; i>=0; i--){
		 
			printf("\n%d",stack[i]);
			
	 }
	 
}

int isEmpty(){
	
	if(top == -1)
		return 1;
		
	else
		return 0;
		
}

int isFull(){
	
	if(top == MAX-1)
		return 1;
	
	else 
		return 0;
		
}
		

	 
	

	
	
			
							
							
						
