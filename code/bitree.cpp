#include<iostream>
#include<stdio.h>
#include<stdlib.h>
using namespace std;

typedef struct BiTNode{
    int data;
    BiTNode * lchild, * rchild;
}BiTNode, *BiTree;

void visit(BiTNode *bitnode);
void PreOrder(BiTree T);
void InOrder(BiTree T);
void PostOrder(BiTree T);
int main(){
    
    return 0;
}

void visit(BiTNode *bitnode){
    printf("%d", bitnode->data);
}

void PreOrder(BiTree T)
{
    if(T!=NULL){
        visit(T);
        PreOrder(T->lchild);
        PreOrder(T->rchild);
    }
}

void InOrder(BiTree T)
{
    if(T!=NULL){
        InOrder(T->lchild);
        visit(T);
        InOrder(T->rchild);
    }
}

void PostOrder(BiTree T)
{
    if(T!=NULL){
        PostOrder(T->lchild);
        PostOrder(T->rchild);
        visit(T);
    }
}
