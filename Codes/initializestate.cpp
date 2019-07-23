#include "initializestate.h"

InitializeState::InitializeState(QWidget *parent, int n):QWidget(parent), N(5) {
    N = n;
    grid = new QGridLayout(this);
    initialize_state();
}

void InitializeState::initialize_state(){
    for (int i = 0; i < N ; i++){
        QVector<bool> temp_bool_vector;
        for (int j = 0; j < N; j++) {
            temp_bool_vector.push_back(DEAD);
            InitButton *btn = new InitButton(this, i, j);
            btn->setStyleSheet("background-color:white;");
            btn->setFixedSize(50, 50);
            connect(btn, SIGNAL(clicked(bool)),this, SLOT(changeState()));
            grid->addWidget(btn, i, j);
        }
        State.push_back(temp_bool_vector);
    }
    setLayout(grid);
}

QVector<QVector<bool>> InitializeState::getState() {
    return State;
}

void InitializeState::changeState() {
    InitButton *button = qobject_cast<InitButton *>(sender());
    State[button->getRowPos()][button->getColumnPos()] = !State[button->getRowPos()][button->getColumnPos()];

    if (State[button->getRowPos()][button->getColumnPos()] == DEAD) {
        button->setStyleSheet("background-color:white;");
    } else {
        button->setStyleSheet("background-color:black;");
    }
}
