#include <iostream>

#include <string>
#include <array>

#include "HashMap.h"
#include "HashMapNode.h"
#include "HashMapAlgos.h"
#include "HashMapTests.h"

using namespace std;

int main()
{
    HashMap *map = createHashMap(default_compare, hash_algos::default_hash);
    testAlgos();
    testGetSet(map);
    testTraverse(map, traverseCallback);
    fillHashmaps();
    delete map;
}
