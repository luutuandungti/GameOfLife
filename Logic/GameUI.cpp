#include <iostream>
#include <vector>
#include <ctime>    
#include <cstdlib>
#include <curses.h>

#define M 10
#define ALIVE true
#define DEAD false

void draw_board(int n){
    //temp for testing
    int N;
    std::vector<std::vector<bool>> state;
    bool temp_bool = DEAD;
    N = n;
    for (int i = 0; i < N ; i++){    
        std::vector<bool> temp_bool_vector;        
        for (int j = 0; i < N; j++) {
            srand(time(0));
            int r = (rand() % 10);
            if (r<5){
                temp_bool_vector.push_back(DEAD);
            } else {
                temp_bool_vector.push_back(ALIVE);
            }           
        }
        state.push_back(temp_bool_vector);
    }
    clear(1);

    for (int i = 0; i < N; i++){
        cout << endl << "|" ; 
        for (int j = 0; j < N; j++){
            char c = ' ';
            if (state[i][j] == ALIVE)
                c = 'x';
            cout << "|" << c << "|"; 
        }
    }
}