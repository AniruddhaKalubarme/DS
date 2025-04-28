#include<iostream>
#include<vector>
using namespace std;

class Node
{
    public:
    int data;
    Node *left, *right;
    Node(int d)
    {
        data = d;
        left = NULL;
        right = NULL;
    }

};

// Node* Insert(Node* root, int data)
// {
//     if(root == NULL)
//     {
//         return new Node(data);
//     }

//     if(root->data < data)
//     {
//         root->right = Insert(root->right, data);
//     }
//     else
//     {
//         root->left = Insert(root->left, data);
//     }
// }

void Insert(Node* &root, int data)
{
    Node* temp = root;
    Node* newn = new Node(data);
    if(root == NULL)
    {
        root = newn;
        return;
    }

    while(true)
    {
        if(temp->data > data)
        {
            if(temp->left == NULL)
            {
                temp->left = newn;
                return;
            }
            temp = temp->left;
        }
        else
        {
            if(temp->right == NULL)
            {
                temp->right = newn;
                return;
            }
            temp = temp->right;
        }
    }
}

int FindMaxLength(Node* root)
{
    if(root == NULL)
        return 0;

    int left = FindMaxLength(root->left);
    int right = FindMaxLength(root->right);

    return max(left, right)+1;
}

void Print(Node* root)
{
    if(root == NULL)
        return;

    Print(root->left);
    cout<<root->data<<" -> ";
    Print(root->right);
}


int main()
{
    Node* root = NULL;
    Insert(root, 5);
    Insert(root, 3);
    Insert(root, 4);
    Insert(root, 2);
    Insert(root, 7);
    Insert(root, 6);

    Print(root);
    cout<<"Maximum Length is: "<<FindMaxLength(root)<<endl;
    return 0;
}