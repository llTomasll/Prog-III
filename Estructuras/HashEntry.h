#ifndef U05_HASH_HASHMAP_HASHENTRY_H_
#define U05_HASH_HASHMAP_HASHENTRY_H_

template <class K, class T> class HashEntry {
private:
  K key;
  T dato;

public:
  HashEntry(K key, T dato) : key(key), dato(dato) {}
  K getKey() const { return key; }
  void setKey(K key) { HashEntry::key = key; }
  T getDato() const { return dato; }
  void setDato(T dato) { HashEntry::dato = dato; }

  bool operator==(const HashEntry &rhs) const { return key == rhs.key; }
  bool operator!=(const HashEntry &rhs) const { return !(rhs == *this); }

  bool operator<(const HashEntry &rhs) const { return key < rhs.key; }
  bool operator>(const HashEntry &rhs) const { return rhs < *this; }
  bool operator<=(const HashEntry &rhs) const { return !(rhs < *this); }
  bool operator>=(const HashEntry &rhs) const { return !(*this < rhs); }
};

#endif // U05_HASH_HASHMAP_HASHENTRY_H_
