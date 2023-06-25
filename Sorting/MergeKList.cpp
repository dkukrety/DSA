#include <iostream>
#include <vector>
#include <bits/stdc++.h>
using namespace std;
/*

For your reference:
class LinkedListNode {
    public:
        int value;
        LinkedListNode *next;

        LinkedListNode(int value) {
            this->value = value;
            this->next = nullptr;
        }
};

LinkedListNode *merge_k_lists(vector<LinkedListNode*> &lists) {
    // Write your code here.
    // we need to use min-heap of k size and then remove one minimum element one by one
    // and store in output list.

    return nullptr;
}
==========================
another logic is to find minmium of element in list[i]
and then incrementing only that pointer...

finding minimum in k list is o(k)
doing it for n lenght is nk
and doing it for k lists is nkk so time complexity
is high here..

===========================

=========Logic using merging list and min heap===
Logic is to have min heap of k size....
for i --> len(lists)
   minheap.insert(list[i].value, list[i].next)

while(minheap is not empty)
  extracMin.
  add tailpointer,
  add tailpointer->next to minheap.
complexity --> nklogk

extracting min is o(1)
adding is o(logk)
adding n elements is nlogk
doing it for k lists is knlogk

==========================


*/

class LinkedListNode
{
public:
    int value;
    LinkedListNode *next;

    LinkedListNode(int value)
    {
        this->value = value;
        this->next = nullptr;
    }
};

struct compare
{
    bool operator()(
        LinkedListNode *a, LinkedListNode *b)
    {
        return a->value > b->value;
    }
};

LinkedListNode *merge_k_lists(vector<LinkedListNode *> &lists)
{
    // Write your code here.
    // we need to use min-heap of k size and then remove one minimum element one by one
    // and store in output list.

    priority_queue<LinkedListNode *, vector<LinkedListNode *>, compare> pq;

    for (int i = 0; i < lists.size() i++)
    {
        if (lists[i] != nullptr)
            pq.push(lists[i]);
    }

    return nullptr;
}

int main()
{
    LinkedListNode *l1 = {{}}
    return 0;
}