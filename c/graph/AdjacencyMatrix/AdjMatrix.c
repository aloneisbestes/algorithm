#include <stdio.h>
#include "AdjMatrix.h"


// 创建图的邻接矩阵表示
void createAdjMat(AdjMat *g, int type) {
    g->graphType = type;    // 初始化图的类型，有向图还是无向图，是否有权

    // 初始化顶点数组
    int i, j, k;
    EdgeType w;     // 权重
    printf("请输入顶点个数和边的条数: \n");
    scanf("%d %d", &g->numVertexes, &g->numEdges);
    printf("请输入顶点信息: \n");
    for (i = 0; i < g->numVertexes; i++) {
        // 解决 scanf 被跳过
        getc(stdin);
        scanf("%c", &g->vexs[i]);
    }

    // 初始化邻接矩阵
    // 显判断是什么图，是否为网图
    int value = 0;
    if (g->graphType & GRAPH_TYPE_WDIRECTED || g->graphType & GRAPH_TYPE_WEDGE) {
        // 表示初始化为无穷大
        value = INFINITY;
    }
    // 开始初始化
    for (i = 0; i < g->numVertexes; i++) 
        for (j = 0; j < g->numVertexes; j++) 
            if (i == j) 
                g->arc[i][j] = 0;
            else 
                g->arc[i][j] = value;
    
    // 创建图
    for (k = 0; k < g->numEdges; k++) {
        if (g->graphType & GRAPH_TYPE_WDIRECTED || g->graphType & GRAPH_TYPE_WEDGE) {
            // 如果是网图需要有权重
            printf("请输入<vi,vj>/(vi,vj)的下标和权(1 2 10): \n");
            getc(stdin);
            scanf("%d %d %d", &i, &j, &w);
            if (g->graphType & GRAPH_TYPE_WDIRECTED) {
                // 表示是有向网图
                g->arc[i][j] = w;
            } else {
                // 表示为无向网图
                g->arc[i][j] = w;
                g->arc[j][i] = w;
            }
        } else {
            // 否则就是不带权的图
            printf("请输入<vi,vj>/(vi,vj)的下标(1 2): \n");
            getc(stdin);
            scanf("%d %d", &i, &j);
            if (g->graphType & GRAPH_TYPE_EDGE) {
                // 无向图
                g->arc[i][j] = 1;
                g->arc[j][i] = 1;
            } else {
                // 有向图
                g->arc[i][j] = 1;
            }
        }
    }
}

// 打印图
void printAdjMat(AdjMat *g) {
    for (int i = 0; i < g->numVertexes; i++) {
        for (int j = 0; j < g->numVertexes; j++) {
            j == 0 || printf(" ");
            if (g->arc[i][j] == INFINITY)
                printf("%s", "∞");
            else 
                printf("%d", g->arc[i][j]);
        }
        printf("\n");
    }
}