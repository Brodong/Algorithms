/***********************************************
♡        Filename : undirected_graph.cpp
♡  
♡     Description : ---
♡          Author : Li Xudong
♡         Contact : 757264690@qq.com
♡         Created : 2020-12-07 20:30:59
***********************************************/
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
using namespace std;


const int maxn = 100;
// 构建无向图的邻接表
//
// 构建边集合
typedef struct Edge{
    string data;
    struct Edge *nextArc;
}Edge;

// 构建顶点集合
typedef struct Node{
    string data;
    struct Edge *firstArc;
}Node;

// 构建图
typedef struct Graph{
    int numVertex;
    int numArc;
    Node adjList[maxn]; // 邻接表
}Graph;

int locate(Graph g, string s)
{
    int i;
    for(i=0; i<g.numVertex; i++)
    {
        if(g.adjList[i].data == s)
            return i;
    }
    return -1;
}

int main()
{
    int i;
    Graph G;
    string left, right; // 边的左边顶点和右边顶点
    int L, R; // 边的左顶点的id号和边的右顶点的id号
    Edge *first, *next;
    printf("Please input the number of Vertices:\n");
    scanf("%d", &G.numVertex);
    printf("Please input the data of Vertices:\n");
    for(i=0; i<G.numVertex; i++)
    {
        cin>>G.adjList[i].data;
        G.adjList[i].firstArc = NULL;
    }

    printf("Please input the number of edges:\n");
    scanf("%d", &G.numArc);
    printf("Please input the edges:\n");
    for(i=0; i<G.numArc; i++)
    {
        cin>>left>>right;
        L = locate(G, left);
        first = G.adjList[L].firstArc;
        next = (struct Edge*)malloc(sizeof(Edge));
        next->data = right;
        next->nextArc = first;
        G.adjList[L].firstArc = next;
    }

    // 输出邻接表
    for(i=0; i<G.numVertex; i++)
    {
        cout<<"顶点："<<G.adjList[i].data;
        first = G.adjList[i].firstArc;
        next = first;
        while(next!=NULL)
        {
            cout<<"->";
            cout<<next->data;
            next = next->nextArc;
        }
        cout<<endl;
    }

}


/*
Please input the number of Vertices:
5
Please input the data of Vertices:
lizzie kevin bohdan lalit ruoyu
Please input the number of edges:
5
Please input the edges:
lizzie kevin
lizzie bohdan
lizzie ruoyu
bohdan lalit
lalit ruoyu
顶点：lizzie->ruoyu->bohdan->kevin
顶点：kevin
顶点：bohdan->lalit
顶点：lalit->ruoyu
顶点：ruoyu
*/
