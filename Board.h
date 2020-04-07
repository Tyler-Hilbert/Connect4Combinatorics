#ifndef BOARD_H
#define	BOARD_H

#include <string>

#define MAX_COL 6
#define MAX_ROW 7

enum PositionPiece {EMPTY=-1, PLAYER1=0, PLAYER2=1}; // TODO - does it make sense to use this for turn and winner?

/*
  Class that has all the Connect 4 board data and functions
*/
class Board {
public:
  Board();
  std::string toString();
  bool place(int col, PositionPiece& turn);
  PositionPiece winner();

private:
  PositionPiece m_board[MAX_ROW][MAX_COL]; // TODO - Would it make more sense to save this in a different data structure?
  bool checkPiecesForWinner(PositionPiece a, PositionPiece b, PositionPiece c, PositionPiece d);
};

#endif
