#include <iostream>
#include <vector>
#include <deque>
using namespace std;

class ListNode {
public:
    ListNode() :data(0), next(0) {};
    ListNode(int a, int w) :data(a), weight(w), next(0) {};
    int data;
    int weight; //圖形edge的權重
    ListNode* next;
};


class LinkedList {
public:
    LinkedList() :head(0), tail(0){};
    ListNode* head;            // list的第一個node
    ListNode* tail;            // list的最後一個node
    void insertTail(int data, int weight); //插入元素至 list 尾巴 
};

void LinkedList::insertTail(int data, int weight) {
    ListNode* node = new ListNode(data, weight);
    if (!head) {
        head = node;
    }
    else {
        tail->next = node;
    }
    tail = node;
}


class Graph {

public:

	
	int n; // 頂點數量
	LinkedList *L; // adjacency list，記錄每個頂點相鄰的頂點(頂點編號為1~n)

	// constructor
	Graph (int n) {
		this->n = n;
		this->L = new LinkedList[n + 1];
	}

	void set_edge (int v_i, int v_j, int weight) {

		// 無向圖的(v_i, v_j) and (v_j, v_i) 相同
		this->L[v_i].insertTail(v_j, weight);
		this->L[v_j].insertTail(v_i, weight);

	}
    

};

int main() {


	int n; // nodes 數量
	std::cin >> n;
	Graph G(n); //創建有n個node的graph
	
	int m; // edge 數量
	std::cin >> m;

	// read E
	for (int i = 0; i <m; ++i) {
		int v_i, v_j, weight; // edge: (v_i, v_j)
		std::cin >> v_i >> v_j >>weight; // read edge
		G.set_edge(v_i, v_j, weight); // set edge
	}
	
	return 0;

}
