#ifndef _LinkList_H_
#define _LinkList_H_

typedef struct LNode {
	int data;
	struct LNode* next;
}LNode, * LinkList;

void InitList(LinkList L);				//��������
void DisplayLink(LinkList L);			//��ʾ����
void ListInsert(LinkList L);			//�ڵ�i���ڵ���������x
int DeleteList(LinkList L);				//ɾ���ڵ�
void EChangeList(LinkList L);			//��ż�ڵ㽻��
void FindMidList(LinkList L);
void JudgRing(LinkList L);
void ReverseList(LinkList L);




#endif
