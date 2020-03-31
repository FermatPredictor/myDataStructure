#include <iostream>
using namespace std;

class ListNode {
public:
    ListNode(int p, int c) :power(p), coff(c) {};
    int power; //次方
    int coff; //係數
    ListNode* next;
};

//多項式，次方數由低排至高，只收集係數非零的項
class Polynomial {
  public:
    ListNode* head;
    ListNode* tail;
    
    void insert(int power, int coff); // 加入單項式，保證加完按次方順序排列
    void insertTail(int power, int coff); // 在尾巴插入節點，若測資保證順序會最簡單
    
    Polynomial():head(0), tail(0){};
    Polynomial add(const Polynomial& other); //多項式加法
    Polynomial mult(const Polynomial& other); //多項式乘法(用多個加法實作)
    
    void Print(); //將多項式由低至高次方印出
};

void Polynomial::Print(){
    ListNode* node = head;
    while (node) {
        cout << node->coff <<" "<< node->power ;
        node = node->next;
        if (node) {
            cout << " ";
        }
    }
    cout << endl;
}

void Polynomial::insert(int power, int coff)
{
    if(coff==0)
        return;
    ListNode* in = new ListNode(power, coff);
    if(!head){
        head = tail = in;
    }
    else if(tail->power < power){
        tail = tail->next = in;
    }
    else{
        ListNode* node = head, *prev;
        while(node){
            if(node->power< power){
                prev = node;
                node = node->next;
            }
            else if(node->power == power){
                node->coff += coff;
                if(node->coff==0){
                    if(node == tail){
                        tail=prev;
                    }
                    prev->next=node->next;
                    node->next=NULL;
                }
                return;
            }
            else{
                if(node==head){
                    in -> next = head;
                    head = in;
                }
                else{
                    in -> next = prev -> next;
                    prev -> next = in;
                }
                return;
            }
        }
    }
}

void Polynomial::insertTail(int power, int coff){
    if(coff==0)
        return;
    ListNode* node = new ListNode(power, coff);
    if (!head) {
        head = node;
    }
    else {
        tail->next = node;
    }
    tail = node;
};


Polynomial Polynomial::add(const Polynomial& other){
    Polynomial p;
    ListNode* node = head, *other_node = other.head;
    while(node || other_node){
        if(node && other_node && node->power == other_node->power){
            if(node->coff + other_node->coff!=0){
                p.insertTail(node->power, node->coff + other_node->coff);
            }
            node = node->next;
            other_node = other_node->next;
        }
        else if(node == NULL || other_node && node->power > other_node->power){
            p.insertTail(other_node->power, other_node->coff);
            other_node = other_node->next;
        }
        else if(other_node==NULL || node && node->power < other_node->power){
            p.insertTail(node->power, node->coff);
            node = node->next;
        }
    }
    return p;
}

Polynomial Polynomial::mult(const Polynomial& other){
    Polynomial final;
    ListNode* node = head, *other_node = other.head;
    for(;;node=node->next){
       for(other_node = other.head;; other_node=other_node->next){
           Polynomial p;
           p.insertTail(node->power+other_node->power, node->coff*other_node->coff);
           final = final.add(p);
           if(other_node==other.tail){
               break;
           }
       }
       if(node == tail){
           break;
       }
    }
    return final;
}
    
int main()
{
    Polynomial p1, p2, p3, p4;
    //令p1= x^2+1, p2= x^2-1
    p1.insert(2, 1);
    p1.insert(0, 1);
    p2.insert(2, 1);
    p2.insert(0, -1);
    p3 = p1.add(p2);
    p3.Print();
    p4 = p1.mult(p2);
    p4.Print();
    return 0;
}
