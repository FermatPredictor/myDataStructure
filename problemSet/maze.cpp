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
bool isValid(const vector<vector<char>> &maze, int row, int col) 
{ 
    int ROW = maze.size(), COL= maze[0].size();
    return row >= 0 && row < ROW && col >= 0 && col < COL; 
} 
  
//相鄰可走的四個方向
vector<Point> adjacentDirection = {
    Point(-1,0), 
    Point(0,-1), 
    Point(0,1),
    Point(1,0)
};
  
/*
函數功能: 給定一個迷宮，由二維的字元陣列表示，
「#」表示障礙物，「.」表示可以通行的道路，
求從起點src前進到dest最短需要走幾步，
用BFS搜索
例如:
#########
#.......#
#.#####.#
#.......#
##.#.####
#..#.#..#
#.##.##.#
#.......#
#########
是一個迷宮
(如果不可能抵達終點回傳-1)
*/
int BFS(vector<vector<char>> &maze, Point src, Point dest) 
{ 
    // 如果起點或終點是障礙物則直接回傳-1
    if (maze[src.r][src.c]=='#' || maze[dest.r][dest.c]=='#') 
        return -1; 
  
    int ROW = maze.size(), COL= maze[0].size();
    vector<vector<bool>> visited(ROW, vector<bool>(COL, false));
    visited[src.r][src.c] = true; //拜訪src
  
    deque<queueNode> q = {queueNode{src, 0}}; 
  

    while (!q.empty()) 
    { 
        queueNode curr = q.front(); 
        Point pt = curr.pt; 
  
        //如果已經到終點了就回傳
        if (pt.r == dest.r && pt.c == dest.c) 
            return curr.dist; 
  
        q.pop_front(); 
  
        //拜訪相鄰四個方向可以走的點
        for (Point direction: adjacentDirection) 
        { 
            Point p = pt + direction;
              
            // 如果沒有超出迷宮範圍，可通行且沒拜訪過就處理
            if (isValid(maze, p.r, p.c) && maze[p.r][p.c]=='.' && !visited[p.r][p.c]) 
            { 
                // 拜訪新的點並加入陣列 
                visited[p.r][p.c] = true; 
                q.push_back(queueNode({ p, curr.dist+1})); 
            } 
        } 
    } 
    return -1; //無法抵達終點
} 
  

int main() 
{

    vector<vector<char>> maze = 
    { 
        { '#', '#', '#', '#', '#', '#', '#', '#', '#'}, 
        { '#', '.', '.', '.', '.', '.', '.', '.', '#'}, 
        { '#', '.', '#', '#', '#', '#', '#', '.', '#'}, 
        { '#', '.', '.', '.', '.', '.', '.', '.', '#'},
        { '#', '#', '.', '#', '.', '#', '#', '#', '#'}, 
        { '#', '.', '.', '#', '.', '#', '.', '.', '#'}, 
        { '#', '.', '#', '#', '.', '#', '#', '.', '#'}, 
        { '#', '.', '.', '.', '.', '.', '.', '.', '#'}, 
        { '#', '#', '#', '#', '#', '#', '#', '#', '#'}
    }; 
  
    Point source = {1, 1}; 
    Point dest = {7, 7}; 
  
    int dist = BFS(maze, source, dest); 
  
    if (dist != -1) 
        cout << "到終點的最短路徑為: " << dist ; 
    else
        cout << "無法抵達終點"; 
  
    return 0; 
} 
