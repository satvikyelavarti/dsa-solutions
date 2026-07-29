#include <iostream>
using namespace std;

void printDegrees(int graph[][10], int vertices) {
    for (int i = 0; i < vertices; i++) {
        int degree = 0;

        for (int j = 0; j < vertices; j++) {
            if (graph[i][j] == 1) {
                degree++;
            }
        }

        cout << "Degree of vertex "
             << i << " = "
             << degree << endl;
    }
}

int main() {
    int vertices = 5;

    int graph[10][10] = {0};

    graph[0][1] = graph[1][0] = 1;
    graph[0][2] = graph[2][0] = 1;
    graph[1][3] = graph[3][1] = 1;
    graph[1][4] = graph[4][1] = 1;

    printDegrees(graph, vertices);

    return 0;
}