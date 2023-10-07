#ifndef HUFFMAN_TREE_NODE_H
#define HUFFMAN_TREE_NODE_H

#include<iostream>
using namespace std;
// 哈夫曼树的结点
template<class T>
class HuffmanTreeNode
{
    public:
        int weight;
        T data; //代表符号
        HuffmanTreeNode<T>* left;
        HuffmanTreeNode<T>* right;
        HuffmanTreeNode<T>* parent;

        HuffmanTreeNode(T data,int weight)
        {
            this->weight = weight;
            this->data = data;
            right = NULL;
            left = NULL;
            parent = NULL;
        }

        bool operator<(HuffmanTreeNode<T>* node1) const
        {
            cout<<"----"<<endl;
            if(this->weight < node1->weight)
                return true;
            return false;
        }
        
        bool operator>(HuffmanTreeNode<T>* node1) const
        {
            cout<<"----"<<endl;
            if(this->weight > node1->weight)
                return true;
            return false;
        }

        bool operator==(HuffmanTreeNode<T>* node1) const
        {
            cout<<"----"<<endl;
            if(this->weight == node1->weight)
                return true;
            return false;
        }

};

#endif