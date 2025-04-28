#include<iostream>
#include<vector>
#include<math.h>
using namespace std;

class Node
{
    public:
    int key;
    string value;
    Node(int k, string v)
    {
        key = k;
        value = v;
    }
};

class HashTable
{
    vector<Node*> *arr;
    int iCnt;
    int size;
    public:
    HashTable(int size)
    {
        this->size = size;
        arr = new vector<Node*>(size, NULL);
        iCnt = 0;
    }

    void InsertLinear(int iNo, string val)
    {
        if(iCnt >= size)
        {
            cout<<"HashTable is FULL"<<endl;
            return;
        }

        Node* newn = new Node(iNo, val);
        iCnt++;
        int index = iNo%size;
        while((*arr)[index] != NULL)
        {
            index = (index+1)%size;
        }

        (*arr)[index] = newn;
    }

    void InsertQuadratic(int iNo, string val)
    {
        if(iCnt >= size)
        {
            cout<<"HashTable is FULL"<<endl;
            return;
        }

        Node* newn = new Node(iNo, val);

        iCnt++;
        int index = iNo % size;
        int i = 0;
        while((*arr)[(index + i*i)%size] != NULL)
        {
            i++;
        }

        (*arr)[(index + i*i)%size] = newn;
    }

    void lookup(int iNo)
    {
        int index = iNo%size;
        do
        {
            if((*arr)[index] && (*arr)[index]->key == iNo)
            {
                cout<<iNo << " -> "<<(*arr)[index]->value<<endl;
                return;
            }
            index = (index+1)%size;
        }while(index != iNo%size);

        cout<<"Data not found!!"<<endl;
    }

    void Display()
    {
        for(int i = 0; i<size; i++)
        {
            if(((*arr)[i]) == NULL)
                cout<<" NULL "<<endl;
            else
                cout<<((*arr)[i])->key<<" -> "<<((*arr)[i])->value<<endl;
        }
    }
};

int main()
{
    HashTable obj(10);
    obj.InsertQuadratic(29, "Ani");
    obj.InsertQuadratic(66, "Kart");
    obj.InsertQuadratic(47, "Dnyan");
    obj.InsertQuadratic(18, "Gan");
    obj.InsertQuadratic(40, "Vaib");
 
    obj.Display();
    obj.lookup(29);
    return 0;
}