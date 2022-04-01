#pragma once
#include<stdio.h>
#include<stdlib.h>
#define TRUE 1
#define FALSE 0
#define OK 1
#define ERROR 0
#define INFEASIBLE -1
#define OVERFLOW -2
typedef struct students{
	int num;
	char name[8];
	int score;
}student;//学生信息
typedef struct Lnode* Linklist;
typedef struct Lnode Lnode;
typedef struct Lnode {
	student std;
	Lnode* next;
};//节点和头节点的定义


int Listempty(Linklist l)
{
	if (l->next)//非空
		return 0;
	else
		return 1;
}//判断链表是否为空
int Listdestory(Linklist l)
{
	Linklist p;
	while (l)
	{
		p = l;
		l = l->next;
		free(p);
	}
	return OK;
}//销毁所有节点，包括头节点
int Listclear(Linklist l)
{
	Linklist p, q;//俩个变量以此保存头指针
	p = l->next;
	while (p) {
		q = p->next;
		free(p);
		p = q;
	}
	l->next = NULL;
	return OK;
}//保存头节点
int List_length(Linklist l)
{
	int i = 0;
	Linklist p;
	p = l->next;
	while (p)
	{
		i++;
		p = p->next;//顺序不能改，i指到位置时，p->next指向NULL
	}
	return i;
}
int Get_data(Linklist l, int i, student* e)//获取某个数据元素的内容，通过e返回
{
	Lnode* p;
	int j = 1;
	p = l->next;
	while (p && j < i)//向后扫描，直到指针为空或者到达指定位置
	{
		p = p->next;
		++j;
	}//p位置与i的数相同，最后p指向目标节点，j++后推出循环
	if (!p || j > i) return ERROR;
	e = &p->std;//返回需要学生的信息，接受类型结构体
	return OK;
}
Lnode* Locate_elem(Linklist l, int e)
{
	Lnode* p;
	p = l->next;
	while (p && p->std.score != e)
		p = p->next;
	if (!p)
	{
		printf("学生中没有人取得这个成绩！");
		return 0;
	}
	return p;
}//查找考取指定成绩的学生信息
int Insert_list(Linklist l, int i)
{
	int j = 0;
	Linklist p=l;
	Linklist e;
	e= (Lnode*)malloc(sizeof(Lnode));
	while (p && j < i-1)
	{
		p = p->next;
		j++;
	}//找添加节点的前驱
	if (!p || j > i - 1) return ERROR;//判断异常情况
	printf("请输入学生学号：");
	scanf_s("%d", &e->std.num);
	printf("请输入学生姓名：");
	scanf_s("%s", &e->std.name, 8);
	printf("请输入学生成绩：");
	scanf_s("%d", &e->std.score);
	e->next = p->next;
	p->next = e;//添加节点
	printf("\n");
	return OK;
}
int Delete_lnode(Linklist l, int i)
{
	int j = 0;
	Linklist p = l;
	Linklist e;
	while (p && j < i-1 )
	{
		p = p->next;
		j++;
	}
	if (!p->next || j > i - 1) return ERROR;//判断异常情况
	e = p->next;
	p->next = e->next;
	free(e);
	return OK;
}//删除节点
void Creat_list_H(Linklist l, int n)
{
	l->next = NULL;
	Lnode* p;
	for (int i = 0; i < n; i++)
	{
		p = (Lnode*)malloc(sizeof(Lnode));
		printf("请输入学生学号：");
		scanf_s("%d", &p->std.num);
		printf("请输入学生姓名：");
		scanf_s("%s", &p->std.name, 8);
		printf("请输入学生成绩：");
		scanf_s("%d", &p->std.score);
		printf("\n");
		p->next = l->next;
		l->next = p;
	}

}//头插法
void Creat_list_E(Linklist l, int n)
{
	l->next = NULL;
	Lnode* p,*a;
	a = l;
	for (int i = 0; i < n; i++)
	{
		p = (Lnode*)malloc(sizeof(Lnode));
		printf("请输入学生学号：");
		scanf_s("%d", &p->std.num);
		printf("请输入学生姓名：");
		scanf_s("%s", &p->std.name,8);
		printf("请输入学生成绩：");
		scanf_s("%d", &p->std.score);
		p->next = NULL;
		a->next = p;
		a = p;
		printf("\n");
	}
}//尾插法
void Print_l(Linklist l)
{
	l = l->next;
	while(l)
	{
		printf("学生学号：%d  ", l->std.num);
		printf("学生姓名：%s  ", l->std.name);
		printf("学生成绩：%d", l->std.score);
		l = l->next;
		printf("\n");
	}
}