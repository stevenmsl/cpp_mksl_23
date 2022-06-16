#include "solution.h"
#include "util.h"
#include <unordered_set>
#include <numeric>
#include <iterator>
#include <unordered_map>
#include <queue>
#include <string>
#include <sstream>
#include <algorithm>
#include <stack>
#include <functional>
using namespace sol23;
using namespace std;

/*takeaways
  - use a minHeap that will have at most k items at a given time
  - since each list is sorted, the one on the top of the heap
    will be the smallest one in the remaining numbers among
    k lists to be added to the resulting list
  - Every time you insert a number to the min-heap the time
    complexity is O(logk). Since every number will be in the
    queue exactly once, the time complexity is O(nlogk)
*/
Node *Solution::mergeKLists(vector<Node *> &lists)
{
  /* define a greater comparer as we need a min-heap  */
  auto comp = [](Node *a, Node *b)
  {
    return a->val > b->val;
  };

  /* min-heap */
  auto q = priority_queue<Node *, vector<Node *>, decltype(comp)>(comp);

  auto dummyHead = new Node(-1);

  /* push the head of each list into the queue
     - since we k lists so the queue now has
       k items
  */
  for (auto l : lists)
    q.push(l);

  auto cur = dummyHead;
  while (!q.empty())
  {
    /*continue picking the smallest value
      among the k lists
    */
    auto next = q.top();
    q.pop();

    cur->next = next;
    cur = cur->next;
    if (cur->next != nullptr)
      q.push(cur->next);
  }
  return dummyHead->next;
}