#ifndef HUFFMAN_H
#define HUFFMAN_H
#endif 
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX_CODE_LENGTH 260// 符号表最大只能有256个节点
struct node
{
    char code[MAX_CODE_LENGTH];
        // 字符串形式存储的Huffman编码
        
    long count;
        // 这个字符在文件中出现的次数
        
    int checked;
        // 在生成Huffman树的时候是否已经被当作叶子节点
        
    char sym;
        // 符号
    struct node* next,*left,*right;// left和right只在生成Huffman树的时候有用
};
///////////////////////////////////////////////////////////////////////////////////////////////////
// 函数原型
///////////////////////////////////////////////////////////////////////////////////////////////////
// 压缩相关
struct node* generate_count(FILE*,struct node*);
struct node* generate_tree(struct node*);
void generate_code(struct node*list);
struct node* free_tree(struct node*list);
void generate_des_file(FILE*,FILE*,struct node*);
// 解压相关
struct node* de_get_sym_list(FILE*);
void de_generate_des_file(FILE*,FILE*,struct node*);
// 辅助函数

// 在链表中查找指定的字符
// 参数：符号表
// 参数：字符
// 返回值：找到的节点的指针
struct node* content_char(struct node*,char);

// 在链表中查找指定编码
// 参数：符号表
// 参数：编码
// 返回值：找到的节点的指针
struct node* content_code(struct node* list,const char* ch);

// 根据字符创建一个新的节点
// 参数：字符
// 参数：计数
// 返回值：新节点指针
struct node* create_new_node(char ch,int count);

// 插入新节点到符号表的最前面
// 参数list：目标链表
// 参数new_node：新节点
// 返回值：插入后的链表
struct node* insert_node(struct node *list,struct node *new_node);

// 输出链表
// 参数list：目标链表
void print_list(struct node *list);
