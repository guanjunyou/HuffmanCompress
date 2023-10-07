#ifndef HUFFMAN_TREE_H
#define HUFFMAN_TREE_H

#include"HuffmanTreeNode.h"
#include"minHeap.h"
#include<map>
#include<unordered_map>
#include<utility>
using namespace std;




template<class T>
class HuffmanTree
{
    public:

        HuffmanTreeNode<T>* root;
        int size;
        map<T,HuffmanTreeNode<T>*> LeafMap; //字符对应叶子的哈希表

        HuffmanTree(T value[], int w[],int n) //建树
        {
            //LeafMap = new  map<T,HuffmanTreeNode<T>*>();
            minHeap<HuffmanTreeNode<T>*> heap;
            for(int i=0;i<n;i++)
            {
               //cout<<w[i]<<endl;
                HuffmanTreeNode<T>* node = new HuffmanTreeNode<T>(value[i],w[i]);
                //HuffmanTreeNode<T> node(value[i],w[i]);
                LeafMap.insert(pair<T,HuffmanTreeNode<T>*>(value[i], node));
                heap.Push(node);
            }
            //cout<<"000"<<endl;
            size = n;
            //开始建树
            for(int i=0;i<size-1;i++)
            {
                //cout<<i<<endl;
                HuffmanTreeNode<T>* leftNode = heap.Top();
                heap.Pop();
                HuffmanTreeNode<T>* rightNode = heap.Top();
                heap.Pop();
                //cout<<leftNode->weight<<" "<<rightNode->weight<<endl;
                HuffmanTreeNode<T>* newNode = new HuffmanTreeNode<T>(leftNode->data,leftNode->weight+rightNode->weight);
                newNode->left = leftNode;
                newNode->right = rightNode;
                leftNode->parent = newNode;
                rightNode->parent = newNode;
                heap.Push(newNode);

                // HuffmanTreeNode<T> leftNode = heap.Top();
                // heap.Pop();
                // HuffmanTreeNode<T> rightNode = heap.Top();
                // heap.Pop();
                // cout<<leftNode.weight<<" "<<rightNode.weight<<endl;
                // HuffmanTreeNode<T> newNode(leftNode.data,leftNode.weight+rightNode.weight);
                // newNode.left = &leftNode;
                // newNode.right = &rightNode;
                // leftNode.parent = &newNode;
                // rightNode.parent = &newNode;
                // heap.Push(newNode);
            }
            root = heap.Top();

        }

        map<T,HuffmanTreeNode<T>*> GetLeaf()
        {
            return LeafMap;
        }

        HuffmanTreeNode<T>* GetRoot()
        {
            return root;
        }

        
};

#endif