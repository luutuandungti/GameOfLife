#include "game_controller.h"

GameController::GameController(QWidget *parent) : QWidget(parent), N(5){
    MainLayout = new QHBoxLayout(this);

    board_dimension_input = new QLineEdit(this);
    board_dimension_input->setValidator(new QIntValidator(this));

    QPushButton *btn = new QPushButton(text_submit_button, this);

    InputLayout = new QFormLayout;
    InputLayout->addRow(text_introduction, board_dimension_input);
    InputLayout->addRow(btn);

    MainLayout->addLayout(InputLayout);

    setLayout(MainLayout);

    connect(btn, &QPushButton::clicked, this, &GameController::OnSubmit);
    //connect(btn, SIGNAL(clicked(bool)),this, SLOT(OnSubmit())); //alternated syntax
}

GameController::~GameController() {}

//Create layout that take input from player to create initial state
void GameController::SetInitialStage(){
    Init = new InitializeState(this, N);
    QLabel *initboard = new QLabel(this);
    initboard->setText("Please create initial state:");
    QPushButton *btn = new QPushButton("Done", this);
    connect(btn, &QPushButton::clicked, this, &GameController::GameOn);
    InputLayout->addRow(initboard);
    InputLayout->addRow(Init);
    InputLayout->addRow(btn);

}

//Create layout for running game
void GameController::GameOn() {
    State = new GameState(N, Init->getState());
    GameBoard = new Board(this, N);
    GameBoard->update(State->getState());

    QPushButton *btnStart = new QPushButton(text_start_button, this);
    connect(btnStart, &QPushButton::clicked, this, &GameController::OnStart);
    QPushButton *btnNext = new QPushButton(text_next_button, this);
    connect(btnNext, &QPushButton::clicked, this, &GameController::OnNext);

    while (!InputLayout->isEmpty()){
        InputLayout->removeRow(0);
    }
    InputLayout->addRow(GameBoard);
    InputLayout->addRow(btnStart);
    InputLayout->addRow(btnNext);
}

//Buttons
//Take input N from player
void GameController::OnSubmit() {
    N = board_dimension_input->text().toInt();

    while (!InputLayout->isEmpty()){
        InputLayout->removeRow(0);
    }
    SetInitialStage();
}

//Automatic run the game
void GameController::OnStart(){
    while (true) {
        State->nextstage();
        GameBoard->update(State->getState());
        QTest::qWait(GAME_SPEED);
    }
}

//Progress 1 state
void GameController::OnNext(){
    State->nextstage();
    GameBoard->update(State->getState());
}


