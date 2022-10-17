#include <iostream>
#include<stack>
#include<vector>
using namespace std;
struct node
{
    int data;
    node *right;
    node *left;
    node(int val)
    {
        data = val;
        right = NULL;
        left = NULL;
    }
};
vector <int> zigzag(node *root)
{
    stack<node*> curr;
    stack<node*> nextl;
    vector<int>ans;
    bool lefttoright = true;

    curr.push(root);
    while(!curr.empty())
    {
        node* temp = curr.top();
        curr.pop();
        if(temp!=NULL)
        {
            // cout<<temp->data<<" ";
            ans.push_back(temp->data);
            if(lefttoright)
            {
                if(temp->left)
                {
                    nextl.push(temp->left);
                }
                if(temp->right)
                {
                    nextl.push(temp->right);
                }
            }
            else
            {
                if(temp->right)
                {
                    nextl.push(temp->right);
                }
                if(temp->left)
                {
                    nextl.push(temp->left);
                }
            }
        }
        if(curr.empty())
        {
            lefttoright = !lefttoright;
            swap(curr,nextl);
        }
    }
    return ans;
}
int main()
{
    node *root = new node(12);
    root->left = new node(9);
    root->right = new node(15);
    root->left->left = new node(5);
    root->left->right = new node(10);
    vector<int> ans;
    ans = zigzag(root);
    for (int i = 0; i < ans.size(); i++)
    {
        cout<<ans[i]<<" ";
    }
    
    return 0;
}