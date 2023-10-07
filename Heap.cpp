#include"minHeap.h"
using namespace std;

int main()
{
    minHeap<int> H1;
    //cout<<(-1/2)<<endl;
    H1.Push(1);
    H1.Push(8);
    H1.Push(4);
    H1.Push(0);
    H1.Push(-1);
    H1.Push(10);
    H1.Push(11);
    H1.Push(19);
    H1.Push(2);
    H1.Push(5);
    //H1.Print();
    while(!H1.isEmpty())
    {
        cout<<H1.Top()<<" ";
        H1.Pop();
    }
    cout<<endl;

    int arr[10] = {1,8,4,0,-1,10,11,19,2,5};
    minHeap<int> H2(arr,10);
    //H.Print();



    while(!H2.isEmpty())
    {
        cout<<H2.Top()<<" ";
        H2.Pop();
    }


    int arr2[5] = {1,4,5,3,1};
    minHeap<int> H3(arr2,5);



    // cout<<H.Top()<<endl;
    // H.Print();
    // H.Pop();
    // H.Print();
    // cout<<H.Top()<<endl;
    // cout<<endl;
    while(!H3.isEmpty())
    {
        cout<<H3.Top()<<" ";
        H3.Pop();
    }

    minHeap<int> H4;
    H4.Push(1);
    H4.Push(4);
    H4.Push(5);
    H4.Push(3);
    H4.Push(1);

    while(!H4.isEmpty())
    {
        cout<<H4.Top()<<" ";
        H4.Pop();
    }

    return 0;
}