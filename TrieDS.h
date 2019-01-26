//
// Created by Siddharth Vijay on 2019-01-21.
//

#ifndef TRIETEST_TRIEDS_H
#define TRIETEST_TRIEDS_H

#include <string>
#include <vector>
#include "TrieNode.h"

using namespace std;

class TrieDS {

public:

    //constructor
    TrieDS();

    //destructor
    ~TrieDS();

    //data members
    TrieNode* root;

    //functions
    void add(string s);;

    //search for something
    void search(string s);

    std::vector<std::string> traverse(TrieNode* temp_root, std::vector<std::string> &list);

};


#endif //TRIETEST_TRIEDS_H
