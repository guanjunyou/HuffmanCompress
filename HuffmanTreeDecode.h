#ifndef HUFFMAN_TREE_DECODE_H
#define HUFFMAN_TREE_DECODE_H
#include"HuffmanTree.h"
#include<bitset>
#include<fstream>
#include<ostream>
#include<string>
#include<algorithm>
#include<stdio.h>
#include <sys/stat.h>
#include<cstring>
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



class HuffmanTreeDecode
{
    public:
        int size;  //应该读取的字节数
        HuffmanTree<char>* tree;
        char* value;
        int* w;
        int index;
        string code;

    HuffmanTreeDecode()
    {
        size = 0;
        tree = NULL;
        value = new char[128];
        w = new int[128];

        char c = 0;
        for(int i=0;i<128;i++)
            value[i] = c+i;

    }



    void decode(string path)
    {
        int codesize = 0;
        ifstream ifs;
        ifs.open("HuffmanPress.dat");
        bitset<1000000> ans;

        ifs>>codesize;
        for(int i=0;i<128;i++)
            ifs>>w[i];

        int rsize = codesize/8 + 1;
        ifs.read((char*)&ans,sizeof(ans));
        ifs.close();
        //cout<<ans<<endl;

        int index = codesize-1;

        //重新建树
        tree = new HuffmanTree<char>(value,w,128);

        string s = "";
        while(index>=0)
        {
            char c = FindLeafChar(tree->GetRoot(),index,ans);
            s+=c;
        }

        //cout<<s<<endl;

        cout<<"-------解压成功！文件输出到 DecodeFile.txt--------"<<endl;
        ofstream ofs;
        ofs.open("DecodeFile.txt");
        ofs<<s;
        ofs.close();
    }


    char FindLeafChar(HuffmanTreeNode<char>* root,int& index,bitset<1000000> code)
    {
        //找到叶子就可以知道原文
        while(root)
        {
            if(root->left == NULL && root->right == NULL)
            {
                return root->data;
            }
            if(code[index] == 1)
            {
                root = root->left;
            }
            else{
                root = root->right;
            }
            index--;
        }
        return ' ';
    }



};

#endif