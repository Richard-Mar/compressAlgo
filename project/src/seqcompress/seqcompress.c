#include"dna_input.h"
#include"static_model.h"
#include"bin_compress.h"
#define BIN_COMPRESS_RATION 25
#define LENTH_OF_SUB_SEGMENT 8

#define LENTH_OF_SEGMENT 1000

int main (int argc, char *argv[])
{
	if(argc != 4)
	{
		printf("usage: source_file op des_file\nop:c:compress\td:decompress\n")	;
	}
	FILE *source_file = fopen(argv[1],"r");
    if(!source_file)
    {
        printf("cannot open source_file.\n");
        exit(0);
    }
    fseek(source_file,0L,SEEK_END);
    long size = ftell(source_file);
    fseek(source_file,0L,SEEK_SET);
    
	long length;
	char *dna;
	dna = (char*)malloc(size*sizeof(char));
	length = return_dna(dna,source_file);
	//printf("dna :\n%s",dna);

	fseek(source_file,0L,SEEK_SET);


    // 打开目标文件
    FILE* des_file=fopen(argv[3],"w+");
	struct node *list=NULL;
    if(!des_file)
    {
        printf("cannot open des file.\n");
        exit(0);
    }

    // 获取操作符
    char op;
	op = argv[2][0];
    if(op!='c' && op!='d')
    {
        printf("usage: source_file op des_file\nop:c:compress\td:decompress\n");
        exit(0);
    }

    // 压缩
    else if(op=='c')
    {
    	//input the header
    	//set a segment length here
		FILE * buff_file = fopen("./buff_file","w+");
		/*
		long i = 0;
		for(i=0;i<length;i=i+1000)
		{
	    	char *segment;
    		segment = (char*)malloc(sizeof(char)*(LENTH_OF_SEGMENT+1));
			segment[LENTH_OF_SEGMENT]='\0';
			strncpy(segment,dna+sizeof(char)*i,1000);
			if(model_compress(segment,buff_file))
			{
				free(segment);
				continue;
			}
			free(segment);
		}
		*/
		fputs(dna,buff_file);
		fseek(buff_file,0L,SEEK_SET);
		list=generate_count(buff_file,list);
        list=generate_tree(list);
        generate_code(list);
        list=free_tree(list);
        generate_des_file(buff_file,des_file,list);
/**/		
		char *header;
		header =(char *)malloc(sizeof(char)*255);
		fgets(header,255,source_file);
		fputs(header,des_file);
		printf("\nsuccess");
		fclose(buff_file);
		remove("./buff_file");
	}
	else if(op == 'd')
	{
        list=de_get_sym_list(source_file);
        de_generate_des_file(source_file,des_file,list);
	}
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
	return 0;

}


