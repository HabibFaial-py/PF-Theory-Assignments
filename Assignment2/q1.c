#include <stdio.h>
int AddNewBook(int isbns[], char titles[][50], float prices[], int quantities[], int bookCount );
void ProcessSale(int isbns[], char titles[][50], float prices[], int quantities[], int bookCount);
void GenerateLowStock(int isbns[], char titles[][50], float prices[], int quantities[], int bookCount);
int main(){
	int isbns[100];
	char titles[100][50];
	float prices[100];
	int quantities[100];
	int user_input;
	int bookCount = 0;
	
	printf("Enter a Number to Begin:\n");
    printf("1. Add New Book\n");
    printf("2. Process a Sale\n");
    printf("3. Generate Low-Stock Report\n");
    printf("Enter your choice: ");
    scanf("%d", &user_input);
    
    switch (user_input) {
        case 1:
            bookCount = AddNewBook(isbns, titles, prices, quantities, bookCount);
            printf("\nTotal Books in Inventory: %d\n", bookCount); 
            break;

        case 2:
            ProcessSale(isbns, titles, prices, quantities, bookCount);
            break;

        case 3:
        	GenerateLowStock(isbns, titles, prices, quantities, bookCount);
            break;

        default:
            printf("Invalid Option! Please try again.\n");
    }

    return 0;
}

// AddNewFunction
int AddNewBook(int isbns[], char titles[][50], float prices[], int quantities[], int bookCount){
	if(bookCount >= 100){
		printf("Inventory Full");
		return bookCount;
	}
  	int newIsbn;
    char newTitle[50];
    float newPrice;
    int newQuantity;
    int duplicate = 0;
    
	printf("Enter ISBN: ");
	scanf("%d" , &newIsbn);
	for(int i = 0 ; i<100 ; i++){
		if (isbns[i] == newIsbn){
			int duplicate = 1;	
		}
	}
	if (duplicate!=0){
		printf("Invalid ISBN");
		return bookCount;
	}
	 printf("Enter Title (single word): ");
    scanf("%s", newTitle);  

    printf("Enter Price: ");
    scanf("%f", &newPrice);

    printf("Enter Quantity: ");
    scanf("%d", &newQuantity);

    isbns[bookCount] = newIsbn;
    prices[bookCount] = newPrice;
    quantities[bookCount] = newQuantity;

    printf("Book added successfully!\n");

    return bookCount + 1;
}

void ProcessSale(int isbns[], char titles[][50], float prices[], int quantities[], int bookCount){
	int userisbn , user_quantity;
	int found = 0;
	
	printf("Enter ISBN: ");
	scanf("%d" , &userisbn);
	
	printf("Enter Quantity: ");
	scanf("%d" , &user_quantity);
	
	for(int i = 0 ; i < bookCount ; i++){
		if(isbns[i] == userisbn){
			found = 1;
			if(quantities[i] >= user_quantity){
				quantities[i] = quantities[i] - user_quantity;
				printf("Sale Processed Successfully\n");
				printf("Remaining Stock: %d\n", quantities[i]);
			}
			else{
				printf("Books Not Available (Only %d left)\n", quantities[i]);
			}
			break;
		}
	}
	if(found == 0){
		printf("Enter Correct ISBN\n");
	}
}
void GenerateLowStock(int isbns[], char titles[][50], float prices[], int quantities[], int bookCount){
	for(int i = 0; i < bookCount; i++){
		if(quantities[i] < 5){
			printf("ISBN: %d\n", isbns[i]);
			printf("Title: %s\n", titles[i]);
			printf("Price: %.2f\n", prices[i]);
			printf("Quantity: %d\n", quantities[i]);
			printf("--------------------------\n");
		}
	}
}

