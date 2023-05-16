#include <iostream>
#include <string>

#define MAX_CODEWORD_LEN 20

struct Node {
    char letter;
    Node* left;
    Node* right;
};

void decode_helper(std::string encoded, Node* root, int& index, std::string& result) {
    Node* curr = root;
    while (curr->left != nullptr || curr->right != nullptr) {
        if (encoded[index] == '0') {
            curr = curr->left;
        } else if (encoded[index] == '1') {
            curr = curr->right;
        } else {
            std::cout << "Error: Invalid encoded message" << std::endl;
            exit(1);
        }
        index++;
    }
    result += curr->letter;
}

void decode(std::string encoded, Node* root, std::string& result) {
    int index = 0;
    while (index < encoded.length()) {
        decode_helper(encoded, root, index, result);
        if (result[result.length() - 1] == ' ' && result[result.length() - 2] == ' ') {
            result[result.length() - 1] = 'y';
            result += "ab";
        }
    }
}

void add_node(Node** node, char letter) {
    *node = new Node;
    (*node)->left = nullptr;
    (*node)->right = nullptr;
    (*node)->letter = letter;
}

int main() {
    std::string encoded = "11111011111111110001111111001011111101011111111100110111111111110001001111110100111100110111111100101111010010111111000111111111110001101111110101110011011111111111000110111101001111110010111111001011011111110100111100110111111111110001011101100011111110111111111001110111111111110001111110111111101011111111110001111110111111100111111111110001111011111110111111110100111111111100010011111101001100111111111100011101111111111010111110111111101011111011111101001111001111111111000100111111010011001111111111000111111011111111110001110011111011111110011111110010111110111111000111011111111111000111111110101111011101111111111100011111111101111111010111111110001100111111111100011111111111000111111111110001111111101011110100111111101011111111110001001111110110111111011011010011111110001111111001111111111100011111101111110100111111111100011111111010111101110111111111110001111111011011110111111110000011111110011101";

    Node* root = new Node;
    root->left = nullptr;
    root->right = nullptr;

   
    std::string letters[] = {"a", "b", "c", "d", "e", "f", "g", "h", "i", "j", "k", "l", "m", "n", "o", "p", "q", "r", "s", "t", "u", "v", "w", "x", "y", "z", " "};
    std::string codewords[] = {"00", "01", "10", "1100", "1101", "1110", "111100", "111101", "111110", "1111110000", "1111110001", "1111110010", "1111110011", "1111110100", "1111110101", "1111110110", "1111110111", "1111111000", "1111111001", "1111111010", "1111111011", "1111111100", "1111111101", "1111111110", "1111111111", "11111111110000", "11111111110001"};
    int num_letters = 27; 
    
    for (int i = 0; i < num_letters; i++) {
        Node* curr = root;
        std::string codeword = codewords[i];
        for (char c : codeword) {
            if (c == '0') {
                if (curr->left == nullptr) {
                    add_node(&(curr->left), '\0');
                }
                curr = curr->left;
            } else if (c == '1') {
                if (curr->right == nullptr) {
                    add_node(&(curr->right), '\0');
                }
                curr = curr->right;
            } else {
                std::cout << "Error: Invalid codeword" << std::endl;
                exit(1);
            }
        }
        curr->letter = letters[i][0];
    }

    
    std::string result;
    decode(encoded, root, result);
    std::cout << "Decoded message: " << result << std::endl;

    return 0;
}

