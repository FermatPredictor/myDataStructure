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

class DoublyLinkedList {
private:
    int sz; //計錄list的大小方便維護
public:
    DoublyLinkedList() :head(0), tail(0), sz(0) {};
    DoublyListNode* head;            // list的第一個node
    DoublyListNode* tail;            // list的第一個node
    void printList();           // 印出list的所有資料，用來除錯
    void printReverseList();    // 倒序印出list的所有資料，用來除錯
    void insertHead(int data); //在list起頭插入元素
    void insertTail(int data); //在list尾巴插入元素
    void insert(int data, int position);   //在特定位置後插入元素
    void DeleteHead();     // 刪除list起頭的元素
    void DeleteTail();     // 刪除list尾巴的元素
    void Delete(int position);  // 刪除特定位置的元素
    void size();
};

void DoublyLinkedList::printList() {
    DoublyListNode* node = head;
    while (node) {
        cout << node->data;
        node = node->next;
        if (node) {
            cout << " ";
        }
    }
    cout << endl;
}

void DoublyLinkedList::printReverseList() {
    DoublyListNode* node = tail;
    while (node) {
        cout << node->data;
        node = node->prev;
        if (node) {
            cout << " ";
        }
    }
    cout << endl;
}


void DoublyLinkedList::insertHead(int data) {
    DoublyListNode* node = new DoublyListNode(data);
    if (!head) {
        tail = node;
    }
    else {
        node->next = head;
        head->prev = node;
    }
    head = node;
    sz++;
}

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
    sz++;
}

//注意pos=0時等同insertHead，pos=list長度時等同insertTail，若pos>list長度則不做事
void DoublyLinkedList::insert(int data, int position) {
    if (position == 0) {
        insertHead(data); //插入頭
    }
    else if (position == sz) {
        insertTail(data); //插入尾巴
    }
    else if (position > sz) {
        return;
    }
    else {
        DoublyListNode* node = new DoublyListNode(data); //欲插入的元素
        DoublyListNode* in = head;
        for (int i = 0; i < position - 1; i++) {
            in = in->next;
        }
        node->next = in->next;
        in->next = node;
        node->prev = in;
        node->next->prev = node;
        sz++;
    }
}

void DoublyLinkedList::DeleteHead() {
    if (sz == 0) {
        return;
    }
    head = head->next;
    if (head) {
        head->prev = NULL;
    }
    else {
        tail = NULL;
    }
    sz--;
}

void DoublyLinkedList::DeleteTail() {
    if (sz == 0) {
        return;
    }
    tail = tail->prev;
    if (tail) {
        tail->next = NULL;
    }
    else{
        head = NULL;
    }
    sz--;
}

void DoublyLinkedList::Delete(int position) {
    if (position == 0) {
        DeleteHead(); //刪除頭
    }
    else if (position == sz - 1) {
        DeleteTail(); //刪除尾巴
    }
    else if (position > sz - 1) {
        return;
    }
    else {
        DoublyListNode* prev = head;
        for (int i = 0; i < position - 1; i++) {
            prev = prev->next;
        }
        DoublyListNode* node = prev->next;
        prev->next = node->next;
        node->next->prev = prev;
        node->next = node->prev = NULL;
        sz--;
    }

}


void DoublyLinkedList::size() {
    std::cout << sz << std::endl;
}

int main()
{
    //測試LinkedList的程式碼
    DoublyLinkedList L;
    L.insertTail(20);
    L.insertTail(35);
    L.insertTail(-7);
    L.insertTail(9);
    L.printList();
    L.printReverseList();
    L.insertTail(10);
    L.insert(5, 5);
    L.printList();
    L.printReverseList();
    L.insert(88, 0);
    L.printList();
    L.printReverseList();
    L.Delete(2);
    L.printList();
    L.printReverseList();
    return 0;
}
