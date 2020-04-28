#include <iostream>
#include <vector>
using namespace std;

/* 函數功能: A, B是兩個陣列，都是1~n 的一種排列，
求A的元素對應到B的相同元素的哪一個index，要求O(n)時間建表
例: 
vector<int> A = {2,5,3,1,4};
vector<int> B = {3,1,4,5,2};
output: 14023

因為A的1出現在B的index1的位置，
因為A的2出現在B的index4的位置，…
以此類推
*/
vector<int> transAtoB(const vector<int> &A, const vector<int> &B)
{
    //建B的反對應表，記錄數字的index
    vector<int> inverse_B(B.size());
    for (int i = 0; i < B.size(); i++) {
        inverse_B[B[i]-1]=i;
    }
    
    vector<int> tableAtoB(A.size());
    for (int i = 0; i < A.size(); i++) {
        tableAtoB[A[i]-1]= inverse_B[A[i]-1];
    }
    return tableAtoB;
}
  

class Node  
{  
public: 
    int data;  
    Node* left;  
    Node* right;
    Node(int d):data(d), left(NULL), right(NULL){};
};  


//函數功能:利用tree的 inorder 和 preorder 建原來的 tree，記錄當前處理的pre和in的位置
Node* buildTree(const vector<int> & pre, const vector<int> &in, int pre_left, int pre_right, int in_left, int in_right)  
{  
 
    if (pre_left>pre_right)  
        return NULL;
        
    vector<int> table = transAtoB(pre, in);
  
    Node* node = new Node(pre[pre_left]);
    int inIndex = table[node->data-1];  //查詢現在的root對應到inorder的哪個index，注意因元素是1~n，查表時要減1
  
    node->left = buildTree(pre, in, pre_left+1, pre_left+inIndex-in_left, in_left, inIndex - 1);  
    node->right = buildTree(pre, in, pre_left+inIndex-in_left+1, pre_right, inIndex + 1, in_right);  
  
    return node;  
}  
  
 
  
//用來測試建樹是否正確
void printInorder(Node* node)  
{  
    if (node != NULL)  {
        printInorder(node->left);  
        cout<<node->data<<" ";  
        printInorder(node->right);  
    }
}  
  

int main()  
{  
    vector<int> pre = {7, 10, 2, 5, 4, 6, 3, 9, 8, 1};
    vector<int>  in = {2, 5, 10, 7, 3, 6, 9, 4, 1, 8};
    vector<int> table = transAtoB(pre, in);
    
    Node* root = buildTree(pre, in, 0,pre.size()-1, 0, in.size() - 1); 
    cout << "樹的inorder為: " << endl;  
    printInorder(root);  
}  
