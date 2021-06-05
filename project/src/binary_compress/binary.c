#include<stdio.h>
#include<stdlib.h>

//基于二进制编码的压缩算法


// 生成目标文件
// 参数：源文件
// 参数：目标文件
// 参数：符号链表

void generate_des_file(FILE* sf,FILE* df,struct node*list)
// 符号表以文本形式写入到目标文件的前端，解压时需要的信息
struct node* index=list;
while(index)
{
    fprintf(df,"%d %s ",index->sym,index->code);
    index=index->next;
}
// 指示结尾，"END"实际上没有用到，只用于和END_SYM_FLAG配对
fprintf(df,"%d %s\n",END_SYM_FLAG,"END");

//对编码进行二进制转化
char* current_code=content->code;
for(int i=0;i<strlen(current_code);i++)
{
    // 每次循环左移一位，长度+1
    des_ch=des_ch<<1;
    des_ch_length++;
    // 末位默认位0，否则置1
    if(current_code[i]=='1')des_ch |= (char)1;
    
    // 已经足够了一个字符，就写入，并清0
    if(des_ch_length==8)
    {
        if(!fwrite(&des_ch,sizeof(char),1,df))
        {
            printf("error:cannot write to des file.\n");
            exit(0);
        }
        des_ch_length=0;
        des_ch=0;
    }// 形成了一个字符
}
