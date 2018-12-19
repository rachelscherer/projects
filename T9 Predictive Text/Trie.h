/* 
 * File:   Trie.h
 * Author: rachel
 *
 * Created on December 13, 2018, 9:38 PM
 */

#ifndef TRIE_H
#define TRIE_H
w
//System Libraries
#include <cstdlib>
#include <queue>
#include <string>
#include <iostream>
using namespace std;

class Trie
{
    
private:
    //Link stores the words associated with a node
    struct Link
    {
        string word;
        int priority;
        Link* next;
    };
    
    //Stores the numbers
    struct Node
    {
        Node* child[8];
        Link* head;
    };
    
    //Root of Trie
    Node* root;
    
    //Getters
    queue<int> getHashQueue(string);                    //Places string into queue of ints
    
    //Recursive add/delete functions
    void insertRec(Node*&,string,int,queue<int>);       //Inserts word into Node on Trie
        void removeRec(Node*&,string,queue<int>);       //Removes word from Node on Trie
    
    //Recursive destroyer helper functions
    void destroySubTree(Node*&);                        //Uses postorder traversal to delete Trie
    void destroyWordLinks(Link*);                       //Deletes Linked List from Trie
    
    //Recursive print functions
    void preorder(Node*);                               //Displays contents using preorder traversal
    void postorder(Node*);                              //Displays contents using postorder traversal
    
    //Recursive search functions
    string searchT9Rec(Node*&,queue<int>);              //Searches Trie by number (returns string)
    bool searchWordRec(Node*&,string,queue<int>);       //Searches Trie by string (returns boolean)
    
    //Recursive setters
    void setPriorityRec(Node*&,string,int,queue<int>);  //Changes priority of word
    void prioritizeRec(Node*&,string,queue<int>);       //Brings word to front of list in its node
    void deprioritizeRec(Node*&,string,queue<int>);     //Brings word to end of list in its node
    
public:
    //Constructor
    Trie();
    
    //Destructor
    ~Trie();
    
    //Print functions
    void preorder();                                    //Calls recursive preorder function
    void postorder();                                   //Calls recursive postorder function
    void breadth();                                     //Displays contents using breadth traversal
    
    //Add/remove functions
    void insert(string,int);                            //Calls recursive insert function
    void remove(string);                                //Calls revursive remove function
    
    //Search functions
    string searchT9(string);                            //Calls recursive search function
    bool searchWord(string);                            //Calls recursive search function
    
    //Getters
    string getHash(string,bool);                        //Returns hash
    
    //Setters
    void setPriority(string,int);                       //Calls recursive setPriority function
    void prioritize(string);                            //Calls recursive prioritize function
    void deprioritize(string);                          //Calls recursive deprioritize function
};
#endif /* TRIE_H */