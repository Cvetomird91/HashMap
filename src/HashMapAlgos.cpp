#include <string>
#include <cstdint>

//settings taken from
//http://www.isthe.com/chongo/tech/comp/fnv/index.html#FNV-param
const uint32_t FNV_PRIME = 16777619;
const uint32_t FNV_OFFSET_BASIS = 2166136261;
const int MOD_ADLER = 65521;

namespace hash_algos {

    uint32_t default_hash(const std::string &data) {
        size_t len = data.length();
        uint32_t hash = 0;
        uint32_t i = 0;

        for (hash = i = 0; i < len; ++i) {
            hash += data[i];
            hash += (hash << 10);
            hash ^= (hash >> 6);
        }

        hash += (hash << 3);
        hash ^= (hash >> 11);
        hash += (hash << 15);

        return hash;
    }

    uint32_t fnv1a_hash(const std::string &data) {
        uint32_t hash = FNV_OFFSET_BASIS;
        unsigned int i = 0;

        for (i = 0; i < data.length(); ++i) {
            hash ^= data[i];
            hash *= FNV_PRIME;
        }

        return hash;
    }

    uint32_t adler32_hash(const std::string &data) {
        uint32_t a = 1, b = 0;
        unsigned int i = 0;

        for (i = 0; i < data.length(); i++) {
            a = (a + data[i]) % MOD_ADLER;
            b = (b + a) % MOD_ADLER;
        }

        return (b << 16) | a;
    }

    uint32_t djb_hash(const std::string &data) {
        uint32_t hash = 5381;
        unsigned int i = 0;

        for (i = 0; i < data.length(); ++i) {
            hash = ((hash << 5) + hash) + data[i];
        }

        return hash;
    }

    uint32_t sdbm_hash(const std::string &data) {
        uint32_t hash = 0;
        unsigned int i = 0;

        for (i = 0; i < data.length(); i++) {
            hash = data[i] + (hash << 6) + (hash << 16) - hash;
        }

        return hash;
    }

    uint32_t lose_hash(const std::string &data) {
        uint32_t hash = 0;
        unsigned int i = 0;

        for (i = 0; i < data.length(); i++) {
            hash += (int)data.at(i);
        }

        return hash;
    }

    uint32_t js_hash(const std::string &data) {
        uint32_t hash = 1315423911;
        unsigned int i = 0;

        for (i = 0; i < data.length(); i++)
        {
            hash ^= ((hash << 5) + data[i] + (hash >> 2));
        }

        return hash;
    }

    uint32_t elf_hash(const std::string &data) {
        uint32_t hash = 0;
        unsigned int x = 0;
        unsigned int i = 0;

        for (i = 0; i < data.length(); ++i)
        {
            hash = (hash << 4) + data[i];

            if ((x = hash & 0xF0000000L) != 0)
            {
                hash ^= (x >> 24);
            }

            hash &= ~x;
        }

        return hash;
    }

    uint32_t bkdr_hash(const std::string &data) {
        uint32_t seed = 131;
        uint32_t hash = 0;
        uint32_t i    = 0;

        for (i = 0; i < data.size(); ++i) {
            hash = (hash * seed) + data[i];
        }

        return hash;
    }

    uint32_t rs_hash(const std::string &data) {
        uint32_t b = 378551;
        uint32_t a = 63689;
        uint32_t hash = 0;
        uint32_t i = 0;

        for (i = 0; i < data.length(); ++i) {
            hash = hash * a + (int)data.at(i);
            a    = a * b;
        }

        return hash;
    }

    uint32_t pjw_hash(const std::string &data) {
        const uint32_t BitsInUnsignedInt = (uint32_t)(sizeof(uint32_t) * 8);
        const uint32_t ThreeQuarters     = (uint32_t)((BitsInUnsignedInt  * 3) / 4);
        const uint32_t OneEighth         = (uint32_t)(BitsInUnsignedInt / 8);
        const uint32_t HighBits          =
                      (uint32_t)(0xFFFFFFFF) << (BitsInUnsignedInt - OneEighth);

        uint32_t hash = 0;
        uint32_t test = 0;
        uint32_t i    = 0;

        for (i = 0; i < data.length(); ++i) {
            hash = (hash << OneEighth) + data[i];

            if ((test = hash & HighBits) != 0) {
                    hash = (( hash ^ (test >> ThreeQuarters)) & (~HighBits));
            }
        }

        return hash;
    }

    uint32_t dek_hash(const std::string &data) {
        uint32_t hash = data.length();
        uint32_t i        = 0;

        for (i = 0; i < data.length(); ++i) {
            hash = ((hash << 5) ^ (hash >> 27)) ^ (int)data[i];
        }

        return hash;

    }

};
