#include <iostream>
#include <vector>
#include <deque>
#include <queue>
#include <list>
using namespace std;

//實作graph，頂點編號為0~n-1
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

public:
    int n; //頂點數量
    vector<list<GraphNode>> L; // adjacency list，記錄每個頂點相鄰的頂點

    Graph (int n)
    {
        this->n = n;
        this->L = vector(n, list<GraphNode>());
    }

    void set_edge (int v_i, int v_j, int weight)
    {

        // 若是無向圖的(v_i, v_j) 和 (v_j, v_i)相同
        // 若是有向圖只能設一邊
        L[v_i].push_back(GraphNode(v_j, weight));
        //L[v_j].push_back(GraphNode(v_i, weight));

    }

    /*
       函數功能: 從src出發，
       用Dijkstra's algorithm算法，
       求src點到其它點的最短距離
    */
    vector<long long> Dijk_BFS(int src)
    {

        long long inf = (long long)1<<32;
        vector<long long> dp(n, inf);//一開始，走到每個點的距離都是無限大
        dp[src] = 0; //起點到起點的最短距離就是0，因為不用動

        int pt = src;

        for(int i=0; i<n; i++)
        {
            auto cmp = [](GraphNode & a, GraphNode & b)
            {
                return a.weight > b.weight;
            };
            priority_queue <GraphNode, vector<GraphNode>, decltype(cmp)>  min_heap(cmp);

            for (auto it = L[pt].begin(); it != L[pt].end(); it++)
            {
                min_heap.push(*it);
            }
            // 已經無路可走了
            if(min_heap.empty())
            {
                break;
            }
            int next = min_heap.top().node;
            while (!min_heap.empty())
            {
                GraphNode node = min_heap.top();
                min_heap.pop();
                dp[node.node]= min(dp[node.node], dp[pt]+node.weight);
            }
            pt = next;
        }
        return dp;

    }

};

int main()
{

    Graph G(3); //創建有3個node的graph
    G.set_edge(0, 1, 100);
    G.set_edge(1, 2, 100);
    G.set_edge(0, 2, 500);
    vector<long long> distance =  G.Dijk_BFS(0);
    for(auto d: distance)
    {
        cout<<d<<' ';
    }
    cout << endl;
    return 0;

}
