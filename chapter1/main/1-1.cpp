#include <algorithm>
#include <iostream>
#include <set>
#include <string>

using namespace std;

/*
 * Problem Statement
 *
 * Implement the algorithm that you can identify whether the string is unique or
 * not. And if you can't use any other data structure, what would you do ?
 *
 * Solution Overview
 *
 * 1. Use set.
 * 2. Double pointer and sort.
 *
 * Time and space complexity would be written below.
 *
 * Test is written in main function;
 * */

namespace Solution {
/*Time complexity: O(N) Space complexity: O(N)*/
class Easy {
private:
  string target_;
  unsigned int n_;
  set<char> used_char_;

public:
  Easy(string s) {
    target_ = s;
    n_ = (unsigned int)s.size();
  }
  bool is_unique() {
    for (unsigned int i = 0; i < n_; i++) {
      if (used_char_.count(target_[i])) {
        cout << "Not Unique." << endl;
        return false;
      }
      used_char_.insert(target_[i]);
    }
    cout << "Unique." << endl;
    return true;
  }
};

class Hard {
  /*Time complexity: O(N(log N)) Space complexity: O(1)*/
private:
  string target_;
  unsigned int n_;

public:
  Hard(string s) {
    target_ = s;
    n_ = (unsigned int)s.size();
  }

  bool is_unique() {
    if (n_ > 26) {
      cout << "Not Unique." << endl;
      return false;
    }
    sort(target_.begin(), target_.end());

    for (unsigned int ptr1 = 0; ptr1 < n_ - 1; ptr1++) {
      unsigned int ptr2 = ptr1 + 1;
      if (target_[ptr1] == target_[ptr2]) {
        cout << "Not Unique." << endl;
        return false;
      }
    }
    cout << "Unique." << endl;
    return true;
  }
};
} // namespace Solution

int main() {
  /* */
  Solution::Easy *solution = new Solution::Easy("taichi");
  solution->is_unique();
  Solution::Hard *solution2 = new Solution::Hard("aiueo");
  solution2->is_unique();
}
