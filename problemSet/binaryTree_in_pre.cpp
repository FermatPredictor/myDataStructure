#include <bits/stdc++.h> 
using namespace std; 
  

class Node  
{  
public: 
    int data;  
    Node* left;  
    Node* right;
    Node(int d):data(d), left(NULL), right(NULL){};
};  


int search(const vector<int> &arr, int strt, int end, int value)  
{   
    for (int i = strt; i <= end; i++)  
    {  
        if (arr[i] == value)  
            return i;  
    }  
} 
  

//函數功能:利用tree的 inorder 和 preorder 建原來的 tree 
Node* buildTree(const vector<int> & pre, const vector<int> &in, int pre_left, int pre_right, int inStrt, int inEnd)  
{  
 
    if (pre_left>pre_right)  
        return NULL;  
  
    Node* tNode = new Node(pre[pre_left]);
  
    int inIndex = search(in, inStrt, inEnd, tNode->data);  
  
    tNode->left = buildTree(pre, in, pre_left+1, pre_left+inIndex-inStrt, inStrt, inIndex - 1);  
    tNode->right = buildTree(pre, in, pre_left+inIndex-inStrt+1, pre_right, inIndex + 1, inEnd);  
  
    return tNode;  
}  
  
 
  
  
/* This funtcion is here just to test buildTree() */
void printInorder(Node* node)  
{  
    if (node == NULL)  
        return;  
  
    printInorder(node->left);  
    cout<<node->data<<" ";  
    printInorder(node->right);  
}  
  
/* Driver code */
int main()  
{  
    vector<int>  in = {2, 5, 10, 7, 3, 6, 9, 4, 1, 8};
    vector<int> pre = {7, 10, 2, 5, 4, 6, 3, 9, 8, 1};  
    Node* root = buildTree(in, pre,0,pre.size()-1, 0, in.size() - 1);  
  
    // test
    cout << "Inorder traversal of the constructed tree is \n";  
    printInorder(root);  
}  
  
