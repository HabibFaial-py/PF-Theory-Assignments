#include <stdio.h>
#include <string.h>


void encodeMessage(char message[100]);
void decodeMessage(char message[100]);

int main() {
    int choice;
    char message[100];

    printf("Welcome To TCS Security System \n 1. Encoding \n 2. Decoding \n 3.Exit\n");
    scanf("%d", &choice);

    switch(choice) {
        case 1:
            printf("Encoding.\n Enter message to Encode:");
            fgets(message, sizeof(message), stdin);
            encodeMessage(message);
            break;

            break;
        case 2:
            printf("Decoding.\n Enter message to Decode: ");
            fgets(message, sizeof(message), stdin);
            decodeMessage(message);
            break;
        case 3:
            printf("Exiting\n");
            break;
        default:
            printf("Invalid choice.\n");
    }

    return 0;
}
void encodeMessage(char message[100]){
	int count = 0 ;
	scanf("%s" , message);
	while(message[count] != '\0'){
		count++;
	}
	for (int i = 0 ; i<count/2 ; i++){
		char temp = message[i];
		message[i] = message[count-1-i];
		message[count-1-i] = temp;
	}
	for(int i = 0 ; i<count ; i++){
		message[i] ^= (1<<1);
		message[i] ^= (1<<4);
	}
	printf("%s" , message);
}

void decodeMessage(char message[100]){
	int count = 0;
	scanf("%s" , message);
	while(message[count] != '\0'){
		count++;
	}
	for (int i = 0 ; i<count ; i++){
		message[i] ^= (1<<1);
		message[i] ^= (1<<4);
	}
	for(int i = 0 ; i<count / 2 ; i++){
		char temp = message[i];
		message[i] = message[count-1-i];
		message[count-1-i] = temp;
	}
	printf("%s" , message);
}

