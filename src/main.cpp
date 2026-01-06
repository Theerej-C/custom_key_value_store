#include <iostream>
#include "hashmap.h"
#include "storage.h"
int main()
{
    std::string PATH = "db/db.txt";
    HashMap map(30);
    load_from_file(map, PATH);
    while (true)
    {
        int op;
        std::cin >> op;

        if (op == 1)
        {
            std::string k, v;
            std::cin >> k >> v;
            map.put(k, v);
        }
        else if (op == 2)
        {
            std::string k, v;
            std::cin >> k;
            if (map.get(k, v))
                std::cout << v << "\n";
            else
                std::cout << "NOT FOUND\n";
        }
        else
        {
            write_to_file(map, PATH);
            break;
        }
    }
}
