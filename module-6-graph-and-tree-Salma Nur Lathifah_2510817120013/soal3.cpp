#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct Position {
    int row;
    int column;
};

int main() {
    int totalRows;
    int totalColumns;

    cin >> totalRows >> totalColumns;

    vector<vector<int>> mazeGrid(
        totalRows,
        vector<int>(totalColumns)
    );

    for (int i = 0; i < totalRows; i++) {
        for (int j = 0; j < totalColumns; j++) {
            cin >> mazeGrid[i][j];
        }
    }

    int startRow;
    int startColumn;

    int finishRow;
    int finishColumn;

    cin >> startRow >> startColumn;
    cin >> finishRow >> finishColumn;

    vector<vector<int>> minimumDistance(
        totalRows,
        vector<int>(totalColumns, -1)
    );

    queue<Position> bfsQueue;

    bfsQueue.push({startRow, startColumn});
    minimumDistance[startRow][startColumn] = 0;

    int rowDirection[4] = {-1, 1, 0, 0};
    int columnDirection[4] = {0, 0, -1, 1};

    while (!bfsQueue.empty()) {

        Position currentPosition = bfsQueue.front();
        bfsQueue.pop();

        for (int k = 0; k < 4; k++) {

            int nextRow =
                currentPosition.row + rowDirection[k];

            int nextColumn =
                currentPosition.column + columnDirection[k];

            if (nextRow < 0 || nextRow >= totalRows ||
                nextColumn < 0 || nextColumn >= totalColumns) {
                continue;
            }

            if (mazeGrid[nextRow][nextColumn] == 1) {
                continue;
            }

            if (minimumDistance[nextRow][nextColumn] != -1) {
                continue;
            }

            minimumDistance[nextRow][nextColumn] =
                minimumDistance[currentPosition.row]
                               [currentPosition.column] + 1;

            bfsQueue.push({nextRow, nextColumn});
        }
    }

    cout << minimumDistance[finishRow][finishColumn] << '\n';

    return 0;
}