#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>


typedef struct LNode {
	int data;
	struct LNode* next;
}LNode, * LinkList;

int x;

void InitList(LinkList L)		//β��
{
	int k = 0;
	printf("����������(��0����)\n");
	scanf("%d", &x);
	if (L == NULL)
	{
		printf("�����ڴ�ʧ��");
		k++;
	}
	L->next = NULL;							//��ʼ��
	LNode* s, * p;							//pָ�����һ���ڵ�
	p = L;
	while (x != 0)
	{
		if (p == NULL)
		{
			printf("pָ��NULL");
			k++;
			break;
		}
		s = (LNode*)malloc(sizeof(LNode));	//���ڵ�s
		if (s == NULL)
		{
			printf("�����ڴ�ʧ��");
			k++;
			break;
		}
		s->data = x;
		s->next = p->next;
		p->next = s;
		p = p->next;
		scanf("%d", &x);
	}
	if (k == 0)printf("1�����\n");
}

void DisplayLink(LinkList L)
{
	LNode* p = L->next;					//����ָ��pָ���һ���ڵ�
	while (p != NULL)
	{
		printf("%d->", p->data);		//��ӡ����
		p = p->next;					//ָ���ƶ���һ���ڵ�
	}
	printf("NULL\n");
}

void ListInsert(LinkList L)	//�ڵ�i���ڵ���������x
{
	int k = 0;
	LNode* h, * s;
	h = L;
	int i = 0, j = 0, x = 0;
	printf("ѡ�����ڵ�:");
	scanf("%d", &i);
	printf("����:");
	scanf("%d", &x);
	if (i < 0)printf("�޴˽ڵ�");
	for (j = 1; j < i; j++)
	{
		h = h->next;
	}
	if (h == NULL)
	{
		printf("hָ��NULL");
		k++;
	}
	s = (LNode*)malloc(sizeof(LNode));	//���ڵ�s
	if (s == NULL)
	{
		printf("�����ڴ�ʧ��");
		k++;
	}
	s->data = x;
	s->next = h->next;
	h->next = s;
	if (k == 0)printf("�Ѳ���");
}

int DeleteList(LinkList L)
{
	int i = 0, j = 0, k = 0;
	LNode* p, * q;
	p = L;
	printf("ѡ��ɾ���ڵ�:");
	scanf("%d", &i);
	for (j = 1; j < i; j++)
	{
		p = p->next;
	}
	if (p->next == NULL)
	{
		printf("�˽ڵ�Ϊ��");
		k++;
		return 0;
	}
	q = p->next;
	p->next = q->next;
	free(q);
	if (k == 0)printf("��ɾ��\n");
}

void EChangeList(LinkList L)				//��ż�ڵ㽻��
{
	int temp = 0;
	if (L->next != NULL)
	{
		LNode* j = L->next;					//jָ����ڵ�
		if (j->next != NULL)
		{
			LNode* o = j->next;		//oָ��ż�ڵ�
			while (1)
			{
				temp = j->data;
				j->data = o->data;
				o->data = temp;
				j = o->next;
				if (j->next == NULL)break;
				else o = j->next;
			}
			printf("�����\n");
		}
	}
}

void FindMidList(LinkList L)
{
	int i = 0, j = 0, k = 0;						//i�ƽڵ���,k=0ִ�гɹ�
	LNode* p = L;							//p�����ڵ�
	while (p->next != NULL)
	{
		++i;
		p = p->next;
	}
	p = L->next;							//p�������е�		
	if (i % 2 == 0)
	{
		printf("ż�����ڵ����м�ڵ�\n");
		k++;
	}
	else for (; j < i / 2, p->next == NULL; j++)
	{
		p = p->next;
	}
	if (k == 0)printf("�м�ڵ�����Ϊ��%d\n", p->data);
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
			printf("�������л�\n");
			break;
		}
	}
	printf("�������޻�\n");
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
	printf("����������\n");
}