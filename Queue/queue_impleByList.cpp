#include <iostream>
using namespace std;

class ListNode {
public:
    ListNode() :data(0), next(0) {};
    ListNode(int a) :data(a), next(0) {};
    int data;
    ListNode* next;
};

class Queue{
private:
    int sz; //記錄queue的大小方便維護
public:
    Queue(): head(0), tail(0), sz(0){};
    ListNode* head;            // queue的第一個node
    ListNode* tail;            // queue的最後一個node
    void enqueue(int data); //放資料到queue的尾端
    void dequeue(); //將queue最前端的資料取出
    int front();
    int size();
    void Print(); //印出Queue裡面有幾個元素及最前方元素，再印出所有元素，用來debug
};


void Queue::enqueue(int data){
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

void Queue::dequeue(){
    if (sz == 0) {
        return;
    }
    head = head->next;
    if (!head) {
        tail = NULL;
    }
    sz--;
}

int Queue::front(){
    return head? head->data:-1;
}

int Queue::size(){
    return sz;
}

void Queue::Print(){
    if(sz==0){
        std::cout << "queue現在是空的" << std::endl;
    }
    else{
        std::cout << "queue大小: "<< size() << ", queue最前方的元素為: "<< front() << std::endl;
        std::cout << "queue裡面的元素: ";
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
}
 
int main()
{
    Queue q;
    q.Print();
    for(int i=1; i<=15;i++){
        q.enqueue(i); //測試放15個數進queue
    }
    q.Print();
    for(int i=0; i<5;i++){
        q.dequeue(); //測試拿5個數字出來
    }
    q.Print();
    for(int i=2; i<=20;i+=2){
        q.enqueue(i); //測試放10個數進queue
    }
    q.Print();
    return 0;
}
