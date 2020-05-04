#include <iostream>
#include <vector>
#include <deque>
#include <list>
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
    vector<int> InDegree;

    Graph (int n)
    {
        this->n = n;
        this->L = vector(n+1, list<GraphNode>());
        this->InDegree  = vector(n+1, 0);
    }

    void set_edge (int v_i, int v_j)
    {

        // 若是無向圖的(v_i, v_j) 和 (v_j, v_i)相同
        // 若是有向圖只能設一邊
        this->L[v_i].push_back(GraphNode(v_j));
        this->InDegree[v_j] ++;

    }


    //利用每個node的indegree做Topological_Sort
    vector<int> Topological_Sort()
    {
        vector<int> inDegree(this->InDegree);
        deque<int> S;
        vector<int> res;
        for (int i = 1; i < inDegree.size(); i++)
        {
            if (inDegree[i] == 0)
                S.push_back(i);
        }

        while (!S.empty())
        {
            int node = S.front();
            S.pop_front();

            for (GraphNode adjNode : L[node])
            {
                int i = adjNode.node;
                inDegree[i]--;
                if (inDegree[i] == 0)
                    S.push_back(i);
            }
            res.push_back(node);
        }
        return res;
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
    vector<int> topological_sort_nodes = G.Topological_Sort();
    if(topological_sort_nodes.size()==n)
    {
        cout << "yes" << endl;
    }
    else
    {
        cout << "no" << endl;
    }
    return 0;

}
