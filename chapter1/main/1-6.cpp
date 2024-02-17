#include <iostream>
#include <vector>

using namespace std;

namespace Solution {
class Solver {
public:
  vector<vector<int>> easy_rotate_right_90(vector<vector<int>> &grid) {
    int h = grid.size();
    int w = grid[0].size();

    vector<vector<int>> tmp(h, vector<int>(w));
    for (int i = 0; i < h; i++) {
      for (int j = 0; j < w; j++) {
        int ni = j;
        int nj = h - i - 1;
        tmp[ni][nj] = grid[i][j];
      }
    }
    return tmp;
  }
  void hard_rotate_right_90(vector<vector<int>> &grid) {
    int h = grid.size();
    int w = grid[0].size();
    /*Transpose*/
    for (int i = 0; i < h; i++) {
      for (int j = i + 1; j < w; j++) {
        swap(grid[i][j], grid[j][i]);
      }
    }

    /*Flip*/
    for (int i = 0; i < h; i++) {
      int l = 0;
      int r = w - 1;
      while (l < r) {
        swap(grid[i][l], grid[i][r]);
        l++;
        r--;
      }
    }
  }
};
} // namespace Solution

int main() {
  Solution::Solver *sol = new Solution::Solver();
  vector<vector<int>> test(3, vector<int>(3));

  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      test[i][j] = i * 3 + j + 1;
    }
  }

  /* test = sol->easy_rotate_right_90(test); */
  sol->hard_rotate_right_90(test);
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      cout << test[i][j] << " ";
    }
    cout << endl;
  }
}
