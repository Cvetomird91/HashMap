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
void testGetSet(HashMap* map);
void testTraverse(HashMap* map, Hashmap_traverse_cb traverse_cb);
int traverseCallback(HashMapNode* node);
void testDeleteNode(HashMap* map);
void fillHashmaps();

#endif // HASHMAPTESTS_H_INCLUDED
