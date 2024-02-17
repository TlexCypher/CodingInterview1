#include "./hashtable.cpp"

using namespace std;

int main() {
  HashTable::HashTable *hashtable = new HashTable::HashTable(3);
  hashtable->put("araki", "taichi");
  hashtable->put("imada", "kakeru");
  hashtable->put("minagawa", "kei");
  hashtable->put("kimura", "ryota");
  hashtable->put("mito", "ayaka");
  hashtable->put("ozeki", "saki");

  cout << hashtable->get("araki") << endl;
  cout << hashtable->get("imada") << endl;
  cout << hashtable->get("minagawa") << endl;
  cout << hashtable->get("kimura") << endl;
  cout << hashtable->get("mito") << endl;
  cout << hashtable->get("ozeki") << endl;
}
