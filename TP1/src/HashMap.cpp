#include "HashMap.h"

using namespace std;

const int HashMap::TABLE_SIZE = 50;

HashMap::~HashMap() {
    // destroy all buckets one by one
    for (int i = 0; i < TABLE_SIZE; ++i) {
        HashNode *entry = table[i];
        while (entry != NULL) {
            HashNode *prev = entry;
            entry = entry->getNext();
            delete prev;
        }
        table[i] = NULL;
    }
    // destroy the hash table
    delete [] table;
}

bool HashMap::get(const std::string &key, int &value) {
    int hashValue = hashFunc(key);
    HashNode *entry = table[hashValue];

    while (entry != NULL) {
        if (entry->getKey() == key) {
            value = entry->getValue();
            return true;
        }
        entry = entry->getNext();
    }
    return false;
}

void HashMap::put(const std::string &key, const int &value) {
    int hashValue = hashFunc(key);
    HashNode *prev = NULL;
    HashNode *entry = table[hashValue];

    while (entry != NULL && entry->getKey() != key) {
        prev = entry;
        entry = entry->getNext();
    }

    if (entry == NULL) {
        entry = new HashNode(key, value);
        if (prev == NULL) {
            // insert as first bucket
            table[hashValue] = entry;
        } else {
            prev->setNext(entry);
        }
    } else {
        // just update the value
        entry->setValue(value);
    }
}

void HashMap::remove(const std::string &key) {
    int hashValue = hashFunc(key);
    HashNode *prev = NULL;
    HashNode *entry = table[hashValue];

    while (entry != NULL && entry->getKey() != key) {
        prev = entry;
        entry = entry->getNext();
    }

    if (entry == NULL) {
        // key not found
        return;
    } else {
        if (prev == NULL) {
            // remove first bucket of the list
            table[hashValue] = entry->getNext();
        } else {
            prev->setNext(entry->getNext());
        }
        delete entry;
    }
}

int HashMap::compteur(const std::string &key){
    int valeur = 0;
    if(!get(key,valeur))
        put(key,1);
    else
        put(key,++valeur);
    return valeur;
}

void HashMap::shallow_copy(HashNode** data){
    
    for(int i=0;i<TABLE_SIZE;i++){
        table[i]=data[i];
    }
    
}

std::vector<std::string> HashMap::getKeys() const{
  std::vector<std::string> res;
  
  for(int i=0;i<TABLE_SIZE;i++){
    HashNode *entry = table[i];
    
    while (entry != NULL) {
      res.push_back(entry->getKey());
      entry = entry->getNext();
    }
  }

  return res;
}
