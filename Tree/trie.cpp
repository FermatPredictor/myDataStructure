#include <string>
#include <unordered_map>
#include <vector>
#include <iostream>
using namespace std;

class Trie
{

    class TrieNode
    {
    public:
        unordered_map<char, TrieNode *> child;
        int leaf_num; // 記錄某點底下有幾個leaf
        bool isWord; //記錄某點是否為單字的結尾
        TrieNode(): leaf_num(0), isWord(false){};
    };

    TrieNode* root; //root為一個空的節點

public:
    /** Initialize your data structure here. */
    Trie(): root(new TrieNode()) {};

    /** Inserts a word into the trie. */
    void insert(string word)
    {
        TrieNode *p = root;
        for (char c : word)
        {
            if (p->child.find(c)==p->child.end())
            {
                p->child[c] = new TrieNode();
            }
            p ->leaf_num++;
            p = p->child[c];
        }
        p ->leaf_num++;
        p->isWord = true;
    }

    /** Returns if the word is in the trie. */
    bool search(string word)
    {
        TrieNode *p = root;
        for (char c : word)
        {
            if (p->child.find(c)==p->child.end())
            {
                return false;
            }
            p = p->child[c];
        }
        return p->isWord;
    }

    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix)
    {
        TrieNode *p = root;
        for (char c : prefix)
        {
            if (p->child.find(c)==p->child.end())
            {
                return false;
            }
            p = p->child[c];
        }
        return true;
    }

    //回傳有幾個字的開頭是prefix
    int count_startsWith(string prefix)
    {
        TrieNode *p = root;
        for (char c : prefix)
        {
             if (p->child.find(c)==p->child.end())
            {
                return false;
            }
            p = p->child[c];
        }
        return p->leaf_num;
    }
};

int main()
{
    Trie* obj = new Trie();
    vector<string> words = {"apple", "at", "app"};
    for(string word : words)
    {
        obj->insert(word);
    }
    cout<< obj->search("ap")<<endl;
    cout<< obj->startsWith("ap")<<endl;
    cout<< obj->count_startsWith("ap")<<endl;

}
