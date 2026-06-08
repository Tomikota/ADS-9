// Copyright 2022 NNTU-CS

#include <iostream>
#include <vector>

#include "tree.h"

void print(std::vector<char> v) {
    for (size_t i = 0; i < v.size(); i++) {
        std::cout << v[i];
    }

    std::cout << std::endl;
}

int main() {
    std::vector<char> in =
        {'1', '3', '5', '7'};

    PMTree tree(in);

    std::vector<std::vector<char>> perms =
        getAllPerms(tree);

    for (size_t i = 0; i < perms.size(); i++) {
        print(perms[i]);
    }

    std::cout << std::endl;

    print(getPerm1(tree, 1));

    print(getPerm2(tree, 2));

    return 0;
}// Copyright 2022 NNTU-CS
#include "tree.h"

int main() {
  return 0;
}
