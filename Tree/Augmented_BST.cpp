#include <iostream>
using namespace std;

// binary search tree
class BST
{
    struct Node
    {
        int key;
        Node *left;
        Node *right;
        int size_L; //size of left subtree
        Node (int key): key(key), left(NULL), right(NULL), size_L(0) {};
    };

public:
    Node *root;
    BST():root(NULL) {};

    //回傳key是否在BST裡
    bool exist (int key)
    {
        Node *node = root;

        while (node != nullptr)
        {
            if (key < node->key)
            {
                node = node->left;
            }
            else if (key > node->key)
            {
                node = node->right;
            }
            else
                return true;
        }
        return false;
    }

    void insert (int key)
    {
        //若key值不存在才插入，避免node的左子樹節點多算
        if(!exist(key)){
            root = _insert(root, key);
        }
    }

    //回傳key值的排名為第幾小
    //若key不存在，回傳其predecessor的排名，
    //否則回傳0
    int rank (int key)
    {

        int rank_so_far = 0; //目前節點的排名
        Node *node = root;
        while (node != NULL)
        {
            if (key < node->key)
            {
                node = node->left;
            }
            else if (key > node->key)
            {
                // 此節點與左子樹皆小於key
                rank_so_far += 1 + node->size_L;
                node = node->right;
            }
            else //找到key了
            {
                // 左子樹皆小於key，不過自己的排名要再+1
                rank_so_far += 1 + node->size_L;
                break;
            }
        }
        return rank_so_far;
    }

    // 回傳第k小的值，若k比tree size大，回傳tree的最大值
    // 若tree為空，回傳0
    int select_k (int k)
    {

        if (!root)
            return 0;

        int rank_prev = 0; //前一個(較小)節點的rank值
        Node *node = root;
        while (true)
        {
            //目前節點的rank值
            int rank_so_far = rank_prev + 1 + node->size_L;
            if (k < rank_so_far)
            {
                if (node->left == NULL)
                    break;
                node = node->left;
            }
            else if (k > rank_so_far)
            {
                rank_prev = rank_so_far;
                if (node->right == NULL)
                    break;
                node = node->right;
            }
            else
                break; // exact rank
        }
        return node->key;
    }

    // 第一個大於key的數字
    int predecessor (int key)
    {
        int pred = 0; // 預設predecessor=0 (predecessor不存在)
        Node *node = root;
        while (node != NULL)
        {

            if (node->key < key)
            {
                // update predecessor
                if (node->key > pred)
                {
                    pred = node->key;
                }
                node = node->right; //找有沒有更大的元素小於key
            }
            else
            {
                node = node->left; //key太大了，往左走
            }
        }
        return pred;
    }

    // 第一個小於key的數字
    int successor (int key)
    {
        int succ = (1<<31)-1; // 預設successor=無限大
        Node *node = root;

        while (node != NULL)
        {

            if (node->key > key)
            {
                // update successor
                if (node->key < succ)
                {
                    succ = node->key;
                }
                node = node->left; //找有沒有更小的元素大於key
            }
            else
            {
                node = node->right; //key太小了，往右走
            }

        }
        return ((succ < (1<<31)-1) ? succ : 0);
    }

private:
    // 插入新的key進BST
    Node* _insert (Node* root, int key)
    {
        if (root == NULL)
        {
            return new Node(key);
        }
        if (key < root->key)
        {
            root->left = _insert(root->left, key);
            ++(root->size_L);
        }
        else
        {
            root->right = _insert(root->right, key);
        }
        return root;
    }

};

int main (int argc, char **argv)
{

    // number of operations
    int m;
    std::cin >> m;
    BST T; // binary search tree

    for (int i = 0; i < m; i++)
    {
        int op, key;
        cin >> op >> key;
        switch (op)
        {
        case 1: // insert: 1 key;
            T.insert(key);
            break;
        case 2: // rank: 2 key
            cout << T.rank(key) << endl;
            break;
        case 3: // select: 3 k
            cout << T.select_k(key) << endl;
            break;
        }
    }
    return 0;
}
