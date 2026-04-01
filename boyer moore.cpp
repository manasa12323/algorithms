#include <iostream>
#include <vector>
#include <string>
using namespace std;

const int CHAR_SIZE = 256;

// Preprocess the bad character heuristic
void badCharHeuristic(const string &pattern, vector<int> &badChar) {
    int m = pattern.size();

    // Initialize all occurrences as -1
    for (int i = 0; i < CHAR_SIZE; i++)
        badChar[i] = -1;

    // Fill the actual value of last occurrence
    for (int i = 0; i < m; i++)
        badChar[(int)pattern[i]] = i;
}

// Boyer-Moore search function
void boyerMooreSearch(const string &text, const string &pattern) {
    int n = text.size();
    int m = pattern.size();

    vector<int> badChar(CHAR_SIZE);

    badCharHeuristic(pattern, badChar);

    int shift = 0; // shift of the pattern

    while (shift <= (n - m)) {
        int j = m - 1;

        // Keep reducing index j while characters match
        while (j >= 0 && pattern[j] == text[shift + j])
            j--;

        // If pattern is present
        if (j < 0) {
            cout << "Pattern found at index " << shift << endl;

            // Shift pattern so next character aligns
            shift += (shift + m < n) ? m - badChar[text[shift + m]] : 1;
        } else {
            // Shift based on bad character rule
            shift += max(1, j - badChar[text[shift + j]]);
        }
    }
}

// Driver code
int main() {
    string text = "ABAAABCD";
    string pattern = "ABC";

    boyerMooreSearch(text, pattern);

    return 0;
}