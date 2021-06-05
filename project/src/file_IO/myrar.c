#include<string.h>
#include<fcntl.h>
#include<unistd.h>
#include<stdio.h>

struct symbol{
	char ch;//保存字符
	int num;//保存字符出现的次数
};

struct Filestate{
	struct symbol symbols[128];	//每个字符对应一个元素
	int ct;//记录一共有多少个字符
};

struct Filestate filestate;//全局变量，保存了字符的统计数据;

void calc_ct(char ch)
{
	//分析ch有没有出现在数组中，有则该元素的num++否则放入新的元素
	int flag = 0;
	int i;
	for(i = 0;i<filestate.ct;i++)
	{
		if(ch == filestate.symbols[i].ch)
		{
			filestate.symbols[i].num++;
			flag = 1;
			break;//没必要往后面走了
		}

	}
	if(flag == 0)
	{
		//找到数组里第一个没有用到的元素放进去
		filestate.symbols[filestate.ct].ch = ch;
		filestate.symbols[filestate.ct].num++;
		filestate.ct++;
	}
}

int main(char *argv[])
{
	bzero(&filestate,sizeof(filestate));
	//打开文件，读取字符，将字符存入数组，然后将次数+1
	
	int fd = open("/home/richard/Desktop/Sophomore2/bioinfo/final_project/project/compressAlgo/project/data/CP015085.1.fasta",O_RDONLY);
	if(fd == -1) return -1;
	char buffer;
	while(read(fd,&buffer,1) == 1)
	{
		calc_ct(buffer);
	}
	int i;
	for(i = 0;i<filestate.ct;i++)
	{
		printf("symbol:\%c,num = %d\n",filestate.symbols[i].ch,filestate.symbols[i].num);
	}
}
