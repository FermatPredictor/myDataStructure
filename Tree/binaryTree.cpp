#include <stdio.h>
#include <iostream>
#include <vector>
#include <map>
#include <deque>
#include <utility>
using namespace std;

class BinaryTree
{
public:
    int root;
    map<int, pair<int, int> > treeNode; //map的意思是node的名字，pair是左、右child的編號 
    
    //開一個vector把拜訪的順序存起來(初始參數應當設空vector, root)
    void preorder(vector<int> &data, int r){
    	if(r!=0){
    		data.push_back(r);
	        preorder(data, treeNode[r].first);
	        preorder(data, treeNode[r].second);
		}	
	}
	
	void inorder(vector<int> &data, int r){
    	if(r!=0){
    		inorder(data, treeNode[r].first);
	        data.push_back(r);
	        inorder(data, treeNode[r].second);
		}
	}
	
	void postorder(vector<int> &data, int r){
    	if(r!=0){
    		postorder(data, treeNode[r].first);
	        postorder(data, treeNode[r].second);
	        data.push_back(r);
		}
	}
	
	void levelorder(vector<int> &data, int r){
		deque<int> Q;
		Q.push_back(r);
		while(!Q.empty()){
			int front = Q.front();
			data.push_back(front);
			int left = treeNode[front].first;
			int right = treeNode[front].second;
			if(left!=0){
				Q.push_back(left);
			}
			if(right!=0){
				Q.push_back(right);
			}
			Q.pop_front();	
		} 
	}
};

void printVector(vector<int> &data){
	
	if(!data.empty()){
		cout<<data[0];
	}
	for(int i=1;i<data.size();i++){
		cout<<" "<<data[i];
	}
	cout << endl;
}

int main()
{
    //讀測資
    int t;
    std::cin >> t;
    BinaryTree tree;
    for (int i = 0; i < t; i++) {
        int key, left, right;
        std::cin >> key >> left >> right;
        tree.treeNode.insert(pair<int, pair<int, int> >(key, {left, right}));
    }
    int rootNo;
    std::cin >> rootNo;
    tree.root = rootNo;
    
    vector<int> data;
    
    tree.preorder(data, tree.root);
    printVector(data);
    
    data.clear();
    tree.inorder(data,tree.root);
    printVector(data);

    data.clear();
    tree.postorder(data,tree.root);
    printVector(data);
    
    data.clear();
    tree.levelorder(data,tree.root);
    printVector(data);
    return 0;
}
