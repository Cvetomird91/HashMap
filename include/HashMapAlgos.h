#ifndef HASHMAPALGOS_H_INCLUDED
#define HASHMAPALGOS_H_INCLUDED

#include <string>
#include <cstdint>

namespace hash_algos {
    uint32_t default_hash(const std::string &data);
    uint32_t fnv1a_hash(const std::string &data);
    uint32_t adler32_hash(const std::string &data);
    uint32_t djb_hash(const std::string &data);
    uint32_t sdbm_hash(const std::string &data);
    uint32_t lose_hash(const std::string &data);
    uint32_t js_hash(const std::string &data);
    uint32_t elf_hash(const std::string &data);
    uint32_t bkdr_hash(const std::string &data);
    uint32_t rs_hash(const std::string &data);
    uint32_t pjw_hash(const std::string &data);
    uint32_t dek_hash(const std::string &data);
};

#endif // HASHMAPALGOS_H_INCLUDED
