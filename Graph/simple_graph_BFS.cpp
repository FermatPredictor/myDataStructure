#include <iostream>
#include <vector>
#include <deque>
using namespace std;

class ListNode {
public:
    ListNode() :data(0), next(0) {};
    ListNode(int a) :data(a), next(0) {};
    int data;
    ListNode* next;
};


class LinkedList {
public:
    LinkedList() :head(0), tail(0){};
    ListNode* head;            // list的第一個node
    ListNode* tail;            // list的最後一個node
    void insertTail(int data); //插入元素至 list 尾巴 
};

void LinkedList::insertTail(int data) {
    ListNode* node = new ListNode(data);
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

	
	int n; // number of nodes
	LinkedList *L; // adjacency list，記錄每個頂點相鄰的頂點(頂點編號為1~n)

	// create graph with number of nodes
	Graph (int n) {
		this->n = n;
		this->L = new LinkedList[n + 1];
	}


	// insert edge (v_i, v_j) into graph
	void set_edge (int v_i, int v_j) {

		// (v_i, v_j) and (v_j, v_i) are the same edge in undirected graph
		this->L[v_i].insertTail(v_j);
		this->L[v_j].insertTail(v_i);

	}

    
	int reachable_nodes (int src) {


		vector<bool> visited(n+1, false); //記錄頂點在BFS中是否拜訪過
		
		deque<int> Q; //記錄接下來BFS的處理順序
		Q.push_back(src);
		visited[src] = true; //先拜訪src


		while (!Q.empty()) {

			int v_i = Q.front();
			Q.pop_front();

			// 拜訪v_i的所有鄰居
			for (ListNode *node = L[v_i].head; node != NULL; node = node->next) {
				int v_j = node->data;
				//若頂點v_j沒拜訪過，拜訪它
				if (!visited[v_j]) {
					visited[v_j] = true;
					Q.push_back(v_j);
				}
			}
		}
		

		int size = 0;
		for (int v_i = 1; v_i < visited.size(); v_i++) {
			if (visited[v_i]) {
				size++;
			}
		}
		return size;

	}

};

int main() {


	int n; // nodes 數量
	std::cin >> n;
	Graph G(n); //創建有n個node的graph

	int m; //edges 數量
	std::cin >> m;

	// read E
	for (int i = 0; i < m; ++i) {
		int v_i, v_j; // edge: (v_i, v_j)
		std::cin >> v_i >> v_j; // read edge
		G.set_edge(v_i, v_j); // set edge
	}
	
	int src;
	std::cin >> src;
	std::cout<< G.reachable_nodes(src) << std::endl;
	return 0;

}
