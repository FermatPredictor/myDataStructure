#include <iostream>
#include <stack>
#include <string>
#include <map>
#include <vector>
#include <set>
#include <cmath>
using namespace std;

//全域變數，定義有哪些運算子可用
map<char, int> ops = 
{ 
    {'*', 2}, {'/', 2}, {'%', 2},
    {'+', 1}, {'-', 1},
};
  
//回傳運算子的優先權
int priority(char c) 
{ 
    return ops.find(c) != ops.end()?ops[c]:-1;
} 
  
//函數功能: 將infix運算式轉postfix
vector<string> infixToPostfix(string s) 
{ 
    stack<char> st; 
    vector<string> result;
    for(int i = 0; i < s.size(); i++) 
    { 
        // 讀取數字 
        if(s[i] >= '0' && s[i] <= '9'){
            string num;
            while(s[i] >= '0' && s[i] <= '9'){
                num += s[i++];
            }
            i--; //因為for迴圈本身會i++，故減回去
            result.push_back(num); 
        }
        else if(s[i] == ' '){
            continue;
        }
        // 讀到左括號不論如何都丟進stack 
        else if(s[i] == '('){
            st.push('(');
        }
        // 若讀到右括號，將stack裡直到左括號前的東西都取出
        else if(s[i] == ')') 
        { 
            while(!st.empty() && st.top() != '(') 
            { 
                result.push_back(string(1,st.top())); 
                st.pop();
            } 
            st.pop(); //看到'('為止就拔掉
        } 
          
        //讀到運算子(+, *)，比優先權，高優先權的才能壓過低的
        else{ 
            while(!st.empty() && priority(s[i]) <= priority(st.top()))
            { 
                result.push_back(string(1,st.top())); 
                st.pop();
            } 
            st.push(s[i]); 
        } 
  
    } 
    //字串掃完之後，將stack裡的元素取出
    while(!st.empty()) 
    { 
        result.push_back(string(1,st.top())); 
        st.pop();
    } 
    return result;
  
} 


int evalOP(int x, int y, string op){
    if(op=="+"){
        return x+y;
    }
    if(op=="-"){
        return x-y;
    }
    if(op=="*"){
        return x*y;
    }
    if(op=="/"){
        return x/y;
    }
    if(op=="%"){
        return x%y;
    }
    return 0;
}

//計算postfix表達式的結果
int evalRPN(vector<string>& tokens) {
    stack<int> evalStack;
    for(string token: tokens){
        if(token.size()==1 && ops.find(token[0])!=ops.end()){
            int x = evalStack.top();
            evalStack.pop();
            int y = evalStack.top();        
            evalStack.pop();
            evalStack.push(evalOP(y, x, token));
        }
        else{
            evalStack.push(atoi(token.c_str()));
        }
    }
    return evalStack.top();
}

int main() 
{ 
    string exp;
    //注意: 輸入可能有空格，需用getline代替普通的cin
    while(getline(cin,exp)){
        vector<string> postfix = infixToPostfix(exp);
        cout << evalRPN(postfix) << endl;
    }
    return 0; 
} 
