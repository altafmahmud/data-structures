#include "HuffmanCoding.hpp"

#include <iostream>
#include <string>

int main() {
    HuffmanCoding hc;
    // std::string str_in("ABBCDBCCDAABBEEEBEAB");
    std::string str_in("BA");
    std::cout << "Input message: " << str_in << '\n';
    const auto& huffman_codes = hc.procStr(str_in);
    std::cout << "Code table:\n";
    hc.printCodes();
    std::cout << "Encoded bits: ";
    for (const auto ch: huffman_codes) {
        std::cout << ch;
    }
    std::cout << '\n';
    std::string h_code(huffman_codes.begin(), huffman_codes.end());
    const auto& decoded = hc.decode(h_code);
    std::cout << "Decoded message: " << decoded << '\n';
    std::cout << ((str_in == decoded) ? "Passed" : "Failed");
    std::cout << '\n';
    return 0;
}
