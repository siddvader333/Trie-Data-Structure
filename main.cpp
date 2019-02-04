#include <iostream>
#include "TrieDS.h"
#include <sstream>
#include "TrieNode.h"
using namespace std;
int main() {
    //std::cout << "Hello, World!" << std::endl;

    TrieDS* tree = new TrieDS();

    TrieNode* sup = new TrieNode();
    string input;
    string command;
    string item;

    //std::cout<<"Hello world 2"<<std::endl;

    //insert 2200 random words of length 6-9

    tree->add("bloor");
    tree->add("bathurst");
    tree->add("spadina");
    tree->add("mccowan");
    tree->add("finch");
    tree->add("brimley");
    tree->add("ellesmere");
    tree->add("highway401");
    tree->add("Gardiner");

    tree->add("bloor1");
    tree->add("bathurst1");
    tree->add("spadina1");
    tree->add("mccowan1");
    tree->add("finch1");
    tree->add("brimley1");
    tree->add("ellesmere1");
    tree->add("highway4011");
    tree->add("Gardiner1");

    tree->add("bloor2");
    tree->add("bathurst2");
    tree->add("spadina2");
    tree->add("mccowan2");
    tree->add("finch2");
    tree->add("brimley2");
    tree->add("ellesmere2");
    tree->add("highway4012");
    tree->add("Gardiner2");

    tree->add("ékjsdv");
    tree->add("üsjdbvs");
    tree->add("母は母");

   string stuff[12] = {"blo", "ba", "spa", "mc", "fi", "bri", "ell", "hi", "ga", "é", "ü", "母"};

    for(int i =0; i <1000000; i++){
        int x = i%12;
        tree->search(stuff[x]);
        cout<<stuff[x]<<endl;
        cout<<endl;
    }

    //cout<<clock()-time1;

    return 0;
}