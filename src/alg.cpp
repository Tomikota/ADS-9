std::vector<char> getPerm2(PMTree& tree, int num) {
    std::vector<char> result;

    if (num <= 0)
        return result;

    int total = factorial(tree.root->children.size());

    if (num > total)
        return {};

    PMTree::Node* current = tree.root;

    num--;

    while (!current->children.empty()) {
        int count = factorial(current->children.size() - 1);

        int index = num / count;

        current = current->children[index];

        result.push_back(current->value);

        num %= count;
    }

    return result;
}
