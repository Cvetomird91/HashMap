#ifndef HASHMAPALGOS_H_INCLUDED
#define HASHMAPALGOS_H_INCLUDED

#include <string>
#include <cstdint>

namespace hash_algos {
    uint32_t default_hash(std::string data);
    uint32_t fnv1a_hash(std::string data);
    uint32_t adler32_hash(std::string data);
    uint32_t djb_hash(std::string data);
    uint32_t sdbm_hash(std::string data);
    uint32_t lose_hash(std::string data);
    uint32_t js_hash(std::string data);
    uint32_t elf_hash(std::string data);
    uint32_t bkdr_hash(std::string data);
};

#endif // HASHMAPALGOS_H_INCLUDED
