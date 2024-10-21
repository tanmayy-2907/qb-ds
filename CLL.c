#include <stdio.h>
#include <stdlib.h>

struct node{
	
	int data;
	struct node *next;
	
};

struct node *head = NULL;
struct node *nn = NULL;

void insert_Beg(int val){
	
	struct node *nn = (struct node*)malloc(sizeof(struct node));
	nn->data = val;
	nn->next = NULL;
	
	if(head == NULL){
		
		
		head = nn;
		nn->next = head;
		
	}
		
	else{
		 		
		struct node *temp = head;
		
			while(temp->next!= head)
				temp = temp->next;
			
			nn->next = head;	
			temp->next = nn;
			
			
		head = nn;
		
	}
	
}
				
void insert_End(int val){
	
	struct node *nn = (struct node*)malloc(sizeof(struct node));
	nn->data = val;
	nn->next = NULL;
	
	if(head == NULL){
		head = nn;
		nn->next = head;
	}
	else{
		struct node *temp = head;
		
			while(temp->next != head)
				temp = temp->next;
				
			temp->next = nn;
			nn->next = head;
		}
		
}
			
			
			
			
int delete_Beg(){
	
    if (head == NULL)
		printf("Empty Linked List");
        
    else if(head->next == head){
		
		struct node *temp = head;
		
			head = NULL;
			free(temp);
		}
			
	else{
		
		struct node *temp = head;
		
		while(temp->next != head)
			temp = temp->next;
		
		temp->next = head->next;
		free(head);
		head = temp->next;
		
	
	}	
}
	

		
		
	
int delete_End(){
	
	 if (head == NULL)
        printf("Empty Linked List");
        
     else if(head->next == head){
		
		struct node *temp = head;
		
			head = NULL;
			free(temp);
		}   
        
     else{
		 
		 struct node *temp,*ptr;
		 
			temp = head;
			
			while(temp->next != head){
				ptr = temp;
				temp = temp->next;
			}
			
			ptr->next = temp->next;
			free(temp);
			
			
	}

}
				
			
	


void display(){


	struct node *ptr;
	
	if(head == NULL)
		printf("\nEmpty Linked List");
		
	else{
	ptr = head;
	
		do{
			printf(" %d", ptr->data);
			ptr = ptr->next;
			
		}while(ptr!=head);
	}
	
}

int count_Nodes(){
	int count = 0;
	struct node *ptr;
	
	if(head == NULL)
		printf("\nEmpty Linked List");
		
	else{
	ptr = head;
	
		while(ptr->next != head){
			count++;
			
			ptr = ptr->next;
			
		}
		count++;
	printf("\nCount of Nodes : %d ",count);
	}
	
}
	



void insert_Node(int val){
	
	struct node *nn = (struct node*)malloc(sizeof(struct node));
	nn->data = val;
	nn->next = NULL;
	
	if(head == NULL){
		head = nn;
		nn->next = head;
	}
	else{
		struct node *temp = head;
		
			while(temp->next != head)
				temp = temp->next;
				
			temp->next = nn;
			nn->next = head;
		}
}



int main(){
	
	int choice,value,pos,n;
	
	do{
	
		printf("\n\n---MENU---\n\n");
		printf("\n1.Insert at Beginning \n2.Insert at End\n3.Delete at Beginning \n4.Delete at End\n5.Display \n6.Count Nodes\n7.Create Node\n0.Exit\n ");
		printf("\nEnter your choice : ");
		scanf("%d", &choice);
		
			switch(choice){
				
				case 1: printf("\nEnter value to be inserted : ");
						scanf("%d",&value);
				
				
						insert_Beg(value);
							
						break;
						
				case 2: printf("\nEnter value to be inserted : ");
						scanf("%d",&value);
				
				
						insert_End(value);
							
						break;
						
				
						
				case 3:  delete_Beg();
				
						
				
						break;
							
				case 4: delete_End();
				
						
						
						break;
							
				
				
				case 5:  display();
				
						break;
						
				case 6:  count_Nodes();
				
						break;
						
				
						
				case 7:	printf("Enter the number of nodes you want to add to the linked list: \n");
							scanf("%d", &n);
							for(int i = 0; i < n; i++){
							
							printf("Enter the data for the %d node: \n", i + 1);
							scanf("%d", &value);
						
							insert_Node(value);
						}
						break;
							
				case 0: printf("Exiting...");
						break;
						
				default: printf("\nInvalid Input " );
						 break;
						 
			}
			
		}while(choice!= 0);
		
	return 0;
	
}
