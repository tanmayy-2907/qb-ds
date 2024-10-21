#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define MAX 10

int stack[MAX] , top = -1;

void push(int val);
int pop();
int PostfixEval(char exp[]);

int main(){
	
	int value;
	char exp[MAX];
	
		printf("\nEnter Postfix Expression :");
		scanf("%s",exp);
		
		value = PostfixEval(exp);
			
		printf("Value Evaluated : %d", value);

	return 0;
	
}

int PostfixEval(char exp[]){
	
	int op1,op2,val;
	int i = 0;
	
	
		while(exp[i] != '\0'){
			
			if(isdigit(exp[i])){
				push(exp[i] - '0');
			}
			
			else{
				
				op2 = pop();
				op1 = pop();
				
				switch(exp[i]){
					
					case '+' : val = op1 + op2;
								break;
								
					case '-' : val = op1 - op2;
								break;
								
					case '*' : val = op1 * op2;
								break;
								
					case '/' : val = op1 / op2;
								break;
								
					case '%' : val = op1 % op2;
								break;
					
					default : printf("\nInvalid Value");
								break;
								
				}
				push(val);
				
			}
			i++;
			
			
			
}

return pop();

}

void push(int val){
	
	if(top == MAX-1)
		printf("\nStack Overflow");
		
	else
		stack[++top] = val;
		
}

int pop(){
	
	if(top==-1)
		printf("\nStack Underflow");
		
	else
		return stack[top--];
		
}

			
				
