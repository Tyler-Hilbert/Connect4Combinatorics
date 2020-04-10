#ifndef BOARD_H
#define	BOARD_H

#include <string>

#define MAX_COL 7
#define MAX_ROW 6

enum PositionPiece {EMPTY=-1, PLAYER1=0, PLAYER2=1};

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
  PositionPiece m_board[MAX_ROW][MAX_COL];
  bool checkPiecesForWinner(PositionPiece a, PositionPiece b, PositionPiece c, PositionPiece d);
};

#endif
