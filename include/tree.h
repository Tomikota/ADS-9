// Copyright 2026 NNTU-CS

#pragma once

#include <vector>

class PMTree {
 public:
    struct Node {
        char value;
        std::vector<Node*> children;

        explicit Node(char v = '\0') : value(v) {}
    };

    Node* root;

    explicit PMTree(const std::vector<char>& data) {
        root = new Node();
        build(root, data);
    }

    ~PMTree() {
        clear(root);
    }

    void collect(Node* node,
                 std::vector<char>* current,
                 std::vector<std::vector<char>>* result) {
        if (node == nullptr)
            return;

        if (node->value != '\0')
            current->push_back(node->value);

        if (node->children.empty()) {
            if (!current->empty())
                result->push_back(*current);
        } else {
            for (auto child : node->children)
                collect(child, current, result);
        }

        if (node->value != '\0')
            current->pop_back();
    }

 private:
    void build(Node* parent, const std::vector<char>& elems) {
        if (elems.empty())
            return;

        for (size_t i = 0; i < elems.size(); i++) {
            Node* child = new Node(elems[i]);
            parent->children.push_back(child);

            std::vector<char> rest;

            for (size_t j = 0; j < elems.size(); j++) {
                if (i != j)
                    rest.push_back(elems[j]);
            }

            build(child, rest);
        }
    }

    void clear(Node* node) {
        if (node == nullptr)
            return;

        for (auto child : node->children)
            clear(child);

        delete node;
    }
};

std::vector<std::vector<char>> getAllPerms(PMTree& tree);

std::vector<char> getPerm1(PMTree& tree, int num);

std::vector<char> getPerm2(PMTree& tree, int num);
