//
// Created by Siddharth Vijay on 2019-01-21.
//

#include "TrieNode.h"
using namespace std;
#include <unordered_map>
#include <string>
#include <iostream>

//default constructor
 TrieNode::TrieNode() {
    //set data string to be empty
    data = ' ';

}


//specific constructor
TrieNode::TrieNode(char s) {
    //assign word associated with node
    data = s;

}

//return data
char TrieNode::getData() {
    return this->data;
}

//return specific child
TrieNode TrieNode::getChild(char i) {
    return *children[i];
}

TrieNode* TrieNode::getChildPointer(char i) {

    //cout<<"inside "<<i<<endl;
auto returnThing = children.find(i);

    if(returnThing == children.end()){
        return nullptr;
    }

     return returnThing->second;
}

std::unordered_map<char, TrieNode*>* TrieNode::getChildren() {
    return &children;
}

//insert child at specific spot
void TrieNode::insertChild(char s) {
    TrieNode* newNode = new TrieNode(s);
    this->children.emplace(s, newNode);
    return;
}

//set node as a word
void TrieNode::setWord() {
     isWord = true;
}

//check if node is a word
bool TrieNode::getWord(){
    return isWord;
}


//destructor
TrieNode::~TrieNode() {
    ///////do this later///////
}

