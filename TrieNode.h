//
// Created by Siddharth Vijay on 2019-01-21.
//

#include <string>
#include <vector>
#include <unordered_map>

using namespace std;
#ifndef TRIETEST_TRIENODE_H
#define TRIETEST_TRIENODE_H


class TrieNode {

public:
    //constructors
    TrieNode();
    TrieNode(char s);

    //destructor
    ~TrieNode();

    //getData
    char getData();

    TrieNode getChild(char i );

    TrieNode* getChildPointer(char i);

    std::unordered_map<char, TrieNode*>* getChildren();

    void insertChild(char s);

    void setWord();

    bool getWord();


private:
    char data;

    //int depth_level;

    bool isWord = false;

    //note its a vector to conserve space because of unknown number of chidlren
    std::unordered_map<char, TrieNode*>children = std::unordered_map<char, TrieNode*>();

    /////[0-9] = 0-9
    /////[10]  = -
    /////[11]  = /
    /////[12]  = " "
    /////[13-38] = a-z

};


#endif //TRIETEST_TRIENODE_H
