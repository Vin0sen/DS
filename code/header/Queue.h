#ifndef _QUEUE_H_
#define _QUEUE_H_

#include<stdio.h>
#include<stdlib.h>
#include<iostream>
using namespace std;
#define MaxSize 10

/* 队列结构声明 */
// 顺序存储 —— 循环队列
struct SeqQueue{
    int data[MaxSize];
    int front, rear;
};
// 链式存储 —— 链队列
struct QNode{
    int data;
    QNode *next;
};
typedef struct{
    QNode * front, * rear;
} LinkQueue;

// 基本操作声明
SeqQueue createQueue();
bool QueueEmpty(SeqQueue Q);
bool enQueue(SeqQueue &Q, int x);
int delQueue(SeqQueue &Q);
int len(SeqQueue Q);
void printQueue(SeqQueue Q);

LinkQueue initQueue();
LinkQueue createLinkQueue();
bool QueueEmpty(LinkQueue Q);
bool enQueue(LinkQueue &Q, int x);
int delQueue(LinkQueue &Q);
int len(LinkQueue Q);
void printQueue(LinkQueue Q);

// 实现 Queue.cpp
// ------------------ 循环队列
SeqQueue createQueue(){
    int x;cin>>x;
    SeqQueue Q;
    Q.rear = Q.front = 0; // 初始化队列
    while(x && Q.rear<MaxSize){
        Q.data[Q.rear++] = x;
        cin>>x;
    }
    return Q;
}
bool QueueEmpty(SeqQueue Q){
    if (Q.rear == Q.front)return true;
    return false;
}
bool enQueue(SeqQueue &Q, int x){
    // 队满条件: (Q.rear+1)%MaxSize == Q.front
    if((Q.rear+1)%MaxSize == Q.front){
        printf("队列已满, 无法入队\n");
        return false;
    }
    Q.data[Q.rear] = x;
    Q.rear = (Q.rear + 1)%MaxSize;
    return true;
}
int delQueue(SeqQueue &Q){
    // 队空条件: Q.rear == Q.front
    if (Q.rear == Q.front){
        printf("队空, 无法出队\n");
        return 0;
    }
    int tmp = Q.front;
    Q.front = (Q.front+1)%MaxSize;
    return Q.data[tmp];
}
int len(SeqQueue Q){
    return (Q.rear -Q.front+MaxSize) % MaxSize;
}
void printQueue(SeqQueue Q){
    if (Q.rear == Q.front)
        printf("队空\n");

    int r = (Q.rear < Q.front)? Q.rear + MaxSize:Q.rear;
    
    printf("front:%d\trear:%d\tlength:%d\n", Q.front, Q.rear, len(Q));
    for(int i=Q.front; i< r; i++)
        cout<<Q.data[i%MaxSize]<<" ";
    cout<<endl;
}
// ------------------ 链队
LinkQueue initQueue(){
    LinkQueue Q;
    Q.front = Q.rear = (QNode*)malloc(sizeof(QNode));
    Q.front->next = NULL;
    return Q;
}
LinkQueue createLinkQueue(){
    int x;cin>>x;
    LinkQueue Q = initQueue();
    while (x){
        QNode * q = new QNode;
        q->data =x;
        q->next = NULL;
        Q.rear -> next = q;
        Q.rear = q;
        cin>>x;
    }return Q;
    
}
bool QueueEmpty(LinkQueue Q){
    if (Q.front == Q.rear)
        return true;
    return false;
}
bool enQueue(LinkQueue &Q, int x){
    QNode* p = (QNode *)malloc(sizeof(QNode));
    if (!p) return false; // 内存分配失败
    p -> data =x;
    p -> next = NULL;
    Q.rear ->next = p;
    Q.rear = p;
    return true;
}
int delQueue(LinkQueue &Q){
    QNode *p = Q.front;
    int x = Q.front->next->data;
    Q.front = Q.front ->next;
    free(p);
    return x;
}
int len(LinkQueue Q)
{
    QNode *q= Q.front->next;
    int l=0;
    while (q){
        l++;
        q = q->next;
    }return l;
}
void printQueue(LinkQueue Q)
{
    QNode *q= Q.front->next;
    printf("length:%2d; queue: ", len(Q));
    while (q){
        cout<<q->data<<" -> ";
        q = q->next;
    }cout<<"NULL"<<endl;
}
#endif