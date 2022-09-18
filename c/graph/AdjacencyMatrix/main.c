#include <stdio.h>
#include "AdjMatrix.h"

int main() {
    AdjMat graph;

    // 无向图
    // createAdjMat(&graph, GRAPH_TYPE_EDGE);
    // printAdjMat(&graph);

    // 有向带权图
    createAdjMat(&graph, GRAPH_TYPE_WDIRECTED);
    printAdjMat(&graph);
    return 0;
}