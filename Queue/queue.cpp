#include <iostream>
using namespace std;

class Queue{
private:
    const int max_sz; //預設Queue的最大容量(為了能判斷Queue為空的狀況，若max_sz=500，實際上最多容納499個元素)
    int head = 0, tail = 0; //目前隊伍頭和尾的編號，兩者相等Queue為空
    int *arr;
public:
    Queue():max_sz(500){arr = new int[max_sz];};
    Queue(int sz):max_sz(sz){arr = new int[max_sz];};
    void enqueue(int data);//放資料到queue的尾端，若queue已滿則不做事
    void dequeue();
    int front();
    int size();
    void Print(); //印出Queue裡面有幾個元素及最前方元素，再印出所有元素，用來debug
};


void Queue::enqueue(int data){
    if(size()==max_sz-1){
        std::cout << "警告: 嘗試添加數字但queue已達最大容量"<< std::endl;
        return;
    }
    arr[tail]=data;
    tail= (tail+1)%max_sz;
}

void Queue::dequeue(){
    if(head!= tail)
        head= (head+1)%max_sz;
}

int Queue::front(){
    return head!= tail? arr[head]:-1;
}

int Queue::size(){
    return (tail-head+max_sz)%max_sz;
}

void Queue::Print(){
    if(size()==0){
        std::cout << "queue現在是空的" << std::endl;
    }
    else{
        std::cout << "queue大小: "<< size() << ", queue最前方的元素為: "<< front() << std::endl;
        std::cout << "queue裡面的元素: ";
        for(int i=0; i<size(); i++){
            std::cout << arr[(head+i)%max_sz] <<" ";
        }
        std::cout << std::endl;
    }
}
 
int main()
{
    Queue q(20);//設置最大容量為19的queue
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
