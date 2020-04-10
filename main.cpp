#include "Board.h" // TODO - should I include h files or cpp?

#include <iostream>
#include <string>
#include <vector>

#include <unistd.h> // Only needed when debugging for sleep mode``

unsigned long long int GAME_COUNTER = 0; // FIXME - will this be large enough or will it overflow?


// FIXME - should these be passed by reference?
void DFS(int col, PositionPiece turn, std::vector<int> plays, Board board) {
  // Place current piece
  if (board.place(col, turn)) {
    plays.push_back(col);
    std::string playStr = "";
    for (int play : plays) {
      playStr += std::to_string(play) + " ";
    }

    printf("Plays: %s\n", playStr.c_str()); 
    printf("%s\n", board.toString().c_str());
    //usleep(500);
    sleep(1);

    // Check for complete game
    if (plays.size() == (MAX_ROW*MAX_COL)) { // Check if board if full
      printf("Board Full\n");
      GAME_COUNTER += 1;
      printf("Game counter %llu\n", GAME_COUNTER);
      sleep(2);
      return;
    }
    if (board.winner() != EMPTY) { // Check if someone won
      GAME_COUNTER += 1;
      printf("Game counter %llu\n", GAME_COUNTER);
      sleep(2);
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

  exit (EXIT_SUCCESS);
}
