#include <stdio.h>
void EnterCustomerInfo(char name[], char cnic[]);
void DisplayInventory(int productIds[] , int stock[] , int prices[] , int n);
void updateInventory(int productIds[], int stock[] , int n);
void updatecart(int productIds[] , int cartquantity[] , int stock[] , int n);
void DisplayBill(int productIds[] , int prices[] , int cartquantity[] , int n);
void ShowInvoice(char name[], char cnic[], int productIds[],
                 int prices[], int n, float total, float discountedTotal);
                 
int main(){
	printf("1. Enter Customer Info\n2. Display Inventory\n3. Add to Cart\n4. Calculate Bill\n5. Show Invoice\n");
    scanf("%d", &choice);

    switch (choice) {
        case 1: EnterCustomerInfo(name, cnic); break;
        case 2: DisplayInventory(productIds, prices, stock, n); break;
        case 3: updateInventory(productIds,  stock, n); break;
        case 4: updatecart(productIds , cartquantity , stock , n );break;
        case 4: DisplayBill(productIds, cartquantity ,prices, n); break;
        case 5: ShowInvoice(name, cnic, productIds, prices, n , total , discountedTotal); break;
        default: printf("Invalid choice \n");break;
    }
	return 0;
}

void EnterCustomerInfo(char name[], char cnic[]){
	char user_name , user_cnic;
	printf("Enter Name and CNIC number: ");
	scanf("%s" , user_name);
	scanf("%s" , user_cnic);
}

void DisplayInventory(int productIds[] , int stock[] , int prices[] , int n){
		for(int i = 0 ; productId	s[i]<n ; i++){
		printf("%d \t %d \t %.2f " , productIds[i] , stock[i] , prices[i]);
	}
}

void updateInventory(int productIds[], int stock[] , int n){
	printf("Enter Product ID to update: ");
    scanf("%d", &id);
    found = -1;

    for (int i = 0; i < n; i++) {
        if (productIds[i] == id) {
            found = i;
            break;
        }
    }
    if (found == -1) {
        printf("Product ID not found!\n");
        return;
    }
    
    printf("Enter quantity purchased: ");
    scanf("%d", &quantity);
    
    if (quantity>stock[found]){
    	printf("? Not enough stock! Available: %d\n", stock[found]);
	}
	else{
		stock[found] = quantity - stock[found];
		printf("Inventory Updated Successfully : Remaning Books %d" , stock[found]);
	}
}

void updatecart(int productIds[] , int cartquantity[] , int stock[] , int n){
	int id  , quantity;
	printf("Enter id and quantity");
	scanf("%d" , id);
	scanf("%d" , quantity);
	found = -1
	for (int i = 0; i < n; i++) {
        if (productIds[i] == id) {
            found = i;
            break;
        }
    }

    if (found == -1) {
        printf("? Product not found!\n");
        return;
    }

    printf("Enter quantity to add: ");
    scanf("%d", &quantity);

    if (quantity > stock[found]) {
        printf("? Not enough stock! Available: %d\n", stock[found]);
    } 
	else {
        cartQuantity[found] += quantity;
        stock[found] -= quantity;
        printf("product %d is added to cart , total %d added.",id , quantity);
    }
}

void DisplayBill(int productIds[] , int prices[] , int cartquantity[] , int n){
		float total = 0;
		int user_voucher;
		for(int i = 0 ; i< ; i++){
			float itemtotal = cartquantity[i]*prices[i];
			total = total + itemtotal;
		}
		printf("Enter 1 to apply Voucher: ");
		scanf("%d" , &user_voucher);
		if(user_voucher == 1){
			float newbill = total-(total*0.25);
			printf("bill after discount is %d" , newbill);
		else{
			printf("Total before discount is : %d" , total);
		}
	}
}

void ShowInvoice(char name[], char cnic[], int productIds[],
                 int prices[], int cart[], int n, float total, float discountedTotal){
                 	printf("Customer Details: %s , %s" , name , cnic);
                 	printf("Bill w/out Discount %f:" , total);
                 	printf("Bill w/Discount %f:" , discountedTotal; 
				}
















































