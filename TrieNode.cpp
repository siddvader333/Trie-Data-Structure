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
    data = "-1";

}


//specific constructor
TrieNode::TrieNode(string s) {
    //assign word associated with node
    data = s;

}

//return data
string TrieNode::getData() {
    return this->data;
}

//return specific child
TrieNode TrieNode::getChild(string i) {
    return *children[i];
}

TrieNode* TrieNode::getChildPointer(string i) {

    //cout<<"inside "<<i<<endl;
auto returnThing = children.find(i);

    if(returnThing == children.end()){
        return nullptr;
    }

     return returnThing->second;
}

std::unordered_map<std::string, TrieNode*>* TrieNode::getChildren() {
    return &children;
}

//insert child at specific spot
void TrieNode::insertChild(string s) {
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

int TrieNode::calculateIndex(char c){

    //exceptions

    if(c == ' '){
        return 12 ;
    }

    if(c == '/'){
        return 11;
    }

    if(c == '-'){
        return 10;
    }

    if(isdigit(c)){//if c is an integer
        return c-48 ;
    }

    //else, c is a character
    return (c -84);



}