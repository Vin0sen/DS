#include<iostream>
#include<stdio.h>
#include<stdlib.h>
using namespace std;
#define MaxSize 10

/* 线性表 */
// 顺序表
struct SqList{
    int data[MaxSize];
    int length;
};
// 链表
typedef struct LNode{
    int data;
    LNode * next;
}LNode, *LinkList;

/* 基本操作声明 */
//-------- 顺序表函数声明
// void initList(SqList &L);
// bool empty(SqList L);
// int getElem(SqList L, int i);
// bool ListInsert(SqList &L, int i, int x);
// int ListDel(SqList &L, int i);
// void printList(SqList L);

//-------- 单链表函数声明
LinkList headInsert();
LinkList tailInsert();
LNode* getElem(LinkList L, int i);
void ListInsert(LinkList &L, int i, int x);
void ListDel(LinkList &L, int i);
int len(LinkList L);
void printList(LinkList L);
void destroyList(LinkList &L);

/* 实现 List.cpp */
void initList(SqList &L){
    L.length = 0;
}
bool empty(SqList L){
    return L.length == 0?true:false;
}
// 在第 i 个位置插入元素
bool ListInsert(SqList &L, int i, int e){
    if(i<1 || i>L.length+1)
        return false;
    if(L.length >= MaxSize)
        return false;
    for (int j=L.length-1; j>=i; j--)
        L.data[j] = L.data[j-1];
    L.data[i-1] = e;
    L.length++;
    return true;
}
// 删除第 i 个元素
int ListDel(SqList &L, int i){
    int e = L.data[i-1];
    for(int j = i; j<L.length; j++)
        L.data[j-1] = L.data[j];
    L.length --;
    return e;
}

int getElem(SqList L, int i){
    return L.data[i];
}

void printList(SqList L)
{
    for(int i=0; i<L.length;i++)
        printf("%d ", L.data[i]);
    printf("\n");
}

// ---------------- 单链表函数实现
bool initList(LinkList &L){ // 带头结点的链表的初始化
    L = new LNode;
    if (L==NULL)return false; //内存分配失败
    L->next = NULL;
    return true;
}
// 头插法创建单链表
LinkList headInsert(){
    LinkList L = new LNode;   
    L -> next = NULL;
    LNode * p;
    int x; cin>> x;
    while(x!=0){
        p = new LNode;
        p->data =x;
        p->next =L->next;
        L->next = p;
        cin>>x;
    }return L;
}
// 尾插法创建单链表
LinkList tailInsert(){
    LinkList L = new LNode;
    LNode *p, *rear=L;  // rear表示表尾结点
    int x; cin>>x;  
    while (x!=0){
        p = new LNode;
        p -> data =x;
        rear -> next = p;
        rear = p;
        cin>>x;
    }rear -> next = NULL;
    return L; 
}
// 找到第 i 个结点
LNode* getElem(LinkList L, int i){
    if(i < 1)return NULL;
    LNode* p = L->next;
    for(int j=1;j<i;j++)
        p = p->next;
    return p;
}
// 第i个位置插入结点
void ListInsert(LinkList &L, int i, int x){
    LNode* p = getElem(L, i-1);
    LNode * s = new LNode;
    s->data = x;
    s->next = p->next;
    p->next =s;
}

// 删除第i个结点
void ListDel(LinkList &L, int i){
    LNode * p = getElem(L, i-1);
    p->next = p->next->next;
}
int len(LinkList L){
    LNode * p = L;int l=0;
    while(p->next!=NULL){
        l++;
        p = p->next;
    }
    return l;
}
// 打印链表
void printList(LinkList L){
    /* 这里要小心, 
    (1) L是指针不是局部变量，不能直接遍历 L = L->next;
    (2) L是头指针, 指向的是头结点, 故要再指向下一个
    */
    LNode* p = L->next; 
	cout<< "head -> ";
    while (p!=NULL){
		if (p -> next == nullptr)
			cout << p->data<<"-> NULL";
		else
			cout << p->data << "-> ";
		p = p->next;
	}
	cout << endl;
}
void destroyList(LinkList &L){
    LinkList p, q;
    p = L->next;
    while(p){
        q=p->next;
        delete p; // free(p)
        p=q;
    }
    L->next = NULL;
}