#include<stdio.h>
#include<string.h>

#define MAX 100
#define NAME_LEN 20
#define PHONE_LEN 15

typedef struct{
	char name[NAME_LEN];
	char phone[PHONE_LEN];
}Contact;

Contact contacts[MAX];
int count=0;

void addcontact(){
	if(count>=MAX){
		printf("Contact list full, cannot add new contact!\n");
		return;
	}
	
	printf("Please enter contact name:");
	scanf("%s",contacts[count].name);
	
	printf("Please enter contact phone number:");
	scanf("%s",contacts[count].phone);
	
	count++;
	
	printf("¡ÌContact added successfully!\n");	
}

void showAllcontacts(){
	if(count==0){
		printf("No contacts stored in list, please create a new contact first£¡\n");
		return; 
	}
	
	printf("\n============== All Contact List ===============\n");
	int i; 
	for(i=0;i<count;i++){
		printf("Index %d  Name£º%s  Phone Number£º%s\n",i+1,contacts[i].name,contacts[i].phone);
	}
	printf("=============================================\n");
}

int main(){
	while(1){
		
	
	printf("=======================================\n");
	printf("===========Contact List Menu===========\n");
	printf("         1.Create New Contact       \n");
	printf("         2.Delete Contact           \n");
	printf("         3.Edit Contact             \n");
	printf("         4.Search Contact           \n");
	printf("         5.Show All Contacts        \n");
	printf("         0.Exit Contact List        \n");
	printf("=======================================\n");
	
	int choice;
	printf("Please enter your option:");
	scanf(" %d",&choice);
	
	
	switch(choice){
		case 1:
			addcontact();
		    break;
		case 2:
		    printf("->Enter contact deletion page\n");
			break;
		case 3:
		    printf("->Enter contact modification page\n");
			break;
		case 4:
		    printf("->Enter contact search page\n");
			break;
		case 5:
		    showAllcontacts();
			break;
		case 0:
		    printf("Goodbye£¡\n");
			return 0; 
		default:
			printf("Invalid input! Please restart the program!\n");
	}
}
	
	
	return 0;
}
