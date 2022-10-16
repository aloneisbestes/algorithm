#include <stdio.h>
#include <stdlib.h>
#include "OrthList.h"

// 创建十字链表
void CreateOrthList(GraphOrth *g) {
    int i, j, k;

    printf("请输入当前的顶点个数及边数: \n");
    scanf("%d %d", &g->numVertex, &g->numEdge);
    getc(stdin);

    // 初始化顶点
    printf("请输入顶点信息: \n");
    for (i = 0; i < g->numVertex; i++) {
        scanf("%c", &g->orthList[i].data);
        getc(stdin);
        g->orthList[i].firstin = NULL;
        g->orthList[i].firstout = NULL;
    }

    // 初始化边
    int edges[VERTEXMAX][2];
    for (k = 0; k < g->numEdge; k++) {
        printf("请输入边<vi, vj>的下标: \n");
        scanf("%d %d", &i, &j);

        // 初始化边
        EdgeNode *tmp = (EdgeNode *)malloc(sizeof(EdgeNode));
        tmp->headvex = g->orthList[i].data;
        tmp->tailvex = g->orthList[j].data;

        // 头插法插入新的p结点
        // 确定入边, i的入边就是j的出边
        tmp->headlist = g->orthList[j].firstin;
        // 确定出边, i的入边
        tmp->taillist = g->orthList[i].firstout;
        // 添加节点
        g->orthList[j].firstin = g->orthList[i].firstout = tmp;
    }
}

void PrintOrthList(GraphOrth *g) {
    // 入度
    for (int i = 0; i < g->numVertex; i++) {
        EdgeNode *move = g->orthList[i].firstout;
        printf("vertex %c of out edge: ", g->orthList[i].data);
        while (move) {
            printf("%c ", move->tailvex);
            move = move->taillist;
        }
        printf("\n");
    }

    // 出度
    for (int i = 0; i < g->numVertex; i++) {
        EdgeNode *move = g->orthList[i].firstin;
        printf("vertex %c of in edge: ", g->orthList[i].data);
        while (move) {
            printf("%c ", move->headvex);
            move = move->headlist;
        }
        printf("\n");
    }
}

void DestroyRothList(GraphOrth *g) {
    for (int i = 0; i < g->numVertex; i++) {
        EdgeNode *move, *tmp;
        move = g->orthList[i].firstout;
        while (move) {
            tmp = move;
            move = move->taillist;
            free(tmp);
        }
    }
}