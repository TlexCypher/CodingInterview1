#include <iostream>
#include <set>
#include <vector>

using namespace std;

namespace Solution {
class Solver {
public:
  void fill_zero(vector<vector<int>> &grid) {
    int m = grid.size();
    int n = grid[0].size();
    set<pair<int, int>> have_zeros;
    for (int i = 0; i < m; i++) {
      for (int j = 0; j < n; j++) {
        if (grid[i][j] == 0) {
          have_zeros.insert(make_pair(i, j));
        }
      }
    }
    for (pair<int, int> p : have_zeros) {
      int i = p.first;
      int j = p.second;
      fill_zero_helper(grid, i, j);
    }
  }

  void fill_zero_helper(vector<vector<int>> &grid, int i, int j) {
    int h = grid.size();
    int w = grid[0].size();
    for (int pj = 0; pj < w; pj++) {
      grid[i][pj] = 0;
    }
    for (int pi = 0; pi < h; pi++) {
      grid[pi][j] = 0;
    }
  }
};
} // namespace Solution

int main() {
  int h = 4;
  int w = 3;
  vector<vector<int>> grid(4, vector<int>(3, 0));
  for (int i = 0; i < h; i++) {
    for (int j = 0; j < w; j++) {
      if ((i * w + j) % 9 == 0) {
        continue;
      }
      grid[i][j] = i * w + j;
    }
  }
  for (int i = 0; i < h; i++) {
    for (int j = 0; j < w; j++) {
      cout << grid[i][j] << " ";
    }
    cout << endl;
  }
  cout << endl;
  Solution::Solver *sol = new Solution::Solver();
  sol->fill_zero(grid);
  for (int i = 0; i < h; i++) {
    for (int j = 0; j < w; j++) {
      cout << grid[i][j] << " ";
    }
    cout << endl;
  }
}
