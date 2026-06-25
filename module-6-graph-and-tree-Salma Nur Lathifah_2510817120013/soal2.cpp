#include <iostream>
#include <vector>

using namespace std;

int main() {
    int totalVertices;
    cin >> totalVertices;

    vector<char> vertexLabels(totalVertices);

    for (int i = 0; i < totalVertices; i++) {
        cin >> vertexLabels[i];
    }

    vector<vector<int>> adjacencyMatrix(
        totalVertices,
        vector<int>(totalVertices)
    );

    for (int i = 0; i < totalVertices; i++) {
        for (int j = 0; j < totalVertices; j++) {
            cin >> adjacencyMatrix[i][j];
        }
    }

    cout << "Adjacency List:\n";

    for (int i = 0; i < totalVertices; i++) {

        cout << vertexLabels[i] << " -> ";

        bool hasOutgoingEdge = false;

        for (int j = 0; j < totalVertices; j++) {

            if (adjacencyMatrix[i][j] > 0) {

                if (hasOutgoingEdge) {
                    cout << ", ";
                }

                cout << "("
                     << vertexLabels[j]
                     << ","
                     << adjacencyMatrix[i][j]
                     << ")";

                hasOutgoingEdge = true;
            }
        }

        if (!hasOutgoingEdge) {
            cout << "-";
        }

        cout << '\n';
    }

    return 0;
}