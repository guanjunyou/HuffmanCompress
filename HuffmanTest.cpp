#include"HuffmanTree.h"
#include"HuffmanTreeEncode.h"
#include"HuffmanTreeDecode.h"
using namespace std;
// template<class T>
// void InOrder(HuffmanTreeNode<T>* node)
// {
//     if(node->left)
//         InOrder(node->left);
//     cout<<node->weight<<" ";
//     if(node->right)
//         InOrder(node->right);
// }

// template<class T>
// void PreOrder(HuffmanTreeNode<T>* node)
// {
//     cout<<node->weight<<" ";
//     if(node->left)
//         PreOrder(node->left);
//     if(node->right)
//         PreOrder(node->right); 
// }


int main()
{
    // int w[5] = {1,4,5,3,1};
    // char value[5] = {'a','b','c','d','e'};
    // HuffmanTree<char> tree(value,w,5);
    // PreOrder(tree.root);
    // cout<<endl;
    // InOrder(tree.root);
    // cout<<endl;
    
    // HuffmanTreeNode<char>* node1 = new HuffmanTreeNode<char>('a',1);
    // HuffmanTreeNode<char>* node2 = new HuffmanTreeNode<char>('a',4);
    // HuffmanTreeNode<char>* node3 = new HuffmanTreeNode<char>('a',5);
    // HuffmanTreeNode<char>* node4 = new HuffmanTreeNode<char>('a',3);
    // HuffmanTreeNode<char>* node5 = new HuffmanTreeNode<char>('a',1);
    // minHeap<HuffmanTreeNode<char>*> heap;
    // heap.Push(node1);
    // heap.Push(node2);
    // heap.Push(node3);
    // heap.Push(node4);
    // heap.Push(node5);

    // while(!heap.isEmpty())
    // {
    //     HuffmanTreeNode<char>* node = heap.Top();
    //     cout<<node->weight<<" ";
    //     heap.Pop();
    // }

    // if(node1<node2)
    //     cout<<"PPPP";
    
    HuffmanTreeEncode Encode;
    HuffmanTreeDecode Decode;
    
    Encode.encode("Inputfile.txt");
    Decode.decode("HuffmanPree.dat");

    //Encode.decode();


    return 0;
}