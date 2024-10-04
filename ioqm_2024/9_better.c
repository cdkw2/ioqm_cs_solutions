/*
Consider the grid of points X = {(m, n) | 0 ≤ m, n ≤ 4}. We say a pair of points {(a, b),(c, d)} in X is a knight-move pair if (c = a ± 2 and d = b ± 1) or (c = a ± 1 and d = b ± 2). The number of knight-move pairs in X is:
*/

#include <stdio.h>
#include <stdbool.h>

#define GRID_SIZE 5

bool is_valid_point(int x, int y) {
    return x >= 0 && x < GRID_SIZE && y >= 0 && y < GRID_SIZE;
}

int count_knight_move_pairs() {
    int count = 0;
    int moves[8][2] = {{2,1}, {2,-1}, {-2,1}, {-2,-1}, {1,2}, {1,-2}, {-1,2}, {-1,-2}};

    for (int x = 0; x < GRID_SIZE; x++) {
        for (int y = 0; y < GRID_SIZE; y++) {
            for (int i = 0; i < 8; i++) {
                int new_x = x + moves[i][0];
                int new_y = y + moves[i][1];
                if (is_valid_point(new_x, new_y)) {
                    count++;
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
