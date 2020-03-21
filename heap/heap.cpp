#include <iostream>
#include <vector>
using namespace std;

class Heap {
private:
    vector<int> array = {0}; //初始給一個元素，讓index0的位置閒置
public:
    Heap() = default;
    Heap(vector<int> _array);
    void insert(int num);
    int get_min();
    int extract_min();
    vector<int> HeapSort();
};

Heap::Heap(vector<int> _array) {
    for (int i = 0; i < _array.size(); i++) {
        insert(_array[i]);
    }
}

void Heap::insert(int num) {
    array.push_back(num);
    int idx = array.size()-1;
    while (idx / 2 > 0 and array[idx] < array[idx / 2]) {
        swap(array[idx], array[idx / 2]);
        idx /= 2;
    }
}

int Heap::get_min() {
    return array.size()>1 ? array[1]: 0;
}

int Heap::extract_min() {
    int min_element = array[1];
    int sz = array.size()-1; //元素個數
    swap(array[1], array[sz]);
    int idx = 1;
    while (idx * 2 <sz) {
        int small_chlid_idx = idx * 2; //判斷小孩節點比較小的那個編號
        if (small_chlid_idx + 1 < sz && array[small_chlid_idx + 1] < array[small_chlid_idx])
            small_chlid_idx++; 
        if(array[idx] > array[small_chlid_idx])
            swap(array[idx], array[small_chlid_idx]);
        idx = small_chlid_idx;
    }
    array.erase(array.end()-1); //清掉最後一個元素(即最小的那個)
    return min_element;    
}

vector<int> Heap::HeapSort() {
    int sz = array.size() - 1; //元素個數
    vector<int> vec;
    for (int i = 0; i < sz; i++) {
        vec.push_back(extract_min());
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
