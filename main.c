#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#define _LinkList_H_

typedef struct LNode {
	int data;
	struct LNode* next;
}LNode,*LinkList;


	int x;								//����data


int main()
{	
	int a=0;								
	LNode* L;
	L = (LNode*)malloc(sizeof(LNode));
	printf("����\n1��������x��������	2��ʾ����\n");
	printf("3�ڽڵ�������ݡ�	4ɾ���ڵ㡣\n");
	printf("5������ż�ڵ㡣		6���м�ڵ㡣\n");
	while(1)
	{	
		printf("���ܣ�");
		scanf("%d", &a);
		switch (a)
		{
			case 1:InitList(L); break;					//��������x��������
			case 2:DisplayLink(L); break;				//��ʾ����
			case 3:ListInsert(L); break;				//��i���ڵ��������x
			case 4:DeleteList(L); break;				//ɾ���ڵ�
			case 5:EChangeList(L); break;				//��ż�ڵ㽻��
			case 6:FindMidList(L); break;				//���м�ڵ�
			case 7:JudgRing(L); break;					//�ж��Ƿ�ɻ�
			case 8:ReverseList(L); break;				//��������
			default:printf("�޴˹���\n");
		}
	}
	return 0;
}