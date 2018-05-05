#include <stdio.h>
#include <string.h>

struct customer {
	char lastName[15];
	char firstName[15];
	unsigned int customerNumber;
		struct {
			char phoneNumber[11];
			char address[50];
			char city[15];
			char state[3];
			char zipCode[6];
		} personal;

} customerRecord, *customerPtr;



int main(int argc, char** argv) {
	customerPtr = &customerRecord;
	
	//a
	strcpy(customerRecord.lastName, "Calis");
	printf("%s\n",customerRecord.lastName);
	
	//b
	printf("%s\n",customerPtr->lastName);
	
	//c
	strcpy(customerRecord.firstName, "Mustafa");
	printf("%s\n",customerRecord.firstName);
	
	//d
	printf("%s\n",customerPtr->firstName);
	
	//e
	customerRecord.customerNumber = 1;
	printf("%d\n",customerRecord.customerNumber);
	
	//e
	printf("%d\n",customerPtr->customerNumber);
	
	//g 
	strcpy(customerRecord.personal.phoneNumber, "05427374979");
	printf("%s\n",customerRecord.personal.phoneNumber);
	
	//h
	printf("%s\n",customerPtr->personal.phoneNumber);
	
	//i 
	strcpy(customerRecord.personal.address, "adres");
	printf("%s\n",customerRecord.personal.address);
	
	//j
	printf("%s\n",customerPtr->personal.address);
	
	//k 
	strcpy(customerRecord.personal.city, "aydin");
	printf("%s\n",customerRecord.personal.city);
	
	//l
	printf("%s\n",customerPtr->personal.city);
	
    //m 
	strcpy(customerRecord.personal.state, "efeler");
	printf("%s\n",customerRecord.personal.state);
	
	//n
	printf("%s\n",customerPtr->personal.state);
	
	//o
	strcpy(customerRecord.personal.zipCode, "09");
	printf("%s\n",customerRecord.personal.zipCode);
	
	//p
	printf("%s\n",customerPtr->personal.zipCode);
	
	
	return 0;
}
