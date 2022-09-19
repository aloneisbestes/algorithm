#include <stdio.h>
#include "AdjList.h"

int main() {
    GraphAdjList g;

    // 创建邻接表
    CreateAdjListGraph(&g);
    
    // 打印邻接表
    PrintGraphAdjList(&g);

    // 销毁邻接表
    DestroyGraphAdjList(&g);

    return 0;
}