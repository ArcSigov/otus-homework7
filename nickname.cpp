#include <iostream>
#include "radix_tree.hpp"


int main()
{
    radix_tree tree;

    std::string aaa {"alesha"};
    tree.add(aaa);
    std::string bbb {"vasya"};
    tree.add(bbb);
    std::string ccc {"alesya"};
    tree.add(ccc);
    std::string ddd {"ale"};
    tree.add(ddd);
    tree.get_info();
    return 1;
}