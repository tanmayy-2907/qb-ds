#include <stdio.h>
#include <stdlib.h>

struct node{
	int data;
	struct node *next;
	
};

struct node *top = NULL;
struct node *nn = NULL;

int isEmpty(){
	
	return top == NULL;
	
}

void push(int value){
	
	struct node *nn = (struct node*)malloc(sizeof(struct node));
	nn->data = value;
	nn->next = NULL;
	
		if(isEmpty())
			top = nn;
			
		else{
			
			nn -> next = top;
			top = nn;
		}
		
}
	
int pop(){
	
	struct node *temp = top;
	
		top = top->next;
		return temp->data;
		
		free(temp);
}

int peek(){
	
	return top->data;
	
}

void display(){
	
	struct node *temp = top;
	
		while(temp!=NULL){
			printf("\n%d",temp->data);
			temp = temp->next;
		}
		
}


			 


int main(){
	
	int choice, num;
	
	do{
		printf("\n\n---MENU---\n");
		printf("\n1.Push \n2.Pop \n3.Peek \n4.Display \n0.Exit");
		printf("\n\nEnter Your Choice : ");
		scanf("%d", &choice);
		
		
			switch(choice){
				
				case 0: printf("\nExiting...");
						break;
						
				case 1:	printf("\nEnter Value : ");
						scanf("%d", &num);
						
				
						push(num);
								
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
						
				
						
				default: printf("\nInvalid Input");
						 break;
						 
			}
			
	}while(choice!=0);
	

return 0;

}
