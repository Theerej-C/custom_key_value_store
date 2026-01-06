#ifndef NODE_H
#define NODE_H
#include <string>
struct Node
{
    std::string key;
    std::string value;
    Node *next;
};
#endif
