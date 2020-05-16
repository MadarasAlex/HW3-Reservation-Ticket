#ifndef NODE_H_INCLUDED
#define NODE_H_INCLUDED
#include<iostream>
#include<cstring>
using namespace std;
class Node{
    private:

        char name[20];

    public:

        char * getName(){
            return name;
        }

        void setName(char * new_name){
            strcpy(this->name, new_name);
        }

    // Hold pointers to node of different level
    Node **forward;
    Node(char name[20] = "", int level = 0);
};


#endif // NODE_H_INCLUDED
