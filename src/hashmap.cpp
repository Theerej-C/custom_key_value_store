#include "hashmap.h"
#include <string>
HashMap::HashMap(int size) : bucket_size(size), buckets(size, nullptr) {}

HashMap::~HashMap()
{
    for (auto &head : buckets)
    {
        while (head)
        {
            Node *temp = head;
            head = head->next;
            delete temp;
        }
    }
}

unsigned int HashMap::hash_function(const std::string &key) const
{
    unsigned int size = (unsigned int)bucket_size;
    unsigned int hash = 0;
    for (char c : key)
    {
        hash += (unsigned int)(c);
    }
    return hash % size;
}

bool HashMap::get(const std::string &key, std::string &value) const
{

    unsigned int hash = hash_function(key);
    Node *initial_hash = buckets[hash];
    while (initial_hash)
    {
        if (initial_hash->key == key)
        {
            value = initial_hash->value;
            return true;
        }
        initial_hash = initial_hash->next;
    }
    return false;
}

void HashMap::put(const std::string &key, const std::string &value)
{
    unsigned int hash = hash_function(key);
    if (this->buckets[hash])
    {
        Node *present_node = buckets[hash];
        while (present_node != nullptr)
        {
            if (present_node->key == key)
            {
                present_node->value = value;
                return;
            }
            present_node = present_node->next;
        }
    }
    else
    {
        Node *node = new Node{key, value, nullptr};
        buckets[hash] = node;
    }
}

const std::vector<Node *> &HashMap::get_buckets() const
{
    return buckets;
}
