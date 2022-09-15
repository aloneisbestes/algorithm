#include <stdio.h>
#include "binarytree.h"

int main() {
    char str[1000]={0};
    printf("请输入广义表: \n");
    scanf("%s", str);

    BiTree tree = createBiTree(str);
    // 树的前序变量
    printf("二叉树的前序遍历: \n");
    preorderTraversal(tree);
    printf("\n");

    printf("二叉树的中序遍历: \n");
    inorderTraversal(tree);
    printf("\n");

    printf("二叉树的后序遍历: \n");
    postorderTraversal(tree);
    printf("\n");

    printf("二叉树的层次遍历: \n");
    levelTraversal(tree);
    printf("\n");

    printf("二叉树的深度或高度: \n");
    printf("%d\n", treeDepth(tree));

    return 0;
}