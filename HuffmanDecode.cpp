#include"HuffmanTree.h"
#include"HuffmanTreeEncode.h"
#include"HuffmanTreeDecode.h"
using namespace std;

//哈夫曼编码解压器
int main()
{

    HuffmanTreeDecode Decode;
    
    Decode.decode("HuffmanPree.dat");

    //Encode.decode();


    return 0;
}