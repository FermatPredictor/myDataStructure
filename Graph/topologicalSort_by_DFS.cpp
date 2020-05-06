#include <iostream>
#include <vector>
#include <deque>
#include <list>
#include <algorithm>
using namespace std;

//實作graph，頂點編號為1~n
class Graph
{

//general的狀況，定義在graph中的節點結構
    class GraphNode
    {
    public:
        GraphNode() {};
        GraphNode(int n) :node(n) {};
        GraphNode(int n, int w) :node(n), weight(w) {};
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
    vector<int> finish; //記錄每個頂點經DFS後的拜訪時間
    vector<int> topolocicalSort; //記錄拓撲排序後的結果

    Graph (int n)
    {
        this->n = n;
        this->L = vector(n+1, list<GraphNode>());
        this->finish  = vector<int>(n+1, 0);
    }

    void set_edge (int v_i, int v_j)
    {

        // 若是無向圖的(v_i, v_j) 和 (v_j, v_i)相同
        // 若是有向圖只能設一邊
        this->L[v_i].push_back(GraphNode(v_j));

    }

    void DFS (int v_i, vector<bool> &visited) {

		static int time = 0;
		visited[v_i] = true;

		for (auto it = L[v_i].begin(); it != L[v_i].end(); it++) {
			int v_j = it->node;
			if (!visited[v_j]){
				DFS(v_j, visited);
			}
		}
        finish[v_i] = ++time;
        topolocicalSort.push_back(v_i);
	}

	// 對graph作拓撲排序並判斷是否有環
	bool is_DAG () {

		vector<bool> visited(n+1, false);
		// topological sort by DFS
		for (size_t v_i = 1; v_i <= n; ++v_i) {
			if (!visited[v_i]) {
				DFS(v_i, visited);
			}
		}
        //在topological sort愈前面的順序，它在DFS的結束時間愈晚
        reverse(topolocicalSort.begin(), topolocicalSort.end());

        //對於所有的邊 (v_i, v_j)，v_i的完成時間必須大於v_j，
        //否則表示有cycle
		bool flag = true;
		for (int v_i = 1; flag && v_i <= n; v_i++) {
			for (auto it = L[v_i].begin(); it != L[v_i].end(); it++) {
				int v_j = it->node;
				if (this->finish[v_i] < this->finish[v_j]) {
					flag = false;
					break;
				}
			}
		}
		return flag;
	}

};

int main()
{


    int n; // nodes 數量
    std::cin >> n;
    Graph G(n); //創建有n個node的graph

    int m; //edges 數量
    std::cin >> m;

    // read E
    for (int i = 0; i < m; ++i)
    {
        int v_i, v_j; // edge: (v_i, v_j)
        std::cin >> v_i >> v_j; // read edge
        G.set_edge(v_i, v_j); // set edge
    }

    //如果是DAG, 印出yes，否則印出no
    if(G.is_DAG())
    {
        cout << "yes" << endl;
    }
    else
    {
        cout << "no" << endl;
    }
    return 0;

}
