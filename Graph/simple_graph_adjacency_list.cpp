#include <iostream>
#include <vector>
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

// 0-index base Heap
class Heap
{
private:
    void heapify();
public:
    Heap() = default;
    Heap(vector<int> vec):arr(vec){heapify();};
    vector<int> arr;
    void insert(int data);
    int get_min();
    void extract_min();
};

//調整heap使它滿足parent都比child小的規則(總時間: O(n))
void Heap::heapify()
{
    //這邊與extract-min的做法一樣，從下往上，將有小孩的節點往下交換
    for (int i = (arr.size()-1)/2; i>=0; i--) {
        int idx=i;
        //若節點是有小孩的就繼續迴圈
        while(idx*2+1 <arr.size()){
            int small_chlid_idx  = idx*2+1; //判斷小孩節點比較小的編號
            if (small_chlid_idx + 1 < arr.size() && arr[small_chlid_idx + 1] < arr[small_chlid_idx])
                small_chlid_idx++;
            if(arr[idx] > arr[small_chlid_idx])
                swap(arr[idx], arr[small_chlid_idx]);
            idx = small_chlid_idx;
        }
    }
}

void Heap::insert(int data)
{
    arr.push_back(data);
    int idx = arr.size()-1;
    while(idx>0 && arr[idx]<arr[(idx-1)/2]){
        swap(arr[idx], arr[(idx-1)/2]);
        idx = (idx-1)/2;
    }
}

int Heap::get_min() {
    return !arr.empty()? arr[0]: 0;
}

//拿走最小的元素，若heap為空不做事
void Heap::extract_min()
{
    if(arr.empty()){
        return;
    }
    
    int small = arr[0];
    swap(arr[0], arr[arr.size()-1]);
    arr.pop_back(); //清掉最後一個元素(即最小的那個)
    int idx = 0;
    //若節點是有小孩的就繼續迴圈
    while(idx*2+1 <arr.size()){
        int small_chlid_idx  = idx*2+1; //判斷小孩節點比較小的編號
        if (small_chlid_idx + 1 < arr.size() && arr[small_chlid_idx + 1] < arr[small_chlid_idx])
            small_chlid_idx++;
        if(arr[idx] > arr[small_chlid_idx])
            swap(arr[idx], arr[small_chlid_idx]);
        idx = small_chlid_idx;
    }
}


class Graph {

public:

	
	int n; // number of nodes
	LinkedList *L; // adjacency list

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

	void print () {
		
		// 重要: 這邊使用heap是因為題目有要求說要照順序把graph的邊印出來，
		// 用heap可以快速找到一堆數字的最小值，避免超時
		// 若用其它排序工具應該也可以
		Heap h;
		for (int v_i = 1; v_i <= this->n; v_i++) {
			
			for (ListNode *cur = this->L[v_i].head; cur != NULL; cur = cur->next){
				int v_j = cur->data;
				// only (v_i, v_j), j > i is valid representation
				if (v_i < v_j) {
					h.insert(v_j);
				}

			}
			
			while(!h.arr.empty()){
				int v_j =h.get_min();
				h.extract_min();
				std::cout << v_i << " " << v_j << "\n";
			}
		}
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

	G.print(); // display E_sorted

	return 0;

}
