#include<iostream>
using namespace std;

class Heap
{
    public:
    int Min[100];
    int Max[100];
    int indexMin;
    int indexMax;
    
    Heap()
    {
        indexMin = 0;
        indexMax = 0;
    }

    void InsertMin(int iNo)
    {
        indexMin++;
        if(indexMin>=100)
        {
            cout<<"Heap is FULL"<<endl;
            return;
        }

        Min[indexMin] = iNo;
        int temp = indexMin;
        while(temp>1 && Min[temp/2] > Min[temp])
        {
            swap(Min[temp], Min[temp/2]);
            temp = temp/2;
        }
    }

    void InsertMax(int iNo)
    {
        indexMax++;
        if(indexMax>=100)
        {
            cout<<"Heap is FULL"<<endl;
            return;
        }

        Max[indexMax] = iNo;
        int temp = indexMax;
        while(temp>1 && Max[temp/2] < Max[temp])
        {
            swap(Max[temp], Max[temp/2]);
            temp = temp/2;
        }
    }

};

int main()
{
    Heap obj;
    obj.InsertMin(5);
    obj.InsertMin(10);
    obj.InsertMin(4);
    obj.InsertMin(8);

    cout<<obj.Min[1];
    return 0;
}