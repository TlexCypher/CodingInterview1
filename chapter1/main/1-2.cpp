#include <cstring>
#include <iostream>
#include <utility>

/*
 * Problem Statement
 *
 * In C/C++, can you implement algorithm that can reverse string ?
 *
 * Time and space complexity would be written below.
 *
 * Test is written in main function;
 * */

using namespace std;

/* Time complexity is O(N), space complexity is O(1)*/
namespace Solution {
class Solver {
private:
public:
  Solver() {}
  char *reverse(char *str) {
    unsigned int head = 0;
    unsigned int tail = 0;
    while (str[tail + 1] != '\0') {
      tail++;
    }
    while (head < tail) {
      swap(str[head], str[tail]);
      head++;
      tail--;
    }
    return str;
  }
};
} // namespace Solution

int main() {
  Solution::Solver *sol = new Solution::Solver();
  char *str = new char[6];
  str[0] = 'H';
  str[1] = 'e';
  str[2] = 'l';
  str[3] = 'l';
  str[4] = 'o';
  str[5] = '\0';
  cout << sol->reverse(str) << endl;
  delete[] str;
}
