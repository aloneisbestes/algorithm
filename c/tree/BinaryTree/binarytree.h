#ifndef __BINARY_TREE__
#define __BINARY_TREE__

/**
 * @brief 
 * 二叉树的实现
 */

// 二叉树结点结构
typedef struct BiTNode {
    int data;               // 数据
    struct BiTNode *leftChild;     // 左子树
    struct BiTNode *rightChild;    // 右子树
}BiTNode, *BiTree;

/* 树的操作 */
// 通过广义表建立二叉树
BiTree createBiTree(const char *str);
// 二叉树的前序遍历
void preorderTraversal(BiTree tree);
// 二叉树的中序遍历
void inorderTraversal(BiTree tree);
// 二叉树的后序遍历
void postorderTraversal(BiTree tree);
// 二叉树的层次遍历
void levelTraversal(BiTree tree);
// 二叉树的深度和高度
int treeDepth(BiTree tree);

#endif // __BINARY_TREE__