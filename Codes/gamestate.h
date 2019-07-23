#ifndef GAMESTATE_H
#define GAMESTATE_H

#include <QVector>
#include "macros_and_functions.h"

#pragma once

class GameState {
    private:
        int N;
        QVector<QVector<bool>> State;

    public:
        GameState (int n, QVector<QVector<bool>> init_state);
        ~GameState();
        //Run this method to process to the next game state
        void nextstage();
        QVector<QVector<bool>> getState();
};

#endif // GAMESTATE_H
