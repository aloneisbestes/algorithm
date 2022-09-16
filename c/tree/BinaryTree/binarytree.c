#include <stdio.h>
#include <malloc.h>
#include "binarytree.h"

#define STACK_SIZE_MAX  100 

typedef enum FlagsLR {
    LEFT_CHILD=0,
    RIGHT_CHILD
}FlagsLR;

// 通过广义表建立二叉树
BiTree createBiTree(const char *str) {
    BiTree tree=NULL;
    int idx = 0;
    FlagsLR lr;     // 左孩子还是右孩子
    // 需要一个栈用来创建二叉树
    BiTNode *stack[STACK_SIZE_MAX];
    BiTNode *tmp;
    int top = -1;

    while (str[idx]) {
        switch (str[idx]) {
            case '(':
                // 如果是左括号，则标记为左孩子，然后让父节点入栈
                lr = LEFT_CHILD;
                stack[++top] = tmp;
                break;            
            case ',':
                lr = RIGHT_CHILD;
                break;
            case ')':
                tree = stack[top--];
                break;
            case ' ':   // 如果是空格则不处理
                break;
            default:
                tmp = (BiTNode *)malloc(sizeof(BiTNode));
                tmp->data = str[idx];
                tmp->leftChild = tmp->rightChild = NULL;
                if (top != -1 && lr == LEFT_CHILD) {
                    // 如果栈不为空，并且是左子树
                    stack[top]->leftChild = tmp;
                } else if (top != -1 && lr == RIGHT_CHILD) {
                    // 如果栈不为空，并且是右子树
                    stack[top]->rightChild = tmp;
                }
                break;
        }
        idx++;
    }

    return tree;
}

// 二叉树的前序遍历
void preorderTraversal(BiTree tree) {
    if (tree == NULL)
        return ;
    
    printf("%c ", tree->data);
    preorderTraversal(tree->leftChild);
    preorderTraversal(tree->rightChild);
}

// 二叉树的中序遍历
void inorderTraversal(BiTree tree) {
    if (tree == NULL)
        return ;

    inorderTraversal(tree->leftChild);
    printf("%c ", tree->data);
    inorderTraversal(tree->rightChild);
}

// 二叉树的后序遍历
void postorderTraversal(BiTree tree) {
    if (tree == NULL) 
        return ;

    postorderTraversal(tree->leftChild);
    postorderTraversal(tree->rightChild);
    printf("%c ", tree->data);
}

// 二叉树的层次遍历
void levelTraversal(BiTree tree) {
    // 层次遍历需要使用一个队列
    BiTNode *queue[STACK_SIZE_MAX] = {NULL};
    int real = -1, start = -1;
    BiTNode *move = tree;

    while (move) {
        // 如果左子树不为空，则入队
        if (move->leftChild != NULL) {
            queue[++real] = move->leftChild;
        }
        // 如果右子树不为空，则入队
        if (move->rightChild != NULL) {
            queue[++real] = move->rightChild;
        }

        // 打印当前元素
        printf("%c ", move->data);
        // 如果队列为空，则表示层次遍历结束
        if (start == real)
            break;
        // 出队
        move = queue[++start];
    }
}

// 二叉树的深度和高度
int treeDepth(BiTree tree) {
    if (tree == NULL)
        return -1;
    
    int leftDepth = 0;
    int rightDepth = 0;

    // 寻找左子树的最大深度
    if (tree->leftChild != NULL) {
        leftDepth = treeDepth(tree->leftChild);
    } else  {
        leftDepth = -1;
    }
    
    // 寻找右子树的最大深度
    if (tree->rightChild != NULL) {
        rightDepth = treeDepth(tree->rightChild);
    } else {
        rightDepth = -1;
    }

    return (rightDepth>leftDepth) ? rightDepth + 1 : leftDepth + 1;
}