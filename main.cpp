#include "Board.h" // TODO - should I include h files or cpp?

#include <iostream>
#include <string>
#include <vector> // FIXME -- debug

#include <unistd.h> // FIXME - remove for sleep 

unsigned long long int GAME_COUNTER = 0; // FIXME - will this be large enough or will it overflow?


/*
void recPlace(Board board, int col, PositionPiece turn) {
  printf("%s\n", board.toString().c_str());
  sleep (.1);

 // FIXME - add bootstrap condition
  
  bool placed = false;
  // Find lowest piece col or greater that can be placed
  for (int i = col; i < MAX_COL; i++) {
    placed = board.place (i, turn);
    if (placed) {
      recPlace(board, col, turn);
//      break;
    }
  }

  if (!placed) {
    // FIXME 
  }
}
*/

// FIXME - should these be passed by reference?
void DFS(int col, PositionPiece turn, std::vector<int> plays, Board board) {
  // Place current piece
  if (board.place(col, turn)) {
    plays.push_back(col);
    std::string playStr = "";
    for (int play : plays) {
      playStr += std::to_string(play) + " ";
    }
    /* FIXME debug
    printf("Plays: %s\n", playStr.c_str()); 
    printf("%s\n", board.toString().c_str());
    // sleep(1);
    */
    
    // FIXME - add check for draw
    
    if (board.winner() != EMPTY) { // Check if someone won
      GAME_COUNTER += 1;
      // sleep(2);
      return;
    }
  } else {
    return;
  }

  // Place next piece
  for (int i = 0; i < MAX_COL; i++) {
    DFS(i, turn, plays, board);
  }
}

int main() {
  Board board;
  PositionPiece turn = PLAYER1;
  std::vector<int> plays;
  for (int firstCol = 0; firstCol < MAX_COL; firstCol++) {
    DFS(firstCol, turn, plays, board);
  }

  printf ("GAME COUNT %llu", GAME_COUNTER);

/*
  Board board;
  PositionPiece turn = PLAYER1; // The piece also keeps track of whose turn it is

  recPlace (board, 0, turn);  
*/
/*
  PositionPiece winner = EMPTY; // The winner of the game
  while (winner == EMPTY) { // FIXME
    // Place piece
    board.place(0, turn);

    // Print board
    printf("%s\n", board.toString().c_str());
    
    // Check if someone won
    winner = board.winner();
  }

  printf("Winner player %i\n", winner); 
*/


  exit (EXIT_SUCCESS);
}
