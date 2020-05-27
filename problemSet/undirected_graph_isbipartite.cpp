#include <iostream> 
#include <list> 
#include <vector>
using namespace std; 
  
// Undirected graph (1-index base)
class Graph 
{ 
    int n;    //vertices數量 
    vector<list<int>> adj; // adjacency list，記錄每個頂點相鄰的頂點

    
    //遞迴判斷從頂點v出發跑DFS，能不能用兩個顏色把頂點分開
    bool isBipartiteUtil(int v, vector<bool>& visited, vector<int>& color) 
    { 
      
        visited[v] = true; //拜訪現在的點
        // 遞迴拜訪相鄰頂點
        for (auto i = adj[v].begin(); i != adj[v].end(); i++) { 
      
            // 若此頂點未拜訪過，遞迴拜訪它
            if (!visited[*i]) { 
                color[*i] = !color[v]; // 將相鄰頂點的顏色跟現在頂點塗相反
                // 子樹不是Bipartite就不是
                if (!isBipartiteUtil(*i, visited, color)) 
                    return false; 
            } 
            // 偵測到相鄰頂點拜訪過了且與現在頂點同色就不是Bipartite
            else if (color[*i] == color[v]) 
                return false; 
        } 
        return true; 
    } 
    
public: 
    Graph(int n){
        this->n = n;
        this->adj = vector(n+1, list<int>());
    };
    void set_edge (int v_i, int v_j)
    {

        // 無向圖的(v_i, v_j) 和 (v_j, v_i)相同
        this->adj[v_j].push_back(v_i);
        this->adj[v_i].push_back(v_j);

    }
    
    bool isBipartite(){
        vector<bool> visited(n+1, false);
        vector<int> color(n+1, 0);
        // DFS
        for (int u = 1; u <= n; u++){
            if (!visited[u]){
                if (!isBipartiteUtil(u, visited, color)){
                    return false; //任一子圖不是bipartite就不是
                }
            }
        }
        return true; 
    };
}; 

  
int main() 
{ 
    Graph g1(5); 
    g1.set_edge(2, 1); 
    g1.set_edge(1, 3); 
    g1.set_edge(3, 2); 
    g1.set_edge(1, 4); 
    g1.set_edge(4, 5); 
    g1.isBipartite()? cout << "Graph is bipartite\n": 
                      cout << "Graph is not bipartite\n"; 
  
    Graph g2(3); 
    g2.set_edge(1, 2); 
    g2.set_edge(2, 3); 
    g2.isBipartite()? cout << "Graph is bipartite\n": 
                      cout << "Graph is not bipartite\n"; 
  
    return 0; 
} 
