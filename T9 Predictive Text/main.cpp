/* 
 * File:   main.cpp
 * Author: rachel
 *
 * Created on December 13, 2018, 9:34 PM
 */

//System Libraries
#include <cstdlib>
#include <iostream>
#include <fstream>
#include <sstream>
using namespace std;

//User Libraries
#include "Trie.h"

//Function prototypes
void insertDictionary(Trie*);
bool validateInputInt(string);
bool validateInputYN(string);
bool validateYN(string);
bool validateInputAlpha(string);
int countDigits(int);

int main(int argc, char** argv)
{
    Trie* newTrie = new Trie;
    
    //Inserting 1000 words in the Trie as a base
    insertDictionary(newTrie);
    
    //Allow the user to search and insert words in the trie.
    string input;
    do
    {
        do
        {
            cout << "\nPlease enter what numbers you'd like read using T9! (ex: 43556375347) ";
            cin >> input;
        }while(!validateInputInt(input));
        string word = newTrie->searchT9(input);
        if(word=="")
        {
            cout << "\nWord not found! ";
            do
            {
                cout << "Would you like to insert one? (y/n) ";
                cin >> input;
            }while(!validateInputYN(input));
            if(tolower(input[0])=='y')
            {
                do
                {
                    cout << "\nWhat is the word you'd like to insert? ";
                    cin >> input;
                }while(!validateInputAlpha(input));
                newTrie->insert(input, 1);
                cout << "\nThe numeric code for this word is: " << newTrie->getHash(input,true);
            }
        }
        else
        {
            cout << "\nYour word is: " << word << "\n";
        }
        do
        {
            cout << "\nIs there another number you'd like to be read? (y/n) ";
            cin >> input;
        }while(!validateInputYN(input));
    }while(validateYN(input));
    
    //Test "getHash"
    string hash = newTrie->getHash("HelloWorld",true);
    
    //Test "insert"
    cout <<"\nInserting 'HelloWorld' into the Trie...";
    newTrie->insert("HelloWorld",true);
    
    cout <<"\nHash for 'HelloWorld' = " << hash;
    
    //Test "searchT9"
    cout << "\nSearching by hash...";
    cout << "\nHash " << hash << " points to " << newTrie->searchT9(hash);
    
    //Test "searchWord"
    cout << "\nSearching by name... ";
    if(newTrie->searchWord("HelloWorld"))
    {
        cout << "Returns true.";
    }
    else
    {
        cout << "Returns false.";
    }
    
    //Test "remove"
    cout << "\nDeleting 'HelloWorld'... ";
    newTrie->remove("HelloWorld");
    
    //Test searchWord again after removing
    cout << "\nSearching again...";
    if(newTrie->searchWord("HelloWorld"))
    {
        cout << "Returns true.";
    }
    else
    {
        cout << "Returns false.";
    }
    
    //Test preorder output
    cout << "\n\n-------------------PREORDER-------------------\n";
    newTrie->preorder();
    
    //Test postorder output
    cout << "\n-------------------POSTORDER-------------------\n";
    newTrie->postorder();
    
    //Test breadth output
    cout << "\n-------------------BREADTH-------------------\n";
    newTrie->breadth();
    
    //Delete the trie
    delete newTrie;
    
    //Exit program
    return 0;
}

/**
 * Inserts "1000Words.txt" into the Trie
 * @param trie
 */
void insertDictionary(Trie* trie)
{
    ifstream fin;
    
    //Open the file
    try
    {
        fin.open("1000Words.txt");
    }
    catch(system_error& e)
    {
        cerr << e.code().message() << "\n";
    }
    
    //Read from the file, setting the line number as the priority of the word since it's sorted by common use.
    string word;
    if(fin.is_open())
    {
        int counter = 0;
        while(fin >> word)
        {
            trie->insert(word,++counter);
        }
    }
    
    //Insert my own word in too
    trie->insert("HelloDrLehr",1);
    
    //Close file
    fin.close();
}

/**
 * Returns true if input only contains digits from 2-9
 * @param input
 * @return 
 */
bool validateInputInt(string input)
{
    for(int i=0;i<input.length();i++)
    {
        if(!isdigit(input[i]))
        {
            cout << "Error! Invalid input.\n";
            return false;
        }
        if((int)input[i] < 50 || (int)input[i] > 57)
        {
            cout << "Error! Digits must be 2-9.\n";
            return false;
        }
    }
    return true;
}

/**
 * Returns true if input is either 'y' or 'n'
 * @param input
 * @return 
 */
bool validateInputYN(string input)
{
    if(tolower(input[0]) != 'y' && tolower(input[0]) != 'n')
    {
        cout << "Error! Invalid input.\n";
        return false;
    }
    return true;
}

/**
 * Returns true if input is 'y'
 * @param input
 * @return 
 */
bool validateYN(string input)
{
    if(tolower(input[0]) == 'y') return true;
    else return false;
}

/**
 * Returns true if input only contains letters
 * @param input
 * @return 
 */
bool validateInputAlpha(string input)
{
    for(int i=0;i<input.length();i++)
    {
        if(!isalpha(input[i]))
        {
            cout << "Error! Must contain letters only.\n";
            return false;
        }
    }
    return true;
}