#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>

#define MAX 10

char stack[MAX];
int top=-1;

int isEmpty(){
	
	return top==-1;
	
}

int isFull(){
	
	return top==MAX-1;
		
}

void push(char oper){
	
	if(isFull())
		printf("\nStack Overflow");
		
	else
		stack[++top] = oper;
		
}

char pop(){
	
	if(isEmpty())
		return 0;
		
	else{
		char ch = stack[top--];
		return ch;
	}
	
}

char peek(){
	
	return stack[top];
	
}

int precedence(char ch){
	
	switch(ch){
		
		case '+':
		case '-':
				return 1;
				
		case '*':
		case '/':
				return 2;
				
		case '^':
				return 3;
	}

return -1;

}

void InfixToPostfix(char *expr){
		
		char pexpr[MAX];
		int i,j;
		
			for(i=0,j=-1; i<strlen(expr); ++i){
				
				if(isalnum(expr[i]))
					pexpr[++j] = expr[i];
				
				
				else if(expr[i] == '(' || expr[i] == '[' || expr[i] == '{')
					push(expr[i]);
					
				else if(expr[i] == ')' || expr[i] == ']' || expr[i] == '}'){
					
					if(expr[i] == ')'){
						
						while(!isEmpty() && peek()!= '(')
								pexpr[++j] = pop();
						}
						pop();
						
					if(expr[i] == '}'){
						
						while(!isEmpty() && peek()!= '{')
								pexpr[++j] = pop();
						}
						pop();
						
					if(expr[i] == ']'){
						
						while(!isEmpty() && peek()!= '[')
								pexpr[++j] = pop();
						}
						pop();
						
				}
				
				else{
					while(!isEmpty() && precedence(peek()) >= precedence(expr[i])){
						pexpr[++j] = pop();
					}
					push(expr[i]);
				}
			}
			
			while(!isEmpty())
				pexpr[++j] = pop();
				
				
				printf("\nInfix Expression : %s", expr);
				printf("\nPostfix Expression : %s", pexpr);
				
	}
						

int main(){
	
	char expr[MAX];
	
		printf("\nEnter Infix Expression : ");
		scanf("%s",&expr);
		
		InfixToPostfix(expr);
		
			
return 0;
}

