#include <iostream>
using namespace std;

class ListNode {
public:
    ListNode() :data(0), next(0) {};
    ListNode(int a) :data(a), next(0) {};
    int data;
    ListNode* next;
};

class LinkedList {
private:
    int sz; //計錄list的大小方便維護
public:
    LinkedList() :head(0), tail(0), sz(0) {};
    ListNode* head;            // list的第一個node
    ListNode* tail;            // list的第一個node
    void printList();           // 印出list的所有資料，用來除錯
    void insertHead(int data); //在list起頭插入元素
    void insertTail(int data); //在list尾巴插入元素
    void insert(int data, int position);   //在特定位置後插入元素
    void DeleteHead();     // 刪除list起頭的元素
    void DeleteTail();     // 刪除list尾巴的元素
    void Delete(int position);  // 刪除特定位置的元素
    void size();
};

void LinkedList::printList() {
    ListNode* node = head;
    while (node) {
        cout << node->data;
        node = node->next;
        if (node) {
            cout << " ";
        }
    }
    cout << endl;
}



void LinkedList::insertHead(int data) {
    ListNode* node = new ListNode(data);
    if (!head) {
        tail = node;
    }
    else {
        node->next = head;
    }
    head = node;
    sz++;
}

void LinkedList::insertTail(int data) {
    ListNode* node = new ListNode(data);
    if (!head) {
        head = node;
    }
    else {
        tail->next = node;
    }
    tail = node;
    sz++;
}

//注意pos=0時等同insertHead，pos=list長度時等同insertTail，若pos>list長度則不做事
void LinkedList::insert(int data, int position) {
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
        ListNode* node = new ListNode(data); //欲插入的元素
        ListNode* in = head;
        for (int i = 0; i < position - 1; i++) {
            in = in->next;
        }
        node->next = in->next;
        in->next = node;
        sz++;
    }
}

void LinkedList::DeleteHead() {
    if (sz == 0) {
        return;
    }
    head = head->next;
    if (!head) {
        tail = NULL;
    }
    sz--;
}

void LinkedList::DeleteTail() {
    if(sz == 0) {
        return;
    }
    if(sz==1){
        DeleteHead();
        return;
    }
    ListNode* prev = head;
    for (int i = 0; i < sz - 2; i++) {
        prev = prev->next;
    }
    prev->next = NULL;
    tail = prev;
    sz--;
}


void LinkedList::Delete(int position) {
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
        ListNode* prev = head;
        for (int i = 0; i < position - 1; i++) {
            prev = prev->next;
        }
        ListNode* node = prev->next;
        prev->next = node->next;
        sz--;
    }

}


void LinkedList::size() {
    std::cout << sz << std::endl;
}

int main()
{
    //測試LinkedList的程式碼
    LinkedList L;
    L.insertTail(20);
    L.insertTail(35);
    L.insertTail(-7);
    L.insertTail(9);
    L.printList();
    L.insertTail(10);
    L.insert(5, 5);
    L.printList();
    L.insert(88, 0);
    L.printList();
    L.Delete(2);
    L.DeleteTail();
    L.printList();
    L.insertTail(3);
    L.printList();
    return 0;
}
