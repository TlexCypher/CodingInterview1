#include <algorithm>
#include <iostream>
#include <map>

using namespace std;

/*
 * Problem Statement
 *
 * When it comes to grab two strings, would you identify whether they are
 * anagrams ?
 *
 *
 * Time and space complexity would be written below.
 *
 * Test is written in main function;
 * */

namespace Solution {
class Solver1 {
public:
  bool is_anagram(string s1, string s2) {
    sort(s1.begin(), s1.end());
    sort(s2.begin(), s2.end());
    cout << (s1 == s2 ? "Not Unique" : "Unique") << endl;
    return s1 == s2;
  }
};
} // namespace Solution

namespace Solution {
class Solver2 {
public:
  bool is_anagram(string s1, string s2) {
    if (s1.size() != s2.size()) {
      cout << "Not Unique." << endl;
      return false;
    }
    map<char, int> mp1;
    map<char, int> mp2;
    for (int i = 0; i < (int)s1.size(); i++) {
      mp1[s1[i]]++;
      mp2[s2[i]]++;
    }
    cout << (mp1 == mp2 ? "Not Unique." : "Unique.") << endl;
    return mp1 == mp2;
  }
};
} // namespace Solution

int main() {
  Solution::Solver1 *sol1 = new Solution::Solver1();
  Solution::Solver2 *sol2 = new Solution::Solver2();
  sol1->is_anagram("Taichi", "aiThic");
  sol1->is_anagram("Taichi", "aithic");
  sol2->is_anagram("Taichi", "aiThic");
  sol2->is_anagram("Taichi", "aithic");
}
