#include "Board.h"

#include <iostream>
#include <string>
#include <vector>

#include <unistd.h> // Only needed when debugging for sleep mode``

unsigned long long int GAME_COUNTER = 0;

void incrementGameCounter() {
  if (GAME_COUNTER < ULLONG_MAX) {
    GAME_COUNTER += 1;
    printf("Game counter %llu\n", GAME_COUNTER);
    sleep(2);
  } else {
    printf("WARNING: Reached max game_counter size");
    printf ("Press any key to continue");
    system("pause"); // Windows
    system("read"); // Mac / Linux
  }
}

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
      incrementGameCounter();
      return;
    }
    if (board.winner() != EMPTY) { // Check if someone won
      incrementGameCounter();
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
