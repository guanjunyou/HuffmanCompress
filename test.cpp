#include<iostream>
#include<bitset>
#include<string>
#include<algorithm>
#include<fstream>
#include<ostream>
using namespace std;
const int n  = 1000;

char arr[10];
int index = 0;
//string s = "0110011001100110011001000111111101100110011001100110010001111111";
// void bitTochar()
// {
//     int cnt = 0;
//     string tmp = "";
//     for(int i=0;i<s.size();i++)
//     {
//         if(cnt==8)
//         {
//             reverse(tmp.begin(),tmp.end());
//             bitset<8> B(tmp);
//             unsigned long i = B.to_ulong();
//             unsigned char c = static_cast<unsigned char> (i);
//             arr[index] = c;
//             index++;
//             cnt = 0;
//             tmp = "";
//         }
//         cnt++;
//         tmp+=s[i];
//     }

//     reverse(tmp.begin(),tmp.end());
//     bitset<8> B(tmp);
//     unsigned long i = B.to_ulong();
//     unsigned char c = static_cast<unsigned char> (i);
//     arr[index] = c;
// }



int main()
{

    // bitTochar();
    // for(int i=0;i<=index;i++)
    // {
    //     cout<<arr[i]<<endl;
    // }
    // ifstream ifsin;
    // ifsin.open("in.txt");
    // string s;
    // ifsin>>s;
    // ifsin.close();
    // cout<<s.size()<<endl;


    // reverse(s.begin(),s.end());
    // bitset<1000> bits(s);
    // cout<<bits<<endl;
    // ofstream ofs;
    // ofs.open("test.dat"); 
    // cout<<sizeof(bits)<<endl;
    // int wsize = 8*s.size()*2;
    // ofs.write((char*)&bits,wsize);
    // ofs.close();
    // cout<<endl;


    // ifstream ifs;
    // ifs.open("test.dat");
    // bitset<70> ans;
    // ifs.read((char*)&ans,sizeof(ans));
    // cout<<ans<<endl;
    // cout<<ans[30]<<endl;
    // ifs.close();
    // return 0;

    ifstream ifs;
    ifs.open("Inputfile.txt");
    string s="";
    char c;
    while(ifs>>c)
    {
        s+=c;
    }
    cout<<s;
    return 0;
}