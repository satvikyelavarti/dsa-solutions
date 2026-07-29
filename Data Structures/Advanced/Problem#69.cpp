#include <iostream>
#include <vector>
#include <string>

using namespace std;

// Definition of a Trie Node
struct TrieNode {
    TrieNode* children[26];
    bool isEndOfWord;

    TrieNode() {
        isEndOfWord = false;

        for (int i = 0; i < 26; i++) {
            children[i] = nullptr;
        }
    }
};

// Trie Class managing insertion and autocomplete
class AutocompleteSystem {
private:
    TrieNode* root;

    // Helper function to collect all words with a given prefix
    void collectWords(TrieNode* curr,
                      string currentWord,
                      vector<string>& results) {
        if (curr == nullptr)
            return;

        // If current node marks the end of a word
        if (curr->isEndOfWord) {
            results.push_back(currentWord);
        }

        // Explore all child nodes
        for (int i = 0; i < 26; i++) {
            if (curr->children[i] != nullptr) {
                char nextChar = 'a' + i;

                collectWords(
                    curr->children[i],
                    currentWord + nextChar,
                    results
                );
            }
        }
    }

public:
    AutocompleteSystem() {
        root = new TrieNode();
    }

    // Insert a word into the Trie
    void insert(const string& word) {
        TrieNode* curr = root;

        for (char ch : word) {
            int index = ch - 'a';

            if (curr->children[index] == nullptr) {
                curr->children[index] = new TrieNode();
            }

            curr = curr->children[index];
        }

        curr->isEndOfWord = true;
    }

    // Return all words that share the given prefix
    vector<string> getSuggestions(const string& prefix) {
        TrieNode* curr = root;
        vector<string> results;

        // Navigate to end of prefix
        for (char ch : prefix) {
            int index = ch - 'a';

            if (curr->children[index] == nullptr) {
                return results; // Prefix not found
            }

            curr = curr->children[index];
        }

        // Collect all words starting from this prefix
        collectWords(curr, prefix, results);

        return results;
    }
};

int main() {
    AutocompleteSystem autoCorrect;

    // Dictionary words
    vector<string> dictionary = {
        "cat",
        "car",
        "cart",
        "dog",
        "dove",
        "deer",
        "catapult",
        "camera"
    };

    // Insert words into Trie
    for (const string& word : dictionary) {
        autoCorrect.insert(word);
    }

    string prefix1 = "ca";
    string prefix2 = "do";

    vector<string> suggestions1 =
        autoCorrect.getSuggestions(prefix1);

    vector<string> suggestions2 =
        autoCorrect.getSuggestions(prefix2);

    cout << "Suggestions for prefix \"" << prefix1 << "\":" << endl;

    for (const string& word : suggestions1) {
        cout << "- " << word << endl;
    }

    cout << "\nSuggestions for prefix \"" << prefix2 << "\":" << endl;

    for (const string& word : suggestions2) {
        cout << "- " << word << endl;
    }

    return 0;
}