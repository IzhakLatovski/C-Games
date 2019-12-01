#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

#define ROWS 20
#define COLUMNS 50


static void initialize_random_board(bool* board)
{
    unsigned int i=0;

    srand(time(0));
    for(i=0 ; i<ROWS*COLUMNS ; i++) {
        board[i]=rand()%2;
    }
}


static void print_board(bool* board)
{
    unsigned int i=0;

    for(i=0 ; i<ROWS*COLUMNS ; i++) {
        if(i%COLUMNS==0) {
            printf("\n");
        }
        board[i]==true ? printf("O") : printf(".");
    }
    printf("\n\n");
}


static void make_move(bool* current_board, bool* created_board)
{
    unsigned int i=0, j=0;

    for(i=0 ; i<ROWS ; i++) {
    	for(j=0 ; j<COLUMNS ; j++) {
    		unsigned int neighbours=0;

		    /* left top */
		    if(i>0 && j>0) {
		    	neighbours+=current_board[(i-1)*COLUMNS+(j-1)];
		    }
		    /* top */
		    if(i>0) {
		    	neighbours+=current_board[(i-1)*COLUMNS+(j)];
		    }
		    /* right top */
		    if(i>0 && j<COLUMNS-1) {
		    	neighbours+=current_board[(i-1)*COLUMNS+(j+1)];
		    }
		    /* left */
		    if(j>0) {
		    	neighbours+=current_board[(i)*COLUMNS+(j-1)];
		    }
		    /* right */
		    if(j<COLUMNS-1) {
		    	neighbours+=current_board[(i)*COLUMNS+(j+1)];
		    }
		    /* left bottom */
		    if(i<ROWS-1 && j>0) {
		    	neighbours+=current_board[(i+1)*COLUMNS+(j-1)];
		    }
		    /* bottom */
		    if(i<ROWS-1) {
		    	neighbours+=current_board[(i+1)*COLUMNS+(j)];
		    }
		    /* right bottom */
		    if(i<ROWS-1 && j<COLUMNS-1) {
		    	neighbours+=current_board[(i+1)*COLUMNS+(j+1)];
		    }

		    /* if I'm alive now */
		    if(current_board[i*COLUMNS+j]) {
		    	switch(neighbours) {
		    		case 0:
		    		case 1:
		    			created_board[i*COLUMNS+j]=false;
		    			break;
		    		case 2:
		    		case 3:
		    			created_board[i*COLUMNS+j]=true;
		    			break;
		    		case 4:
		    		case 5:
		    		case 6:
		    		case 7:
		    		case 8:
		    			created_board[i*COLUMNS+j]=false;
		    			break;
		    	}
		    /* if I'm dead, only 3 live neighbours will make me alive */
		    } else if(neighbours==3) {
		    	created_board[i*COLUMNS+j]=true;
		    } else {
		    	created_board[i*COLUMNS+j]=false;
		    }
    	}
    }
}


int main()
{
    bool board1[ROWS][COLUMNS];
    bool board2[ROWS][COLUMNS];
    bool* board=&board1[0][0];

    initialize_random_board(board);
    while(1) {
        print_board(board);
        if(board==&board1[0][0]) {
            make_move(&board1[0][0],&board2[0][0]);
            board=&board2[0][0];
        } else {
            make_move(&board2[0][0],&board1[0][0]);
            board=&board1[0][0];
        }
        sleep(1);
    }

    return 0;
}
