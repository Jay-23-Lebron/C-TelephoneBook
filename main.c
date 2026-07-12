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
		printf("通讯录已满，无法添加新联系人！\n");
		return;
	}
	
	printf("请输入联系人姓名：");
	scanf("%s",contacts[count].name);
	
	printf("请输入联系人电话：");
	scanf("%s",contacts[count].phone);
	
	count++;
	
	printf("√联系人添加成功！\n");
	
	
	
}

int main(){
	while(1){
		
	
	printf("================================\n");
	printf("===========通讯录菜单===========\n");
	printf("         1.新建联系人           \n");
	printf("         2.删除联系人           \n");
	printf("         3.修改联系人           \n");
	printf("         4.查找联系人           \n");
	printf("         5.显示所有联系人       \n");
	printf("         0.退出通讯录           \n");
	printf("================================\n");
	
	int choice;
	printf("请输入你的选择：");
	scanf(" %d",&choice);
	
	
	switch(choice){
		case 1:
			addcontact();
		    break;
		case 2:
		    printf("->进入删除联系人\n");
			break;
		case 3:
		    printf("->进入修改联系人\n");
			break;
		case 4:
		    printf("->进入查找联系人\n");
			break;
		case 5:
		    printf("->显示所有联系人\n");
			break;
		case 0:
		    printf("再见！\n");
			return 0; 
		default:
			printf("输入错误！请重新运行！\n");
	}
}
	
	
	return 0;
}
