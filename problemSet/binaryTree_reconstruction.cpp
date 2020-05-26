#include <iostream>
#include <vector>
#include <map>
using namespace std;


/* 函數功能: A, B是兩個陣列，彼此為重新排列，
求A的元素對應到B的相同元素的哪一個index，要求O(n)時間建表
例:
vector<int> A = {3,9,20,15,7};
vector<int> B = {9,3,15,20,7};
output: 1 0 3 2 4
因為A的第0個元素3出現在B的index1的位置，
因為A的第1個元素9出現在B的index3的位置，…
以此類推
*/
vector<int> transAtoB(const vector<int> &A, const vector<int> &B)
{
    //建B的反對應表，記錄數字的index
    //例如 B = {9,3,15,20,7};
    //則map[9]=0, map[3]=1, ...
    map<int, int> inverse_B;
    for (int i = 0; i < B.size(); i++)
    {
        inverse_B[B[i]]=i;
    }

    vector<int> tableAtoB(A.size());
    for (int i = 0; i < A.size(); i++)
    {
        tableAtoB[i]= inverse_B[A[i]];
    }
    return tableAtoB;
}

/*
class功能:
利用preorder, inorder，
或是postorder, inorder將原本的binary tree建構出來
*/
class BinaryTree
{
    class Node
    {
    public:
        int data;
        Node* left;
        Node* right;
        Node(int d):data(d), left(NULL), right(NULL) {};
    };
public:
    Node* root;

    void readPreoder(vector<int> &vec)
    {
        preorder = vec;
    }

    void readInorder(vector<int> &vec)
    {
        inorder = vec;
    }

    void readPostorder(vector<int> &vec)
    {
        postorder = vec;
    }

    //函數功能:利用preorder 和 inorder 建原來的 tree
    void buildTree_pre_in()
    {
        table = transAtoB(preorder, inorder);
        root = myBuildTree_pre_in(0, preorder.size()-1, 0, inorder.size()-1);
    }

    //函數功能:利用postorder 和 inorder 建原來的 tree
    void buildTree_post_in()
    {
        table = transAtoB(postorder, inorder);
        root = myBuildTree_post_in(0, postorder.size()-1, 0, inorder.size()-1);
    }


    //函數功能: 以preOrder順序訪樹，回傳vector<int>
    vector<int> preOrder()
    {
        help_preOrder(true, root);
        return visit_order;
    }

    //函數功能: 以postOrder順序訪樹，回傳vector<int>
    vector<int> postOrder()
    {
        help_postOrder(true, root);
        return visit_order;
    }

private:
    vector<int> preorder, inorder, postorder;
    vector<int> table;
    vector<int> visit_order;
    // 函數功能:利用inorder 和 preorder 建原來的 tree，記錄當前處理的pre和in的位置
    Node* myBuildTree_pre_in(int pre_left, int pre_right, int in_left, int in_right)
    {

        if (pre_left>pre_right)
            return NULL;
        Node* node = new Node(preorder[pre_left]);
        int inIndex = table[pre_left];

        node->left = myBuildTree_pre_in(pre_left+1, pre_left+inIndex-in_left, in_left, inIndex - 1);
        node->right = myBuildTree_pre_in(pre_left+inIndex-in_left+1, pre_right, inIndex + 1, in_right);

        return node;
    }

    // 函數功能:利用tree的 postorder 和 inorder 建原來的 tree，記錄當前處理的post和in的位置
    Node* myBuildTree_post_in(int post_left, int post_right, int in_left, int in_right)
    {

        if (post_left>post_right)
            return NULL;
        Node* node = new Node(postorder[post_right]);
        int inIndex = table[post_right];

        node->left = myBuildTree_post_in(post_left, post_left+inIndex-in_left-1, in_left, inIndex - 1);
        node->right = myBuildTree_post_in(post_left+inIndex-in_left, post_right-1, inIndex + 1, in_right);

        return node;
    }

    void help_preOrder(bool first, Node* node)
    {
        if(first)
        {
            visit_order.clear();
            first=false;
        }
        if (node != NULL)
        {
            visit_order.push_back(node->data);
            help_preOrder(first, node->left);
            help_preOrder(first, node->right);

        }
    }

    void help_postOrder(bool first, Node* node)
    {
        if(first)
        {
            visit_order.clear();
            first=false;
        }
        if (node != NULL)
        {
            help_postOrder(first, node->left);
            help_postOrder(first, node->right);
            visit_order.push_back(node->data);
        }
    }

};

int main()
{
    /*Note: 樹的長相:
       3
      / \
      9  20
        /  \
      15   7
    */
    vector<int> preorder = {3,9,20,15,7};
    vector<int> postorder = {9,15,7,20,3};
    vector<int> inorder= {9,3,15,20,7};

    BinaryTree tree;
    tree.readPreoder(preorder);
    tree.readPostorder(postorder);
    tree.readInorder(inorder);

    //測試一: 利用preorder, inorder建樹，印postOrder檢查
    tree.buildTree_pre_in();
    vector<int> visited = tree.postOrder();
    for(int node:visited)
    {
        cout<<node<<" ";
    }
    cout<<endl;

    //測試二: 利用postorder, inorder建樹，印preOrder檢查
    tree.buildTree_post_in();
    visited = tree.preOrder();
    for(int node:visited)
    {
        cout<<node<<" ";
    }
    cout<<endl;

}
