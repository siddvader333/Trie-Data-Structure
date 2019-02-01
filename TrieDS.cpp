//
// Created by Siddharth Vijay on 2019-01-21.
//

#include "TrieDS.h"
#include <algorithm>
#include <iostream>

//constructor
TrieDS::TrieDS() {

    root = new TrieNode(" ");

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
        string checkChar = s.substr(i, 1);

        //if there is no path, make  a new node
        if(temp->getChildren()->find(checkChar) == temp->getChildren()->end()){

            (*temp->getChildren())[checkChar] = new TrieNode(s.substr(0, i+1));
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
        string checkChar = s.substr(i, 1);

        /*go to next node*/
        temp = (*temp->getChildren())[checkChar];

        if(temp == nullptr){
            return false;
        }
    }//end of iteration


    //once its reached here, do the following:
    //traverse through subTree of every child of current node that is non-null
    traverse(temp, list);

    for(auto it = list.begin(); it!=list.end(); it++){
        std::cout<<*it<<std::endl;
    }

    //cout<<temp->getData()<<endl;

    return list;

}

// add all full words to a list and output
std::vector<std::string> TrieDS::traverse(TrieNode* temp_root, std::vector<std::string> &list){

    if(temp_root == nullptr){
        return list;
    }

    //check current node
    if(temp_root->getWord()){
        //std::cout<<temp_root->getData()<<std::endl;
        //add it to the list
        list.push_back(temp_root->getData());
    }

    //iterate through children
    for(auto it = temp_root->getChildren()->begin(); it!= temp_root->getChildren()->end(); ++it){
            traverse(it->second, list);
    }

    return list;
}

int TrieDS::calculateIndex(char c){

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
        return c-48;
    }

    //else, c is a character
    return (c-84);



}