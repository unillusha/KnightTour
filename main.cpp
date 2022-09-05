/// kNIGHT TOUR
#include <iostream>
#include <iomanip>
#include <bits/stdc++.h>
#define N 8

using namespace std;

// essential parameters
int KnightTour(int x, int y, int movei, int sol[N][N],
                    int xMove[], int yMove[]);

// check validity of x and y
int isValid(int x, int y, int sol[N][N])
{
    return (x >= 0 && x < N && y >= 0 && y < N
            && sol[x][y] == -1);
}

// print the matrix funtion
void printSolution(int sol[N][N])
{
    for (int x = 0; x < N; x++) {
        for (int y = 0; y < N; y++)
            cout << " " << setw(2) << sol[x][y] << " ";
        cout << endl;
    }
}

// solves knight tour function
int solveKnightTour()
{
    int sol[N][N];

     // to intialise the matrix
    for (int x = 0; x < N; x++)
        for (int y = 0; y < N; y++)
            sol[x][y] = -1;

    // knight's possible movement (x,y)
    int xMove[8] = { 2, 1, -1, -2, -2, -1, 1, 2 };
    int yMove[8] = { 1, 2, 2, 1, -1, -2, -2, -1 };

    // knight start point
    sol[0][0] = 0;

    // knight explores possible tours
    if (KnightTour(0, 0, 1, sol, xMove, yMove) == 0) {
        cout << "No Solution ";
        return 0;
    }
    else
        printSolution(sol);

    return 1;

}

// finding knight tour & backtracking
int KnightTour(int x, int y, int movei, int sol[N][N],
                int xMove[8], int yMove[8])
{
    int k, next_x, next_y;
    if (movei == N * N)     // when the whole board is covered
        return 1;

    // test all possible moves from current point
    for (k = 0; k < 8; k++) {
        next_x = x + xMove[k];
        next_y = y + yMove[k];
        if (isValid(next_x, next_y, sol)) {
            sol[next_x][next_y] = movei;
            if (KnightTour(next_x, next_y, movei + 1, sol,
                            xMove, yMove)
                == 1)
                return 1;
            else

               // backtracking
                sol[next_x][next_y] = -1;
        }
    }
    return 0;
}

int main()
{
    solveKnightTour();
    return 0;
}
