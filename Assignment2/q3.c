#include <stdio.h>
void update(int grows , int gcols,int array_grid[grows][gcols]);
void query(int grows , int gcols,int array_grid[grows][gcols]);
void diagnostics(int grows , int gcols,int array_grid[grows][gcols]);


int main() {
    int choice;

    printf("Welcome to IESCO Power Grid Monitoring System\n");
    printf("1. Update Sector Status\n");
    printf("2. Query Sector Status\n");
    printf("3. Run System Diagnostic\n");
    printf("4. Exit\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);
    int rows, cols;
    printf("Enter grid size (rows cols): ");
    scanf("%d %d", &rows, &cols);
    int grid[rows][cols];
		for(int i=0;i<rows;i++){
   			 for(int j=0;j<cols;j++){
        		grid[i][j] = 0;
			}
		}
    switch(choice) {
        case 1:
            printf("Update Sector Status selected.\n");
            update(rows , cols ,grid);
            break;
        case 2:
            printf("Query Sector Status selected.\n");
            query(rows , cols ,grid);
            break;
        case 3:
            printf("Run System Diagnostic selected.\n");
            diagnostics(rows , cols ,grid);
            break;
        case 4:
            printf("Exiting...\n");
            break;
        default:
            printf("Invalid choice.\n");
    }

    return 0;
}
void update(int grows , int gcols,int array_grid[grows][gcols]){
	int user_status , user_flag;
	int row , col;
	printf("Enter Status Flag : \n 1.Power \n2.Overload \n3.Maintanece \n  ");
	scanf("%d" , &user_status);
	printf("To Set press 1 ; To clear press 2:");
	scanf("%d" , &user_flag);
	printf("Enter sector row and column: "); 
    scanf("%d %d", &row, &col);
	switch(user_status) {
        case 1:
            printf("Power selected.\n");
            switch (user_flag){
            	case 1:
            		printf("Set Selected:");
            		array_grid[row][col] |= (1 << 0);
            		break;
            	case 2:
            		printf("Clear Selected:");
            		array_grid[row][col] &= ~(1 << 0);
            		break;
			}
            break;
        case 2:
            printf("Overload selected.\n");
            switch (user_flag){
            	case 1:
            		printf("Set Selected:");
            		array_grid[row][col] |= (1 << 1);
            		break;
            	case 2:
            		printf("Clear Selected:");
            		array_grid[row][col] &= ~(1 << 1);
            		break;
			}
            break;
        case 3:
            printf("maintanence selected.\n");
            switch (user_flag){
            	case 1:
            		printf("Set Selected:");
            		array_grid[row][col] |= (1 << 2);
            		break;
            	case 2:
            		printf("Clear Selected:");
            		array_grid[row][col] &= ~(1 << 2);
            		break;
			}
            break;
        default:
            printf("Invalid choice.\n");
    }
}
void query(int grows , int gcols ,int array_grid[grows][gcols] ){
	printf("Enter sector row and column: "); 
	int row , col ;
    scanf("%d %d", &row, &col);
    if(array_grid[row][col] & (1 << 0)){ 
	    printf("Power: ON\n");
		}
		else{
	    printf("Power: OFF\n");
		}
	if(array_grid[row][col] & (1<<1)){
		printf("Overload On \n");
	}else{
		printf("Overload Off \n");
	}
	if(array_grid[row][col] & (1<<2)){
		printf("Maintanence ON \n");
	}else{
		printf("Maintanence Off \n");
	}
}

void diagnostics(int grows, int gcols ,int array_grid[grows][gcols]){
    int count = 0;
    for(int i = 0 ; i < grows ; i++){
        for(int j = 0 ; j < gcols ; j++){
            if ((array_grid[i][j] & (1<<1)) || (array_grid[i][j] & (1<<2))){
                count = count + 1;
            }   
        }
    }
    printf("The total sectors which require overload or maintenance is %d\n", count);
}





