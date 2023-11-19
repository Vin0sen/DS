#pragma once
#include<iostream>
#include<stdio.h>
#include "Queue.h"
using namespace std;

#define N 8
// 邻接矩阵表示
struct MGraph{
    char vertex[N]; // 顶点表
    int edge[N][N]; // 边表
    int vexnum, arcnum; // 顶点数和边数
};
// 邻接表表示
struct ArcNode{ //边表结点
    int a;
    ArcNode * next;
};
typedef struct VNode{ // 顶点表结点
    char vertex;
    ArcNode * first;
}VNode, AdjList;

struct ALGraph{ // 邻接表
    AdjList vertices;
    int vexnum, arcnum;
};

#define Graph MGraph
int FirstNeighbor(Graph G, int v);
int NextNeighbor(Graph G, int v, int w);
void DFS(Graph G, int v);

Graph createGraph(){
    Graph G; int b;
    for (int i = 0; i < N; i++){
        cin>> G.vertex[i];
        for (int j = 0; j < N; j++){
            cin>>b;
            if(b==-1)
                while(j++<N)
                    G.edge[i][j-1]=0;
            else G.edge[i][j] = b;
        }
    }return G;
}
void printGraph(MGraph G){
    for (int i = 0; i < N; i++){
        for(int j = 0;j<N;j++){
            printf("%d ", G.edge[i][j]);
        }printf("\n");
    }
    
}
bool visited[N]={false};
void resetVisited(){
    // 每次搜索之后, 访问标记数组要重置
    for(int i=0;i<N;i++)visited[i] = false;
}
// 深度优先搜索
// 图的深搜(通用连通图和非连通图)
void DFSTraverse(MGraph G){
    for (int v=0; v < G.vexnum; v++) 
        visited[v]=false;
    for (int v=0; v<G.vexnum; v++)
        if(!visited[v])
            DFS(G, v);
}
// 连通图 深搜 —— 从顶点V出发
void DFS(Graph G, int v=1){
    if(v<1 || v>N)return;
    printf("%c ", G.vertex[v-1]);
    visited[v-1]=true;
    for(int w=FirstNeighbor(G,v);w>0;w=NextNeighbor(G,v,w))
        if(!visited[w-1])
            DFS(G,w);
}
int FirstNeighbor(Graph G, int v){
    //返回第i个顶点的第一个邻接点
    for(int i=0;i<N;i++){
        if(G.edge[v-1][i])return i+1;
    }
    return 0;
}
int NextNeighbor(Graph G, int v, int w){
    for(int i=w;i<N;i++){
        if(G.edge[v-1][i])return i+1;
    }
    return 0;
}

// 广度优先搜索
void BFS(Graph G, int v){
    if(v<1 || v>N)return;
    printf("%c ", G.vertex[v-1]);
    visited[v-1]=true;
    LinkQueue Q = initQueue();
    enQueue(Q, v);
    while(Q.rear !=Q.front){
        v = delQueue(Q);
        for(int w=FirstNeighbor(G, v);w>0;w=NextNeighbor(G,v,w)){
            if(!visited[w-1]){
                printf("%c ", G.vertex[w-1]);
                visited[w-1]=true;
                enQueue(Q, w);
            }
        }
    }printf("\n");
}