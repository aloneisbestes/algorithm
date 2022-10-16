#ifndef __ORTHOGONA_LIST_H__
#define __ORTHOGONA_LIST_H__

/**
 * @brief 
 * 十字链表的实现
 */

#define VERTEXMAX   100

typedef char    VertexType;         // 顶点类型
typedef int     EdgeType;           // 边上的权值类型

// 边表结构
typedef struct EdgeNode{
    VertexType tailvex, headvex;   // 弧头弧尾信息
    struct EdgeNode *taillist, *headlist;    // 出边和入边指针
}EdgeNode;

// 顶点表结构体
typedef struct VertexNode{
    /* data */
    VertexType data;
    struct EdgeNode *firstin, *firstout;
}VertexNode, OrthList[VERTEXMAX+5];

typedef struct GraphOrthogonal{
    OrthList orthList;
    int numEdge, numVertex;
}GraphOrth;

// 创建十字链表
void CreateOrthList(GraphOrth *g);

// 打印图
void PrintOrthList(GraphOrth *g);

// 销毁图
void DestroyRothList(GraphOrth *g);

#endif // __ORTHOGONA_LIST_H__