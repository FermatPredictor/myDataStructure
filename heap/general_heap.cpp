#include <iostream>
#include <vector>
using namespace std;

class Node
{
public:
    Node() = default;
    Node(int d): data(d){};
    int data;
    bool operator<(const Node& other){
        return data < other.data;
    }
    bool operator>(const Node& other){
        return data > other.data;
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
    vector<T> HeapSort();
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

template <typename T>
vector<T> Heap<T>::HeapSort() {
    int sz = arr.size(); //元素個數
    vector<T> vec;
    for (int i = 0; i < sz; i++) {
        vec.push_back(*get_min());
        extract_min();
    }
    return vec;
}

int main()
{
    vector<Node> vec = { Node(1),Node(5),Node(6),Node(3),Node(2),Node(8),Node(10),Node(7)};
    Heap<Node> heap(vec);
    vec = heap.HeapSort();
    for (int i = 0; i < vec.size(); i++)
        cout << vec[i].data << " " ;
    cout << endl;
    return 0;
}
