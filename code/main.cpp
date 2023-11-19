#include<iostream>
#include "head/Stack.h"
#include "head/Queue.h"
#include "head/Tree.h"
#include "head/graph.h"
using namespace std;

void testLinkStack();
void testSeqQueue();
void testLinkQueue();
void testTree();
void testGraph();

int main(){
    // testLinkQueue();
    // testTree();
    testGraph();
    return 0;    
}

void testLinkStack(){
    LinkStack S = createStack();
    printStack(S);

    pushStack(S, 10);
    printStack(S);
    
    cout<<popStack(S)<<endl;
    printStack(S);
    destroyStack(S);
}
void testSeqQueue(){
    SeqQueue Q = createQueue();
    printQueue(Q);
    delQueue(Q); delQueue(Q);
    printQueue(Q);

    for (int i = 1; i<8;i++) enQueue(Q, i*10);
    printQueue(Q);
    enQueue(Q, 70);
}

void testLinkQueue(){
    LinkQueue Q = createLinkQueue();
    printQueue(Q);
    for (int i = 5; i < 9; i++){
        enQueue(Q, i);
    }
    printQueue(Q);
    printf("出队:%d\n", delQueue(Q));
    printf("出队:%d\n", delQueue(Q));
    printQueue(Q);
}
void testTree(){
    /**
     *       1
     *    2    3
     *  0   4 0 5
     *     6 0  00
     *    00
     * input: 1 2 0 4 6 0 0 0 3 0 5 0 0
    */
    BiTree T;
    createTree(T);

    preOrder(T);printf("\n");
    inOrder(T);printf("\n");
    postOrder(T);printf("\n");
    levelOrder(T);printf("\n");
}

void testGraph(){
/*
A 0 1 0 1 0 
B 1 0 1 0 1
C 0 1 0 1 1
D 1 0 1 0 0
E 0 1 1 0 0*/
    Graph G = createGraph();
    // printGraph(G); 
    // 广搜
    BFS(G, 5);
    // 深搜
    // cout<<FirstNeighbor(G,5);
    resetVisited();
    DFS(G, 1);cout<<endl;
    resetVisited();
    DFS(G, 2);cout<<endl;
    resetVisited();
    DFS(G, 3);cout<<endl;
}
/*
1 0 1 0 0 1 -1
2 1 0 0 0 0 1 -1
3 0 0 0 1 0 1 1 0
4 0 0 1 0 0 0 1 1
5 1 -1
6 0 1 1 0 0 0 1 0
7 0 0 1 1 0 1 0 1
8 0 0 0 1 0 0 1 0
*/