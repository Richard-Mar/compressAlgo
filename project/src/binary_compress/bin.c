#include<stdio.h>


int main (int argc, char *argv[])
{
    // 传的参数一定是三个：可执行程序 源文件 目标文件
    if(argc != 4)
    {
        printf("usage: ./bin source_file op(c\d\q) des_file.\n");
        exit(0);
    }
    //打开源文件
    FILE *source_file = fopen(argv[1],"rb");
    if(!source_file)
    {
    	printf("Error,fail to open source_file!\n");
    	exit(0);
    }
    //打开目标文件
    FILE* des_file = fopen(argv[3],"wb");
    if(!des_file)
    {
    	printf("Error,fail to open des_file!\n");
    	exit(0);
    }
    // 压缩
    else if(argv[2]=='c')
    {
        list=generate_count(source_file,list);
        list=generate_tree(list);
        generate_code(list);
        list=free_tree(list);
        generate_des_file(source_file,des_file,list);
    }
    // 解压
    else if(argv[2]=='d')
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
}
