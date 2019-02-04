//
// Created by Siddharth Vijay on 2019-01-21.
//

#include "TrieDS.h"
#include <algorithm>
#include <iostream>

//constructor
TrieDS::TrieDS() {

    root = new TrieNode(' ');

}


//destructor
TrieDS::~TrieDS() {

    ///////////
    ///leave this for later/////
    /////its gonna be messy/////
    ///////////////////////////

}


//list of functions
void TrieDS::add(string s) {

    //std::transform(s.begin(), s.end(), s.begin(), ::tolower);

    TrieNode* temp = this->root;
    //iterate through string/tree  --> i represents depth level
    for(int i = 0; i<s.length(); i++){
        //which character to look for and whch index of children array
        char checkChar = s.at(i);

        //if there is no path, make  a new node
        if(temp->getChildren()->find(checkChar) == temp->getChildren()->end()){

            (*temp->getChildren())[checkChar] = new TrieNode(s.at(i));
        }

        temp = (*temp->getChildren())[checkChar];

    }//end iteration

    //final node is a word
    temp->setWord();

    std::cout<<"success add" <<std::endl;

}


std::vector<string> TrieDS::search(string s) {

    std::transform(s.begin(), s.end(), s.begin(), ::tolower);
    TrieNode* temp = this->root;
    std::vector<std::string> list;

    if(root == nullptr){
        return list;
    }

    //iterate through string/tree  --> i represents depth level
    for(int i = 0; i<s.length(); i++){

        //which character to look for and whch index of children array
        char checkChar = s.at(i);

        /*go to next node*/
        temp = (*temp->getChildren())[checkChar];

        if(temp == nullptr){
            return list;
        }
    }//end of iteration


    //once its reached here, do the following:
    //traverse through subTree of every child of current node that is non-null
    traverse(temp, list, s);

    for(auto it = list.begin(); it!=list.end(); it++){
        std::cout<<*it<<std::endl;
    }

    //cout<<temp->getData()<<endl;

    return list;

}

// add all full words to a list and output
std::vector<std::string> TrieDS::traverse(TrieNode* temp_root, std::vector<std::string> &list, string &prefix){

    if(temp_root == nullptr){
        return list;
    }

    //check current node
    if(temp_root->getWord()){
        //std::cout<<temp_root->getData()<<std::endl;
        //add it to the list
        list.push_back(prefix);
    }

    //iterate through children
    for(auto it = temp_root->getChildren()->begin(); it!= temp_root->getChildren()->end(); ++it){
            //find the data of the child
            char c = (it->second)->getData();
            string newPrefix = prefix + c;
            traverse(it->second, list, newPrefix);
    }

    return list;
}

