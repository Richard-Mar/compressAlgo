#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define LENGTH_OF_SEED 8
//全局变量字典
static struct Dict{
	//存储种子
	char string[LENGTH_OF_SEED+1];
	//存储匹配位置
	int *position;	
};

static struct Node{
	struct Dict data;
	struct Node *next;
};

//辅助函数
//种子字典初始化

//匹配种子
void seed_compare(FILE* source_file){
	return;
};
//写入信息
void seed_output(FILE* des_file){
	return;
};

int main (int argc, char *argv[])
{
	struct Node* head;
	head = (struct Node*)malloc(sizeof(struct Node));
	//读取文件
	FILE *source_file = fopen(argv[1],"r+");
    if(!source_file)
    {
        printf("cannot open source file.\n");
        exit(0);
    }
    
    //打开待写入文件
    FILE* des_file=fopen(argv[2],"w+");
    if(!des_file)
    {
        printf("cannot open des file.\n");
        exit(0);
    }
	
	//跳过第一行
	char *buff;
	buff =(char *) malloc(100*sizeof(char));
	fgets(buff,100,source_file);
	fprintf(des_file,buff);
	free(buff);
	//读入DNA序列暂存
	seed_compare(source_file);
	seed_output(des_file);
    // 关闭文件
    if(fclose(source_file))
    {
        printf("cannot close source file!\n");
        exit(0);
    }
    if(fclose(des_file))
    {
        printf("cannot close des file!\n");
        exit(0);
    }

}
void seed_compare(FILE *fp,struct Node* head){
	struct Node* p = head;
	long position_of_pointer;
	struct Node* temp = (sturct Node*)malloc(sizeof(struct Node));
	char *temp_string = (char *)malloc(sizeof(char)*9);
	temp_string = fgets(fp,8);
/*		if(遇到换行符)
		{
			continue;
		}
*/
	strcpy((temp->data).string,temp_string);
	free(temp_string);
	
	//循环
	while(fp!=NULL)
	{
/*		if(遇到换行符)
		{
			continue;
		}
*/
		//循环比较
		
		int position;
		比较这里面的匹配结果？？？
		
		{
			(temp->data).position[i] = position;
		}
	}
	p->next = temp
	p = p->next;
}
void seed_output(FILE *fp,struct Node* head){

	struct Node* p = head;
	文件的指针现在在第二行刚刚开始
	//循环输入到目标文件里面
	while(p!=NULL)
	{
		fputs((p->data).string,fp);
		fputc(' ',fp);
		for(???)
		{
			fputs((p->data).position[i],fp);
			fputc(' ',fp);
		}
	}
}
