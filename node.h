#ifndef NODE_H
#define NODE_H

#include <vector>
#include <cinttypes>
using namespace std;

namespace sol23
{
    struct Node
    {
        int val;
        Node *next;
        Node(int val) : val(val), next(nullptr){};
    };
}
#endif