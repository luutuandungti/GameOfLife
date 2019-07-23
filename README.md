# GameOfLife
Quick description of each class:
Game is control by class GameController. In this class, methods for buttons are used to change layout depend on the state of the game.

GameState store the back-end data for the game. It stores the array of booleans for the state of each cell.

Board is the graphical presentation of the cells and their states. 

InitButton is used create interactive cell for player to generate initial state.

InitializeState is the layout of InitButton and take their input data, sending it to back-end data.

macros_and_function.h store setting of the game and two stand alone functions that return number of alive neighbors (number_of_neighors) and game rules (game_logic). If game rules changed, only game_logic function needed to be changed.

text.h store text for button or text field. Implementing this way could increase the reusability and make it easier to deploy to multiple languages.
