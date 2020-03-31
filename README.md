# myDataStructure

本程式庫希望收集各種常用的資料結構方便使用，
程式全用c++寫成

## 資料結構

| 資料結構/演算法 | 程式 | 可參考題目(驗證程式正確性)|
| --- | --- | --- |
| 二分搜索 | [binarySearch](https://github.com/FermatPredictor/myDataStructure/blob/master/BinarySearch/binarySearch.cpp) | [LeetCode- 34. Find First and Last Position of Element in Sorted Array](https://leetcode.com/problems/find-first-and-last-position-of-element-in-sorted-array/)|
| 排序問題 | [mergeSort](https://github.com/FermatPredictor/myDataStructure/blob/master/Sorting/mergeSort.cpp) |[zerojudge- a233: 排序法~~~ 挑戰極限](https://zerojudge.tw/ShowProblem?problemid=a233)|
| Heap | [heap](https://github.com/FermatPredictor/myDataStructure/blob/master/heap/heap.cpp) | |
|LinkedList|[linkedList](https://github.com/FermatPredictor/myDataStructure/blob/master/linkedList/linkedList.cpp)| [LeetCode- 707. Design Linked List](https://leetcode.com/problems/design-linked-list/) |
|LinkedList|[doubleLinkedList](https://github.com/FermatPredictor/myDataStructure/blob/master/linkedList/doubleLinkedList.cpp)| [LeetCode- 707. Design Linked List](https://leetcode.com/problems/design-linked-list/) |
|Stack|[stack](https://github.com/FermatPredictor/myDataStructure/blob/master/Stack/stack.cpp)| |
|Queue|[queue](https://github.com/FermatPredictor/myDataStructure/blob/master/Queue/queue.cpp) (用array實作)|[Hackerrank- Queue using Two Stacks](https://www.hackerrank.com/challenges/queue-using-two-stacks/problem)|
|Queue|[queue_impleByList](https://github.com/FermatPredictor/myDataStructure/blob/master/Queue/queue_impleByList.cpp) (用list實作)|[Hackerrank- Queue using Two Stacks](https://www.hackerrank.com/challenges/queue-using-two-stacks/problem)|

## 問題集
收集各種資料結構的題目運用

|類別|可參考題目| 描述| 程式|
| --- | --- | --- | --- |
|排序問題| [Hackerrank- Merge Sort: Counting Inversions](https://www.hackerrank.com/challenges/ctci-merge-sort/problem)| 利用mergeSort數有幾個inversions，若是題目改問bubble Sort或是insertsion Sort需要交換的次數為幾次，答案與inversions的個數是相同的| [countInversions](https://github.com/FermatPredictor/myDataStructure/blob/master/problemSet/countInversions.cpp) |
|circular linked list| [CodeWar- Josephus Survivor](https://www.codewars.com/kata/555624b601231dc7a400017a/cpp)| Josephus問題，原本有編號1,2,...,n個人，每k個人殺一人，求最後倖存者的編號|[josephus](https://github.com/FermatPredictor/myDataStructure/blob/master/problemSet/josephus.cpp)|
|Stack|[zerojude- e924: pC. 括號配對](https://zerojudge.tw/ShowProblem?problemid=e924)|判斷輸入的字串的括號配對是否正確，要檢查的括號有圓括號 ()、方括號 []、小於大於括號 <> 和曲括號 {}|[parentheses](https://github.com/FermatPredictor/myDataStructure/blob/master/problemSet/parentheses.cpp)|
