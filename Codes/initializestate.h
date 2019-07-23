#ifndef INITIALIZESTATE_H
#define INITIALIZESTATE_H

#pragma once

#include <QWidget>
#include <QFrame>
#include <QGridLayout>
#include <QVector>

#include "initbutton.h"
#include "macros_and_functions.h"

class InitializeState : public QWidget {

    Q_OBJECT

public:
    InitializeState(QWidget *parent = 0, int n = 0);
    QVector<QVector<bool>> getState();
    void draw();

private:
    int N;
    QGridLayout *grid;
    QVector<QVector<bool>> State;    

private slots:
    void initialize_state();
    void changeState();

};

#endif // INITIALIZESTATE_H
