#include "HashMapNode.h"

HashMapNode::HashMapNode(int hash, const std::string &key, const std::string &data)
{
    this->key = key;
    this->data = data;
    this->hash = hash;
}

HashMapNode::HashMapNode() {

}
