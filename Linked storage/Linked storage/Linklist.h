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
}student;//ѧ����Ϣ
typedef struct Lnode* Linklist;
typedef struct Lnode Lnode;
typedef struct Lnode {
	student std;
	Lnode* next;
};//�ڵ��ͷ�ڵ�Ķ���


int Listempty(Linklist l)
{
	if (l->next)//�ǿ�
		return 0;
	else
		return 1;
}//�ж������Ƿ�Ϊ��
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
}//�������нڵ㣬����ͷ�ڵ�
int Listclear(Linklist l)
{
	Linklist p, q;//���������Դ˱���ͷָ��
	p = l->next;
	while (p) {
		q = p->next;
		free(p);
		p = q;
	}
	l->next = NULL;
	return OK;
}//����ͷ�ڵ�
int List_length(Linklist l)
{
	int i = 0;
	Linklist p;
	p = l->next;
	while (p)
	{
		i++;
		p = p->next;//˳���ܸģ�iָ��λ��ʱ��p->nextָ��NULL
	}
	return i;
}
int Get_data(Linklist l, int i, student* e)//��ȡĳ������Ԫ�ص����ݣ�ͨ��e����
{
	Lnode* p;
	int j = 1;
	p = l->next;
	while (p && j < i)//���ɨ�裬ֱ��ָ��Ϊ�ջ��ߵ���ָ��λ��
	{
		p = p->next;
		++j;
	}//pλ����i������ͬ�����pָ��Ŀ��ڵ㣬j++���Ƴ�ѭ��
	if (!p || j > i) return ERROR;
	e = &p->std;//������Ҫѧ������Ϣ���������ͽṹ��
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
		printf("ѧ����û����ȡ������ɼ���");
		return 0;
	}
	return p;
}//���ҿ�ȡָ���ɼ���ѧ����Ϣ
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
	}//����ӽڵ��ǰ��
	if (!p || j > i - 1) return ERROR;//�ж��쳣���
	printf("������ѧ��ѧ�ţ�");
	scanf_s("%d", &e->std.num);
	printf("������ѧ��������");
	scanf_s("%s", &e->std.name, 8);
	printf("������ѧ���ɼ���");
	scanf_s("%d", &e->std.score);
	e->next = p->next;
	p->next = e;//��ӽڵ�
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
	if (!p->next || j > i - 1) return ERROR;//�ж��쳣���
	e = p->next;
	p->next = e->next;
	free(e);
	return OK;
}//ɾ���ڵ�
void Creat_list_H(Linklist l, int n)
{
	l->next = NULL;
	Lnode* p;
	for (int i = 0; i < n; i++)
	{
		p = (Lnode*)malloc(sizeof(Lnode));
		printf("������ѧ��ѧ�ţ�");
		scanf_s("%d", &p->std.num);
		printf("������ѧ��������");
		scanf_s("%s", &p->std.name, 8);
		printf("������ѧ���ɼ���");
		scanf_s("%d", &p->std.score);
		printf("\n");
		p->next = l->next;
		l->next = p;
	}

}//ͷ�巨
void Creat_list_E(Linklist l, int n)
{
	l->next = NULL;
	Lnode* p,*a;
	a = l;
	for (int i = 0; i < n; i++)
	{
		p = (Lnode*)malloc(sizeof(Lnode));
		printf("������ѧ��ѧ�ţ�");
		scanf_s("%d", &p->std.num);
		printf("������ѧ��������");
		scanf_s("%s", &p->std.name,8);
		printf("������ѧ���ɼ���");
		scanf_s("%d", &p->std.score);
		p->next = NULL;
		a->next = p;
		a = p;
		printf("\n");
	}
}//β�巨
void Print_l(Linklist l)
{
	l = l->next;
	while(l)
	{
		printf("ѧ��ѧ�ţ�%d  ", l->std.num);
		printf("ѧ��������%s  ", l->std.name);
		printf("ѧ���ɼ���%d", l->std.score);
		l = l->next;
		printf("\n");
	}
}