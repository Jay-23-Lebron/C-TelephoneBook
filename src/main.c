/**
 * Project: Contact Address Book
 * Core Functions: Add / Delete / Search / Show All / Count Statistics
 * Extra Feature: Phone number format validation (11 digits, only numeric)
 * Coding Standard: Standard C, English prompt & comments for overseas resume
 */

#include<stdio.h>
#include<string.h>

// Macro definition for length limit
#define MAX 20 // Maximum storage capacity of contacts
#define NAME_LEN 20 // Max character length of contact name
#define PHONE_LEN 15 // Max character length of phone number

/**
 * Contact structure: store single contact data
 * @member name: contact name text
 * @member phone: contact mobile number string
 */

typedef struct{
	char name[NAME_LEN];
	char phone[PHONE_LEN];
}Contact;

// Global data storage
Contact contacts[MAX];// Array to save all contact objects
int count=0;// Counter: record current total contacts


/**
 * @brief Validate phone number format
 * @param phone: input phone string waiting for check
 * @return int 1 = legal 11-digit pure number; 0 = illegal number
 */
int checkPhone(char phone[]){
	// Judge if the digit length is exactly 11
	if(strlen(phone)!=11){
		return 0;
	}
	// Traverse every character to check all are digits
	int k;
	for(k=0;phone[k]!='\0';k++){
		if(phone[k]<'\0'||phone[k]>'\9'){
			return 0;
		}
	}
	return 1;
}

/**
 * @brief Create and save new contact
 */
void addContact(){
	// Judge if contact storage reaches maximum limits
	if(count>=MAX){
		printf("Contact list is full (max capacity: 20 contacts), cannot add new contacts!\n");
		return;
	}
	
	printf("Please enter contact name:");
	scanf("%19s",contacts[count].name);
	
	printf("Please enter contact phone number:");
	scanf("%14s",contacts[count].phone);
	
	// Call validation function to check phone format
	if(checkPhone(contacts[count].phone)==0){
		printf("Invalid mobile number! Must be exactly 11 pure digits without letters/symbols. Addition failed!\n");
		return;
	}
	// Valid data, total contact number +1
	count++;
	printf("Contact added successfully!\n");	
}

/**
 * @brief Print all saved contacts list
 */
void showAllContacts(){
	// Judge empty address book
	if(count==0){
		printf("No contacts stored in list, please create a new contact first£¡\n");
		return; 
	}
	
	printf("\n============== All Contact List ===============\n");
	int i; 
	for(i=0;i<count;i++){
		printf("Index %d | Name£º%s | Phone Number£º%s\n",i+1,contacts[i].name,contacts[i].phone);
	}
	printf("\n===============================================\n");
}

/**
 * @brief Search contact by full name, optimize empty & no-match prompt
 */
void searchContact(){
	char searchName[NAME_LEN];
	
	printf("Please enter the contact name you want to search£º\n");
	scanf("%s",searchName);
	
	// Optimize prompt: handle empty address book separately
	if(count==0){
		printf("Search failed:The address book has no contacts stored yet.\n");
		printf("Tip:You can create a new contact via option 1 in menu");
		return;
	}
	
	// Traverse all contacts to match name
	int isFind=0;
	int i;
	for(i=0;i<count;i++){
		if(strcmp(contacts[i].name,searchName)==0){
			printf("\n ¡ÌMatching contact found£º\n");
			printf("Index %d  Name: %s  Phone Number: %s\n",i+1,contacts[i].name,contacts[i].phone);
			isFind=1; 
		}
	}
	
	// Optimized no-result prompt, show search keyword & suggestions
	if(isFind==0){
	printf("\n No contact named %s exists in the address book!\n",searchName);
	printf("Currently total stored contacts:%d\n",count);
	printf("Tips:\n");
	printf("1.Check if you entered the name correctly(case sensitively)\n");
	printf("2.Use option 1 to add this new contact if you needed\n");
  }
	
}

/**
 * @brief Delete target contact by name
 */
void delContact(){
	if(count==0){
		printf("No contacts stored in address book, deletion operation unavailable!\n");
	}
	
	char delName[NAME_LEN];
	printf("Please enter the name of contact to delete£º");
	scanf("%s",delName);
	
	int isFind=0;
	int i,j;
	
	// Loop to find matching contact
	for(i=0;i<count;i++){
		if(strcmp(contacts[i].name,delName)==0){
			// Overwrite current contact with next data to complete deletion
			for(j=i;j<count-1;j++){
				contacts[j]=contacts[j+1];
			}
			count--; // Reduce total contact counter
			isFind=1;
			printf("contact deleted successfully£¡\n");
			break;
		}
	}
	// Prompt when target name not found
	if(isFind==0){
		printf("Target contact not found, deletion failed£¡\n");
	}
	
}

/**
 * @brief Count & print contact storage statistics
 */
void countContacts(){
	printf("\n====Contact Count Statistics====\n");
	printf("Total existing contacts£º%d\n",count);
	printf("Maximum capacity of address book£º%d\n",MAX);
	printf("Remaining available slots£º%d\n",MAX-count);
}

/**
 * @brief Main program loop: print menu & handle user operation selection
 * @return int Program exit status, 0 = normal exit
 */
int main(){
	while(1){
		
	
	printf("=======================================\n");
	printf("===========Contact List Menu===========\n");
	printf("         1.Create New Contact       \n");
	printf("         2.Delete Contact           \n");
	printf("         3.Edit Contact             \n");
	printf("         4.Search Contact           \n");
	printf("         5.Show All Contacts        \n");
	printf("         6.Contacts Quantity Statistics\n");
	printf("         0.Exit Contact List        \n");
	printf("=======================================\n");
	
	int choice;
	printf("Please enter your option:");
	scanf(" %d",&choice);
	while(getchar()!='\n');
	
	// Branch processing for different menu options
	switch(choice){
		case 1:
			addContact();
		    break;
		case 2:
		    delContact();
			break;
		case 3:
		    printf("->Enter contact modification page\n");
			break;
		case 4:
		    searchContact();
			break;
		case 5:
		    showAllContacts();
			break;
		case 6:
			countContacts();
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









































