#ifndef HASH_MAP_H
#define HASH_MAP_H
#include <vector>
#include <string>
#include "node.h"
class HashMap
{
private:
    int bucket_size;
    std::vector<Node *> buckets;
    unsigned int hash_function(const std::string &key) const;

public:
    ~HashMap();
    explicit HashMap(int bucket_size);

    bool get(const std::string &key, std::string &value) const;
    void put(const std::string &key, const std::string &value);
    const std::vector<Node *> &get_buckets() const;
};
#endif