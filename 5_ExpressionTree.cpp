#include<iostream>
#include<stack>
using namespace std;

class Node
{
    public:
    char data;
    Node* left, *right;

    Node(char ch)
    {
        this->data = ch;
        left = right = NULL;
    }
};

class ExpressionTree
{
    public:
    
    Node* BuildTree(string str)
    {
        stack<Node*> s;
        for(int i = str.length()-1; i>=0; i--)
        {
            if(isalnum(str[i]))
            {
                s.push(new Node(str[i]));
            }
            else
            {
                Node* newn = new Node(str[i]);
                newn -> left = s.top();
                s.pop();
                newn -> right = s.top();
                s.pop();

                s.push(newn);
            }
        }

        return s.top();
    }

    void PostOrder(Node* root)
    {
        if(!root) return;
        stack<Node*> s1, s2;
        s1.push(root);
        while(!s1.empty())
        {
            Node* node = s1.top();
            s1.pop();
            s2.push(node);

            if(node->left) s1.push(node->left);
            if(node->right) s1.push(node->right);
        }

        while(!s2.empty())
        {
            Node* node = s2.top();
            cout<<node->data<<" -> ";
            s2.pop();
        }
    }

    Node* DeleteTree(Node* root)
    {
        if(!root) return NULL;

        root->left =  DeleteTree(root->left);
        root->right = DeleteTree(root->right);
        delete root;
        return NULL;
    }
};

int main()
{
    string str = "-+abc";
    ExpressionTree obj;
    Node* root = NULL;
    root = obj.BuildTree(str);
    obj.PostOrder(root);
    root = obj.DeleteTree(root);
    cout<<root<<endl;
    obj.PostOrder(root);
    return 0;
}