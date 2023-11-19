#include<stdio.h>
#include<iostream>
using namespace std;
#define MaxSize 10

/* 栈结构声明 */
// 顺序存储 —— 顺序栈
struct SeqStack{
    int data[MaxSize];
    int top;
};
// 链式存储 —— 链栈
typedef struct LinkNode{
    int data;
    LinkNode * next;
} *LinkStack;

/* 基本操作声明 */
void initStack(SeqStack &S);
bool StackEmpty(SeqStack S);
bool pushStack(SeqStack &S, int x);
int popStack(SeqStack &S);
int getTop(SeqStack S);

/* 实现 Stack.cpp */
void initStack(SeqStack &S){
    S.top = -1;
}
bool StackEmpty(SeqStack S){
    if(S.top == -1)return true;
    return false;
}
bool pushStack(SeqStack &S, int x){
    if(S.top == MaxSize){
        printf("栈满, 无法入栈\n");
        return false;
    }
    S.top++;
    S.data[S.top] = x;
    return true;
}
int popStack(SeqStack &S){
    if(S.top == -1){
        printf("栈空, 无法出栈\n");
        return false;
    }int tmp = S.top--;
    return S.data[tmp];
}
int getTop(SeqStack S){
    if(S.top == -1)return false;
    return S.data[S.top];
}

// 链栈 operation
bool empty(LinkStack S);
void pushStack(LinkStack &S, int x);
LinkStack createStack();
int popStack(LinkStack &S);
void printStack(LinkStack S);

bool empty(LinkStack S){ // 判空
	return (S==NULL)?true:false;
}
LinkStack createStack(){
    int x;cin>>x;
    LinkStack S = NULL; // 栈不带头节点
    
    while (x){
        pushStack(S, x);
        cin>>x;        
    }return S;
    
}
void pushStack(LinkStack &S, int x){
    LinkNode * p = new LinkNode;
    p->data = x;
    p->next = S;
    S = p;
}
int popStack(LinkStack &S){
    LinkNode * p = S;
    int ret = p->data;
    S = p->next;
    free(p);
    return ret;
}
void printStack(LinkStack S){
    LinkNode * p=S;
    while(p!=NULL){
        cout<<p->data<<" ";
        p=p->next;
    }cout<<endl;
}
void destroyStack(LinkStack &S){
    LinkStack p, q;
    p = S->next;
    while(p){
        q=p->next;
        delete p; // free(p)
        p=q;
    }
    S->next = NULL;
}