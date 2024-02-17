#include "./string_buffer.cpp"

using namespace std;

int main() {
  StringBuffer::StringBuffer *sb = new StringBuffer::StringBuffer("Taichi");
  sb->append(" ");
  sb->append("Araki");
  sb->print();
  sb->erase(6);
  sb->print();
}
