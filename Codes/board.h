#ifndef BOARD_H
#define BOARD_H

#include <QWidget>
#include <QGridLayout>
#include <QVector>
#include <QPushButton>
#include "macros_and_functions.h"

class Board : public QWidget {

    Q_OBJECT

public:
    Board(QWidget *parent = 0, int n = 0);
    virtual ~Board();
    void update(QVector<QVector<bool>> state);



private:
    int N;
    QGridLayout *grid;
    QVector<QVector<bool>> State;

    void draw();
    //Initialize state with all cell DEAD
    void initialize_state();

};

#endif // BOARD_H
