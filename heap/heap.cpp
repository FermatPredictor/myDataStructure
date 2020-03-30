#include <iostream>
#include <vector>
using namespace std;

// 0-index base Heap
class Heap
{
private:
    void heapify();
public:
    Heap() = default;
    Heap(vector<int> vec):arr(vec){heapify();};
    vector<int> arr;
    void insert(int data);
    int get_min();
    void extract_min();
    void Print();  //印出heap的元素檢查是否滿足規則，debug用
    vector<int> HeapSort();
};

//調整heap使它滿足parent都比child小的規則(總時間: O(n))
void Heap::heapify()
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

void Heap::insert(int data)
{
    arr.push_back(data);
    int idx = arr.size()-1;
    while(idx>0 && arr[idx]<arr[(idx-1)/2]){
        swap(arr[idx], arr[(idx-1)/2]);
        idx = (idx-1)/2;
    }
}

int Heap::get_min() {
    return !arr.empty()? arr[0]: 0;
}

//拿走最小的元素，若heap為空不做事
void Heap::extract_min()
{
    if(arr.empty()){
        return;
    }
    
    int small = arr[0];
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

void Heap::Print()
{
    for (auto v : arr) {
        std::cout << v << " ";
    }
    std::cout << std::endl;
    
}

vector<int> Heap::HeapSort() {
    int sz = arr.size(); //元素個數
    vector<int> vec;
    for (int i = 0; i < sz; i++) {
        vec.push_back(get_min());
        extract_min();
    }
    return vec;
}

int main()
{
    vector<int> vec = { 1,5,6,3,2,8,10,7 };
    Heap heap(vec);
    vec = heap.HeapSort();
    for (int i = 0; i < vec.size(); i++)
        cout << vec[i] << " " ;
    cout << endl;
    return 0;
}
