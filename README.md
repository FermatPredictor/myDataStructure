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
|Simple Graph|[simple_graph_adjacency_matrix](https://github.com/FermatPredictor/myDataStructure/blob/master/Graph/simple_graph_adjacency_matrix.cpp)|[12625 - Simple Graph](https://acm.cs.nthu.edu.tw/problem/12625/)|
|Simple Graph|[simple_graph_adjacency_list](https://github.com/FermatPredictor/myDataStructure/blob/master/Graph/simple_graph_adjacency_list.cpp)|[12625 - Simple Graph](https://acm.cs.nthu.edu.tw/problem/12625/)|
|Graph_DFS|[simple_graph_DFS](https://github.com/FermatPredictor/myDataStructure/blob/master/Graph/simple_graph_DFS.cpp)|[12626 - Reachable Nodes](https://acm.cs.nthu.edu.tw/problem/12626/)|
|Graph_BFS|[simple_graph_BFS](https://github.com/FermatPredictor/myDataStructure/blob/master/Graph/simple_graph_BFS.cpp)|[12626 - Reachable Nodes](https://acm.cs.nthu.edu.tw/problem/12626/)|
|BinaryTree遍歷 (用map實作)|[binaryTree](https://github.com/FermatPredictor/myDataStructure/blob/master/Tree/binaryTree.cpp)|[12627 - Binary Tree Traversal](http://140.114.86.238/problem/12627/)|

## 廣義的資料結構
在原來的資料結構中，我們都假設放入的資料型態是int，但為了能更廣泛的使用，我們用類別模版改寫，使資料結構能放入其它的物件
| 資料結構/演算法 | 程式 | 放進資料結構的物件需重載運算子 |
| --- | --- | --- |
| Heap | [heap](https://github.com/FermatPredictor/myDataStructure/blob/master/heap/general_heap.cpp) | 小於<，大於>|

## 問題集
收集各種資料結構的題目運用

|類別|可參考題目| 描述| 程式|
| --- | --- | --- | --- |
|排序問題| [Hackerrank- Merge Sort: Counting Inversions](https://www.hackerrank.com/challenges/ctci-merge-sort/problem)| 利用mergeSort數有幾個inversions，若是題目改問bubble Sort或是insertsion Sort需要交換的次數為幾次，答案與inversions的個數是相同的| [countInversions](https://github.com/FermatPredictor/myDataStructure/blob/master/problemSet/countInversions.cpp) |
|heap| [LeetCode 373. Find K Pairs with Smallest Sums](https://leetcode.com/problems/find-k-pairs-with-smallest-sums/)|nums1, nums2 是兩個排序好的陣列，求前k個總和最小的數對|[n_smallest_pair](https://github.com/FermatPredictor/myDataStructure/blob/master/problemSet/n_smallest_pair.cpp)|
|linked list| (暫無) | linked list的經典運用之一是做多項式的加、乘法，之所以不用陣列，是因為可能多項式的項數很少但最高次方很大 |[polynomial_list](https://github.com/FermatPredictor/myDataStructure/blob/master/problemSet/polynomial_list.cpp)|
|circular linked list| [CodeWar- Josephus Survivor](https://www.codewars.com/kata/555624b601231dc7a400017a/cpp)| Josephus問題，原本有編號1,2,...,n個人，每k個人殺一人，求最後倖存者的編號|[josephus](https://github.com/FermatPredictor/myDataStructure/blob/master/problemSet/josephus.cpp)|
|Stack|[zerojude- e924: pC. 括號配對](https://zerojudge.tw/ShowProblem?problemid=e924)|判斷輸入的字串的括號配對是否正確，要檢查的括號有圓括號 ()、方括號 []、小於大於括號 <> 和曲括號 {}|[parentheses](https://github.com/FermatPredictor/myDataStructure/blob/master/problemSet/parentheses.cpp)|
|BFS|[zerojude- a982: 迷宮問題#1](https://zerojudge.tw/ShowProblem?problemid=a982)|計算從起點走到終點的最短步數|[maze](https://github.com/FermatPredictor/myDataStructure/blob/master/problemSet/maze.cpp)|
|BinaryTree|[LeetCode- 105. Construct Binary Tree from Preorder and Inorder Traversal](https://leetcode.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal/)|經典題型: 給你binaryTree的preorder和inorder，將原本的樹建出來|[binaryTree_in_pre](https://github.com/FermatPredictor/myDataStructure/blob/master/problemSet/binaryTree_in_pre.cpp)|
|BinaryTree|[LeetCode- 124. Binary Tree Maximum Path Sum](https://leetcode.com/problems/binary-tree-maximum-path-sum/)|找二元樹的最大路徑和|[BinaryTree_MaxPathSum](https://github.com/FermatPredictor/myDataStructure/blob/master/problemSet/BinaryTree_MaxPathSum.cpp)|
