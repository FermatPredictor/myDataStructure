#include <iostream>
#include <vector>
using namespace std;

//函數功能: 對排序陣列二元搜索，數字可能重複，回傳第一個出現目標數字的位置，若沒有則回傳-1
int binarySearch_first(std::vector<int>& vec, int target)
{
    int left = 0, right = vec.size()-1, mid; //邊界意義: 可能範圍落於index[left, right]區間
    while (left< right) {
        mid = left + (right - left) / 2;
        if (target < vec[mid])
            right = mid - 1;
        else if (target > vec[mid])
            left = mid + 1;
        else
            right = mid;
    }
    return !vec.empty() && vec[left]==target?left:-1;
}

//函數功能: 對排序陣列二元搜索，數字可能重複，回傳最右邊出現目標數字的位置，若沒有則回傳-1
int binarySearch_last(std::vector<int>& vec, int target)
{
    int left = 0, right = vec.size()-1, mid; //邊界意義: 可能範圍落於index[left, right]區間
    while (left< right) {
        mid = left + (right - left) / 2 + 1;
        if (target < vec[mid])
            right = mid - 1;
        else if (target > vec[mid])
            left = mid + 1;
        else
            left = mid;
    }
    return !vec.empty() && vec[right]==target?right:-1;
}

//函數功能: 回傳在nums中，第一個大於或等於目標值的位置
int firstGreaterEqual(vector<int>& nums, int target) {
    int left = 0, right = nums.size();
    while (left < right) {
        int mid = left + (right - left) / 2;
        if (nums[mid] < target) 
            left = mid + 1;
        else
            right = mid;
    }
    return right;
}

int main()
{
    vector<int> v = {1,3,15,15,26,35,35,35,88,125};
    int value;
    while (std::cin >> value) {
        cout << binarySearch_first(v, value) <<" "<< binarySearch_last(v, value) << endl;
    }
    return 0;
}
