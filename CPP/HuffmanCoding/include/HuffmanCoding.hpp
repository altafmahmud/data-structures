#ifndef HUFFMAN_CODING_HPP
#define HUFFMAN_CODING_HPP

#include <string_view>
#include <unordered_map>
#include <map>
#include <queue>
#include <vector>

namespace {
struct Node {
    constexpr Node() = delete;
    Node(const unsigned f): freq(f), left{nullptr}, right{nullptr} {}
    ~Node() = default;

    constexpr virtual bool isLeaf() const {
        return false;
    }

    unsigned freq;
    Node *left, *right;
};

struct LeafNode: public Node {
    constexpr LeafNode() = delete;
    LeafNode(const unsigned f, const char c): Node(f), ch(c) {}
    ~LeafNode() = default;

    constexpr bool isLeaf() const override {
        return true;
    }

    char ch;
};

struct CompareNode {
    bool operator()(const Node* node1, const Node* node2) const {
        if (node1 == nullptr) {
            return true;
        }
        if (node2 == nullptr) {
            return false;
        }
        return node1->freq > node2->freq;
    }
};
}

class HuffmanCoding {
public:
    HuffmanCoding(): root{nullptr} {}
    ~HuffmanCoding();

    void procStr(const std::string_view str);

private:
    void calFreq(const std::string_view str) noexcept;
    void fillUp();
    void buildTree();
    void findCodes(Node* node, std::vector<char> codeVec);
    void printCodes() const;
    void clearPq();
    void delTree(Node* node);

    std::unordered_map<char, unsigned> charFreq;
    std::map<char, std::vector<char>> codes;
    std::priority_queue<Node*, std::vector<Node*>, CompareNode> pq;
    Node* root;
};

#endif // HUFFMAN_CODING_HPP
