#ifndef HUFFMAN_TREE_ENCODE_H
#define HUFFMAN_TREE_ENCODE_H
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

template<class T>
void InOrder(HuffmanTreeNode<T>* node)
{
    if(node->left)
        InOrder(node->left);
    cout<<node->weight<<" ";
    if(node->right)
        InOrder(node->right);
}

template<class T>
void PreOrder(HuffmanTreeNode<T>* node)
{
    cout<<node->weight<<" ";
    if(node->left)
        PreOrder(node->left);
    if(node->right)
        PreOrder(node->right); 
}

//获得文件大小的函数
int getFileSize1(string fileName) {

	struct stat statbuf;
    char file[10];
    strcpy(file,fileName.c_str());

	stat(file, &statbuf);
	
	int filesize = statbuf.st_size;

	return filesize;
}


class HuffmanTreeEncode
{
    public:
        int size;
        HuffmanTree<char>* tree;
        char* value;
        int* w;
        int index;
        int BeforePressSize;
        string code;
        map<char,HuffmanTreeNode<char>*> LeafMap;

    HuffmanTreeEncode()
    {

        size = 0;
        tree = NULL;
        char c = 0;
        value = new char[128];

        for(int i=0;i<128;i++)
            value[i] = c+i;
        w = new int[128];
        for(int i=0;i<128;i++)
            w[i] = 0;
        code = "";
    }

    void encode(string path)  //规则 往左子树为1 右子树为0
    {
        //string text = "";
        ifstream ifs;
        ifs.open(path);
        // string tmp;
        // while(ifs>>tmp)
        // {
        //     text+=tmp;
        // }
         BeforePressSize = getFileSize1(path);

        istreambuf_iterator<char> begin(ifs);
        istreambuf_iterator<char> end;
        string text(begin, end);
        ifs.close();
    


        for(int i=0;i<text.size();i++)
        {
            w[text[i]-char(0)]++;
        }

        // for(int i=0;i<26;i++)
        //     cout<<w[i]<<" ";
        
        tree = new HuffmanTree<char>(value,w,128);
        // InOrder(tree->root);
        // cout<<endl;
        // PreOrder(tree->root);

        LeafMap = tree->GetLeaf();
        
        for(int i=0;i<text.size();i++)
        {
            //cout<<i<<endl;
            code+=FindToRoot(text[i]);
        }

        int n = code.size();
        
        // 编码输出到文�?
        //cout<<code<<endl;
        //reverse(code.begin(),code.end());
        bitset<1000000> bits(code);  //开大点，能最多放�?100�?
        //cout<<bits<<endl;
        ofstream ofs;
        ofs.open("HuffmanPress.dat");
        cout<<sizeof(bits)<<endl;
        // for(int i=0;i<10;i++)
        //     cout<<bits[i]<<endl;
        int wsize = code.size()/8+128;  //保证输出的字节数够用但是尽量少，因为一开始bitset数组里面的多余位�?0
        //int wsize = sizeof(bits);
 
        //输出权重信息等到文件以便解码时建树
        ofs<<code.size()<<' ';
        for(int i=0;i<127;i++)
            ofs<<w[i]<<' ';
        ofs<<w[127];
        //cout<<bits<<endl;
 
        ofs.write((char*)&bits,wsize);
        ofs.close();
        int AfterPressSize = getFileSize1("HuffmanPress.dat");

        float ratio = 0;//压缩率
        ratio = ( (float) AfterPressSize) / ((float)BeforePressSize) ;
        //cout << "压缩前大小为：" << BeforePressSize << "字节    压缩后大小为：" << AfterPressSize << "字节" << endl;
        printf("压缩前大小为：%d 字节  压缩后大小为：%d 字节 ", BeforePressSize,AfterPressSize);
        printf("---------- 压缩成功！---------\n");
        printf("---------压缩率为: %.2f %%--------",ratio*100);

        cout<<endl;
        
    }
    



    string FindToRoot(char key)
    {
        string ans = "";
         HuffmanTreeNode<char>* node = LeafMap[key];
        while(node->parent)
        {
            HuffmanTreeNode<char>* parent = node->parent;
            if(parent->left == node)
                ans+='1';
            else
                ans+='0';
            node = node->parent;
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }




};

#endif