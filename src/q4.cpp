#include <iostream>
#include <string>
#include <vector>
using namespace std;

vector<string> board;

void tile(int r, int c, int size, int hr, int hc);


void tile_over_2(int r, int c, int size, int hr, int hc){
    int half = size / 2;
    int holeQuadrant = (hr >= r + half ? 2 : 0) + (hc >= c + half ? 1 : 0);

    int cr0 = r + half - 1, cc0 = c + half - 1;
    int cr1 = r + half - 1, cc1 = c + half;
    int cr2 = r + half,     cc2 = c + half - 1;
    int cr3 = r + half,     cc3 = c + half;

    if (holeQuadrant != 0) board[cr0][cc0] = 'C';
    if (holeQuadrant != 1) board[cr1][cc1] = 'C';
    if (holeQuadrant != 2) board[cr2][cc2] = 'C';
    if (holeQuadrant != 3) board[cr3][cc3] = 'C';

    if (holeQuadrant == 0) tile(r, c, half, hr, hc);
    else tile(r, c, half, cr0, cc0);

    if (holeQuadrant == 1) tile(r, c + half, half, hr, hc);
    else tile(r, c + half, half, cr1, cc1);

    if (holeQuadrant == 2) tile(r + half, c, half, hr, hc);
    else tile(r + half, c, half, cr2, cc2);

    if (holeQuadrant == 3) tile(r + half, c + half, half, hr, hc);
    else tile(r + half, c + half, half, cr3, cc3);
}





void tile(int r, int c, int size, int hr, int hc) {
    if (size == 1) return;

    if (size == 2) {
        char color = (((r / 2) + (c / 2)) % 2 == 0) ? 'A' : 'B';

        if (!(r == hr && c == hc)) board[r][c] = color;
        if (!(r == hr && c + 1 == hc)) board[r][c + 1] = color;
        if (!(r + 1 == hr && c == hc)) board[r + 1][c] = color;
        if (!(r + 1 == hr && c + 1 == hc)) board[r + 1][c + 1] = color;

        return;
    }

    tile_over_2(r, c, size, hr, hc);

    
}
void printRows(int l, int r) {
    if (l >= r) return;

    if (r - l == 1) {
        cout << board[l] << '\n';
        return;
    }

    int m = (l + r) / 2;
    printRows(l, m);
    printRows(m, r);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, R, C;
    cin >> n;
    cin >> R >> C;

    R--;
    C--;

    board.assign(n, string(n, '?'));
    board[R][C] = '.';

    tile(0, 0, n, R, C);
    printRows(0, n);

    return 0;
}