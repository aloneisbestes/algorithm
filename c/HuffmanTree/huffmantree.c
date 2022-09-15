#include <stdio.h>
#include <malloc.h>
#include <string.h>
#include "huffmantree.h"

// 创建赫夫曼树
void createHuffmanTree(HuffmanTree *htree, int *w, int n) {
    // 判断赫夫曼树的节点个数是否小于等于1
    if (n <= 1) // 如果小于等于1表示当前的赫夫曼树只有一个节点，无法创建赫夫曼树
        return ;

    // 计算当前赫夫曼的节点个数
    int nodeNum = 2*n - 1;
    // 为赫夫曼树开辟内存空间，这里使用数组实现
    *htree = (HuffmanTree)malloc(sizeof(HTNode)*(nodeNum+1)); // 这里+1的原因是数组的第0位不使用
    HuffmanTree p = *htree;

    // 初始化赫夫曼树
    for (int i = 1; i <= n; i++) {
        (p+i)->parent = 0;
        (p+i)->rchild = 0; 
        (p+i)->lchild = 0;
        (p+i)->weight = *(w+i-1);
    }

    // 初始化除叶子结点外的其他结点
    for (int i = n+1; i <= nodeNum; i++) {
        (p+i)->lchild = 0;
        (p+i)->rchild = 0;
        (p+i)->parent = 0;
        (p+i)->weight = 0;
    }

    // 开始构建huffman树
    for (int i = n+1; i <= nodeNum; i++) {
        int min1, min2; // 找到两个权重最小的索引
        selectTwoMin(*htree, i-1, &min1, &min2);
        printf("min1 = %d, min2 = %d\n", min1, min2);
        // 构建赫夫曼树
        (*htree)[i].weight = (*htree)[min1].weight+(*htree)[min2].weight;
        // 较大的放在右子树上，较小的放在左子树上
        (*htree)[i].lchild = min1;
        (*htree)[i].rchild = min2;
        // 更新索引为min1和min2结点的父节点
        (*htree)[min1].parent = (*htree)[min2].parent = i;
    }
}

// 从Huffman树中寻找两个最小的节点
void selectTwoMin(HuffmanTree htree, int end, int *idx1, int *idx2) {
    // 记录权重的大小
    int min1, min2;
    // 赫夫曼数组下标是从1开始的
    int idx = 1;

    // 找到第一个还没有构建的结点
    while (htree[idx].parent != 0 && idx <= end) {
        idx++;
    }
    min1 = htree[idx].weight;
    *idx1 = idx;

    // 找到第二个还没有构建的结点
    idx++;
    while (htree[idx].parent != 0 && idx <= end) {
        idx++;
    }
    // 需要判断一下找到的两个结点的大小，min1为较小的那个，min2为较大的那个
    if (min1 > htree[idx].weight) {
        min2 = min1;
        *idx2 = *idx1;
        min1 = htree[idx].weight;
        *idx1 = idx;
    } else {
        min2 = htree[idx].weight;
        *idx2 = idx;
    }

    // 需要在当前的huffman输中查找最小的两个结点
    for (int i=idx+1; i <= end; i++) {
        if (htree[i].parent != 0)   // 如果结点的父节点是不为0，表示当前的结点已经被构造了，直接跳过
            continue;
        
        if (htree[i].weight < min1) {
            // 如果比最小的还小，则将min1的值赋给min2，然后min1更新为更小的
            min2 = min1;
            *idx2 = *idx1;
            min1 = htree[i].weight;
            *idx1 = i;
        } else if (htree[i].weight >= min1 && htree[i].weight < min2) {
            // 如果当前结点的权重是大于等于min1并且小于min2的，则将min2更新
            min2 = htree[i].weight;
            *idx2 = i;
        }
    }
}

// 得到赫夫曼编码
void huffmanCoding(HuffmanTree htree, HuffmanCode *htable, int n) {
    (*htable) = (HuffmanCode)malloc(sizeof(char *)*(n+1));
    char *cd = (char *)malloc(sizeof(char)*n);   
    cd[n-1] = '\0';

    // 从叶子结点开始得到赫夫曼编码的逆序
    for (int i = 1; i <= n; i++) {
        // 因为得到的是逆序，所需也需要逆序存储
        int start = n-1;
        int c = i;  // 记录当前结点
        int parent = htree[i].parent;   // 记录父节点
        while (parent != 0) {
            // 如果该结点父节点的左孩子，计为0，否则计为1
            if (htree[parent].lchild == c) 
                cd[--start] = '0';
            else 
                cd[--start] = '1';
            // 以父节点为孩子结点，继续向树根变量
            c = parent;
            parent = htree[parent].parent;
        }
        // 跳出循环，说明得到当前的结点的赫夫曼编码
        (*htable)[i] = (char *)malloc(sizeof(char) * (n-start));
        strncpy((*htable)[i], cd+start, n-start);        
    }

    // 遍历结束后删除创建的 cd 内存
    free(cd);
}

// 打印赫夫曼编码
void printHuffmanCoding(HuffmanCode htable, int *w, int n) {
    printf("Huffman code: \n");
    for (int i = 1; i <= n; i++) {
        printf("%d code = %s\n", w[i-1], htable[i]);
    }
}