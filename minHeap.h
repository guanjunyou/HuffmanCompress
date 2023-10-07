#ifndef MIN_HEAP_H
#define MIN_HEAP_H

#include<iostream>

using namespace std;
// utf8 
template<class T>
class minHeap
{
    private:
        T* heap;  //结点从 0 开始的堆
        int size;
        int Capacity;

        void expand()  //空间不够，扩展
        {
            T* newArray = new T[Capacity*2];
            for(int i=0; i < Capacity; i++)
            {
                newArray[i] = heap[i];
            }
            T* toDel = heap;
            heap = newArray;
            Capacity =Capacity*2;
            delete toDel;
        }

        bool cmp(T a,T b)   
        {  //是不是左边那个小
            // if(a < b)
            //     return true;
            // return false;
            return a->weight < b->weight;
        }

        void AdjustDown(int currentIndex) // 向下调整
        {
            T value = heap[currentIndex];

            int nextIndex = currentIndex;
            while(1)
            {
                if(currentIndex * 2 +1 >= size) // 2i+1=left  2i+2 = right
                    break;
                nextIndex = 2*currentIndex + 1;
                if(nextIndex + 1 < size && cmp(heap[nextIndex+1],heap[nextIndex])) // 选最小的儿子
                {
                    nextIndex = nextIndex + 1;
                }
                
                if(cmp(value,heap[nextIndex]))   // value 比下面的还要小
                    break; // 不用处理了
                //更小的上去
                heap[currentIndex] = heap[nextIndex];
                currentIndex = nextIndex;


            }

            heap[currentIndex] = value; //找到正确的位置放下去

        }

        void AdjustUp(int currentIndex)
        {
            T value = heap[currentIndex];

            int nextIndex = currentIndex;
            while(1)
            {
                if(currentIndex <= 0)
                    break; // 到树根了

                nextIndex = (currentIndex-1) / 2;  //它的双亲
               // cout<<heap[currentIndex]<<" "<<heap[nextIndex]<<endl;
                if(cmp(heap[nextIndex],value))
                    break;

                heap[currentIndex] = heap[nextIndex];
                currentIndex = nextIndex; 

                 //this->Print();
            }
            heap[currentIndex] = value;
        }


    public:
        minHeap()
        {
            heap = new T[10];
            size = 0;
            Capacity = 10;
        }

        minHeap(T arr[],int n)  //把一个数组初始化为堆
        {
            heap = arr;
            size = n;
            Capacity = 2*size;

            int i = (size - 3)/2; // 即 (最后一个元素下标 - 2) / 2 开始
            while(i>=0)
            {
                AdjustDown(i);
                i--;
            }
        }
    
        int Size()
        {
            return size;
        }

        T Top()  //返回堆顶元素
        {
            if(size == 0)
                cout<<"没有元素"<<endl;
            return heap[0];
        }

        void Push(T element) //插入
        {
            if(size == Capacity)
                expand();
            size++;
            heap[size-1] = element;
            AdjustUp(size-1);
        }

        void Pop() //删除堆顶
        {
            if(size == 0)
                cout<<"操作非法"<<endl;
            heap[0] = heap[size-1];
            size--;
            AdjustDown(0);
        }

        void Print()
        {
            for(int i=0;i<size;i++)
            {
                cout<<heap[i]<<" ";
            }
            cout<<endl;
        }

        bool isEmpty()
        {
            return size==0;
        }

};

#endif
