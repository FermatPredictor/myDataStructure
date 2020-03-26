#include <iostream>
#include <stdio.h>
#include <vector>
using namespace std;

//結合兩陣列排序好的結果，
//左陣列為arr[l..m]，右陣列為 arr[m+1..r]
void merge(vector<int> &arr, int left, int medium, int right)
{
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
}

// 將arr[l...r]的範圍排序好(包含left, right邊界)
void mergeSort(vector<int> &arr, int left, int right)
{
    if(left<right){
        int mid = left+(right-left)/2;
        mergeSort(arr, left, mid);
        mergeSort(arr, mid+1, right);
        merge(arr, left, mid, right);
    }
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
    mergeSort(arr, 0, arr.size()-1);
    printArray(arr, arr.size()-1);
    return 0;
}
