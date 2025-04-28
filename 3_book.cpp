#include<iostream>
#include<vector>
using namespace std;

class Node
{
    public:
    string data;
    vector<Node*> children;
    Node(string str)
    {
        data = str;
    }
};

void addData(Node* Head, Node* newn)
{
    if(Head == NULL)
        return;

    Head->children.push_back(newn);
}

void Print(Node* Head)
{
    if(Head == NULL)
        return;

    cout<<"Title of Book is: "<<Head->data<<endl;

    for(auto i:Head->children)
    {
        cout<<"\tChapter is: "<<i->data<<endl;
        for(auto j : i->children)
        {
            cout<<"\t\tSection is: "<<j->data<<endl;
            for(auto k : j->children)
            {
                cout<<"\t\t\tsubSection is: "<<k->data<<endl;
            }
        }
    }
}

int main()
{
    Node* Book = new Node("Babbar");
    Node* Chapter1 = new Node("Love");
    Node* Section1 = new Node("DSA");
    Node* subSection1 = new Node("Binary Search");

    addData(Book, Chapter1);
    addData(Chapter1, Section1);
    addData(Section1, subSection1);

    Print(Book);
    return 0;
}