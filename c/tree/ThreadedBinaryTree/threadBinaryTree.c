#include <stdio.h>
#include <malloc.h>
#include "threadBinaryTree.h"

typedef enum {
    LEFT_CHILD,
    RIGHT_CHILD
}ChildTag;

#define STACK_SIZE_MAX 1000

// 创建一个二叉树
BTree createBTree(const char *str) {
    BTree tree;
    ChildTag childTag;      // 是左孩子还是右孩子
    BTNode *stack[STACK_SIZE_MAX]={NULL};
    BTNode *tmp=NULL;
    int idx=0, top=-1;

    while (str[idx]) {
        switch (str[idx]) {
            case '(':
                childTag = LEFT_CHILD;
                stack[++top] = tmp;
                break;
            case ')':
                tree = stack[top--];
                break;
            case ',':
                childTag = RIGHT_CHILD;
                break;
            case ' ':
                // 如果是空格不做任何处理
                break;
            default:
                tmp = (BTNode *)malloc(sizeof(BTNode));
                tmp->data = str[idx];
                tmp->lchild = tmp->rchild = NULL;
                tmp->ltag = tmp->rtag = LINK;
                if (top != -1 && childTag == LEFT_CHILD) {
                    stack[top]->lchild = tmp;
                } else if (top != -1 && childTag == RIGHT_CHILD) {
                    stack[top]->rchild = tmp;
                }
                break;
        }
        idx++;
    }

    return tree;
}

// 二叉树的中序遍历
void inorderTraversal(BTree tree) {
    if (tree == NULL) 
        return ;

    inorderTraversal(tree->lchild);
    printf("%c ", tree->data);
    inorderTraversal(tree->rchild);
}

// 将二叉树中序遍历为线索二叉树
BTNode *pre=NULL;
void inorderThreadBTree(BTNode *now) {
    if (now) {
        inorderThreadBTree(now->lchild);
        // 二叉树线索化
        if (!now->lchild) {
            // 检测当前的左孩子是否为空，如果为空，则添加他的前驱
            now->lchild = pre;
            now->ltag = THREAD;
        }

        if (pre && !pre->rchild) {  // 当前的前驱结点要不为NULL，并且当前的前驱结点的左子树要为空
            // 这里处理比较麻烦，因为当前不知道now的后继是谁，所以需要等遍历到下一个结点时才会知道当前结点的后继，
            // 所以这里使用的是上一个来处理后继问题
            pre->rchild = now;
            pre->rtag = THREAD;
        }
        // 更新前驱结点为当前结点
        pre = now;
        inorderThreadBTree(now->rchild);
    }
}

// 线索二叉树的遍历
void threadedBTreeTraversal(ThreadBTree tree) {
    while (tree) {
        // 一直找左孩子
        while (tree->ltag == LINK) {
            tree = tree->lchild;
        }
        // 打印该结点的数据
        printf("%c ", tree->data);

        // 当结点的右标记为THREAD时，则直接找到后继
        while (tree->rtag == THREAD && tree->rchild != NULL) {
            tree = tree->rchild;
            printf("%c ", tree->data);
        }

        // 否则，按照中序遍历的规律，找到其左子树中最左下的节点，也就是继续循环遍历
        tree = tree->rchild;
    }
}