#include <iostream>
using namespace std;

class DoublyListNode {
public:
    DoublyListNode() :data(0), prev(0), next(0) {};
    DoublyListNode(int a) :data(a), prev(0), next(0) {};
    int data;
    DoublyListNode* next;
    DoublyListNode* prev;
};

//為解Josephus問題，特化成循環的DoublyLinkedList
class DoublyLinkedList {
private:
    int sz; //記錄list的大小方便維護
public:
    DoublyLinkedList() :head(0), tail(0), sz(0){};
    DoublyListNode* head;            // list的第一個node
    DoublyListNode* tail;            // list的最後一個node
    void insertTail(int data); //在list尾巴插入元素
    void Delete();  //刪除head的節點位置，head移至下一個位置
    void Move(int pos); //將head節點往後移動pos個位置
    int size();
};

void DoublyLinkedList::insertTail(int data) {
    DoublyListNode* node = new DoublyListNode(data);
    if (!head) {
        head = node;
    }
    else {
        tail->next = node;
        node->prev = tail;
    }
    tail = node;
    head -> prev = tail;
    tail -> next = head;
    sz++;
}

void DoublyLinkedList::Delete() {
    if(sz==2){
        head = tail = head->next;
    }
    else{
        head->prev->next = head->next;
        head->next->prev = head->prev;
        head = head->next;
        tail = head->prev;
    }
    sz--;
}

void DoublyLinkedList::Move(int pos)
{
    for (int i = 0; i < pos%sz; i++) {
        head = head->next;
    }
    tail = head->prev;
}

int DoublyLinkedList::size() {
    return sz;
}

/*
程式功能: 解Josephus問題，
原本有編號1,2,...,n個人，
每k個人殺一人，
求最後倖存者的編號
*/
int josephus(int n, int k)
{
    DoublyLinkedList d;
    for (int i = 1; i <= n; i++) {
        d.insertTail(i);
    }
    d.Move(k-1);
    while(d.size()>1){
        //std::cout << d.head->data << std::endl;
        d.Delete();
        d.Move(k-1);
    }
    return d.head->data;

}

int main()
{
    /*
    例子: josephus_survivor(7,3) = 4
    [1,2,3,4,5,6,7] - initial sequence
    [1,2,4,5,6,7] => 3 is counted out
    [1,2,4,5,7] => 6 is counted out
    [1,4,5,7] => 2 is counted out
    [1,4,5] => 7 is counted out
    [1,4] => 5 is counted out
    [4] => 1 counted out, 4 is the last element - the survivor!
    */
    
    int n,k;
    std::cin >> n >> k;
    std::cout << josephus(n,k) << std::endl;
    return 0;
}
