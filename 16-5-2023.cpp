#include <iostream>
#include <vector>
#include <algorithm>

void printLayout(const std::vector<std::vector<char>>& layout) {
    for (const auto& row : layout) {
        for (char tile : row) {
            std::cout << tile;
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;
}

int calculateLifeformScore(const std::vector<std::vector<char>>& layout) {
    int score = 0;
    for (int row = 0; row < 5; row++) {
        for (int col = 0; col < 5; col++) {
            if (layout[row][col] == 'X') {
                int tileNumber = row * 5 + col;
                score += 1 << tileNumber;
            }
        }
    }
    return score;
}

int getAdjacentLifeforms(const std::vector<std::vector<char>>& layout, int row, int col) {
    int lifeformsCount = 0;
    for (const auto& direction : {std::make_pair(0, 1), std::make_pair(0, -1), std::make_pair(1, 0), std::make_pair(-1, 0)}) {
        int dx = direction.first;
        int dy = direction.second;
        int adjacentRow = row + dx;
        int adjacentCol = col + dy;
        if (adjacentRow >= 0 && adjacentRow < 5 && adjacentCol >= 0 && adjacentCol < 5 && layout[adjacentRow][adjacentCol] == 'X') {
            lifeformsCount++;
        }
    }
    return lifeformsCount;
}

std::vector<std::vector<char>> nextMinuteLayout(const std::vector<std::vector<char>>& layout) {
    std::vector<std::vector<char>> newLayout(5, std::vector<char>(5, '.'));

    for (int row = 0; row < 5; row++) {
        for (int col = 0; col < 5; col++) {
            int lifeformsCount = getAdjacentLifeforms(layout, row, col);
            if (layout[row][col] == 'X') {
                if (lifeformsCount == 1) {
                    newLayout[row][col] = 'X';
                }
            } else {
                if (lifeformsCount == 1 || lifeformsCount == 2) {
                    newLayout[row][col] = 'X';
                }
            }
        }
    }

    return newLayout;
}

int main() {
    std::vector<std::vector<char>> startState = {
        {'X', 'X', 'X', 'X', '.'},
        {'X', '.', '.', '.', '.'},
        {'X', '.', '.', 'X', '.'},
        {'.', 'X', '.', 'X', '.'},
        {'X', 'X', '.', 'X', 'X'}
    };

    std::cout << "Start state:" << std::endl;
    printLayout(startState);

    std::vector<std::vector<std::vector<char>>> encounteredLayouts;
    encounteredLayouts.push_back(startState);
    int minute = 1;
    int repeatedMinute = 0;

    while (true) {
        std::vector<std::vector<char>> nextLayout = nextMinuteLayout(encounteredLayouts.back());

        auto it = std::find(encounteredLayouts.begin(), encounteredLayouts.end() - 1, nextLayout);
        if (it != encounteredLayouts.end() - 1) {
            repeatedMinute = std::distance(encounteredLayouts.begin(), it);
            std::cout << "\nRepeated layout is the " << repeatedMinute << "th minute and " << minute << "st minute." << std::endl;
            break;
        } else {
            encounteredLayouts.push_back(nextLayout);
            minute++;
        }
    }

    int lifeformScore = calculateLifeformScore(encounteredLayouts[repeatedMinute]);
    std::cout << "Lifeform score is " << lifeformScore << std::endl;

    return 0;
}
