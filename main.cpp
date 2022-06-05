#include <iostream>
#include <vector>
#include <string>
#include <tuple>
#include <unordered_map>
#include "solution.h"
#include "util.h"

using namespace std;
using namespace sol23;

/*
Input:
[
  1->4->5,
  1->3->4,
  2->6
]
Output: 1->1->2->3->4->4->5->6
*/

tuple<vector<Node *>, string>
testFixture1()
{
  auto input = vector<Node *>();
  auto l1 = new Node(1);
  l1->next = new Node(4);
  l1->next->next = new Node(5);
  input.push_back(l1);
  auto l2 = new Node(1);
  l2->next = new Node(3);
  l2->next->next = new Node(4);
  input.push_back(l2);
  auto l3 = new Node(2);
  l3->next = new Node(6);
  input.push_back(l3);

  return make_tuple(input, "1->1->2->3->4->4->5->6");
}

void test1()
{
  auto f = testFixture1();
  Solution sol;

  cout << "Expect to see : " << get<1>(f) << endl;

  auto l = sol.mergeKLists(get<0>(f));
  string s;

  while (l != nullptr)
  {
    s += to_string(l->val) + "->";
    l = l->next;
  }

  if (s.back() == '>')
    s.pop_back(), s.pop_back();

  cout << s << endl;
}

main()
{
  test1();

  return 0;
}