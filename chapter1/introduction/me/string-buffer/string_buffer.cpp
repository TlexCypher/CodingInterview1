#include <cstring>
#include <iostream>
#include <string>

using namespace std;

namespace StringBuffer {
class StringBuffer {
private:
  char *buffer_;
  /* include null character. */
  int size_;

  void _append(char c) {
    char *tmp = new char[size_];
    strcpy(tmp, buffer_);
    buffer_ = new char[size_ + 1];
    strcpy(buffer_, tmp);
    buffer_[size_ - 1] = c;
    buffer_[size_] = '\0';
    size_++;
    delete[] tmp;
  }

public:
  StringBuffer() {}
  StringBuffer(string s) {
    int length = s.size();
    buffer_ = new char(length + 1);
    for (int i = 0; i < length; i++) {
      buffer_[size_ + i] = s[i];
    }
    buffer_[size_ + length] = '\0';
    size_ += length + 1;
  }

  void append(string s) {
    for (int i = 0; i < (int)s.size(); i++) {
      _append(s[i]);
    }
  }

  void erase(int n) {
    int t = size_ - n - 1;
    if (t < 0) {
      t = 0;
    }
    char *tmp = new char[t + 1];
    strncpy(tmp, buffer_, t);
    tmp[t] = '\0';
    buffer_ = new char[t + 1];
    strcpy(buffer_, tmp);
    delete[] tmp;
  }

  void print() { printf("%s\n", buffer_); }
};
} // namespace StringBuffer
