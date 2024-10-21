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
	
	if(head == NULL)
		head = nn;
		
	else{
		nn->next = head;
		head = nn;
	}
	
}
				
void insert_End(int val){
	
	struct node *nn = (struct node*)malloc(sizeof(struct node));
	nn->data = val;
	nn->next = NULL;
	
	if(head == NULL)
		head = nn;
	
	else{
		struct node *temp = head;
		
			while(temp->next != NULL)
				temp = temp->next;
				
			temp->next = nn;
		}
		
}
	
void insert_Before(int val, int pos){
	
	struct node *nn = (struct node*)malloc(sizeof(struct node));
	nn->data = val;
	nn->next = NULL;
	
	if(pos == 1)
		insert_Beg(val);
		
	else{
		
		struct node *ptr, *temp;
		
			ptr = head;
		
		while(pos > 1){
			
			temp = ptr;
			ptr = ptr->next;
			pos--;
			
		}
		
			temp->next = nn;
			nn->next = ptr;
			
	}
	
}


			
			
			
			
			
			
			
int delete_Beg(){
	
    if (head == NULL)
        printf("Empty Linked List");
        
    else{
		struct node *temp = head;
		
		head = head->next;
		free(temp);
			
	}
	
}
		
		
	
int delete_End(){
	
	 if (head == NULL)
        printf("Empty Linked List");
        
     else{
		 
		 struct node *temp,*ptr;
		 
			temp = head;
			
			while(temp->next != NULL){
				ptr = temp;
				temp = temp->next;
			}
			
			free(temp);
			ptr->next = NULL;
			
	}

}
				
			
	
int delete_Before(int pos){

	if (head == NULL)
        printf("Empty Linked List");
        
    else if(pos == 1)
		printf("\nInvalid Input");
		
	else if(pos == 2)
		delete_Beg();
        
    else{
		
		struct node *temp, *ptr;
		
		ptr = head;
		
		 while(pos > 2){
			 temp = ptr;
			 ptr = ptr->next;
			 pos--;
		}
		
		temp->next = ptr->next;
		free(ptr);
		
		
	}
}

void display(){


	struct node *ptr;
	
	if(head == NULL)
		printf("\nEmpty Linked List");
		
	else{
	ptr = head;
	
		while(ptr!=NULL){
			printf(" %d", ptr->data);
			
			ptr = ptr->next;
			
		}

	}
	
}

int count_Nodes(){
	int count = 0;
	struct node *ptr;
	
	if(head == NULL)
		printf("\nEmpty Linked List");
		
	else{
	ptr = head;
	
		while(ptr!=NULL){
			count++;
			
			ptr = ptr->next;
			
		}
	printf("\nCount of Nodes : %d ",count);
	}
	
}
	
int sort_Nodes(){
	while (1) {
        int swapped = 0;  
        struct node *temp = head;

     
        while (temp != NULL && temp->next != NULL) {
            
            if (temp->data > temp->next->data) {
                
                int tempData = temp->data;
                temp->data = temp->next->data;
                temp->next->data = tempData;
                swapped = 1;  
            }
            temp = temp->next;  
        }

        // If no swaps were made during the last pass, the list is sorted
        if (swapped == 0) {
            break;  // Exit the loop
        }
    }

    
    struct node *ptr = head;
    printf("\nSorted Linked List: \n");
    while (ptr != NULL) {
        printf(" %d", ptr->data);
        ptr = ptr->next;
    }
}
		
	
	
void search_Node(int val){
	
	if(head == NULL)
		printf("\nEmpty Linked List");
		
	else{
	struct node *ptr = head;
	
		while(ptr!=NULL){
			if(ptr->data == val){
				printf("%d is present in the list",ptr->data);
				break;
			}
		
			ptr = ptr->next;
			
		}
		printf("\nElement Not Present in List ");
		
	}
}


void insert_Node(int val){
	
	struct node *nn = (struct node*)malloc(sizeof(struct node));
	nn->data = val;
	nn->next = NULL;
	
		if(head == NULL)
			head = nn;
			
		else{
			struct node* temp = head; 
        while(temp -> next != NULL){
            temp = temp -> next; 
        }
        temp -> next = nn;
	}
	
}



int main(){
	
	int choice,value,pos,n;
	
	do{
	
		printf("\n\n---MENU---\n\n");
		printf("\n1.Insert at Beginning \n2.Insert at End \n3.Insert Before Specified Position \n4.Delete at Beginning \n5.Delete at End \n6.Delete Before Specified Position \n7.Display \n8.Count Nodes \n9.Sort Nodes \n10.Search Nodes \n11.Create Node\n0.Exit\n ");
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
						
				case 3: printf("\nEnter value to be inserted : ");
						scanf("%d",&value);
						printf("\nEnter Position : ");
						scanf("%d",&pos);
				
				
						insert_Before(value , pos);
						
						break;
						
				case 4:  delete_Beg();
				
						
				
						break;
							
				case 5: delete_End();
				
						
						
						break;
							
				case 6: printf("\nEnter Position : ");
						scanf("%d",&pos);
				
						 delete_Before(pos);
				
						
						
						break;
				
				case 7:  display();
				
						break;
						
				case 8:  count_Nodes();
				
						break;
						
				case 9:  sort_Nodes();
						break;
						
				case 10: printf("\nEnter value to be searched : ");
						 scanf("%d",&value);
				
						 search_Node(value);
						break;
						
				case 11:	printf("Enter the number of nodes you want to add to the linked list: \n");
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
