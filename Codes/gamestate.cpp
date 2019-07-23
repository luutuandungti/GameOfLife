#include "gamestate.h"

GameState::GameState (int n, QVector<QVector<bool>> init_state) : N(0) {
    N = n;
    State = init_state;
}

GameState::~GameState(){}

void GameState::nextstage() {
    QVector<QVector<bool>> newState;
    for (int i = 0; i < N ; i++){
        QVector<bool> temp_bool_vector;
        for (int j = 0; j < N; j++) {
            temp_bool_vector.push_back(game_logic(number_of_neighbors(i,j,N,State), State[i][j]));
        }
        newState.push_back(temp_bool_vector);
    }
    State = newState;
}

QVector<QVector<bool>> GameState::getState() {
    return State;
}
