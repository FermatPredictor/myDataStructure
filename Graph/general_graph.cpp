#include <iostream>
#include <vector>
#include <deque>
#include <list>
using namespace std;

//實作graph，頂點編號為1~n
class Graph {

//general的狀況，定義在graph中的節點結構
class GraphNode {
public:
    GraphNode(){};
    GraphNode(int n) :node(n){};
    GraphNode(int n, int w) :node(n), weight(w){};
    int node; //頂點編號
    int weight; //for weighted graph
};

//general的狀況，定義在BFS中使用的node結構
struct queueNode 
{ 
    int node; //頂點編號
    int dist; //距離起點的距離
}; 

public:
	int n; //頂點數量
	vector<list<GraphNode>> L; // adjacency list，記錄每個頂點相鄰的頂點

	Graph (int n) {
		this->n = n;
		this->L = vector(n+1, list<GraphNode>());
	}

	// insert edge (v_i, v_j) into graph
	void set_edge (int v_i, int v_j) {

		// 無向圖的(v_i, v_j) 和 (v_j, v_i)相同
        // 若是有向圖只能設一邊
		this->L[v_i].push_back(GraphNode(v_j));
		this->L[v_j].push_back(GraphNode(v_i));

	}

    // 功能: 從src出發，用BFS拜訪相鄰頂點
    // 這邊回傳與src相連的點有幾個
	int BFS(int src) {


		vector<bool> visited(n+1, false); //記錄頂點在BFS中是否拜訪過
		
		deque<queueNode> Q; //記錄接下來BFS的處理順序
		Q.push_back({src,0});
		visited[src] = true; //先拜訪src

		while (!Q.empty()) {

			queueNode v_i = Q.front();
			Q.pop_front();

			// 拜訪v_i的所有鄰居
			for (auto it = L[v_i.node].begin(); it != L[v_i.node].end(); it++) {
				GraphNode v_j = *it;
                int node= v_j.node;
				//若頂點v_j沒拜訪過，拜訪它
				if (!visited[node]) {
					visited[node] = true;
					Q.push_back({node, v_i.dist+1});
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
	std::cout<< G.BFS(src) << std::endl;
	return 0;

}
