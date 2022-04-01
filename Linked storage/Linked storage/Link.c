#include<stdio.h>
#include"Linklist.h"
int main()
{
	
	int n,a,b,c,d,e;
	Linklist l=  (Lnode*)malloc(sizeof(Lnode));
	printf("请输入你要添加学生的数量：");
	scanf_s("%d", &n);
	//Creat_list_H(l, n);
	Creat_list_E(l, n);
	Print_l(l);
	printf("请输入要删除的节点：");
	scanf_s("%d", &a);
	Delete_lnode(l,a);
	Print_l(l);
	printf("请输入要加入的节点：");
	scanf_s("%d", &b);
	Insert_list(l, b);
	Print_l(l);
	
	return 0;
}