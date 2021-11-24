#include <iostream>
#include <string>

using namespace std;

class TrieNode{
public:
    char data;
    TrieNode**children;
    bool isTerminal;

    TrieNode(char data){
        this->data = data;
        children = new TrieNode*[26];
        for(int i=0;i<26;i++){
            children[i] = NULL;
        }
        isTerminal = false;
    }
};

class Trie{
    TrieNode*root;

public:
    Trie(){
        root = new TrieNode('\0');
    }

    void insertWord(TrieNode*root , string word){
        //base case
        if(word.size()==0){
            root->isTerminal = true;
            return;
        }

        //small calculation
        int index = word[0]-'a';
        TrieNode*child;
        if(root->children[index]!=NULL){
            child = root->children[index];
        }
        else{
            child = new TrieNode(word[0]);
            root->children[index] = child;
        }

        insertWord(child , word.substr(1));
    }

    bool search(TrieNode*root , string word){
        //base case
        if(word.size()==0){
            return root->isTerminal;
        }


        //small calculation
        int index = word[0]-'a';
        TrieNode*child;
        if(root->children[index]!=NULL){
            child = root->children[index];
        }
        else{
            return false;
        }

        return search(child , word.substr(1));
    }

    void removeWord(TrieNode*root , string word){

         //base case
        if(word.size()==0){
            root->isTerminal = false;
            return;
        }


        //small calculation
        int index = word[0]-'a';
        TrieNode*child;
        if(root->children[index]!=NULL){
            child = root->children[index];
        }
        else{
            return;
        }

        return removeWord(child , word.substr(1));

        if(child->isTerminal == false){
            for(int i=0;i<26;i++){
                if(child->children[i]!=NULL){}
                return;
            }
        }

        delete child;
        root->children[index]=NULL;

    }

    void insertWord(string word){
        insertWord(root , word);
    }


    bool search(string word){
        return search(root , word);
    }

    void removeWord(string word){
        removeWord(root,word);
    }
};


int main(){
    Trie t;
    t.insertWord("are");
    t.insertWord("and");
    t.insertWord("not");
    t.insertWord("dot");

    cout<<t.search("not")<<endl;
    cout<<t.search("bed")<<endl;

    t.removeWord("not");
    cout<<t.search("not")<<endl;

}
