#include<iostream>
#include "SkipList.h"
#include <bits/stdc++.h>
using namespace std;
SkipList::SkipList(int MAXLVL, float P)
{
    this->MAXLVL = MAXLVL;
    this->P = P;
    level = 0;
    header = new Node("", MAXLVL);
};
int SkipList::randomLevel()
{
    float r = (float)rand()/RAND_MAX;
    int lvl = 0;
    while (r < P && lvl < MAXLVL)
    {
        lvl++;
        r = (float)rand()/RAND_MAX;
    }
    return lvl;
};

Node* SkipList::createNode(char name[20], int level)
{
    Node *n = new Node(name, level);
    return n;
};

void SkipList::insertElement(char name[20])
{
    Node *current = header;
    Node *update[MAXLVL+1];
    memset(update, 0, sizeof(Node*)*(MAXLVL+1));
    for (int i = level; i >= 0; i--)
    {
        while (current->forward[i] != NULL && strcmp(current->forward[i]->getName(), name) < 0)
            current = current->forward[i];
        update[i] = current;
    }
    current = current->forward[0];
    if (current == NULL || strcmp(current->getName(), name) != 0)
    {

        int rlevel = randomLevel();
        if (rlevel > level)
        {
            for (int i=level+1;i<rlevel+1;i++)
                update[i] = header;
            level = rlevel;
        }
        Node* n = createNode(name, rlevel);
        for (int i=0;i<=rlevel;i++)
        {
            n->forward[i] = update[i]->forward[i];
            update[i]->forward[i] = n;
        }
    }
}
void SkipList::displayList()
{
    std::cout<<"\n_____________Skip List_____________\n\n";
    for (int i=0;i<=level;i++)
    {
        Node *node = header->forward[i];
        std::cout << "Level " << i << ": ";
        while (node != NULL)
        {
            std::cout << node->getName()<<" ";
            node = node->forward[i];
        }
        std::cout << "\n";
    }
}
void SkipList::deleteElement(char name[20])
{
    Node *current = header;

    // create update array and initialize it
    Node *update[MAXLVL+1];
    memset(update, 0, sizeof(Node*)*(MAXLVL+1));

    /*    start from highest level of skip list
        move the current pointer forward while key
        is greater than key of node next to current
        Otherwise inserted current in update and
        move one level down and continue search
    */
    for(int i = level; i >= 0; i--)
    {
        while(current->forward[i] != NULL  && strcmp(current->forward[i]->getName(),name)<0)
            current = current->forward[i];
        update[i] = current;
    }

    /* reached level 0 and forward pointer to
       right, which is possibly our desired node.*/
    current = current->forward[0];

    // If current node is target node
    if(current != NULL && strcmp(current->getName(),name)==0)
    {
        for(int i=0;i<=level;i++)
        {

            if(update[i]->forward[i] != current)
                break;

            update[i]->forward[i] = current->forward[i];
        }

        // Remove levels having no elements
        while(level>0 && header->forward[level] == 0)
            level--;
         cout<<"Successfully deleted key "<<name<<"\n";
    }
}
void SkipList::searchElement(char name[20])
{
    Node *current = header;
    for(int i = level; i >= 0; i--)
    {
        while(current->forward[i] && strcmp(current->forward[i]->getName(),name)<0)
            current = current->forward[i];

    }


    current = current->forward[0];

    // If current node have key equal to
    // search key, we have found our target node
    if(current && strcmp(current->getName(),name)==0)
        cout<<"Found key: "<<name<<"\n";
    else cout<<"No results";
};

