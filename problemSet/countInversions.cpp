#include <iostream>
#include <stdio.h>
#include <vector>
using namespace std;

/*
程式功能: 將一個陣列用mergeSort排序好，
並同時該回陣列原本的inversions數量，
定義inversion是有某個index i<j 但arr[i]>arr[j]
(由於inversions數量可能為O(n^2)，宣告為long long)
*/


//結合兩陣列排序好的結果，並返回inversions的數量
//左陣列為arr[l..m]，右陣列為 arr[m+1..r]
long long merge(vector<int> &arr, int left, int medium, int right)
{
    long long inversions = 0;
    int lnum = medium-left+1, rnum=right-medium;
    vector<int> larr(arr.begin()+left, arr.begin()+medium+1);
    vector<int> rarr(arr.begin()+medium+1, arr.begin()+right+1);

    int idx = left;
    int left_idx = 0, right_idx = 0;
    //如果左邊的陣列或右邊的陣列還有數字，就把各自最小的數拿出來比較
    while(left_idx<lnum && right_idx<rnum){
        if(larr[left_idx]<= rarr[right_idx]){
            arr[idx]= larr[left_idx];
            left_idx++;
        }
        else{
            arr[idx]= rarr[right_idx];
            right_idx++;
            inversions += lnum-left_idx;
        }
        idx++;
    }
    
    while(left_idx<lnum){
        arr[idx]= larr[left_idx];
        idx++;
        left_idx++;
    }
    
    while(right_idx<rnum){
        arr[idx]= rarr[right_idx];
        idx++;
        right_idx++;
    }
    return inversions;
}

// 將arr[l...r]的範圍排序好(包含left, right邊界)，並返回inversions的數量
long long mergeSort(vector<int> &arr, int left, int right)
{
    long long inversions = 0;
    if(left<right){
        int mid = left+(right-left)/2;
        inversions += mergeSort(arr, left, mid);
        inversions += mergeSort(arr, mid+1, right);
        inversions += merge(arr, left, mid, right);
    }
    return inversions;
}

//單純將一個陣列印出來做測試
void printArray(vector<int> arr, int size)
{
    int i;
    for (i=0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

int main()
{
    vector<int> arr= {1,5,6,3,2,8,10,7};
    long long inversions = mergeSort(arr, 0, arr.size()-1);
    printArray(arr, arr.size());
    std::cout << inversions << std::endl;
    return 0;
}
