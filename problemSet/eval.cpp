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
    {'^', 3},
    {'*', 2}, {'/', 2}, {'%', 2}, 
    {'+', 1}, {'-', 1},
};

//全域變數，定義哪些優先權的運算子是右結合
set<int> rightAsso = {3};
  
//回傳運算子的優先權
int priority(char c) 
{ 
    return ops.find(c) != ops.end()?ops[c]:-1;
} 

//回傳某個等級優先權的運算子是「左結合」還是「右結合」
//這邊假設同級的運算子的結合性相同，
//不會有加法是「左結合」，減法卻是「右結合」的情形
bool leftAssociate(int priority)
{
    return rightAsso.find(priority) == rightAsso.end();
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
          
        // 讀到運算子(ex: +, *)，比優先權，高優先權的才能壓過低的，
        // 這邊又分兩種情形: 左結合的運算子要優先權絕對大才能壓過(將stack裡優先權<=s[i]的都清掉)，
        // 右結合的運算子只要優先權大於或等於即可壓過 (將stack裡優先權<s[i]的都清掉)
        else if(ops.find(s[i])!=ops.end()){ 
            int add = leftAssociate(priority(s[i]));
            while(!st.empty() && priority(s[i]) < (priority(st.top())+add))
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


long long evalOP(long long x, long long y, string op){
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
    if(op=="^"){
        return pow(x,y);
    }
    return 0;
}

//計算postfix表達式的結果
long long evalRPN(vector<string>& tokens) {
    stack<long long> evalStack;
    for(string token: tokens){
        if(token.size()==1 && ops.find(token[0])!=ops.end()){
            long long x = evalStack.top();
            evalStack.pop();
            long long y = evalStack.top();        
            evalStack.pop();
            evalStack.push(evalOP(y, x, token));
        }
        else{
            evalStack.push(atoll(token.c_str()));
        }
    }
    return evalStack.top();
}

int main() 
{ 
    string expr;
    while(getline(cin, expr)){
        vector<string> postfix = infixToPostfix(expr);
        cout << evalRPN(postfix) << endl;
    }
    return 0; 
} 
