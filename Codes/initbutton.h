#ifndef INITBUTTON_H
#define INITBUTTON_H

#include <QPushButton>
#include <QWidget>

class InitButton : public QPushButton {

    Q_OBJECT

public:
    InitButton(QWidget *parent,int row = 0, int column = 0);
    virtual ~InitButton();
    int getRowPos();
    int getColumnPos();


private:
    int Row;
    int Column;
};

#endif // INITBUTTON_H
