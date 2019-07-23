#include "board.h"

Board::Board(QWidget *parent, int n) : QWidget(parent) {
    N = n;
    grid = new QGridLayout(this);
    initialize_state();
    draw();
}

Board::~Board() {}

void Board::update(QVector<QVector<bool>> state){
    State = state;
    draw();
}

void Board::draw(){
    for (int i = 0; i < N ; i++){
        for (int j = 0; j < N; j++) {
            QPushButton *btn = new QPushButton(this);
            btn->setFixedSize(50, 50);
            if(State[i][j] == ALIVE) {
                btn->setStyleSheet("background-color:black;");
            } else {
                btn->setStyleSheet("background-color:white;");
            }
            grid->addWidget(btn, i, j);
        }
    }
    setLayout(this->grid);
}

void Board::initialize_state(){
    for (int i = 0; i < N ; i++){
        QVector<bool> temp_bool_vector;
        for (int j = 0; j < N; j++) {
            temp_bool_vector.push_back(DEAD);
        }
        State.push_back(temp_bool_vector);
    }
}
