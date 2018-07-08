#include "HashMap.h"

#include <string>
#include <array>
#include <cstdint>
#include <iostream>

#include "HashMapNode.h"
#include "HashMapAlgos.h"

int default_compare(std::string a, std::string b) {
    return a == b;
}

HashMap::HashMap(Hashmap_compare compare, Hashmap_hash hash){
    this->compare = compare == NULL ? default_compare : compare;
    this->hash    = hash    == NULL ? hash_algos::default_hash : hash;
    this->buckets = new HashMapNode[DEFAULT_NUMBER_OF_BUCKETS]();
}

HashMap::HashMap()
{
    this->compare = default_compare;
    this->hash 	  = hash_algos::default_hash;
    this->buckets = new HashMapNode[DEFAULT_NUMBER_OF_BUCKETS]();
}

HashMapNode* HashMap::findBucket(std::string key, uint32_t *hash_out) {
    uint32_t hash = this->hash(key);
    int bucket_n = hash % DEFAULT_NUMBER_OF_BUCKETS;
    *hash_out = hash;

    HashMapNode *bucket = &this->buckets[bucket_n];

    return bucket;
}

void HashMap::setNode(std::string key, std::string data) {
    uint32_t hash = 0;
    HashMapNode *bucket = this->findBucket(key, &hash);
    bucket->hash = hash;
    bucket->key = key;
    bucket->data = data;
}

HashMapNode* HashMap::getNode(uint32_t hash, std::string key) {
    unsigned int i = 0;

    for (i = 0; i < DEFAULT_NUMBER_OF_BUCKETS; ++i) {
        HashMapNode *node = &this->buckets[i];
        if (node->hash == hash && this->compare(node->key, key)) {
            return node;
        }
    }

    return NULL;
}

HashMapNode* HashMap::getNode(std::string key) {
    unsigned int i = 0;

    for (i = 0; i < DEFAULT_NUMBER_OF_BUCKETS; ++i) {
        HashMapNode *node = &this->buckets[i];
        if (this->compare(node->key, key)) {
            return node;
        }
    }

    return NULL;
}

std::string HashMap::getData(std::string key) {
    uint32_t hash = 0;
    HashMapNode *bucket = this->findBucket(key, &hash);

    try {
        if (key.empty()) {
            throw new std::logic_error("The key you searched for shouldn't be empty");
        }

        if (bucket->key.empty() && bucket->hash == 0) {
            throw new std::logic_error("There isn't an element with such a key!");
        }
    } catch (std::logic_error& error) {
        std::cerr << error.what() << std::endl;
    }
    std::string data = bucket->data;

    return data;
}

int HashMap::traverse(Hashmap_traverse_cb traverse_cb) {
    int i = 0;
    int rc = 0;

    for (i = 0; i < DEFAULT_NUMBER_OF_BUCKETS; i++) {
        HashMapNode *bucket = &this->buckets[i];
        if(bucket) {
            rc = traverse_cb(bucket);
            if (rc != 0)
                return rc;
        }
    }

    return 0;
}

void HashMap::deleteNode(std::string key) {
    uint32_t hash = 0;
    HashMapNode *bucket = this->findBucket(key, &hash);

    bucket->key = "";
    bucket->data = "";
    bucket->hash = 0;
}

HashMap::~HashMap() {
    delete[] this->buckets;
}
