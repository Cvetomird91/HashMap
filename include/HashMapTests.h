#ifndef HASHMAPTESTS_H_INCLUDED
#define HASHMAPTESTS_H_INCLUDED

#include <string>
#include <array>

#include "HashMap.h"

int traverse_called;

HashMap* createHashMap(Hashmap_compare compare, Hashmap_hash hash);
int testSet(HashMap *map);
std::string generateRandomString(int len);
void testSetNode(uint32_t hash, std::string key);

#endif // HASHMAPTESTS_H_INCLUDED
