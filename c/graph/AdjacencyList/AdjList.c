#include <stdio.h>
#include <malloc.h>
#include "AdjList.h"

// 创建图
void CreateAdjListGraph(GraphAdjList *g) {
    // 需要使用的变量
    int i, j, w, k;
    // 输入顶点个数和边数
    printf("请输入顶点个数和边个条数(1 2): \n");
    scanf("%d %d", &g->numVertex, &g->numEdge);
    getc(stdin); // 去除scanf最后一个没有读取的 \n

    // 初始化顶点
    printf("请输入顶点信息: \n");
    for (i = 0; i < g->numVertex; i++) {
        // 初始化顶点值
        scanf("%c", &g->adjList[i].data);
        // 初始化顶点的第一个边表为NULL
        g->adjList[i].firstEdge = NULL;
        getc(stdin);    // 吃掉 scanf 输入时的回车键或其他空格键
    }

    // 创建无向有权图
    for (k = 0; k < g->numEdge; k++) {
        printf("请输入(vi,vj)的下标和权(1 2 10): \n");
        scanf("%d %d %d", &i, &j, &w);
        getc(stdin);

        // 添加到顶点对应的边表上，因为是无向图，所以两边顶点都需要添加
        // 添加顶点i的邻接点
        AddEdge(g, i, j, w);
        // 添加顶点j的邻接点
        AddEdge(g, j, i, w);
    }
}

// 添加边
void AddEdge(GraphAdjList *g, int i, int j, int w) {
    EdgeNode *tmp = (EdgeNode *)malloc(sizeof(EdgeNode));
    tmp->idxVertex = j;
    tmp->weight = w;
    tmp->pnext = g->adjList[i].firstEdge;
    g->adjList[i].firstEdge = tmp;
}

// 打印邻接表
void PrintGraphAdjList(GraphAdjList *g) {
    for (int i = 0; i < g->numVertex; i++) {
        EdgeNode *move = g->adjList[i].firstEdge;
        printf("%c的邻接点: ", g->adjList[i].data);
        while (move) {
            printf("%d ", move->idxVertex);
            move = move->pnext;
        }
        printf("\n");
    }
}

// 销毁邻接表
void DestroyGraphAdjList(GraphAdjList *g) {
    for (int i = 0; i < g->numVertex; i++) {
        EdgeNode *move = g->adjList[i].firstEdge;
        EdgeNode *tmp = NULL;
        while (move){ 
            tmp = move;
            move = move->pnext;
            free(tmp);
        }
    }
}