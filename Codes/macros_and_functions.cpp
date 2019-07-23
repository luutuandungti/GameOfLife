#include "macros_and_functions.h"

// Find number of alive neighbors around given cell
// INPUT
// int i, j                             : position of cell in array
// int N                                : dimension of the board (NxN)
// std::vector<std::vector<bool>>state  : board status represent by an array
//
// RETURN number of neighbors
int number_of_neighbors(int i, int j, int N, QVector<QVector<bool>> state){
    int Neighbors = 0;
    if (i>0) {
        if (j>0){
            if(state[i-1][j-1] == ALIVE){
                Neighbors++;
            }
        }
        if (j< (N-1)) {
            if(state[i-1][j+1] == ALIVE){
                Neighbors++;
            }
        }
        if(state[i-1][j] == ALIVE){
            Neighbors++;
        }
    }
    if (i < (N-1)) {
        if (j>0){
            if(state[i+1][j-1] == ALIVE){
                Neighbors++;
            }
        }
        if (j< (N-1)) {
            if(state[i+1][j+1] == ALIVE){
                Neighbors++;
            }
        }
        if(state[i+1][j] == ALIVE){
            Neighbors++;
        }
    }
    if (j > 0){
        if(state[i][j-1] == ALIVE){
            Neighbors++;
        }
    }
    if (j < (N-1)){
        if(state[i][j+1] == ALIVE){
            Neighbors++;
        }
    }
    return Neighbors;
}

//Game Logic: return the next state of the cell
// INPUT
// int neighbors        :   number of alive neighbors of the cell
// bool cell_state      :   current state of the cell
//
// RETURN state of the cell for next stage.
//
// Rules: If the cell is alive:
//          1. If it has 1 or no neighbors, it will turn "dead". As if by solitude.
//          2. if it has 4 or more neighbors, it will turn "dead". As if by overpopulation.
//          3. If it has 2 or 3 neighbors, it will remain "alive".
//        If the cell is dead:
//          1. If it has exactly three neighbors, it will turn "alive", as if by regrowth.
//
// Note: Based on the given rules, any number of neighbors that is not 2 or 3 will give the next cell state as DEAD.
//       2 neighbors return same state
//       3 neighbors return ALIVE
bool game_logic(int neighbors, bool cell_state) {
    switch (neighbors) {
        case 2:
            return cell_state;
        case 3:
            return ALIVE;
        default:
            return DEAD;
    }
}
