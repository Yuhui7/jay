#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#define _LinkList_H_

typedef struct LNode {
	int data;
	struct LNode* next;
}LNode,*LinkList;


	int x;								//传入data


int main()
{	
	int a=0;								
	LNode* L;
	L = (LNode*)malloc(sizeof(LNode));
	printf("功能\n1输入数据x建立链表。	2显示链表。\n");
	printf("3在节点插入数据。	4删除节点。\n");
	printf("5交换奇偶节点。		6找中间节点。\n");
	while(1)
	{	
		printf("功能：");
		scanf("%d", &a);
		switch (a)
		{
			case 1:InitList(L); break;					//输入数据x建立链表
			case 2:DisplayLink(L); break;				//显示链表
			case 3:ListInsert(L); break;				//第i个节点插入数据x
			case 4:DeleteList(L); break;				//删除节点
			case 5:EChangeList(L); break;				//奇偶节点交换
			case 6:FindMidList(L); break;				//找中间节点
			case 7:JudgRing(L); break;					//判断是否成环
			case 8:ReverseList(L); break;				//逆置链表
			default:printf("无此功能\n");
		}
	}
	return 0;
}