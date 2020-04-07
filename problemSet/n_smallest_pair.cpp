#include <iostream>
#include <vector>
#include <climits>
using namespace std;

class Node
{
public:
    Node() = default;
    Node(int x, int y, vector<int> d): index_x(x), index_y(y), data(d){};
    int index_x, index_y;
    vector<int> data;
    
    //因為陣列元素可能重複，故數對和相同時，定義x座標小的較小避免順序錯亂
    bool operator<(const Node& other){
        if(data[0]+data[1] < other.data[0]+other.data[1])
            return true;
        if(data[0]+data[1] > other.data[0]+other.data[1])
            return false;
        return index_x<other.index_x;
    }
    bool operator>(const Node& other){
        if(data[0]+data[1] > other.data[0]+other.data[1])
            return true;
        if(data[0]+data[1] < other.data[0]+other.data[1])
            return false;
        return index_x>other.index_x;
    }
};

// 0-index base Heap
template <typename T> class Heap
{
private:
    void heapify();
public:
    Heap() = default;
    Heap(vector<T> vec):arr(vec){heapify();};
    vector<T> arr;
    void insert(T node);
    T* get_min();
    void extract_min();
};

//調整heap使它滿足parent都比child小的規則(總時間: O(n))
template <typename T>
void Heap<T>::heapify()
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

template <typename T>
void Heap<T>::insert(T data)
{
    arr.push_back(data);
    int idx = arr.size()-1;
    while(idx>0 && arr[idx]<arr[(idx-1)/2]){
        swap(arr[idx], arr[(idx-1)/2]);
        idx = (idx-1)/2;
    }
}

template <typename T>
T* Heap<T>::get_min()
{
    return !arr.empty()?&arr[0]:NULL;
}

//拿走最小的元素，若heap為空不做事
template <typename T>
void Heap<T>::extract_min()
{
    if(arr.empty()){
        return;
    }
    T small = arr[0];
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

//函數功能: nums1, nums2 是兩個排序好的陣列(數字可重複)，回傳前k個總和最小的數對
vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
    
    if(nums1.empty()||nums2.empty())
        return vector<vector<int>>{}; //若其中一個陣列為空直接回傳
    if(nums1.size()*nums2.size()<INT_MAX) //避免nums1.size()*nums2.size()相乘溢位
        k = std::min(k, (int)(nums1.size()*nums2.size())); //k有可能比陣列大小更大，此時回傳陣列所有數對即可
    
    vector<int> boudary(nums2.size(), -1); //每一列使用的右邊界
    boudary[0] = 0;
    vector<vector<int>> result = {{nums1[0],nums2[0]}};
    Node last_use(0,0, {nums1[0],nums2[0]}); //最後一個用到的Node
    Heap<Node> h;
    
    for (int i = 0; i < k-1; i++) {
        int one = last_use.index_x, two = last_use.index_y;
        vector<vector<int>> candidates = {{one+1, two}, {one, two+1}};
        for(auto c: candidates){
            // 要檢查候選人是否超出邊界或重複添加
            if(c[0]<nums1.size() && c[1] < nums2.size() && c[0]> boudary[c[1]]){
                h.insert(Node(c[0],c[1], {nums1[c[0]], nums2[c[1]]}));
                boudary[c[1]] = c[0];
            }
        }
        last_use = *h.get_min();
        result.push_back(last_use.data);
        h.extract_min();
    }
    return result;
}

int main()
{
    vector<int> vec1={1,3,3,5};
    vector<int> vec2={2,4,6};
    int k = 13;

    vector<vector<int>> result = kSmallestPairs(vec1,vec2,k);
    for (int i = 0; i < result.size();i++) {
        std::cout << "["<<result[i][0]<< ", "<<result[i][1]<<"]";
        std::cout << (i < result.size()-1? ", ":"");
    }
    std::cout << std::endl;
    return 0;
}
