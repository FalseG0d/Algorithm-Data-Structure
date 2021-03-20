#include <bits/stdc++.h>
#define ALPHABET_SIZE 26

using namespace std;

struct TrieNode{
    TrieNode*children[ALPHABET_SIZE];
    bool endOfWord;
};

TrieNode*getNode(){
    TrieNode*temp=new TrieNode();
    temp->endOfWord=false;
    for(int i=0;i<ALPHABET_SIZE;i++)temp->children[i]=NULL;

    return temp;
}

void insert(TrieNode*root,string key){
    TrieNode*crawl=root;

    for(int i=0;i<key.size();i++){
        int index=key[i]-'a';

        if(!crawl->children[index])crawl->children[index]=getNode();

        crawl=crawl->children[index];
    }

    crawl->endOfWord=true;
}

bool search(TrieNode*root,string key){
    TrieNode*crawl=root;

    for(int i=0;i<key.length();i++){
        int index=key[i]-'a';

        if(!crawl->children[index])return false;

        crawl=crawl->children[index];
    }

    return crawl->endOfWord&&crawl!=NULL;
}

bool isEmpty(TrieNode*root){
    for(int i=0;i<ALPHABET_SIZE;i++){
        if(root->children[i])return false;
    }return true;
}

TrieNode*remove(TrieNode*root,string key,int depth=0){
    if(root==NULL)return NULL;

    if(depth==key.size()){
        if(root->endOfWord)root->endOfWord=false;

        if(isEmpty(root)){
            delete root;
            root=NULL;
        }

        return root;
    }

    int index=key[depth]-'a';
    root->children[index]=remove(root->children[index],key,depth+1);

    if(isEmpty(root)&root->endOfWord==false){
        delete root;
        root=NULL;
    }

    return root;
}

int main() {
    string keys[]={"the", "a", "there", "answer", "any", "by", "bye", "their" };
    int n=sizeof(keys)/sizeof(keys[0]);

    TrieNode*root=getNode();
    for(int i=0;i<n;i++)insert(root,keys[i]);

    search(root,"the")?cout<<"Yes\n":cout<<"No\n";
    remove(root,"the");
    search(root,"the")?cout<<"Yes\n":cout<<"No\n";

    return 0;
}
