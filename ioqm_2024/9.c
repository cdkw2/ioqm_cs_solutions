/*
Consider the grid of points X = {(m, n) | 0 ≤ m, n ≤ 4}. We say a pair of points {(a, b),(c, d)} in X is a knight-move pair if (c = a ± 2 and d = b ± 1) or (c = a ± 1 and d = b ± 2). The number of knight-move pairs in X is:
*/

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

#define GRID_SIZE 5

bool is_valid_point(int x, int y) {
    return x >= 0 && x < GRID_SIZE && y >= 0 && y < GRID_SIZE;
}

bool is_knight_move(int x1, int y1, int x2, int y2) {
    int dx = abs(x2 - x1);
    int dy = abs(y2 - y1);
    return (dx == 2 && dy == 1) || (dx == 1 && dy == 2);
}

int count_knight_move_pairs() {
    int count = 0;

    for (int x1 = 0; x1 < GRID_SIZE; x1++) {
        for (int y1 = 0; y1 < GRID_SIZE; y1++) {
            for (int x2 = 0; x2 < GRID_SIZE; x2++) {
                for (int y2 = 0; y2 < GRID_SIZE; y2++) {
                    if (is_knight_move(x1, y1, x2, y2)) {
                        count++;
                    }
                }
            }
        }
    }

    return count / 2;
}

int main() {
    int result = count_knight_move_pairs();
    printf("%d\n", result);
    return 0;
}
