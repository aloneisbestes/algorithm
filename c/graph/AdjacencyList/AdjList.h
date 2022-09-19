#ifndef __ADJACENCY_LIST_H__
#define __ADJACENCY_LIST_H__

/**
 * @brief 
 * 邻接表的实现，该实现是无向有权图
 */

#define MAXVERTEX   100

typedef char VertexType;
typedef int EdgeType;

typedef struct EdgeNode {
    int idxVertex;      // 顶点的索引
    EdgeType weight;    // 权重
    struct EdgeNode *pnext; // 指向下一个边表指针
}EdgeNode;  // 边表的结点结构

typedef struct VertexNode {
    VertexType data;
    struct EdgeNode *firstEdge;
}VertexNode, AdjList[MAXVERTEX+5];    // 顶点集合

typedef struct {
    AdjList adjList;
    int numEdge, numVertex; // 边数和顶点数
}GraphAdjList;  // 图

// 创建图
void CreateAdjListGraph(GraphAdjList *g);

// 添加边
void AddEdge(GraphAdjList *g, int i, int j, int w);

// 打印邻接表
void PrintGraphAdjList(GraphAdjList *g);

// 销毁邻接表
void DestroyGraphAdjList(GraphAdjList *g);

#endif // __ADJACENCY_LIST_H__