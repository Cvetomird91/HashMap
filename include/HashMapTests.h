#ifndef HASHMAPTESTS_H_INCLUDED
#define HASHMAPTESTS_H_INCLUDED

#include <string>
#include <array>
#include <cassert>
#include <map>

#include "HashMap.h"

HashMap* createHashMap(Hashmap_compare compare, Hashmap_hash hash);
std::string generateRandomString(int len);
void testAlgos();
void testSetNode(HashMap* map, std::string key, std::string value);

#endif // HASHMAPTESTS_H_INCLUDED
