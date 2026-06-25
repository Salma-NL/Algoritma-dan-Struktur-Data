#include <iostream>
#include <vector>
#include <map>

using namespace std;

int main() {
    int totalVertices;
    cin >> totalVertices;

    vector<char> vertexLabels(totalVertices);
    map<char, int> vertexIndex;

    for (int i = 0; i < totalVertices; i++) {
        cin >> vertexLabels[i];
        vertexIndex[vertexLabels[i]] = i;
    }

    int totalEdges;
    cin >> totalEdges;

    vector<vector<int>> adjacencyMatrix(
        totalVertices,
        vector<int>(totalVertices, 0)
    );

    for (int i = 0; i < totalEdges; i++) {
        char sourceVertex;
        char destinationVertex;
        int edgeWeight;

        cin >> sourceVertex >> destinationVertex >> edgeWeight;

        adjacencyMatrix[vertexIndex[sourceVertex]]
                       [vertexIndex[destinationVertex]]
                       = edgeWeight;
    }

    cout << "Adjacency Matrix:\n";

    cout << " ";
    for (int i = 0; i < totalVertices; i++) {
        cout << " " << vertexLabels[i];
    }
    cout << '\n';

    for (int i = 0; i < totalVertices; i++) {
        cout << vertexLabels[i];

        for (int j = 0; j < totalVertices; j++) {
            cout << " " << adjacencyMatrix[i][j];
        }

        cout << '\n';
    }

    return 0;
}