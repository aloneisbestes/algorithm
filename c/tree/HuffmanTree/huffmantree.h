#ifndef __HUFFMAN_TREE_H__
#define __HUFFMAN_TREE_H__

/**
 * @brief 
 * 赫夫曼树的实现
 */

typedef struct {
    int weight;     // 权重
    int parent, lchild, rchild; // 双亲和左右孩子结点
}HTNode, *HuffmanTree;

typedef char ** HuffmanCode;

/**
 * @brief Create a Huffman Tree object
 * 创建赫夫曼树
 * @param htree 赫夫曼树
 * @param w 权重
 * @param n 叶子结点数
 */
void createHuffmanTree(HuffmanTree *htree, int *w, int n);

/**
 * @brief 
 * 查找赫夫曼树中结点权值最小的两个值
 * @param htree 
 * @param end 
 * @param idx1 
 * @param idx2 
 */
void selectTwoMin(HuffmanTree htree, int end, int *idx1, int *idx2);

/**
 * @brief 
 * 将赫夫曼树转化为赫夫曼编码
 * @param htree 
 * @param htable 
 * @param n 
 */
void huffmanCoding(HuffmanTree htree, HuffmanCode *htable, int n);

/**
 * @brief 
 * 打印赫夫曼编码
 * @param htable 
 * @param w 
 * @param n 
 */
void printHuffmanCoding(HuffmanCode htable, int *w, int n);
#endif // __HUFFMAN_TREE_H__