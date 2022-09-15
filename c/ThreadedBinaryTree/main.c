#include <stdio.h>
#include "threadBinaryTree.h"


int main() {
    char str[1000];
    printf("请输入广义表: \n");
    scanf("%s", str);

    BTree tree = createBTree(str);
    // 二叉树的中序遍历
    printf("二叉树的中序遍历: \n");
    inorderTraversal(tree);
    printf("\n");

    // 二叉树的中序线索化
    printf("二叉树的中序线索化, 线索化后的线索二叉树遍历结果为: \n");
    inorderThreadBTree(tree);
    // 中序线索化后的二叉树遍历结果
    threadedBTreeTraversal(tree);
    printf("\n");

    return 0;
}