#include <iostream>
#include <vector>

class BTreeNode {
public:
    std::vector<int> keys;
    std::vector<BTreeNode*> children;
    bool isLeaf;

    BTreeNode(bool leaf);
    void insertNonFull(int key);
    void splitChild(int i, BTreeNode *y);
    void traverse();
    BTreeNode* search(int key);
};

class BTree {
public:
    BTreeNode *root;
    int t;

    BTree(int _t) : root(nullptr), t(_t) {}
    void traverse() {
        if (root) root->traverse();
    }
    BTreeNode* search(int key) {
        return root == nullptr ? nullptr : root->search(key);
    }
    void insert(int key);
};

BTreeNode::BTreeNode(bool leaf) : isLeaf(leaf) {}

void BTreeNode::insertNonFull(int key) {
    int i = keys.size() - 1;
    if (isLeaf) {
        keys.insert(keys.begin() + i + 1, key);
        while (i >= 0 && keys[i] > key) {
            keys[i + 1] = keys[i];
            i--;
        }
        keys[i + 1] = key;
    } else {
        while (i >= 0 && keys[i] > key) i--;
        if (children[i + 1]->keys.size() == 2 * t - 1) {
            splitChild(i + 1, children[i + 1]);
            if (keys[i + 1] < key) i++;
        }
        children[i + 1]->insertNonFull(key);
    }
}

void BTreeNode::splitChild(int i, BTreeNode *y) {
    BTreeNode *z = new BTreeNode(y->isLeaf);
    z->keys.resize(t - 1);
    for (int j = 0; j < t - 1; j++) z->keys[j] = y->keys[j + t];
    if (!y->isLeaf) {
        z->children.resize(t);
        for (int j = 0; j < t; j++) z->children[j] = y->children[j + t];
    }
    y->keys.resize(t - 1);
    children.insert(children.begin() + i + 1, z);
    keys.insert(keys.begin() + i, y->keys[t - 1]);
}

void BTreeNode::traverse() {
    int i;
    for (i = 0; i < keys.size(); i++) {
        if (!isLeaf) children[i]->traverse();
        std::cout << " " << keys[i];
    }
    if (!isLeaf) children[i]->traverse();
}

BTreeNode* BTreeNode::search(int key) {
    int i = 0;
    while (i < keys.size() && key > keys[i]) i++;
    if (keys[i] == key) return this;
    if (isLeaf) return nullptr;
    return children[i]->search(key);
}

void BTree::insert(int key) {
    if (root == nullptr) {
        root = new BTreeNode(true);
        root->keys.push_back(key);
    } else {
        if (root->keys.size() == 2 * t - 1) {
            BTreeNode *s = new BTreeNode(false);
            s->children.push_back(root);
            s->splitChild(0, root);
            int i = 0;
            if (s->keys[0] < key) i++;
            s->children[i]->insertNonFull(key);
            root = s;
        } else {
            root->insertNonFull(key);
        }
    }
}

int main() {
    BTree t(3);
    t.insert(10);
    t.insert(20);
    t.insert(5);
    t.insert(6);
    t.insert(12);
    t.insert(30);
    t.insert(7);
    t.insert(17);

    std::cout << "Traversal of the constructed tree is ";
    t.traverse();

    int key = 6;
    (t.search(key) != nullptr) ? std::cout << "\nPresent" : std::cout << "\nNot Present";

    return 0;
}