#include "HuffmanCoding.hpp"

#include <iostream>

HuffmanCoding::~HuffmanCoding() {
    delTree(root);
    root = nullptr;
    charFreq.clear();
    clearPq();
}

void HuffmanCoding::procStr(const std::string_view str) {
    calFreq(str);
    fillUp();
    buildTree();
    findCodes(root, std::vector<char>());
    printCodes();
}

void HuffmanCoding::calFreq(const std::string_view str) noexcept {
    for (const auto& c: str) {
        auto it = charFreq.find(c);
        if (it != charFreq.end()) {
            auto& freq = it->second;
            ++freq;
        } else {
            charFreq.emplace(c, 1);
        }
    }
}

void HuffmanCoding::fillUp() {
    for (const auto& [ch, freq]: charFreq) {
        pq.emplace(new LeafNode(freq, ch));
        if (!codes.contains(ch)) {
            codes.emplace(ch, std::vector<char>());
        }
    }
}

void HuffmanCoding::buildTree() {
    while (pq.size() > 1) {
        auto node1 = pq.top();
        pq.pop();
        auto node2 = pq.top();
        pq.pop();
        auto parent = new Node(node1->freq + node2->freq);
        parent->left = node1;
        parent->right = node2;
        pq.push(parent);
    }
    root = pq.top();
    pq.pop();
}

void HuffmanCoding::findCodes(Node* node, std::vector<char> codePrefix){
    if (node == nullptr) {
        return;
    }
    if (node->isLeaf()) {
        const auto c = static_cast<LeafNode*>(node)->ch;
        codes[c] = codePrefix;
        return;
    }
    auto left_code_prefix = codePrefix;
    auto right_code_prefix = codePrefix;
    if (node->left != nullptr) {
        left_code_prefix.push_back('0');
        findCodes(node->left, left_code_prefix);
    }
    if (node->right != nullptr) {
        right_code_prefix.push_back('1');
        findCodes(node->right, right_code_prefix);
    }
}

void HuffmanCoding::printCodes() const {
    for (const auto& [ch, codeVec]: codes) {
        std::cout << ch << ": ";
        for (const auto& code: codeVec) {
            std::cout << code;
        }
        std::cout << '\n';
    }
}

void HuffmanCoding::clearPq() {
    while (!pq.empty()) {
        auto node = pq.top();
        if (node != nullptr) {
            delete node;
        }
        pq.pop();
    }
}

void HuffmanCoding::delTree(Node *node) {
    if (node == nullptr) {
        return;
    }

    char ch = '\0';
    if (node->isLeaf()) {
        ch = static_cast<LeafNode*>(node)->ch;
    }
    const auto freq = node->freq;

    if (node->left != nullptr) {
        delTree(node->left);
    }
    if (node->right != nullptr) {
        delTree(node->right);
    }

    delete node;
    node = nullptr;

    std::cout << "Node: " << freq;
    if (ch != '\0') {
        std::cout << " char: " << ch;
    }
    std::cout << " deleted\n";
}
