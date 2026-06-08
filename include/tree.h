// Copyright 2022 NNTU-CS

#include <vector>
#include <charconv>

class PMTree
{
public:

    struct Node
    {
        char value;
        std::vector<Node*> children;

        Node(char v = '\0')
            : value(v)
        {}
    };

    Node* root;

    PMTree(const std::vector<char>& data)
    {
        root = new Node();
        build(root, data);
    }

    ~PMTree()
    {
        clear(root);
    }

private:

    void build(Node* parent, const std::vector<char>& elems)
    {
        if (elems.empty())
            return;

        for (size_t i = 0; i < elems.size(); i++)
        {
            Node* child = new Node(elems[i]);
            parent->children.push_back(child);

            std::vector<char> rest;

            for (size_t j = 0; j < elems.size(); j++)
            {
                if (i != j)
                    rest.push_back(elems[j]);
            }

            build(child, rest);
        }
    }

    void clear(Node* node)
    {
        if (!node)
            return;

        for (auto child : node->children)
            clear(child);

        delete node;
    }
};

std::vector<std::vector<char>> getAllPerms(PMTree& tree);

std::vector<char> getPerm1(PMTree& tree, int num);

std::vector<char> getPerm2(PMTree& tree, int num);
