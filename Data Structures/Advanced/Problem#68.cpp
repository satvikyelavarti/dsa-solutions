#include <iostream>
#include <vector>
using namespace std;

class HashTable {
private:
    static const int TABLE_SIZE = 10;
    vector<int> table[TABLE_SIZE];

    int hashFunction(int key) {
        return key % TABLE_SIZE;
    }

public:
    // Insert a key
    void insert(int key) {
        int index = hashFunction(key);
        table[index].push_back(key);
    }

    // Search for a key
    bool search(int key) {
        int index = hashFunction(key);

        for (int value : table[index]) {
            if (value == key)
                return true;
        }

        return false;
    }

    // Display table
    void display() {
        for (int i = 0; i < TABLE_SIZE; i++) {
            cout << i << " : ";

            for (int value : table[i]) {
                cout << value << " ";
            }

            cout << endl;
        }
    }
};

int main() {
    HashTable ht;

    ht.insert(15);
    ht.insert(25);
    ht.insert(35);
    ht.insert(12);
    ht.insert(22);

    ht.display();

    cout << "\nSearch 25: ";
    cout << (ht.search(25) ? "Found" : "Not Found");

    cout << "\nSearch 50: ";
    cout << (ht.search(50) ? "Found" : "Not Found");

    return 0;
}