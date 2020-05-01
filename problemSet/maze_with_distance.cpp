#include <iostream>
#include <vector>
#include <deque>
using namespace std; 
  
//座標，以(row, col)表示
class Point 
{ 
public:
    int r; 
    int c; 
    Point(int _r, int _c):r(_r), c(_c){};
    Point operator + (const Point & pt){
        return Point(r+pt.r, c+pt.c);
    }
}; 
  
//在 BFS中使用的node 
struct queueNode 
{ 
    Point pt;  // 座標
    int dist;  // 此點距離起點的距離
}; 
  
// 檢查給定的座標(row, col) 是否在迷宮邊界內
bool isValid(const vector<vector<int>> &maze, int row, int col) 
{ 
    int ROW = maze.size(), COL= maze[0].size();
    return row >= 0 && row < ROW && col >= 0 && col < COL; 
} 
  

void BFS(vector<vector<int>> &maze, Point src, vector<Point> & adjacentDirection) 
{ 
  
    int ROW = maze.size(), COL= maze[0].size();
    vector<vector<bool>> visited(ROW, vector<bool>(COL, false));
    visited[src.r][src.c] = true; //拜訪src
  
    deque<queueNode> q = {queueNode{src, 1}}; 
  

    while (!q.empty()) 
    { 
        queueNode curr = q.front(); 
        Point pt = curr.pt; 
        maze[pt.r][pt.c] = curr.dist; //記錄此點的距離
  
        q.pop_front(); 
  
        //拜訪相鄰四個方向可以走的點
        for (Point direction: adjacentDirection) 
        { 
            Point p = pt + direction;
              
            // 如果沒有超出迷宮範圍，可通行且沒拜訪過就處理
            if (isValid(maze, p.r, p.c) && maze[p.r][p.c]==1 && !visited[p.r][p.c]) 
            { 
                // 拜訪新的點並加入陣列 
                visited[p.r][p.c] = true; 
                q.push_back(queueNode({ p, curr.dist+1})); 
            } 
        } 
    } 
} 
  

int main() 
{
    int S;
    int i=1;
    while(std::cin >> S){
        int n, m;
        std::cin >> n >> m;
        vector<vector<int>> maze(n, vector<int>(m));
        for(int i=0; i<n; i++){
            for (int j = 0; j < m; j++) {
                std::cin >> maze[i][j];
            }
        }

        vector<Point> adjacentDirection= { 
            Point(0,-1), 
            Point(0,1),
            Point(1,0)
        };

        //題目說當S==1時，水才可向上流
        if(S==1){
            adjacentDirection.push_back(Point(-1,0));
        }

        for(int j = 0; j < m; j++){
            if(maze[0][j]==1){
                BFS(maze, Point(0, j), adjacentDirection);
            }
        }

        //水流不到的地方設成0
        for(int i=1; i<n; i++){
            for (int j = 0; j < m; j++) {
                if(maze[i][j]==1){
                    maze[i][j] = 0;
                }
            }
        }

        std::cout << "Case "<< i <<":" << std::endl;
        for(int i=0; i<n; i++){
            for (int j = 0; j < m; j++) {
                std::cout << maze[i][j] << " ";
            }
            std::cout << endl;
        }
        i++;
    }  
    return 0; 
} 
