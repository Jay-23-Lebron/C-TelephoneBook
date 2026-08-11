/**
 * Project: Contact Address Book
 * Core Functions: Add / Delete / Search / Show All / Count Statistics
 * Extra Feature: Phone number format validation (11 digits, only numeric)
 * Coding Standard: Standard C, English prompt & comments for overseas resume
 */

#include<stdio.h>
#include<string.h>
#include<stdlib.h>

// Macro definition for length limit
#define MAX 20 // Maximum storage capacity of contacts
#define NAME_LEN 20 // Max character length of contact name
#define PHONE_LEN 15 // Max character length of phone number

/**
 * @brief Linked list node for contact storage
 * Replace fixed-size array to store contact information dynamically
 */
typedef struct ContactNode{
	char name[NAME_LEN];
	char phone[PHONE_LEN];
	struct ContactNode *next;
}ContactNode;

// Global data storage
ContactNode contacts[MAX];// Array to save all contact objects
int count=0;// Counter: record current total contacts
ContactNode *head=NULL;

/**
 * @brief Create empty contact node with dynamic memory allocation
 * @return ContactNode* New node pointer; return NULL if malloc fails
 */
ContactNode* createNode(){
	ContactNode* newNode=(ContactNode*)malloc(sizeof(ContactNode));
	if (newNode == NULL)
    {
        printf("Memory allocation failed, create contact failed!\n");
        return NULL;
    }
    newNode->next = NULL;
    return newNode;
}

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
		if(phone[k]<'0'||phone[k]>'9'){
			return 0;
		}
	}
	return 1;
}


/**
 * @brief Add a new contact to linked list
 * Receive user input of contact info, verify phone format, then append node to the end of linked list
 */
void addContact(){
	ContactNode* newNode = createNode();
    if(newNode == NULL) return;

    printf("Please enter contact name:");
    scanf("%19s", newNode->name);
    printf("Please enter contact phone number:");
    scanf("%14s", newNode->phone);

    //Verify phone number format
    if(checkPhone(newNode->phone)==0){
        printf("Invalid mobile number! Must be 11 digits. Addition failed!\n");
        free(newNode); //release memory to avoid leak
        return;
    }

    if(head == NULL)
    {
    	//Empty list: new node acts as head
        head = newNode;
    }
    else
    {
        ContactNode* p = head;
        //Traverse to the last node
        while(p->next != NULL) p = p->next;
        p->next = newNode;//Attach new node at list tail
    }
    count++;//Update total contact number
    printf("Contact added successfully!\n");
}

/**
 * @brief Print all saved contacts list
 */
void showAllContacts(){
	// Judge empty address book
	if(head==NULL){
		printf("No contacts stored in list, please create a new contact first£¡\n");
		return; 
	}
	
	printf("\n============== All Contact List ===============\n");
	ContactNode* p=head;
	int index=1;
	while(p!=NULL){
		printf("index %d | Name %s | Phone Number %s |",index,p->name,p->phone);
		p=p->next;
		index++;
	}
	printf("\n===============================================\n");
}

/**
 * @brief Batch formatted print all contacts (Formal report style)
 */
void batchPrintContacts(){
	if(head==NULL){
		printf("\n[Batch print] No contacts stored in list!\n");
		return;
	}
	ContactNode* p=head;
	int count=0;
	
	printf("\n===============================================\n");
	printf("              BATCH CONTACT REPORT                 ");
	printf("\n===============================================\n");
	printf("%-4s | %-15s | %s\n","Index","Name","Phone Number");
	printf("\n-----------------------------------------------\n");
	while(p!=NULL){
		printf("%-4d | %-15s | %s\n",count+1,p->name,p->phone);
		count++;
		p=p->next;
	}
	printf("\n-----------------------------------------------\n");
	printf("Count Contact Quantity:%d\n",count);
	printf("\n===============================================\n");
}

/**
 * @brief Sort all contacts alphabetically by contact name
 * Implement bubble sort and arrange contacts from A to Z
 */
void sortContactByName(){
	//Check whether there are at least two contacts to sort
	if(head==NULL||head->next==NULL){
		printf("Insufficient contacts for sorting!\n");
		return;
	}
	
	ContactNode *p=NULL;
	ContactNode *q=NULL;
	char tempName[20];
	char tempPhone[12];
	int count=0;
	
	p=head;
	//Calculate total number of contacts
	while(p!=NULL){
		count++;
		p=p->next;
	}
	
	int i,j;
	//Bubble sort for contact list
	for(i=0;i<count-1;i++){
		p=head;
		for(j=0;j<count-1-i;j++){
			q=p->next;
			//Swap data if names are in wrong alphabetical order
			if(strcmp(p->name,q->name)>0){
				strcpy(tempName,p->name);
				strcpy(tempPhone,p->phone);
				
				strcpy(p->name,q->name);
				strcpy(p->phone,q->phone);
				
				strcpy(q->name,tempName);
				strcpy(q->phone,tempPhone);
			}
			p=p->next;
		}
	}
	printf("Sort finished! Sorted by name(A~Z).\n");
	showAllContacts();
}

/**
 * @brief Search contact by full name, optimize empty & no-match prompt
 */
void searchContact(){
	char searchName[NAME_LEN];
	
	printf("Please enter the contact name you want to search£º\n");
	scanf("%19s",searchName);
	
	// Optimize prompt: handle empty address book separately
	if(head==NULL){
		printf("Search failed:The address book has no contacts stored yet.\n");
		printf("Tip:You can create a new contact via option 1 in menu");
		return;
	}
	
	// Traverse all contacts to match name
	ContactNode* p=head;
	int isFind=0;
	int count=1;
	while(p!=NULL){
		if(strcmp(p->name,searchName)==0){
			printf("\n Matching contact found£º\n");
			printf("index %d  Name: %s  Phone Number: %s\n",count,p->name,p->phone);
			isFind=1; 
		}
		p=p->next;
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
 * @brief Delete contact node by matched name
 * Traverse linked list to find target contact, adjust pointer relation and release memory, update total count
 */
void delContact(){
	if(head==NULL){
		printf("No contacts stored in address book, deletion operation unavailable!\n");
		return;
	}
	
	char delName[NAME_LEN];
	printf("Please enter the name of contact to delete£º");
	scanf("%s",delName);
	
	ContactNode* p = head;
    ContactNode* prev = NULL;
    int isFind=0;
    while(p != NULL)
    {
        if(strcmp(p->name, delName)==0)
        {
            if(prev == NULL) head = p->next;
            else prev->next = p->next;
            free(p);
            count--;
            isFind=1;
            printf("contact deleted successfully! \n");
            break;
        }
        prev = p;
        p = p->next;
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
	printf("Storage: Dynamic linked list, no fixed maximum limit\n");
	printf("\n================================\n");
}

/**
 * @brief Binary search contact by contact name
 * Copy linked list node pointers into an array for binary search.
 * Reminder: The contact list must be sorted by name before calling this function.
 */
void binarySearchContact(){
	//Check whether the contact list is empty
	if(head==NULL){
		printf("Contact list is empty!\n");
		return;
	}
	
	int count=0;
	ContactNode* p=head;
	//Calculate total number of contacts
	while(p!=NULL){
		count++;
		p=p->next;
	}
	
	//Calculate array to store pointers of contact nodes
	ContactNode** nameArr=(char**)malloc(count * sizeof(char*));
	if(nameArr==NULL){
		printf("Memory allocation failed!\n");
		return;
	}
	
	p=head;
	int i;
	//Copy node pointers from linked list to array
	for(i=0;i<count;i++){
		nameArr[i]=p;
		p=p->next;
	}
	
	char targetName[20];
	printf("Please input name to search:\n");
	scanf("%s",targetName);
	
	int left=0;
	int right=count-1;
	int findIndex=-1;
	
	//Main loop of binary search
	while(left<=right){
		int mid=(left+right)/2;
		int cmpRet=strcmp(nameArr[mid]->name,targetName);
		
		if(cmpRet==0){
			findIndex=mid;
			break;
		}else if(cmpRet<0){
			left=mid+1;
		}else{
			right=mid-1;
		}
	}
	
	if(findIndex!=-1){
		p=head;
		int i;
		//Locate the matched contact node
		for(i=0;i<findIndex;i++){
			p=p->next;
		}
		printf("======Found Contact======\n");
		printf("Name:%s",p->name);
		printf("Phone:%s",p->phone);
	}else{
		printf("No matching contact found!\n");
	}
	//Release dynamically allocated array memory
	free(nameArr);
}

/**
 * @brief Save all contacts from linked list to text file
 * Write each contact's name and phone number into ../data/contact.txt
 */
void saveToFile(){
	//Open file with write mode
	FILE* fp=fopen("../data/contact.txt","w");
	
	if(fp==NULL){
		printf("File open failed!\n");
		return;
	}
	
	ContactNode* p=head;
	//Traverse list and write contact information into file
	while(p!=NULL){
		fprintf(fp,"%s %s\n",p->name,p->phone);
		p=p->next;
	}
	//Close file to ensure data is saved
	fclose(fp);
}

/**
 * @brief Free memory of all contact nodes in linked list
 */
void freeAllContacts(){
	ContactNode* p=head;
	//Traverse and release each contact node
	while(p!=NULL){
		ContactNode* temp=p;
		p=p->next;
		free(temp);
	}
	head=NULL;
	count=0;
	printf("All contact memory has been released successfully.\n");
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
	printf("         6.Batch Print Contacts     \n");
	printf("         7.sort contacts by name    \n");
	printf("         8.Contacts Quantity Statistics\n");
	printf("         9.Binary Search contact(By Name)\n");
	printf("         10.Manual save contacts to contact.txt\n");
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
			batchPrintContacts();
			break;
		case 7:
			sortContactByName();
			break;
		case 8:
			countContacts();
			break;
		case 9:
			binarySearchContact();
			break;
		case 10:
			saveToFile();
			printf("Manual save finished, saved to contact.txt\n");
			break;
		case 0:
			freeAllContacts();
		    printf("Goodbye£¡\n");
			return 0; 
		default:
			printf("Invalid input! Please restart the program!\n");
	}
}
	
	return 0;
}









































