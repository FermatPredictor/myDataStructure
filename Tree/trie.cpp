#include <string>
#include <vector>
#include <iostream>
using namespace std;

class Trie
{

    class TrieNode
    {
    public:
        vector<TrieNode *> child; //子節點有a~z共26種可能，初始設為null
        bool isWord; //記錄某點是否為單字的結尾
        TrieNode(): isWord(false), child(vector<TrieNode *>(26, NULL)) {};
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
            int i = c - 'a';
            if (!p->child[i])
            {
                p->child[i] = new TrieNode();
            }
            p = p->child[i];
        }
        p->isWord = true;
    }

    /** Returns if the word is in the trie. */
    bool search(string word)
    {
        TrieNode *p = root;
        for (char c : word)
        {
            int i = c - 'a';
            if (!p->child[i])
            {
                return false;
            }
            p = p->child[i];
        }
        return p->isWord;
    }

    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix)
    {
        TrieNode *p = root;
        for (char c : prefix)
        {
            int i = c - 'a';
            if (!p->child[i])
            {
                return false;
            }
            p = p->child[i];
        }
        return true;
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

}
