/* Minmax algorithm - Tic tac toe game
 * 
 * Board representation : vector of 9 elements 
 * where coordinates can be calculated by 
 * [n/3, n%3]
 * 
 * Heuristic values for final game result
 * Win : +1
 * Lose : -1
 * Draw : 0
 */

#include <bits/stdc++.h>
using namespace std;

#define INF (1<<9);			// for calculating sum

struct Board_config {
	int cell[9], move;		// cel[i] is 'X' for computer and 'O' for player
};

struct Decision {		
	int val, rating;		// val represents min-max value and rating is the sum of leaves
};	

typedef struct Board_config BOARD;
typedef struct Decision DECISION;

int check_winner(BOARD bord) {
    /* return values :
     * win : 1
     * lose : -1
     * draw : 0
     * continue : 2
     */  
     
    register int i;
    register char a, b, c;
    
    //horizontal
    for (i=0; i<3; ++i) {
        a = bord.cell[i*3 + 0]; 	b = bord.cell[i*3 + 1]; 	c = bord.cell[i*3 + 2];
        if ((a == b) &&  (b == c)) {
			if (a == 'X') return 1;				// computer wins
			else if (a == 'O') return -1;		// computer loses	
		}	
    }

    //vertical
    for (i=0; i<3; ++i) {
        a = bord.cell[i];  b = bord.cell[i+3]; c = bord.cell[i+6];
        if ((a == b)  &&  (b == c)) {
			if (a == 'X') return 1;				// computer wins
			else if (a == 'O') return -1;		// computer loses	
		}	
    }

    //diagonal
    a = bord.cell[0]; b = bord.cell[4]; c = bord.cell[8];
    if ((a == b)  &&  (b == c)) {
		if (a == 'X') return 1;				// computer wins
		else if (a == 'O') return -1;		// computer loses	
	}	
	
    a = bord.cell[2]; b = bord.cell[4]; c = bord.cell[6];
    if ((a == b)  &&  (b == c)) {
		if (a == 'X') return 1;				// computer wins
		else if (a == 'O') return -1;		// computer loses	
	}
    
    if (bord.move == 9) return 0;				// Draw 
    else return 2;								// Continue game
}





DECISION minmax(BOARD brd, bool maxPlayer) {
	int bestval, status, i, rat;
	DECISION dec, t;
	
	status = check_winner(brd);	
	
	if (status == 2) {						// Continue game
		brd.move++;
		rat = 0;
		
		if (maxPlayer) {					// if maximizing player
			bestval = -INF;
			for (i=0; i<9; ++i) {
				if (brd.cell[i] == 0) {		// For each unmarked cell
					brd.cell[i] = 'X';
					t = minmax(brd, false);
					brd.cell[i] = 0;
					rat += t.rating;
					if (bestval < t.val) bestval = t.val;
				}
			}		
		}	
		
		
		else {								// if minimizing player
			bestval = INF;
			for (i=0; i<9; ++i) {
				if (brd.cell[i] == 0) {		// For each unmarked cell
					brd.cell[i] = 'O';
					t = minmax(brd, true);
					brd.cell[i] = 0;
					rat += t.rating;
					if (bestval > t.val) bestval = t.val;
				}
			}
		}	
		
		dec.val = bestval;
		dec.rating = rat;	
	}
		
	else {									// if draw or win by any player 
		dec.val = status;					// return heuristic value
		dec.rating = status;
	}
	
	return dec;
}

int getNextMove(BOARD bord) {
	DECISION d;
	int bestval, bestrat, bestmove, i;
	bord.move++;								// Increment board move
	
	bestval = -INF;
	for (i=0; i<9; ++i) {
		if (bord.cell[i] == 0) {				// For each unmarked cell
			cout << "i : " << i << endl;
			bord.cell[i] = 'X';
			d = minmax(bord, false);
			
			cout << "minmax val : " << d.val << "  rating : " << d.rating << endl << endl; 
			
			bord.cell[i] = 0;
			if ((d.val == 1) && (d.rating == 1)) {			// computer wins in next move
				bestmove = i;
				break;
			}	
			else if (bestval < d.val) {
				bestval = d.val;
				bestrat = d.rating;
				bestmove = i;
			}
			else if (bestval == d.val) {
				if (bestrat < d.rating) {
					bestrat = d.rating;
					bestmove = i;
				}
			}			
		}
	}	
	
	return bestmove;
}	

/*
void firstmove(bool fp) {
	if (fp) {		//first move made by computer
		move = 1;	
		notclicked[0][0] = false;
        //set icon X
        //make first move at (0, 0)
		ui->pb00->setIcon(*icon_x); ui->pb00->setIconSize(QSize(81,81));
		main_board.cell[0] = 'X';
	}
	else {			//first move made by player
		move = 0;
	}	
}	
*/

int main() {
	BOARD b;
	int nexmov;
	
	b.cell[0] = 'O';  b.cell[1] = 0;  b.cell[2] = 0;
	b.cell[3] = 0;  b.cell[4] = 'X'; b.cell[5] = 'O';
	b.cell[6] = 0;  b.cell[7] = 0;  b.cell[8] = 'X';
	b.move = 4;
	
	nexmov = getNextMove(b);
	cout << "next move : [" << nexmov/3 + 1 << ", " << nexmov%3 + 1 << "]" << endl;
	return 0;
}	
