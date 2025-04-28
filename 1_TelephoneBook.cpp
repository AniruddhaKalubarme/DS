#include<iostream>
#include<vector>
#include<math.h>
using namespace std;

class HashTable
{
    vector<int> *arr;
    int iCnt;
    int size;
    public:
    HashTable(int size)
    {
        this->size = size;
        arr = new vector<int>(size, -1);
        iCnt = 0;
    }

    void InsertLinear(int iNo)
    {
        if(iCnt >= size)
        {
            cout<<"HashTable is FULL"<<endl;
            return;
        }

        iCnt++;
        int index = iNo%size;
        while((*arr)[index] != -1)
        {
            index = (index+1)%size;
        }

        (*arr)[index] = iNo;
    }

    void InsertQuadratic(int iNo)
    {
        if(iCnt >= size)
        {
            cout<<"HashTable is FULL"<<endl;
            return;
        }

        iCnt++;
        int index = iNo % size;
        int i = 0;
        while((*arr)[index + i*i] != -1)
        {
            i++;
        }

        (*arr)[index + i*i] = iNo;
    }

    void lookup(int iNo)
    {
        int index = iNo%size;
        do
        {
            if((*arr)[index] == iNo)
            {
                cout<<"Number found at index: "<<index<<endl;
                return;
            }
            index = (index+1)%size;
        }while(index != iNo%size);

        cout<<"Number not found!!"<<endl;
    }

    void Display()
    {
        for(int i = 0; i<size; i++)
        {
            cout<<(*arr)[i]<<" -> ";
        }

    }
};

int main()
{
    HashTable obj(10);
    obj.InsertQuadratic(10);
    obj.InsertQuadratic(8);
    obj.InsertQuadratic(6);
    obj.InsertQuadratic(16);
 
    obj.Display();
    obj.lookup(16);
    return 0;
}