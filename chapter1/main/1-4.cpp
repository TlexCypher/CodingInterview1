#include <cstdio>

using namespace std;

namespace Solution {
class Solver {
public:
  char *replace_space(char *str, int length) {
    int space_count = 0;
    for (int i = 0; i < length; i++) {
      if (str[i] == ' ') {
        space_count++;
      }
    }
    int new_length = space_count * 2 + length;
    char *new_str = new char[new_length + 1];
    new_str[new_length] = '\0';
    int ptr = length - 1;
    while (ptr >= 0) {
      if (str[ptr] == ' ') {
        new_str[new_length - 1] = '0';
        new_length--;
        new_str[new_length - 1] = '2';
        new_length--;
        new_str[new_length - 1] = '%';
        new_length--;
      } else {
        new_str[new_length - 1] = str[ptr];
        new_length--;
      }
      ptr--;
    }
    return new_str;
  }
};
} // namespace Solution

int main() {
  Solution::Solver *sol = new Solution::Solver();
  char *arr = new char[20];
  arr[0] = 'A';
  arr[1] = 'B';
  arr[2] = 'C';
  arr[3] = ' ';
  arr[4] = 'D';
  arr[5] = ' ';
  arr[6] = ' ';
  arr[7] = ' ';
  arr[8] = 'E';
  arr[9] = ' ';
  arr[10] = 'F';
  arr[11] = 'G';
  arr[12] = ' ';
  arr[13] = ' ';
  arr[14] = 'H';
  arr[15] = ' ';
  arr[16] = 'I';
  arr[17] = ' ';
  printf("%s\n", sol->replace_space(arr, 17));
  delete[] arr;
}
