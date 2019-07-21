#include <vector>

#define ALIVE true
#define DEAD false

// Find number of alive neighbors around given cell
// INPUT
// int i, j                             : position of cell in array
// int N                                : dimension of the board (NxN)
// std::vector<std::vector<bool>>state  : board status represent by an array
// 
// RETURN number of neighbors 
int number_of_neighbors(int i, int j, int N, std::vector<std::vector<bool>> state){    
    int Neighbors = 0;
    if (i>0) {
        if (j>0){
            if(state[i-1][j-1] == ALIVE){
                Neighbors++;
            }                            
        }
        if (j< (N-1)) {
            if(state[i-1][j+1] == ALIVE){
                Neighbors++;
            }
        }
        if(state[i-1][j] == ALIVE){
            Neighbors++;
        }               
    }
    if (i < (N-1)) {
        if (j>0){
            if(state[i+1][j-1] == ALIVE){
                Neighbors++;
            }                        
        }
        if (j< (N-1)) {
            if(state[i+1][j+1] == ALIVE){
                Neighbors++;
            }
        }
        if(state[i+1][j] == ALIVE){
            Neighbors++;
        }            
    }
    if (j > 0){
        if(state[i][j-1] == ALIVE){
            Neighbors++;
        }
    }
    if (j < (N-1)){
        if(state[i][j+1] == ALIVE){
            Neighbors++;
        }
    }
    return Neighbors;
}

//Game Logic: return the next state of the cell
// INPUT
// int neighbors        :   number of alive neighbors of the cell
// bool cell_state      :   current state of the cell
// 
// RETURN state of the cell for next stage.
//
// Rules: If the cell is alive:
//          1. If it has 1 or no neighbors, it will turn "dead". As if by solitude.
//          2. if it has 4 or more neighbors, it will turn "dead". As if by overpopulation.
//          3. If it has 2 or 3 neighbors, it will remain "alive".
//        If the cell is dead:
//          1. If it has exactly three neighbors, it will turn "alive", as if by regrowth.
// Note: Based on the given rules, any number of neighbors that is not 2 or 3 will give the next cell state as DEAD.
//       2 neighbors return same state
//       3 neighbors return ALIVE
bool game_logic(int neighbors, bool cell_state) {
    switch (neighbors) {
        case 2: 
            return cell_state;
        case 3: 
            return ALIVE;
        default:
            return DEAD;
    }
}

class GameState {
    private:
        int N;
        std::vector<std::vector<bool>> State;
        
    public:
        GameState (int n) {
            bool temp_bool = DEAD;
            N = n;
            for (int i = 0; i < N ; i++){    
                std::vector<bool> temp_bool_vector;        
                for (int j = 0; i < N; j++) {
                    temp_bool_vector.push_back(DEAD);
                }
                State.push_back(temp_bool_vector);
            }
        }
        //Run this method to process to the next game state
        void nextstage() {            
            for (int i = 0; i < N ; i++){ 
                for (int j = 0; i < N; j++) {
                    State[i][j] = game_logic(number_of_neighbors(i,j,N,State), State[i][j]);           
                }
            }
        }
};