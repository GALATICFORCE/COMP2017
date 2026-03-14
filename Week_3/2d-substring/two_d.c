#include <stdio.h>
#include <string.h>

// Define the grid size
#define ROWS 10
#define COLS 10

// Function prototypes
void search_horizontal(const char grid[ROWS][COLS], const char *str);
void search_vertical(const char grid[ROWS][COLS], const char *str);
void search_diagonal(const char grid[ROWS][COLS], const char *str);

void search_horizontal(const char grid[ROWS][COLS], const char *str) {
    int len = strlen(str);
    for (int r = 1; r < ROWS - 1; r++) {
        for (int c = 1; c < COLS - 1; c++) {
            int match = 1;
            for (int k = 0; k < len; k++) {
                if (c + k >= COLS - 1 || grid[r][c + k] != str[k]) {
                    match = 0;
                    break;
                }
            }
            if (match) {
                printf("Found horizontal match for \"%s\": row %d, column %d\n", str, r, c);
            }
        }
    }
}

void search_vertical(const char grid[ROWS][COLS], const char *str) {
    int len = strlen(str);
    for (int c = 1; c < COLS - 1; c++) {
        for (int r = 1; r < ROWS - 1; r++) {
            int match = 1;
            for (int k = 0; k < len; k++) {
                if (r + k >= ROWS - 1 || grid[r + k][c] != str[k]) {
                    match = 0;
                    break;
                }
            }
            if (match) {
                printf("Found vertical match for \"%s\": row %d, column %d\n", str, r, c);
            }
        }
    }
}

void search_diagonal(const char grid[ROWS][COLS], const char *str) {
    int len = strlen(str);
    for (int r = 1; r < ROWS - 1; r++) {
        for (int c = 1; c < COLS - 1; c++) {
            int match = 1;
            for (int k = 0; k < len; k++) {
                if (r + k >= ROWS - 1 || c + k >= COLS - 1 || grid[r + k][c + k] != str[k]) {
                    match = 0;
                    break;
                }
            }
            if (match) {
                printf("Found diagonal match for \"%s\": row %d, column %d\n", str, r, c);
            }
        }
    }
}

int main() {
    // Example grid (outer rows and columns are null terminators)
    char grid[ROWS][COLS] = {
        {'\0', '\0', '\0', '\0', '\0', '\0', '\0', '\0', '\0', '\0'},
        {'\0', 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', '\0'},
        {'\0', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', '\0'},
        {'\0', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', '\0'},
        {'\0', 'y', 'z', 'a', 'b', 'c', 'd', 'e', 'f', '\0'},
        {'\0', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', '\0'},
        {'\0', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', '\0'},
        {'\0', 'w', 'x', 'y', 'z', 'a', 'b', 'c', 'd', '\0'},
        {'\0', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', '\0'},
        {'\0', '\0', '\0', '\0', '\0', '\0', '\0', '\0', '\0', '\0'}
    };

    search_horizontal(grid, "abc");
    search_vertical(grid, "aiq");
    search_diagonal(grid, "ajs");
}
