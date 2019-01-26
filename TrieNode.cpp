//
// Created by Siddharth Vijay on 2019-01-21.
//

#include "TrieNode.h"
using namespace std;
#include <vector>
#include <string>

//default constructor
 TrieNode::TrieNode() {
    //set data string to be empty
    data = "-1";

    for(int i = 0; i <26; i++){
        children[i] = nullptr;
    }

}


//specific constructor
TrieNode::TrieNode(string s) {
    //assign word associated with node
    data = s;

    for(int i = 0; i <26; i++){
        children[i] = nullptr;
    }

}

//return data
string TrieNode::getData() {
    return this->data;
}

//return specific child
TrieNode TrieNode::getChild(int i) {
    return *children[i];
}

TrieNode* TrieNode::getChildPointer(int i) {
    return children[i];
}

//get vector of children

vector<TrieNode*> TrieNode::getChildren(){
    return children;
};


//insert child at specific spot
void TrieNode::insertChild(string s) {

    //insert in alphabetical position
    int index = s.at(s.length()-1) - 97;
    children[index] = new TrieNode(s);

    return;
}

void TrieNode::setWord() {
     isWord = true;
}

bool TrieNode::getWord(){
    return isWord;
}


//destructor
TrieNode::~TrieNode() {
    ///////do this later///////
}