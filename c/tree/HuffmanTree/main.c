#include <stdio.h>
#include <malloc.h>
#include "huffmantree.h"

int main() {
    HuffmanTree htree;

    int n = 0;
    printf("请输入权重个数: \n");
    scanf("%d", &n);
    int *w = (int *)malloc(sizeof(int) * n);

    printf("请输入权重: \n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &w[i]);
    }

    // 构建赫夫曼树
    createHuffmanTree(&htree, w, n);
    for (int i = 1; i <= 2*n-1; i++) {
        printf("%d ", htree[i].weight);
    }
    printf("\n");
    // 得到赫夫曼编码
    HuffmanCode htable;
    huffmanCoding(htree, &htable, n);
    // 打印赫夫曼编码
    printHuffmanCoding(htable, w, n);
    
    // 释放 huffmanCoding 函数分配的内存空间
    for (int i = 0; i <= n; i++) {
        free(htable[i]);
    }
    free(htable);

    return 0;
}