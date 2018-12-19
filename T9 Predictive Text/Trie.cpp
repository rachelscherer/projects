/* 
 * File:   Trie.cpp
 * Author: rachel
 * 
 * Created on December 13, 2018, 9:38 PM
 */

//User libraries
#include "Trie.h"

//Default constructor
Trie::Trie()
{
    root = new Node;
    for(int i=0;i<8;i++)
    {
        root->child[i] = NULL;
    }
    root->head = NULL;
}

//Destructor
Trie::~Trie()
{
    destroySubTree(root);
}

/**
 * Destructor helper function that destroys nodes using postorder traversal
 * @param node
 */
void Trie::destroySubTree(Node*& node)
{
    if(!node)
    {
        return;
    }
    else
    {
        for(int i=0;i<8;i++)
        {
            destroySubTree(node->child[i]);
        }
        destroyWordLinks(node->head);
        delete node;
    }
}

/**
 * Destructor helper function that deletes the linked list associated with a node.
 * @param head
 */
void Trie::destroyWordLinks(Link* head)
{
    if(!head)
    {
        return;
    }
    else
    {
        Link* temp = new Link;
        temp = head;
        while(temp)
        {
            temp = temp->next;
            delete head;
            head = temp;
        }
    }
}

/**
 * Gets hash, then calls recursive insert function using the root as an argument
 * @param word
 * @param priority
 */
void Trie::insert(string word, int priority)
{
    queue<int> hash = getHashQueue(word);
    if(hash.empty())
    {
        return;
    }
    else
    {
    insertRec(root,word,priority,hash);
    }
}

/**
 * Recursively inserts a word into an existing node, or creates a new node if it doesn't already exist
 * @param node
 * @param word
 * @param priority
 * @param hash
 */
void Trie::insertRec(Node*& node, string word, int priority, queue<int>hash){
    if(!node)
    {
        node = new Node;
        for(int i=0;i<8;i++)
        {
            node->child[i] = NULL;
        }
        node->head = NULL;
    }
    if(hash.empty())
    {
        if(!node->head)
        {
            node->head = new Link;
            node->head->priority = priority;
            node->head->word = word;
            node->head->next = NULL;
        }
        else
        {
            Link* newLink = new Link;
            if(node->head->priority >= priority)
            {
                newLink->next = node->head;
                node->head = newLink;
                newLink->word = word;
                newLink->priority = priority;
            }
            else
            {
                Link* temp = new Link;
                while(temp->next && priority > temp->next->priority)
                {
                    temp = temp->next;
                }
                newLink->next = temp->next;
                temp->next = newLink;
                newLink->priority = priority;
                newLink->word = word;
            }
        }
    }
    else
    {
        int val = hash.front();
        hash.pop();
        insertRec(node->child[val],word,priority,hash);
    }
}

/**
 * Gets hash, then calls recursive remove function using the root as an argument
 * @param word
 */
void Trie::remove(string word)
{
    queue<int> hash = getHashQueue(word);
    if(hash.empty())
    {
        return;
    }
    else
    {
    removeRec(root,word,hash);
    }
}

/**
 * Recursively removes a word from a node
 * @param node
 * @param word
 * @param hash
 */
void Trie::removeRec(Node*& node, string word, queue<int> hash)
{
    if(!node)
    {
        cout << "'" << word << "'" << " not found - cannot delete.\n";
    }
    else
    {
        if(hash.empty())
        {
            if(!node->head)
            {
                cout << "'" << word << "'" << " not found - cannot delete.\n";
            }
            else if(node->head->word == word)
            {
                Link* temp = new Link;
                temp = node->head;
                delete node->head;
                node->head = temp->next;
            }
            else if(!node->head->next && node->head->word != word)
            {
                cout << "'" << word << "'" << " not found - cannot delete.\n";
            }   
            else
            {
                Link* prev = new Link;
                prev = node->head;
                while(prev->next && prev->next->word != word)
                {
                    prev = prev->next;
                }
                if(prev->next->word == word)
                {
                    Link* dltLnk = new Link;
                    dltLnk = prev->next;
                    prev->next = dltLnk->next;
                    delete dltLnk;
                    dltLnk = NULL;
                }
                else
                {
                    cout << "'" << word << "'" << " not found - cannot delete.\n";
                }
            }
        }
        else
        {
            int val = hash.front();
            hash.pop();
            removeRec(node->child[val],word,hash);
        }
    }
}

/**
 * Using the input as the hash, calls recursive searchT9 function
 * @param input
 * @return 
 */
string Trie::searchT9(string input)
{
    int currentNum;
    queue<int> hashQueue;
    for(int i=0;i<input.size();i++)
    {
        currentNum = (int)input[i] - 50;
        hashQueue.push(currentNum);
    }
    string word = searchT9Rec(root,hashQueue);
    return word;
}

/**
 * Returns head of link list associated with a given node using recursion
 * @param node
 * @param hashQueue
 * @return 
 */
string Trie::searchT9Rec(Node*& node, queue<int> hashQueue)
{
    if(!node)
    {
        return "";
    }
    else
    {
        if(hashQueue.empty())
        {
            if(!node->head)
            {
                return "";
            }
            return node->head->word;
        }
        else
        {
            int val = hashQueue.front();
            hashQueue.pop();
            return searchT9Rec(node->child[val],hashQueue);
        }
    }
}

/**
 * Gets hash, then calls recursive searchWord function using the root as an argument
 * @param input
 * @return 
 */
bool Trie::searchWord(string input)
{
    queue<int> hash = getHashQueue(input);
    if(hash.empty())
    {
        return false;
    }
    else
    {
    return searchWordRec(root,input,hash);
    }
}

/**
 * Recursively searches for a given node using hashQueue. If the node exists, searches for "word" in linked list.
 * @param node
 * @param word
 * @param hashQueue
 * @return 
 */
bool Trie::searchWordRec(Node*& node, string word, queue<int> hashQueue)
{
    if(!node)
    {
        return false;
    }
    else
    {
        if(hashQueue.empty())
        {
            if(!node->head)
            {
                return false;
            }
            else
            {
                Link* temp = new Link;
                temp = node->head;
                while(temp)
                {
                    if(temp->word == word)
                    {
                        return true;
                    }
                    temp = temp->next;
                }
                return false;
            }
        }
        else
        {
            int val = hashQueue.front();
            hashQueue.pop();
            return searchWordRec(node->child[val],word,hashQueue);
        }
    }
}

/**
 * Calls recursive preorder function using root as an argument.
 */
void Trie::preorder()
{
    preorder(root);
}

/**
 * Recursively prints node, then iterates through the children.
 * @param node
 */
void Trie::preorder(Node* node)
{
    if(!node)
    {
        return;
    }
    else
    {
        if(node->head)
        {
            cout << node->head->word << "\n";
        }
        for(int i=0;i<8;i++)
        {
            preorder(node->child[i]);
        }
    }
}

/**
 * Calls recursive postorder function using root as an argument.
 */
void Trie::postorder()
{
    postorder(root);
}

/**
 * Recursively iterates through the children, then prints node.
 * @param node
 */
void Trie::postorder(Node* node)
{
    if(!node)
    {
        return;
    }
    else
    {
        for(int i=0;i<8;i++)
        {
            preorder(node->child[i]);
        }
        if(node->head)
        {
            cout << node->head->word << "\n";
        }
    }
}

/**
 * Uses a queue to print upper level nodes first, then the leaves
 */
void Trie::breadth()
{
    Node* temp = new Node;
    Link* tempLink = new Link;
    queue<Node*> newQueue;
    newQueue.push(root);
    while(newQueue.size()>0)
    {
        temp = newQueue.front();
        if(temp->head)
        {
            tempLink = temp->head;
        }
        while(tempLink)
        {
            cout << tempLink->word << "\n";
            tempLink = tempLink->next;
        }
        newQueue.pop();
        for(int i=0;i<8;i++)
        {
            if(temp->child[i])
            {
                newQueue.push(temp->child[i]);
            }
        }
    }
}

/**
 * Calls getHash(), then puts it in a queue
 * @param key
 * @return 
 */
queue<int> Trie::getHashQueue(string key)
{
    queue<int> hashQueue;
    string hash = getHash(key,false);
    int val;
    //Create a queue of integers to hold the hash
    for(int i=0;i<hash.length();i++)
    {
       val = (int)hash[i] - 48;
       hashQueue.push(val);
    }
    //Return queue
    return hashQueue;
}

/**
 * Using phone number-letter pairings, returns integers 2-9 if flag is false and 0-7 if true.
 * @param key
 * @param adjustFlag
 * @return 
 */
string Trie::getHash(string key, bool adjustFlag)
{
    string hash = "";
    for(int i=0;i<key.length();i++)
    {
        if(!isalpha(key[i]))
        {
            cout << "Error! Must contain letters only.\n";
            return "";
        }
        if(!adjustFlag)
        {
            if(toupper(key[i])=='A' || toupper(key[i])=='B' || toupper(key[i])=='C')
            {
                hash+="0";
            }
            if(toupper(key[i])=='D' || toupper(key[i])=='E' || toupper(key[i])=='F')
            {
                hash+="1";
            }
            if(toupper(key[i])=='G' || toupper(key[i])=='H' || toupper(key[i])=='I')
            {
                hash+="2";
            }
            if(toupper(key[i])=='J' || toupper(key[i])=='K' || toupper(key[i])=='L')
            {
                hash+="3";
            }
            if(toupper(key[i])=='M' || toupper(key[i])=='N' || toupper(key[i])=='O')
            {
                hash+="4";
            }
            if(toupper(key[i])=='P' || toupper(key[i])=='Q' || toupper(key[i])=='R' || toupper(key[i])=='S')
            {
                hash+="5";
            }
            if(toupper(key[i])=='T' || toupper(key[i])=='U' || toupper(key[i])=='V')
            {
                hash+="6";
            }
            if(toupper(key[i])=='W' || toupper(key[i])=='X' || toupper(key[i])=='Y' || toupper(key[i])=='Z')
            {
                hash+="7";
            }
        }
        else
        {
            if(toupper(key[i])=='A' || toupper(key[i])=='B' || toupper(key[i])=='C')
            {
                hash+="2";
            }
            if(toupper(key[i])=='D' || toupper(key[i])=='E' || toupper(key[i])=='F')
            {
                hash+="3";
            }
            if(toupper(key[i])=='G' || toupper(key[i])=='H' || toupper(key[i])=='I')
            {
                hash+="4";
            }
            if(toupper(key[i])=='J' || toupper(key[i])=='K' || toupper(key[i])=='L')
            {
                hash+="5";
            }
            if(toupper(key[i])=='M' || toupper(key[i])=='N' || toupper(key[i])=='O')
            {
                hash+="6";
            }
            if(toupper(key[i])=='P' || toupper(key[i])=='Q' || toupper(key[i])=='R' || toupper(key[i])=='S')
            {
                hash+="7";
            }
            if(toupper(key[i])=='T' || toupper(key[i])=='U' || toupper(key[i])=='V')
            {
                hash+="8";
            }
            if(toupper(key[i])=='W' || toupper(key[i])=='X' || toupper(key[i])=='Y' || toupper(key[i])=='Z')
            {
                hash+="9";
            }
        }
    }
    return hash;
}

/**
 * Gets hash, then calls recursive setPriorty function using root as an argument
 * @param word
 * @param priority
 */
void Trie::setPriority(string word, int priority)
{
    queue<int> hash = getHashQueue(word);
    if(hash.empty())
    {
        return;
    }
    else
    {
        setPriorityRec(root,word,priority,hash);
    }
}

/**
 * Sets the priority of a given word to move its place in a node's linked list.
 * @param node
 * @param word
 * @param priority
 * @param hashQueue
 */
void Trie::setPriorityRec(Node*& node, string word, int priority, queue<int> hashQueue)
{
    if(!node)
    {
        cout << "'" << word << "'" << " not found - cannot set priority.\n";
    }
    else
    {
        if(hashQueue.empty())
        {
            if(!node->head)
            {
                cout << "'" << word << "'" << " not found - cannot set priority.\n";
            }
            else
            {
                Link* temp = new Link;
                temp = node->head;
                while(temp)
                {
                    if(temp->word == word)
                    {
                        temp->priority = priority;
                        return;
                    }
                    temp = temp->next;
                }
            }
        }
        else
        {
            int val = hashQueue.front();
            hashQueue.pop();
            setPriorityRec(node->child[val],word,priority,hashQueue);
        }
    }
}

/**
 * Gets hash, then calls recursive prioritize function using root as an argument
 * @param word
 */
void Trie::prioritize(string word)
{
    queue<int> hash = getHashQueue(word);
    if(hash.empty())
    {
        return;
    }
    else
    {
        prioritizeRec(root,word,hash);
    }
}

/**
 * Moves the position of a given word to the head of a linked list
 * @param node
 * @param word
 * @param hashQueue
 */
void Trie::prioritizeRec(Node*& node, string word, queue<int> hashQueue)
{
    if(!node)
    {
        return;
    }
    else
    {
        if(hashQueue.empty())
        {
            if(!node->head)
            {
                cout << "'" << word << "'" << " not found - cannot prioritize.\n";
            }
            else if(node->head->word == word)
            {
                cout << "'" << word << "'" << " is already prioritized.\n";
            }
            else if(!node->head->next && node->head->word != word)
            {
                cout << "'" << word << "'" << " not found - cannot prioritize.\n";
            }
            else
            {
                Link* prev = new Link;
                prev = node->head;
                while(prev->next && prev->next->word != word)
                {
                    prev = prev->next;
                }
                if(prev->next->word == word)
                {
                    Link* moveFront = new Link;
                    moveFront = prev->next;
                    prev->next = moveFront->next;
                    moveFront->next = node->head;
                    node->head = moveFront;
                    node->head->priority = 0;
                }
                else
                {
                    cout << "'" << word << "'" << " not found - cannot prioritize.\n";
                }
            }
        }
        else
        {
            int val = hashQueue.front();
            hashQueue.pop();
            prioritizeRec(node->child[val],word,hashQueue);
        }
    }
}

/**
 * Gets hash, then calls recursive prioritize function using root as an argument
 * @param word
 */
void Trie::deprioritize(string word)
{
    queue<int> hash = getHashQueue(word);
    if(hash.empty())
    {
        return;
    }
    else
    {
        deprioritizeRec(root,word,hash);
    }
}

/**
 * Moves the position of a given word to the end of a linked list
 * @param node
 * @param word
 * @param hashQueue
 */
void Trie::deprioritizeRec(Node*& node, string word, queue<int> hashQueue)
{
    if(!node)
    {
        return;
    }
    else
    {
        if(hashQueue.empty())
        {
            if(!node->head)
            {
                cout << "'" << word << "'" << " not found - cannot deprioritize.\n";
            }
            else if(!node->head->next)
            {
                if(node->head->word != word)
                {
                    cout << "'" << word << "'" << " not found - cannot deprioritize.\n";
                }
                else
                {
                    cout << "'" << word << "'" << " already deprioritized.\n";
                }
            }
            else
            {
                Link* prev = new Link;
                prev = node->head;
                while(prev->next && prev->next->word != word)
                {
                    prev = prev->next;
                }
                if(prev->next->word == word)
                {
                    Link* moveBack = new Link;
                    moveBack = prev->next;
                    prev->next = moveBack->next;
                    while(moveBack)
                    {
                        moveBack = moveBack->next;
                    }
                    moveBack->next = NULL;
                }
                else
                {
                    cout << "'" << word << "'" << " not found - cannot deprioritize.\n";
                }
            }
        }
        else
        {
            int val = hashQueue.front();
            hashQueue.pop();
            deprioritizeRec(node->child[val],word,hashQueue);
        }
    }
}