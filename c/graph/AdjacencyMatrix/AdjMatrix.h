#ifndef __ADJACENCY_MAXTRIX_H__
#define __ADJACENCY_MAXTRIX_H__

/**
 * @brief 
 * 邻接矩阵的实现
 */

#include <limits.h>

typedef char    VertexType;         // 顶点类型
typedef int     EdgeType;           // 边上的权值类型

#define         MAXVEX      100         // 最大顶点数
#define         INFINITY    INT_MAX     // 无穷大值

/* 图的类型定义 */
#define         GRAPH_TYPE_EDGE         0x01    // 无向图
#define         GRAPH_TYPE_DIRECTED     0x02    // 有向图
#define         GRAPH_TYPE_WEDGE        0x04    // 无向有权图
#define         GRAPH_TYPE_WDIRECTED    0x08    // 有向有权图

typedef struct AdjMat {
    VertexType  vexs[MAXVEX+5];             // 顶点表
    EdgeType    arc[MAXVEX+5][MAXVEX+5];    // 邻接表
    int numVertexes, numEdges;              // 图中的顶点个数和边数
    int graphType;                          // 图的类型，有向还是无向图
}AdjMat;

// 创建网图的邻接矩阵表示
void createAdjMat(AdjMat *g, int type);

// 打印图
void printAdjMat(AdjMat *g);

#endif // __ADJACENCY_MAXTRIX_H__