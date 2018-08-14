#ifndef HASHMAP_H
#define HASHMAP_H

#include <string>
#include <array>

#include "HashMapNode.h"

#define DEFAULT_NUMBER_OF_BUCKETS 100

typedef int (*Hashmap_compare) (const std::string &a, const std::string &b);
typedef uint32_t (*Hashmap_hash) (const std::string &key);
typedef int (*Hashmap_traverse_cb) (HashMapNode *node);

class HashMap
{
    public:
        HashMap();
        HashMap(Hashmap_compare compare, Hashmap_hash hash);
        uint32_t setNode(const std::string &key, const std::string &data);
        HashMapNode* getNode(uint32_t hash, const std::string &key);
        HashMapNode* getNode(const std::string &key);
        std::string getData(const std::string &key);
        int traverse(Hashmap_traverse_cb traverse_cb);
        void deleteNode(const std::string &key);
        HashMapNode *buckets;
        ~HashMap();

    private:
        HashMapNode *findBucket(const std::string &key, uint32_t* hash_out);
        Hashmap_compare compare;
        Hashmap_hash    hash;
};

#endif // HASHMAP_H

int default_compare(const std::string &a, const std::string &b);
