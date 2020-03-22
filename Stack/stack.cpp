#include <iostream>
using namespace std;

class Stack{
private:
    const int max_sz; //預設stack的最大容量
    int currunt_sz = 0; //目前Stack裡有幾個元素
    int *arr;
public:
    Stack():max_sz(500){arr = new int[max_sz];};
    Stack(int sz):max_sz(sz){arr = new int[max_sz];};
    void push(int data);
    int pop();
    int top();
    int size();
    void Print(); //印出stack有幾個元素及最上層元素，用來debug
};

void Stack::push(int data){
    arr[currunt_sz]=data;
    currunt_sz++;
}


int Stack::pop(){
    int top = currunt_sz>0?arr[currunt_sz-1]:0;
    currunt_sz--;
    return top;
}

int Stack::top(){
    return currunt_sz>0?arr[currunt_sz-1]:0;
}

int Stack::size(){
    return currunt_sz;
}

void Stack::Print(){
    if(currunt_sz>0){
        std::cout << "stack大小: "<< size() << std::endl;
        std::cout << "stack最上面的元素為: "<< top() << std::endl;
    }
    else{
        std::cout << "stack現在是空的" << std::endl;
    }
}
    
int main()
{
    Stack s;
    s.Print();
    s.push(15);
    s.Print();
    s.push(26);
    s.Print();
    s.pop();
    s.Print();
    return 0;
}
