#ifndef __THREADED_BINARY_TREE_H__
#define __THREADED_BINARY_TREE_H__

/**
 * @brief 
 * 线索二叉树的实现
 */

typedef enum {
    LINK,   // LINK表示当前指针为左右孩子指针
    THREAD  // THREAD表示当前指针为前驱或后继指针
}PointerTag;

typedef struct ThreadBinaryNode {
    int data;
    struct ThreadBinaryNode *lchild;
    struct ThreadBinaryNode *rchild;
    PointerTag ltag;
    PointerTag rtag;
}BTNode, *ThreadBTree, *BTree;

// 创建一个二叉树
BTree createBTree(const char *str);

// 二叉树的中序遍历
void inorderTraversal(BTree tree);

// 将二叉树中序遍历为线索二叉树
void inorderThreadBTree(BTNode *now);

// 线索二叉树的遍历
void threadedBTreeTraversal(ThreadBTree tree);

#endif // __THREADED_BINARY_TREE_H__