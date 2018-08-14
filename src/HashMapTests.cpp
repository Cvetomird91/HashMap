#include <string>
#include <array>
#include <cassert>
#include <iostream>

#include "HashMap.h"
#include "HashMapAlgos.h"
#include "HashMapTests.h"

#define ALGOS_COUNT 11

static int traverse_called = 0;

uint32_t (*algos[])(const std::string&) = {
    hash_algos::default_hash,
    hash_algos::fnv1a_hash,
    hash_algos::adler32_hash,
    hash_algos::djb_hash,
    hash_algos::sdbm_hash,
    hash_algos::lose_hash,
    hash_algos::js_hash,
    hash_algos::elf_hash,
    hash_algos::bkdr_hash,
    hash_algos::rs_hash,
    hash_algos::pjw_hash,
    hash_algos::dek_hash
};

HashMap* createHashMap(Hashmap_compare compare, Hashmap_hash hash) {
    HashMap* hashmap = new HashMap(compare, hash);

    assert(hashmap != NULL && "Hashmap didn't instantiate properly");
    return hashmap;
}

int traverseCallback(HashMapNode* node) {
    traverse_called++;
    return 0;
}

std::string generateRandomString(int len) {
    std::string alphanum =
        "0123456789"
        "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
        "abcdefghijklmnopqrstuvwxyz";

    std::string random_string;

    for (int i = 0; i < len; ++i) {
        random_string += alphanum[rand() & (sizeof(alphanum) - 1)];
    }

    return random_string;

}

void testAlgos() {
    int i = 0;
    int y = 0;

    std::array<std::string, 5> keys;

    for (y = 0; y < 5; ++y) {
        keys[y] = generateRandomString(5);
    }

    for (i = 0; i < ALGOS_COUNT; ++i) {
        uint32_t hash;

        for (y = 0; y < 5; ++y) {
            hash = algos[i](keys[y]);
            assert(hash != 0 && "Bad hash.");
        }
    }
}

void testGetSet(HashMap* map) {
    for (int i = 0; i < DEFAULT_NUMBER_OF_BUCKETS; ++i) {
        uint32_t hash;
        std::string key = generateRandomString(5);
        std::string data = generateRandomString(10);

        hash = map->setNode(key, data);

        HashMapNode* node = map->getNode(hash, key);

        assert(node != NULL && "Node didn't set properly!");
    }
}

void testTraverse(HashMap* map, Hashmap_traverse_cb traverse_cb) {
    map->traverse(traverse_cb);
}

void fillHashmaps() {
    for (int i = 0; i < ALGOS_COUNT; ++i) {
        HashMap* map = new HashMap(default_compare, algos[i]);
        testGetSet(map);
        delete map;
    }
}
