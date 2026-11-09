#include "HuffmanCoding.hpp"

#include <iostream>
#include <string>

void execHuffmanCoding (const unsigned input_no, const std::string& message) {
    std::cout << "Input " << input_no << ":\n";
    HuffmanCoding hc;
    std::cout << "Input message: " << message << '\n';
    const auto& huffman_codes = hc.procStr(message);
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
    std::cout << ((message == decoded) ? "Passed" : "Failed");
    std::cout << '\n';
}

int main () {
    execHuffmanCoding(1, "AB");
    std::cout << '\n';
    execHuffmanCoding(2, "ABBCDBCCDAABBEEEBEAB");
    return 0;
}
