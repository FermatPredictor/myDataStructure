#include <iostream>
using namespace std;

// binary search tree
struct BST {

    struct Node {
        int key;
        Node *left;
        Node *right;
        Node (int key): key(key), left(NULL), right(NULL) {};
    };

	Node *root;
	BST():root(NULL) {};

	// 插入新的key進BST
	void insert (int key) {

		if (root == NULL) { 
			root = new Node(key);
		} 
        else {
			Node *node = root;
			while (true) {
				if (key < node->key) { 
					if (node->left == NULL) { 
						node->left = new Node(key);
						break;
					}
                    else{
						node = node->left; 
					}
				} 
                else {
					if (node->right == NULL) { 
						node->right = new Node(key);
						break;
					} 
                    else{
						node = node->right;
					}
				}
			}
		}
	}

	// return predecessor of key in BST
	int predecessor (int key) {

		int pred = 0; // 預設predecessor=0 (predecessor不存在)
		Node *node = root;
		while (node != NULL) {

			if (node->key < key) {

				// update predecessor
				if (node->key > pred){
                    pred = node->key;
                } 
				node = node->right; //找有沒有更大的元素小於key

			} 
            else {
				node = node->left; //key太大了，往左走
			}
		}
		return pred;
	}

	// return successor of key in BST
	int successor (int key) {

		int succ = (1<<31)-1; // 預設successor=無限大
		Node *node = root;

		while (node != NULL) {

			if (node->key > key) {

				// update successor
				if (node->key < succ){
                    succ = node->key;
                }
				node = node->left; //找有沒有更小的元素大於key

			}
            else{
				node = node->right; //key太小了，往右走
			}

		}
		return ((succ < (1<<31)-1) ? succ : 0);
	}
};

int main (int argc, char **argv) {

	int m;
	std::cin >> m;
	BST T;

	for (int i = 0; i < m; i++) {

		int op, key;
		cin >> op >> key;

		switch (op) {

			case 1: // insert: 1 key

				T.insert(key);
				break;

			case 2: // predecessor: 2 key
				cout << T.predecessor(key) << endl;
				break;

			case 3: // successor: 3 key

				cout << T.successor(key) << endl;
				break;
		}
	}
	return 0;
}
