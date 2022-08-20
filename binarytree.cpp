#include <iostream>
#include <queue>
using namespace std;

class Node
{
public:
    int data;
    Node *left;
    Node *right;

    Node(int data)
    {
        this->data = data;
        this->left = NULL;
        this->right = NULL;
    }
};

Node *buildTree(Node *root)
{
    cout << "Enter data:" << endl;
    int data;
    cin >> data;
    root = new Node(data);
    if (data == -1)
        return NULL;

    cout << "Enter left child of " << data << ":" << endl;
    root->left = buildTree(root->left);
    cout << "Enter right child of " << data << ":" << endl;
    root->right = buildTree(root->right);
    return root;
}

void levelOrder(Node *root)
{
    if (root == NULL)
        return;
    queue<Node *> q;
    q.push(root);
    q.push(NULL);
    while (!q.empty())
    {
        Node *temp = q.front();
        q.pop();
        if (temp == NULL) // level complete
        {
            cout << endl;
            if (!q.empty())
                q.push(NULL);
        }
        else
        {
            cout << temp->data << " ";
            if (temp->left != NULL)
                q.push(temp->left);
            if (temp->right != NULL)
                q.push(temp->right);
        }
    }
}

void inOrder(Node *root)
{
    if (root == NULL)
        return;
    inOrder(root->left);
    cout << root->data << " ";
    inOrder(root->right);
}

void preOrder(Node *root)
{
    if (root == NULL)
        return;
    cout << root->data << " ";
    preOrder(root->left);
    preOrder(root->right);
}

void postOrder(Node *root)
{
    if (root == NULL)
        return;
    postOrder(root->left);
    postOrder(root->right);
    cout << root->data << " ";
}

Node *buildFromLevelOrder(int *arr, int n)
{
    if (n == 0)
        return NULL;
    Node *root = new Node(arr[0]);
    queue<Node *> q;
    q.push(root);
    int i = 1;
    while (!q.empty())
    {
        Node *temp = q.front();
        q.pop();
        if (i < n)
        {
            temp->left = new Node(arr[i]);
            q.push(temp->left);
        }
        i++;
        if (i < n)
        {
            temp->right = new Node(arr[i]);
            q.push(temp->right);
        }
        i++;
    }
    return root;
}

Node *buildFromLevelOrder(int *arr, int n, int *i)
{
    if (*i >= n)
        return NULL;
    Node *root = new Node(arr[*i]);
    (*i)++;
    if (*i >= n)
        return root;
    root->left = buildFromLevelOrder(arr, n, i);
    root->right = buildFromLevelOrder(arr, n, i);
    return root;
}

Node *buildFromLevelOrder(Node *root)
{
    queue<Node *> q;
    cout << "Enter data for root" << endl;
    int data;
    cin >> data;
    root = new Node(data);
    if (root == NULL)
        return NULL;
    q.push(root);

    while (!q.empty())
    {
        Node *temp = q.front();
        q.pop();

        cout << "Enter left node for: " << temp->data << endl;
        int leftData;
        cin >> leftData;
        if (leftData != -1)
        {
            temp->left = new Node(leftData);
            q.push(temp->left);
        }

        cout << "Enter right node for: " << temp->data << endl;
        int rightData;
        cin >> rightData;
        if (rightData != -1)
        {
            temp->right = new Node(rightData);
            q.push(temp->right);
        }
    }
}

int main()
{
    Node *root = NULL;
    root = buildTree(root);
    return 0;
}