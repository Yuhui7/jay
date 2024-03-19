#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>


typedef struct LNode {
	int data;
	struct LNode* next;
}LNode, * LinkList;

int x;

void InitList(LinkList L)		//尾插
{
	int k = 0;
	printf("请输入数据(以0结束)\n");
	scanf("%d", &x);
	if (L == NULL)
	{
		printf("分配内存失败");
		k++;
	}
	L->next = NULL;							//初始化
	LNode* s, * p;							//p指向最后一个节点
	p = L;
	while (x != 0)
	{
		if (p == NULL)
		{
			printf("p指向NULL");
			k++;
			break;
		}
		s = (LNode*)malloc(sizeof(LNode));	//建节点s
		if (s == NULL)
		{
			printf("分配内存失败");
			k++;
			break;
		}
		s->data = x;
		s->next = p->next;
		p->next = s;
		p = p->next;
		scanf("%d", &x);
	}
	if (k == 0)printf("1已完成\n");
}

void DisplayLink(LinkList L)
{
	LNode* p = L->next;					//定义指针p指向第一个节点
	while (p != NULL)
	{
		printf("%d->", p->data);		//打印数据
		p = p->next;					//指针移动下一个节点
	}
	printf("NULL\n");
}

void ListInsert(LinkList L)	//在第i个节点后插入数据x
{
	int k = 0;
	LNode* h, * s;
	h = L;
	int i = 0, j = 0, x = 0;
	printf("选择插入节点:");
	scanf("%d", &i);
	printf("数据:");
	scanf("%d", &x);
	if (i < 0)printf("无此节点");
	for (j = 1; j < i; j++)
	{
		h = h->next;
	}
	if (h == NULL)
	{
		printf("h指向NULL");
		k++;
	}
	s = (LNode*)malloc(sizeof(LNode));	//建节点s
	if (s == NULL)
	{
		printf("分配内存失败");
		k++;
	}
	s->data = x;
	s->next = h->next;
	h->next = s;
	if (k == 0)printf("已插入");
}

int DeleteList(LinkList L)
{
	int i = 0, j = 0, k = 0;
	LNode* p, * q;
	p = L;
	printf("选择删除节点:");
	scanf("%d", &i);
	for (j = 1; j < i; j++)
	{
		p = p->next;
	}
	if (p->next == NULL)
	{
		printf("此节点为空");
		k++;
		return 0;
	}
	q = p->next;
	p->next = q->next;
	free(q);
	if (k == 0)printf("已删除\n");
}

void EChangeList(LinkList L)				//奇偶节点交换
{
	int temp = 0;
	if (L->next != NULL)
	{
		LNode* j = L->next;					//j指向奇节点
		if (j->next != NULL)
		{
			LNode* o = j->next;		//o指向偶节点
			while (1)
			{
				temp = j->data;
				j->data = o->data;
				o->data = temp;
				j = o->next;
				if (j->next == NULL)break;
				else o = j->next;
			}
			printf("已完成\n");
		}
	}
}

void FindMidList(LinkList L)
{
	int i = 0, j = 0, k = 0;						//i计节点数,k=0执行成功
	LNode* p = L;							//p遍历节点
	while (p->next != NULL)
	{
		++i;
		p = p->next;
	}
	p = L->next;							//p重置找中点		
	if (i % 2 == 0)
	{
		printf("偶数个节点无中间节点\n");
		k++;
	}
	else for (; j < i / 2, p->next == NULL; j++)
	{
		p = p->next;
	}
	if (k == 0)printf("中间节点数据为：%d\n", p->data);
}

void JudgRing(LinkList L)
{
	LNode* fast, * slow;
	fast=slow = L;
	while (fast->next != NULL)
	{
		slow = slow->next;
		fast = fast->next;
		if (fast->next != NULL)
			fast = fast->next;
		if (fast == slow)
		{
			printf("该链表有环\n");
			break;
		}
	}
	printf("该链表无环\n");
}

void ReverseList(LinkList L)
{
	LNode* r, * p = L->next;
	L->next = NULL;
	while (p != NULL)
	{
		r = p->next;
		p->next = L->next;
		L->next = p;
		p = r;
	}
	printf("已逆置链表\n");
}