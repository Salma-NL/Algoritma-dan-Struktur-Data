#include <iostream>
#include <vector>

using namespace std;

int totalRows;
int totalColumns;

int finishRow;
int finishColumn;

long long totalValidPaths = 0;

vector<vector<int>> mazeGrid;
vector<vector<bool>> visitedCells;

int rowDirection[4] = {-1, 1, 0, 0};
int columnDirection[4] = {0, 0, -1, 1};

void countPathsDFS(int currentRow, int currentColumn) {

    if (currentRow == finishRow &&
        currentColumn == finishColumn) {

        totalValidPaths++;
        return;
    }

    visitedCells[currentRow][currentColumn] = true;

    for (int k = 0; k < 4; k++) {

        int nextRow =
            currentRow + rowDirection[k];

        int nextColumn =
            currentColumn + columnDirection[k];

        if (nextRow < 0 || nextRow >= totalRows ||
            nextColumn < 0 || nextColumn >= totalColumns) {
            continue;
        }

        if (mazeGrid[nextRow][nextColumn] == 1) {
            continue;
        }

        if (visitedCells[nextRow][nextColumn]) {
            continue;
        }

        countPathsDFS(nextRow, nextColumn);
    }

    visitedCells[currentRow][currentColumn] = false;
}

int main() {

    cin >> totalRows >> totalColumns;

    mazeGrid.assign(
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

    cin >> startRow >> startColumn;
    cin >> finishRow >> finishColumn;

    visitedCells.assign(
        totalRows,
        vector<bool>(totalColumns, false)
    );

    countPathsDFS(startRow, startColumn);

    cout << totalValidPaths << '\n';

    return 0;
}