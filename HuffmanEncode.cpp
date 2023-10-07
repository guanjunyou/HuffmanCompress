#include"HuffmanTree.h"
#include"HuffmanTreeEncode.h"
#include"HuffmanTreeDecode.h"
using namespace std;

//哈夫曼编码压缩
int main()
{

    
    HuffmanTreeEncode Encode;
    
    Encode.encode("Inputfile.txt");

    //Encode.decode();


    return 0;
}