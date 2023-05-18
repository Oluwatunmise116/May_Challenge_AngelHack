#include <iostream>
#include <vector>

void printLayout(const std::vector<std::vector<char>>& layout) {
    for (const auto& row : layout) {
        for (const auto& cell : row) {
            std::cout << cell;
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;
}

std::vector<std::vector<char>> nextMinuteLayout(const std::vector<std::vector<char>>& layout) {
    std::vector<std::vector<char>> newLayout(5, std::vector<char>(5, '.'));

    for (int i = 0; i < 5; ++i) {
        for (int j = 0; j < 5; ++j) {
            int lifeformsCount = 0;
            int emptySpacesCount = 0;

            // Check the four adjacent tiles
            std::vector<std::pair<int, int>> directions = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
            for (const auto& dir : directions) {
                int dx = dir.first;
                int dy = dir.second;
                int x = i + dx;
                int y = j + dy;

                // Count the adjacent lifeforms and empty spaces
                if (x >= 0 && x < 5 && y >= 0 && y < 5) {
                    if (layout[x][y] == 'X') {
                        lifeformsCount++;
                    } else {
                        emptySpacesCount++;
                    }
                }
            }

            // Apply the rules to update the tile
            if (layout[i][j] == 'X') {
                if (lifeformsCount == 1) {
                    newLayout[i][j] = 'X';
                } else {
                    newLayout[i][j] = '.';
                }
            } else {
                if (lifeformsCount == 1 || lifeformsCount == 2) {
                    newLayout[i][j] = 'X';
                } else {
                    newLayout[i][j] = '.';
                }
            }
        }
    }

    return newLayout;
}

int main() {
    // Example start state
    std::vector<std::vector<char>> startState = {
        {'X', 'X', 'X', 'X', '.'},
        {'X', '.', '.', '.', '.'},
        {'X', '.', '.', 'X', '.'},
        {'.', 'X', '.', 'X', '.'},
        {'X', 'X', '.', 'X', 'X'},
    };

    // Print the start state
    std::cout << "Start state:" << std::endl;
    printLayout(startState);

    std::vector<std::vector<std::vector<char>>> layouts; // Keep track of encountered layouts
    layouts.push_back(startState);
    int minute = 1;

    while (true) {
        std::vector<std::vector<char>> nextLayout = nextMinuteLayout(layouts.back());

        bool isRepeated = false;
        for (const auto& layout : layouts) {
            if (layout == nextLayout) {
                isRepeated = true;
                break;
            }
        }

        if (isRepeated) {
            std::cout << minute << " minute:" << std::endl;
            printLayout(nextLayout);
            std::cout << "Repeated layout encountered after " << minute << " minute(s)." << std::endl;
            break;
        } else {
            layouts.push_back(nextLayout);
            std::cout << minute << " minute:" << std::endl;
            printLayout(nextLayout);
             minute++;
        }
    }

    return 0;
}

