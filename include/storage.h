#ifndef STORAGE_H
#define STORAGE_H
#include "hashmap.h"
#include <string>

void load_from_file(HashMap &hash_map, const std::string &path);
void write_to_file(HashMap &hash_map, const std::string &path);
#endif