#include "initbutton.h"

InitButton::InitButton(QWidget *parent, int row, int column): QPushButton(parent), Row(1), Column(1) {
    Row = row;
    Column = column;
}

InitButton::~InitButton() {}

int InitButton::getColumnPos() {
    return Column;
}

int InitButton::getRowPos() {
    return Row;
}
