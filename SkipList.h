#ifndef SKIPLIST_H_INCLUDED
#define SKIPLIST_H_INCLUDED
#include "Node.h"
class SkipList
{
    int MAXLVL;
    float P;
    int level;
    Node *header;
public:
    SkipList(int, float);
    int randomLevel();
    Node* createNode(char name[20], int);
    void insertElement(char name[20]);
    void displayList();
    void deleteElement(char name[20]);
    void searchElement(char name[20]);
};


#endif // SKIPLIST_H_INCLUDED
