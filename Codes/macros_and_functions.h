#ifndef MACROS_AND_FUNCTIONS_H
#define MACROS_AND_FUNCTIONS_H

#include <QVector>

#define ALIVE true
#define DEAD false

//Game automatic speed : time waiting to process to next state in ms
#define GAME_SPEED 500

// Find number of alive neighbors around given cell
int number_of_neighbors(int i, int j, int N, QVector<QVector<bool>> state);

//Game Logic: return the next state of the cell
bool game_logic(int neighbors, bool cell_state);

#endif // MACROS_AND_FUNCTIONS_H
