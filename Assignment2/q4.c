#include <stdio.h>
void push(int stack[], int top, int maxSize);
void pop(int stack[], int top);
void peek(int stack[], int top);
void display(int stack[], int top);
int main(){
	int MAX = 5;
    int stack[MAX];
    int top = -1;
    int choice;
        printf("\n--- STACK MENU ---\n");
        printf("1. Push\n2. Pop\n3. Peek\n4. Display\n5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
        	case 1:
                push(stack, top, MAX);
                break;
        	case 2:
                pop(stack, top);
                break;
        	case 3:
                peek(stack, top);
                break;
        	case 4:
                display(stack, top);
                break;
        	case 5:
                printf("Exiting...\n");
                break;
        	default:
                printf("Invalid choice!\n");
        }

    return 0;
}

void push(int stack[], int top, int maxSize){
	printf("Enter number to push");
	int user_input;
	scanf("%d" , user_input);
	if(top == maxSize-1){
		printf("No Space in the Stack.");
	}else{
		top = top + 1;
		stack[top] = user_input;
		printf("Pushed Successfully");
	}
}
void pop(int stack[], int top){
	if(top == -1){
		printf("No Element");
	}
	else{
		printf("Printed Element is %d" , stack[top]);
		top = top - 1;
	}
}
void peek(int stack[], int top) {
    if (top == -1) {
        printf("Stack is empty.\n");
    } else {
        printf("Top element is: %d\n", stack[top]);
    }
}
void display(int stack[] , int top){
	if (top == -1) {
    	printf("Stack is empty.\n");
    }
    else{
    	printf("Stack elements (top to bottom): ");
    	for(int i = top ; i<0 ; i++){
    		printf("%d" , stack[i]);
		}
		printf("\n");
	}
}
