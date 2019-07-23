#ifndef GAMECONTROLLER_H
#define GAMECONTROLLER_H

#pragma once

#include <QWidget>
#include <QFormLayout>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
#include <QIntValidator>
#include <QHBoxLayout>
#include <QTest>

#include "text.h"
#include "gamestate.h"
#include "board.h"
#include "initializestate.h"
#include "macros_and_functions.h"

class GameController : public QWidget {

    Q_OBJECT

public:
    GameController(QWidget *parent = 0);
    virtual ~GameController();

private slots:
    void OnSubmit();
    void GameOn();
    void OnStart();
    void OnNext();

private:
    int N;
    //GameState *aData;
    QLineEdit *board_dimension_input;
    Board *GameBoard;
    InitializeState *Init;
    GameState *State;

    QHBoxLayout *MainLayout;
    QFormLayout *InputLayout;
    void SetInitialStage();
};

#endif // USERINPUTFORM_H
