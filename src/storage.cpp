#include <string>
#include <fstream>
#include <sstream>
#include "hashmap.h"
#include "storage.h"

void load_from_file(HashMap &map, const std::string &path)
{
    std::ifstream file(path);
    std::string line;

    while (std::getline(file, line))
    {
        std::stringstream ss(line);
        std::string key, value;

        if (std::getline(ss, key, ':') &&
            std::getline(ss, value))
        {
            map.put(key, value);
        }
    }
}

void write_to_file(HashMap &hash_map, const std::string &path)
{
    std::ofstream out_file(path);
    auto buckets = hash_map.get_buckets(); // Assuming get_buckets returns a container of Node* or similar
    for (auto &bucket : buckets)
    {
        Node *node = bucket;
        while (node)
        {
            out_file << node->key + ":" + node->value + "\n";
            node = node->next;
        }
    }
    out_file.close();
}