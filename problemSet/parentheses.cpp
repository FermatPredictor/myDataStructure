#include <iostream>
#include <string>
using namespace std;

class Stack{
private:
    const int max_sz; //預設stack的最大容量
    int currunt_sz = 0; //目前Stack裡有幾個元素
    char *arr;
public:
    Stack():max_sz(500){arr = new char[max_sz];};
    Stack(int sz):max_sz(sz){arr = new char[max_sz];};
    void push(char data);
    void pop();
    char top();
    int size();
};

void Stack::push(char data){
    arr[currunt_sz]=data;
    currunt_sz++;
}


void Stack::pop(){
    currunt_sz--;
}

char Stack::top(){
    return currunt_sz>0?arr[currunt_sz-1]:0;
}

int Stack::size(){
    return currunt_sz;
}

bool cheakValidParentheses(const string& s){
    Stack stack(1000);
    for (auto c : s) {
        if(c=='(' || c=='['|| c=='<' || c=='{'){
            stack.push(c);
        }
        else{
            switch(c){
                case ')':
                    if(stack.size() && stack.top()=='('){
                        stack.pop();
                        break;
                    }
                    return false;
                case ']':
                    if(stack.size() && stack.top()=='['){
                        stack.pop();
                        break;
                    }
                    return false;
                case '>':
                    if(stack.size() && stack.top()=='<'){
                        stack.pop();
                        break;
                    }
                    return false;
                case '}':
                    if(stack.size() && stack.top()=='{'){
                        stack.pop();
                        break;
                    }
                    return false;
            }
        }
    }
    return stack.size()==0;
    
}
int main()
{
    int t;
    string test;
    cin >> t;
    getline(cin, test); //吃掉第一行的換行字符
    for(int i=0; i<t;i++){
        getline(cin, test); //選擇用getline讀字串是因為怕測資有空字串
        std::cout << (cheakValidParentheses(test)?'Y':'N') << std::endl;
    }
    return 0;
}
