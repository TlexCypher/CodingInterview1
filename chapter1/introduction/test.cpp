#include "./hashtable_with_linked_list.cpp"

using namespace std;

int main() {
  HashTable::_HashTableWithLinkedList hashtable(3);
  hashtable.put("araki", "taichi");
  hashtable.put("minagawa", "kei");
  hashtable.put("imada", "kakeru");
  hashtable.put("mito", "ayaka");
  hashtable.put("ozeki", "saki");
  hashtable.put("kimura", "ryota");

  cout << hashtable.get("araki") << endl;
  cout << hashtable.get("minagawa") << endl;
  cout << hashtable.get("imada") << endl;
  cout << hashtable.get("mito") << endl;
  cout << hashtable.get("ozeki") << endl;
  cout << hashtable.get("kimura") << endl;
}
