#include<iostream>
using namespace std;

class Node
{
public:
    Node* left, *right;
    string key, value;
    int height;
    Node(string key, string value)
    {
        this->key = key;
        this->value = value;
        left = right = NULL;
        height = 1;
    }
};

int getHeight(Node* root)
{
    if(root == NULL)
        return 0;
    return root->height;
}

Node* RightRotation(Node* y)
{
    Node* x = y->left;
    Node* T2 = x->right;

    x->right = y;
    y->left = T2;

    y->height = max(getHeight(y->left), getHeight(y->right)) + 1;
    x->height = max(getHeight(x->left), getHeight(x->right)) + 1;

    return x;
}

Node* LeftRotation(Node* x)
{
    Node* y = x->right;
    Node* T2 = y->left;

    y->left = x;
    x->right = T2;

    x->height = max(getHeight(x->left), getHeight(x->right)) + 1;
    y->height = max(getHeight(y->left), getHeight(y->right)) + 1;

    return y;
}

int getBal(Node* root)
{
    if(root == NULL)
        return 0;
    return getHeight(root->left) - getHeight(root->right);
}

Node* Insert(Node* root, string key, string value)
{
    if(root == NULL)
        return new Node(key, value);

    if(key < root->key)
        root->left = Insert(root->left, key, value);
    else if(key > root->key)
        root->right = Insert(root->right, key, value);
    else
    {
        root->value = value;
        return root;
    }

    root->height = 1 + max(getHeight(root->left), getHeight(root->right));

    int bf = getBal(root);

    // LL
    if(bf > 1 && key < root->left->key)
        return RightRotation(root);

    // RR
    if(bf < -1 && key > root->right->key)
        return LeftRotation(root);

    // LR
    if(bf > 1 && key > root->left->key)
    {
        root->left = LeftRotation(root->left);
        return RightRotation(root);
    }

    // RL
    if(bf < -1 && key < root->right->key)
    {
        root->right = RightRotation(root->right);
        return LeftRotation(root);
    }

    return root;
}

Node* getMin(Node* root)
{
    Node* current = root;
    while(current->left != NULL)
    {
        current = current->left;
    }
    return current;
}

Node* Delete(Node* root, string key)
{
    if(root == NULL)
        return root;

    if(key < root->key)
        root->left = Delete(root->left, key);
    else if(key > root->key)
        root->right = Delete(root->right, key);
    else
    {
        if(root->left == NULL || root->right == NULL)
        {
            Node* temp = root->left ? root->left : root->right;

            if(temp == NULL)
            {
                temp = root;
                root = NULL;
            }
            else
            {
                *root = *temp;
            }

            delete temp;
        }
        else
        {
            Node* temp = getMin(root->right);
            root->key = temp->key;
            root->value = temp->value;
            root->right = Delete(root->right, temp->key);
        }
    }

    if(root == NULL)
        return root;

    root->height = 1 + max(getHeight(root->left), getHeight(root->right));

    int bf = getBal(root);

    // LL
    if(bf > 1 && getBal(root->left) >= 0)
        return RightRotation(root);

    // LR
    if(bf > 1 && getBal(root->left) < 0)
    {
        root->left = LeftRotation(root->left);
        return RightRotation(root);
    }

    // RR
    if(bf < -1 && getBal(root->right) <= 0)
        return LeftRotation(root);

    // RL
    if(bf < -1 && getBal(root->right) > 0)
    {
        root->right = RightRotation(root->right);
        return LeftRotation(root);
    }

    return root;
}

void Inorder(Node* root)
{
    if(root == NULL)
        return;
    Inorder(root->left);
    cout << root->key << " -> " << root->value << endl;
    Inorder(root->right);
}

int main()
{
    Node* root = NULL;
    root = Insert(root, "aniruddha", "shiv");
    root = Insert(root, "kartavya", "vaibhav");
    root = Insert(root, "dnyanesh", "amol");
    root = Insert(root, "kshitij", "ganesh");

    cout << "Inorder before deletion:\n";
    Inorder(root);

    cout << "\nDeleting 'kartavya'...\n";
    root = Delete(root, "kartavya");

    cout << "\nInorder after deletion:\n";
    Inorder(root);

    return 0;
}