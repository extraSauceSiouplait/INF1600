#include "SomeKeyHash.h"

using namespace std;

SomeKeyHash::SomeKeyHash(const int& m):modu(m){}
    
int SomeKeyHash::operator()(const std::string& s) const {
  return hash(s.c_str()) % modu;
}

unsigned long SomeKeyHash::hash(const char *str) const {
        unsigned long hash = 5381;
        int c;

        while (c = *str++)
            hash = ((hash << 5) + hash) + c; /* hash * 33 + c */

        return hash;
}
