#include <stdio.h>
#include <string.h>
#include <stdlib.h>
 
#define WORDSIZE 20
#define MEANSIZE 25
 
 
struct Record{
	char word[WORDSIZE];
	char mean[MEANSIZE];
};
 
struct Node{
	struct Record data;
	struct Node *next;
};
 
int flag = 0;
 
void initData(struct Node *head);
void printData(struct Node *head);
void searchByWord(struct Node *head,char *word);
void searchByMean(struct Node *head,char *mean);
int main()
{
	struct Node* head;
	head = (struct Node*)malloc(sizeof(struct Node));
	initData(head);
	int choose;
	char input[20];
	printData(head);
	while(!flag){
		
		printf("------------------\n");
		printf("1.根据中文查英文\n");
		printf("2.根据英文查中文\n");
		printf("------------------\n");
		printf("请输入你的选择\n");
		scanf("%d",&choose);
		switch(choose)
		{
			case 1:
				printf("请输入(中文)：");
				scanf("%s",input);
				searchByMean(head,input);
				break;
			case 2:
				printf("请输入(英文)：");
				scanf("%s",input);
				searchByWord(head,input);
				break;
			default:
				printf("输入有误，请重新输入\n");
				break;
		}
		//printData(head);
		
	}
	return 0;
}
 
//初始化数据
void initData(struct Node *head)
{
	char english[10][6] = {"One","Two","Three","Four","Five","Six","Seven","Eight","Nine","Ten"};
	char chinese[10][10] = {"一","二","三","四","五","六","七","八","九","十"};
	struct Node *p = head;
	int i; 
	for(i=0;i<10;i++)
	{
		struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
		strcpy((temp->data).word,english[i]);
		strcpy((temp->data).mean,chinese[i]);
		//printf("%s",(temp->data).word);
		//printf("%s",(temp->data).mean);  
		p->next = temp;
		p = p->next; 
	}
	p->next = NULL;	 
}
 
//打印出链表数据 
void printData(struct Node* head)
{
	struct Node* p = head;
	p = p->next;
	while(p!=NULL){
		printf("word is；%s\n",(p->data).word);
		printf("mean is:%s\n",(p->data).mean);
		p = p->next;
	}
 }
 
 //根据英文查中文 
 void searchByWord(struct Node *head,char *word)
 {
 	struct Node* p = head;
 	p = p->next;
 	while(p!=NULL){
 		if(strcmp((p->data).word,word)==0)
 		{
 			printf("\t---已找到---\n");
 			printf("\tENGLISH\tCHINESE\n");
 			//printf("\t%s\t%s\n",(p->data).word,(p->data).mean);
 			//printf("\t--------------\n");
 			flag = 1;
 			return;
		 } else{
		 	p = p->next;
		 }
		 
	 }
	 if(p->next = NULL) printf("未找到，请重新输入\n");
  }
  
  //根据中文查英文 
  void searchByMean(struct Node *head,char *mean)
  {
  	struct Node* p = head;
 	p = p->next;
 	while(p!=NULL){
 		if(strcmp((p->data).mean,mean)==0)
 		{
 			printf("\t---已找到---\n");
 			printf("\tENGLISH\tCHINESE\n");
 			printf("\t%s\t%s\n",(p->data).word,(p->data).mean);
 			printf("\t--------------\n");
 			flag = 1;
 			return;
		 } else{
		 	p = p->next;
		 }
		 
	 }
	 if(p->next = NULL) printf("未找到，请重新输入\n");
  	
   } 
