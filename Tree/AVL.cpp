#include <iostream>
using namespace std;

// AVL tree
class AVL
{
    struct Node
    {
        int height;
        int key;
        Node *left, *right;
        // create a node with key
        Node(int key):height(1), key(key), left(NULL), right(NULL){};

    };

    // node of binary tree

    Node *root;

    int height(Node *v)
    {
        return v==NULL?0:v->height;
    }

    int getBalance(Node *v)
    {
        return v==NULL?0:height(v->left) - height(v->right);
    }

    void update_height(Node *node)
    {
        node->height = max(height(node->left), height(node->right))+1;
    }

    /*
    *      u O            O v
    *       / \          / \
    *    v O   ^   <=   ^   O u
    *     / \              / \
    *    ^   ^            ^   ^
    */
    Node* L_rotate (Node *v)
    {
        Node *u = v->right;
        v->right = u->left;
        u->left = v;
        update_height(v);
        update_height(u);
        return u;
    }

    /*
    *      v O            O u
    *       / \          / \
    *    u O   ^   =>   ^   O v
    *     / \              / \
    *    ^   ^            ^   ^
    */
    Node* R_rotate (Node *v)
    {
        Node *u = v->left;
        v->left = u->right;
        u->right = v;
        update_height(v);
        update_height(u);
        return u;
    }


    Node* _insert(Node* node, int key)
    {
        // 1. 用正常的BST插入法
        if (node == NULL)
            return new Node(key);

        if (key < node->key)
            node->left = _insert(node->left, key);
        else if (key > node->key)
            node->right = _insert(node->right, key);
        else // Equal keys are not allowed in BST
            return node;

        // 2. 更新node的高度 */
        update_height(node);

        // 3. 計算node的 balance factor以檢查樹有沒有不平衡
        int balance = getBalance(node);

        // 不平衡的樹有四種情形: LL, LR, RR, RL
        if (balance > 1){
            if(key < node->left->key){// Left Left Case
                return R_rotate(node); 
            }
            else{ // Left Right Case
                node->left = L_rotate(node->left); 
                return R_rotate(node);
            }
        }
        if(balance < -1){
            if(key > node->right->key){ // Right Right Case
                return L_rotate(node);
            }
            else{ // Right Left Case
                node->right = R_rotate(node->right);
                return L_rotate(node); 
            }
        }
        return node; //回傳原本的node pointer
    }

public:
    AVL (): root(NULL) {};

    // insert key into AVL tree
    void insert (int key)
    {
        root = _insert(root, key);
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

};

int main ()
{

    // number of operations
    int m;
    std::cin >> m;

    // AVL tree
    AVL T;

    // sum of responses of predecessor operation
    long long sum = 0;

    for (int i = 0; i < m; i++)
    {
        // operation identifier & key
        int op, key;
        std::cin >> op >> key;
        switch (op)
        {
        case 1: // insert: 1 key
            T.insert(key);
            break;
        case 2: // predecessor: 2 key
            sum += T.predecessor(key);
            break;
        }
    }
    cout << sum << endl;
    return 0;

}
