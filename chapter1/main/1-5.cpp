#include <iostream>
#include <string>

using namespace std;

namespace Solution {
class Solver {
public:
  string run_length_compress(string s) {
    int n = (int)s.size();
    pair<char, int> p = {s[0], 1};
    int ptr = 1;
    string ans;
    while (ptr < n) {
      if (p.first == s[ptr]) {
        p.second++;
      } else {
        ans += p.first;
        ans += to_string(p.second);
        p.second = 1;
      }
      p.first = s[ptr];
      ptr++;
    }
    ans += p.first;
    ans += to_string(p.second);
    return ans;
  }
};
} // namespace Solution

int main() {
  Solution::Solver *sol = new Solution::Solver();
  cout << sol->run_length_compress("aabcccccaaa") << endl;
}
