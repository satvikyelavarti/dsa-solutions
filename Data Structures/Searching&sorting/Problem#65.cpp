#include <iostream>
#include <vector>
#include <queue>
#include <fstream>
#include <string>
#include <algorithm>
#include <random>

using namespace std;

// Structure for Min-Heap nodes
struct HeapNode {
    int value;
    int run_index;

    bool operator>(const HeapNode& other) const {
        return value > other.value;
    }
};

class ExternalMergeSortSimulation {
private:
    const string input_file = "unsorted_data.txt";
    const string output_file = "sorted_output.txt";

    const int CHUNK_SIZE = 250;
    const int TOTAL_ELEMENTS = CHUNK_SIZE * 100;

public:

    // Generate random unsorted data
    void generateUnsortedData() {

        ofstream out(input_file);

        mt19937 rng(42);
        uniform_int_distribution<int> dist(1, 100000);

        for (int i = 0; i < TOTAL_ELEMENTS; i++) {
            out << dist(rng) << "\n";
        }

        out.close();

        cout << "[Setup] Generated mock file containing "
             << TOTAL_ELEMENTS
             << " integers.\n";
    }

    // Phase 1: Create sorted runs
    int generateSortedRuns() {

        ifstream in(input_file);

        vector<int> ram_buffer;

        int val;
        int run_count = 0;

        while (in >> val) {

            ram_buffer.push_back(val);

            if (ram_buffer.size() == CHUNK_SIZE) {

                sort(ram_buffer.begin(),
                     ram_buffer.end());

                ofstream run_file(
                    "run_" +
                    to_string(run_count) +
                    ".tmp"
                );

                for (int num : ram_buffer) {
                    run_file << num << "\n";
                }

                run_file.close();

                ram_buffer.clear();
                run_count++;
            }
        }

        // Handle leftover elements
        if (!ram_buffer.empty()) {

            sort(ram_buffer.begin(),
                 ram_buffer.end());

            ofstream run_file(
                "run_" +
                to_string(run_count) +
                ".tmp"
            );

            for (int num : ram_buffer) {
                run_file << num << "\n";
            }

            run_file.close();
            run_count++;
        }

        in.close();

        cout << "[Phase 1] Created "
             << run_count
             << " sorted run files.\n";

        return run_count;
    }

    // Phase 2: Merge sorted runs
    void mergeSortedRuns(int run_count) {

        vector<ifstream> run_files(run_count);

        priority_queue<
            HeapNode,
            vector<HeapNode>,
            greater<HeapNode>
        > min_heap;

        ofstream out(output_file);

        // Insert first element of each run
        for (int i = 0; i < run_count; i++) {

            run_files[i].open(
                "run_" +
                to_string(i) +
                ".tmp"
            );

            int val;

            if (run_files[i] >> val) {
                min_heap.push({val, i});
            }
        }

        // K-Way Merge
        while (!min_heap.empty()) {

            HeapNode smallest =
                min_heap.top();

            min_heap.pop();

            out << smallest.value << "\n";

            int next_val;

            if (run_files[smallest.run_index]
                >> next_val) {

                min_heap.push(
                    {next_val,
                     smallest.run_index}
                );
            }
        }

        // Cleanup
        for (int i = 0; i < run_count; i++) {

            run_files[i].close();

            remove(
                ("run_" +
                 to_string(i) +
                 ".tmp").c_str()
            );
        }

        out.close();

        cout << "[Phase 2] Final sorted file saved as "
             << output_file
             << endl;
    }

    // Verify sorting
    void verifySortedOrder() {

        ifstream in(output_file);

        int current;
        int previous;

        bool is_sorted = true;

        if (in >> previous) {

            while (in >> current) {

                if (current < previous) {
                    is_sorted = false;
                    break;
                }

                previous = current;
            }
        }

        in.close();

        if (is_sorted) {
            cout << "[Validation] Success! "
                 << "Output file is sorted."
                 << endl;
        }
        else {
            cout << "[Validation] Failed!"
                 << endl;
        }
    }
};

int main() {

    ExternalMergeSortSimulation simulation;

    simulation.generateUnsortedData();

    int total_runs =
        simulation.generateSortedRuns();

    simulation.mergeSortedRuns(total_runs);

    simulation.verifySortedOrder();

    return 0;
}