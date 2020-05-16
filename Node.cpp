#include "Node.h"
#include<iostream>
using namespace std;
Node::Node(char new_name[20], int level)
{
    setName(new_name);

    // Allocate memory to forward
    forward = new Node*[level+1];

    // Fill forward array with 0(NULL)
    memset(forward, 0, sizeof(Node*)*(level+1));
};
