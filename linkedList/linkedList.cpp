#include <iostream>
using namespace std;

class ListNode{
public:
    ListNode():data(0),next(0){};
    ListNode(int a):data(a),next(0){};
    int data;
    ListNode *next;
};

class LinkedList{
public:
    LinkedList():head(0){};
    ListNode *head;            // list的第一個node
    void printList();           // 印出list的所有資料，用來除錯
    void insertTail(int data); //在list尾巴插入元素
    void insert(int data, int position);   //在特定位置後插入元素
    void Delete(int position);         // 刪除特定位置的元素
};

void LinkedList::printList(){
    ListNode *node = head;
    while (node) {
        cout << node->data;
        node = node->next;
        if (node) {
            cout << " ";
        }
    }
    cout << endl;
}

void LinkedList::insertTail(int data){
    ListNode *node = new ListNode(data);
    if(!head){
        head=node;
    }
    else{
        ListNode *tail = head;
        while(tail->next){
            tail=tail->next;   
        }
        tail->next=node;
    }
}

void LinkedList::insert(int data, int position){
    ListNode *node = new ListNode(data); //欲插入的元素
    ListNode *prev = head;
    for(int i=0; i<position-1; i++){
        prev=prev->next;
    }
    node->next=prev->next;
    prev->next=node;
}

void LinkedList::Delete(int position){
    if(position==0){
        head = head->next; //處理要刪除位置就是head的情況
    }
    ListNode *prev = head;
    for(int i=0; i<position-1; i++){
        prev=prev->next;
    }
    ListNode *node = prev->next;
    prev->next=node->next;
    node->next=NULL;    
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
    L.insert(88,0);
    L.printList();
    L.Delete(2);
    L.printList();
    return 0;
}
