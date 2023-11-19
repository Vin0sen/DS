#include<iostream>
#include<stdio.h>
#include<stdlib.h>
using namespace std;

typedef struct LinkNode{
    int data;
    LinkNode * next;
}LinkNode, *LinkList;

bool InitList(LinkList &L);
// 单链表创建
void ListHeadInsert(LinkList &L);
void ListTailInsert(LinkList &L);
// 单链表的查找
LinkNode* GetElem(LinkList L, int i);
// 单链表插入和删除
bool ListInsert(LinkList &L, int i, int e);
bool ListDelete(LinkList &L, int i);
void PrintList(LinkList &L);
int main(){
    LinkList L1, L2;
    ListTailInsert(L1);
    // ListHeadInsert(L2);
    PrintList(L1);
    cout<<GetElem(L1, 2)->data;
    // ListInsert(L, 1, 0);
    // ListDelete(L, 2);
    // PrintList(L2);
    return 0;
}
// 头插法
void ListHeadInsert(LinkList &L){
    LinkNode *s;int x; 
    L=(LinkNode *)malloc(sizeof(LinkNode));
    L->next = NULL;
    scanf("%d", &x);
    while(x!=0){
        s = (LinkNode*)malloc(sizeof(LinkNode));
        s->data = x;
        s->next = L->next;
        L->next = s;
        scanf("%d", &x);
    }
}
// 尾插法
void ListTailInsert(LinkList &L){
    int x; 
    L = (LinkList)malloc(sizeof(LinkNode)); // 头节点
    LinkNode *s, *r=L; // r为表尾指针
    scanf("%d", &x);
    while(x!=0){
        s = (LinkNode*)malloc(sizeof(LinkNode));
        s->data = x;
        r->next = s;
        r = s;
        scanf("%d", &x);
    }
    r->next=NULL; // 尾指针置空
}
// 按位查找, 返回第i个元素指针
LinkNode *GetElem(LinkList L, int i){
    if(i<0)return nullptr;
    LinkNode * p = L;
    int j = 0;
    while(p->next!=NULL && j<i){
        p=p->next;
        j++;
    }
    return p;
}
bool ListInsert(LinkList &L, int i, int e)
{
    if(i<1)return false;
    LinkNode *p; // 指针p最后指向要插入位置的前一个结点
    int j = 0;   // 当前p指向第j个结点, 头节点是第0个结点
    p=L;
    while (p!=NULL && j<i-1){//循环找到第 i-1 个结点
        p = p->next;
        j++;
    }
    if (p==NULL) // i值超出链表长度, 不合法
        return false;
    
    LinkNode *s = (LinkNode *) malloc(sizeof(LinkNode));
    s->data = e;
    s->next = p->next;
    p->next = s;
    return true;
}

bool ListDelete(LinkList &L, int i)
{
    LinkNode *p;
    p=L;
    int j=0;
    while (p!=NULL && j<i-1){
        j++;
        p=p->next;
    }
    if (p==NULL)return false;
    p->next = p->next->next;
    return false;
}
void PrintList(LinkList &L) //顺序打印表中数据
{
	LinkNode* p;
	p = L;
	if(p->next == NULL)	//这种是含头节点链表的输出方法
	{
		printf("表中没有数据，只有一个头节点！\n");
		return ;
	}
	p = p->next;	//p指针指向第一个数据节点 
	while(p != NULL){
		printf("%d ",p->data);
		p = p->next;	//p指针指向下一个数据节点 
	}printf("\n");
}