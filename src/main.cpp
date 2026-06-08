// Copyright 2026 NNTU-CS

#include <iostream>
#include <vector>

#include "../include/tree.h"

int main() {
    std::vector<char> in = {'1', '2', '3'};

    PMTree tree(in);

    std::cout << "All permutations:" << std::endl;

    std::vector<std::vector<char>> perms = getAllPerms(tree);

    for (const auto& perm : perms) {
        for (char c : perm)
            std::cout << c;

        std::cout << std::endl;
    }

    std::cout << std::endl;

    std::vector<char> p1 = getPerm1(tree, 1);

    std::cout << "Permutation #1: ";

    for (char c : p1)
        std::cout << c;

    std::cout << std::endl;

    std::vector<char> p2 = getPerm2(tree, 2);

    std::cout << "Permutation #2: ";

    for (char c : p2)
        std::cout << c;

    std::cout << std::endl;

    return 0;
}
