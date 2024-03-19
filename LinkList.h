#ifndef _LinkList_H_
#define _LinkList_H_

typedef struct LNode {
	int data;
	struct LNode* next;
}LNode, * LinkList;

void InitList(LinkList L);				//建立链表
void DisplayLink(LinkList L);			//显示链表
void ListInsert(LinkList L);			//在第i个节点后插入数据x
int DeleteList(LinkList L);				//删除节点
void EChangeList(LinkList L);			//奇偶节点交换
void FindMidList(LinkList L);
void JudgRing(LinkList L);
void ReverseList(LinkList L);




#endif
