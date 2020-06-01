#include <iostream>
using namespace std;

struct Node
{

    int height;
    size_t key;
    Node *left, *right;

    // create a node with key
    Node (size_t key):height(1), key(key), left(NULL), right(NULL) {};

    ~Node ()
    {
        if (this->left != NULL)
            delete this->left;
        if (this->right != NULL)
            delete this->right;
    }

};


// AVL tree
struct AVL
{

    // node of binary tree

    Node *root;

    // create a empty AVL tree
    AVL (): root(NULL) {};

    ~AVL()
    {
        if (this->root == NULL)
            delete this->root;
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
        return u;

    }


    Node* _insert(Node* node, int key)
    {
        /* 1. Perform the normal BST insertion */
        if (node == NULL)
            return new Node(key);

        if (key < node->key)
            node->left = _insert(node->left, key);
        else if (key > node->key)
            node->right = _insert(node->right, key);
        else // Equal keys are not allowed in BST
            return node;
        return node;
    }


    // insert key into AVL tree
    void insert (size_t key)
    {

        this->root = this->_insert(this->root, key);
    }

    Node* search(int key){

        if(root->key==key){
            return NULL;
        }

        Node *parent = root, *node = root;
        while (node && node->key!=key)
        {
            parent = node;
            if (node->key < key)
            {
                node = node->right;
            }
            else
            {
                node = node->left; 
            }
        }
        return parent;

    }

    // return predecessor of key in BST
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

};

int main ()
{

    // number of operations
    int m;
    std::cin >> m;

    // AVL tree
    AVL T;
    for (int i = 0; i < m; i++)
    {
        int key;
        cin>> key;
        T.insert(key);
    }
    cin>>m;
    for (int i = 0; i < m; i++)
    {
        int type, key;
        std::cin >> type >> key;
        Node* parent = T.search(key);
        Node* node;
        if(parent==NULL){
          node = T.root;
        }
        else if(key>parent->key){
          node = parent->right;
        }
        else{
          node = parent->left;
        }
        switch (type)
        {
        case 1: // RL
            node->right = T.R_rotate(node->right);
            node = T.L_rotate(node);
            break;
        case 2: // R
            node = T.R_rotate(node);
            break;
        case 3: // LR
            node->left = T.L_rotate(node->left);
            node = T.R_rotate(node);
            break;
        case 4: // L
            node = T.L_rotate(node);
            break;
        }
        cout<< node->key <<endl;
        if(parent==NULL){
          T.root = node;
        }
        else if(key>parent->key){
          parent->right = node;
        }
        else{
          parent->left = node ;
        }
    }
    return 0;

}
