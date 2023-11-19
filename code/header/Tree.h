#ifndef _TREE_H_
#define _TREE_H_

//Binary tree, balanced tree
typedef struct TNode {
    int data;
    TNode * lchild, * rchild;
}TNode, *BiTree;

BiTree createTree();
void preOrder(BiTree T);
void inOrder(BiTree T);
void postOrder(BiTree T);
void levelOrder(BiTree T);


struct Node{
    TNode* t;
    Node *next;
};
typedef struct{
    Node * front, * rear;
} Queue;
bool EnQueue(Queue &Q, TNode* x){
    Node* p = new Node;
    p -> t = x;
    p -> next = NULL;
    Q.rear ->next = p;
    Q.rear = p;
    return true;
}
BiTree DeQueue(Queue &Q){
    Node *q = Q.front;
    BiTree x = Q.front->next->t;
    Q.front = Q.front ->next;
    free(q);
    return x;
}
void createTree(BiTree &T){//先序序列创建
	int a; cin>>a;
	if (a == 0) // '#'
		T = NULL;
	else{
		T = new TNode;
		T-> data = a;
		createTree(T->lchild);
		createTree(T->rchild);
	}
}
void preOrder(BiTree T){
    if(T!=NULL){
        printf("%d ", T->data);
        preOrder(T->lchild);
        preOrder(T->rchild);
    }
}
void inOrder(BiTree T) { 
    if(T!=NULL){
        inOrder(T->lchild);
        printf("%d ", T->data);
        inOrder(T->rchild);
    }
}
void postOrder(BiTree T) {
    if(T!=NULL){
        postOrder(T->lchild);
        postOrder(T->rchild);
        printf("%d ", T->data);
    }
}
void levelOrder(BiTree T){
    Queue Q;
    Q.front = Q.rear = new Node;
    Q.front->next = NULL;
    BiTree p;
    EnQueue(Q, T);
    while(Q.rear != Q.front){ //队列非空        
        p = DeQueue(Q);
        cout << p->data<< " ";
        if (p->lchild!=NULL)
            EnQueue(Q, p->lchild);
        if (p->rchild!=NULL)
            EnQueue(Q, p->rchild);
    }
}
// 二叉排序树的查找
TNode * BST_Search(BiTree T, int key){
    while(T){
        if(T->data == key) break;
        if(T->data > key) T=T->lchild;
        if(T->data < key) T=T->rchild;
    }return T;
}

#endif