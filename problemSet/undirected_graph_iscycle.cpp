#include <iostream> 
#include <list> 
#include <vector>
using namespace std; 
  
// Undirected graph (1-index base)
class Graph 
{ 
    int n;    //vertices數量 
    vector<list<int>> adj; // adjacency list，記錄每個頂點相鄰的頂點
    
    //遞迴判斷從頂點v出發，會不會回到頂點v
    bool isCyclicUtil(int v, vector<bool> & visited, int parent){
        visited[v] = true; //拜訪現在的點
  
        // 遞迴拜訪相鄰頂點
        for (auto i = adj[v].begin(); i != adj[v].end(); i++) 
        { 
            // 若此頂點未拜訪過，遞迴拜訪它
            if (!visited[*i]) 
            { 
               if (isCyclicUtil(*i, visited, v)) 
                  return true; 
            } 
            //如果沒有cycle的狀況下，DFS走到底的時候就只會碰到拜訪過的parent
            //所以碰到拜訪過的點但不是parent，表示有cycle了
            else if (*i != parent) 
               return true; 
        } 
        return false; 
    };
    
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
    
    //檢測一張圖是否有cycle
    bool isCyclic(){
        vector<bool> visited(n, false);
        // DFS
        for (int u = 1; u < n; u++){
            if (!visited[u]){
                if (isCyclicUtil(u, visited, -1)){
                    return true; //找到任一cycle就算有cycle
                }
            }
        }
        return false; 
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
    g1.isCyclic()? cout << "Graph contains cycle\n": 
                   cout << "Graph doesn't contain cycle\n"; 
  
    Graph g2(3); 
    g2.set_edge(1, 2); 
    g2.set_edge(2, 3); 
    g2.isCyclic()? cout << "Graph contains cycle\n": 
                   cout << "Graph doesn't contain cycle\n"; 
  
    return 0; 
} 
