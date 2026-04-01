#include <iostream>
#include <queue>
#include <unordered_map>
using namespace std;

// Node structure
struct Node {
    char ch;
    int freq;
    Node *left, *right;

    Node(char c, int f) {
        ch = c;
        freq = f;
        left = right = nullptr;
    }
};

// Comparator for priority queue (min-heap)
struct compare {
    bool operator()(Node* l, Node* r) {
        return l->freq > r->freq;
    }
};

// Function to print Huffman codes
void printCodes(Node* root, string code, unordered_map<char, string>& huffmanCode) {
    if (!root)
        return;

    // Leaf node
    if (!root->left && !root->right) {
        huffmanCode[root->ch] = code;
        cout << root->ch << " : " << code << endl;
    }

    printCodes(root->left, code + "0", huffmanCode);
    printCodes(root->right, code + "1", huffmanCode);
}

// Build Huffman Tree
void buildHuffmanTree(string text) {
    unordered_map<char, int> freq;

    // Count frequency
    for (char ch : text)
        freq[ch]++;

    // Min heap
    priority_queue<Node*, vector<Node*>, compare> pq;

    // Create leaf nodes
    for (auto pair : freq) {
        pq.push(new Node(pair.first, pair.second));
    }

    // Build tree
    while (pq.size() != 1) {
        Node* left = pq.top(); pq.pop();
        Node* right = pq.top(); pq.pop();

        Node* sum = new Node('\0', left->freq + right->freq);
        sum->left = left;
        sum->right = right;

        pq.push(sum);
    }

    Node* root = pq.top();

    unordered_map<char, string> huffmanCode;

    cout << "Huffman Codes:\n";
    printCodes(root, "", huffmanCode);

    // Encode input text
    string encoded = "";
    for (char ch : text) {
        encoded += huffmanCode[ch];
    }

    cout << "\nEncoded string:\n" << encoded << endl;
}

int main() {
    string text = "huffman coding example";

    buildHuffmanTree(text);

    return 0;
}