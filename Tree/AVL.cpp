#include <iostream>
using namespace std;
//ref: https://www.geeksforgeeks.org/avl-tree-set-1-insertion/

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

    int height(Node *v)
    {
        return ((v==NULL)?0:v->height);
    }

    int getBalance(Node *v)
    {
        return (v==NULL?0:(height(v->left) - height(v->right)));
    }

    Node* L_rotate (Node *v)
    {

        Node *u = v->right;
        v->right = u->left;
        u->left = v;

        v->height = max(height(v->left), height(v->right))+1;
        u->height = max(height(u->left), height(u->right))+1;

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

        v->height = max(height(v->left), height(v->right))+1;
        u->height = max(height(u->left), height(u->right))+1;
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

        /* 2. Update height of this ancestor node */
        node->height = 1 + max(height(node->left),
                               height(node->right));

        /* 3. Get the balance factor of this ancestor
            node to check whether this node became
            unbalanced */
        int balance = getBalance(node);

        // If this node becomes unbalanced, then
        // there are 4 cases

        // Left Left Case
        if (balance > 1 && key < node->left->key)
            return R_rotate(node);

        // Right Right Case
        if (balance < -1 && key > node->right->key)
            return L_rotate(node);

        // Left Right Case
        if (balance > 1 && key > node->left->key)
        {
            node->left = L_rotate(node->left);
            return R_rotate(node);
        }

        // Right Left Case
        if (balance < -1 && key < node->right->key)
        {
            node->right = R_rotate(node->right);
            return L_rotate(node);
        }

        /* return the (unchanged) node pointer */
        return node;
    }


    // insert key into AVL tree
    void insert (size_t key)
    {

        this->root = this->_insert(this->root, key);
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
