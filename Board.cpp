#include "Board.h"

// Initialize empty board
Board::Board() {
  for (int row = 0; row < MAX_ROW; row++) {
    for (int col = 0; col < MAX_COL; col++) {
      m_board[row][col] = EMPTY;
    }
  }
}

// Return board as formated string
std::string Board::toString() {
  std::string str = "";
  for (int row = 0; row < MAX_ROW; row++) {
    for (int col = 0; col < MAX_COL; col++) {
      std::string placeHolder;
      if (m_board[row][col] == EMPTY) {
        placeHolder = "*";
      } else {
        placeHolder = std::to_string(m_board[row][col]);
      }
      str += " " + placeHolder + " ";
    }
    str += "\n"; 
  }
  return str;
}

// Attempt to place piece in column.  Returns true is successful
// Updates turn
bool Board::place(int col, PositionPiece& turn) {
  for (int row = MAX_ROW; row >= 0; row--) {
    if (m_board[row][col] == EMPTY) {
      m_board[row][col] = turn;
      turn = static_cast<PositionPiece>((turn+1)%2); // Update turn
      return true;
    }
  }
  return false; // Piece was not able to be placed
}

// Returns who won or EMPTY if nobody won
PositionPiece Board::winner() {
  // Check verticals
  for (int col = 0; col < MAX_COL; col++) {
    // TODO - would it be easier to check this with a rotating array or other data structure?
    for (int row = 3; row < MAX_ROW; row++) {
      if (checkPiecesForWinner(m_board[row][col], m_board[row-1][col], m_board[row-2][col], m_board[row-3][col])) {
        printf ("v\n");
	      return m_board[row][col];
      }
    }
  }

  // Check horizontals
  for (int row = 0; row < MAX_ROW; row++) {
    for (int col = 3; col < MAX_COL; col++) {
       if (checkPiecesForWinner(m_board[row][col], m_board[row][col-1], m_board[row][col-2], m_board[row][col-3])) {
        printf ("h\n");
	      return m_board[row][col];
      }
    }
  }

  // Check diagonals
  for (int row = 3; row < MAX_ROW; row++) { // Up-left diagonol
    for (int col = 3; col < MAX_COL; col++) {
      if (checkPiecesForWinner(m_board[row][col], m_board[row-1][col-1], m_board[row-2][col-2], m_board[row-3][col-3])) {
        printf ("ul\n");
	      return m_board[row][col];
      }     
    }
  }
  for (int row = 0; row < MAX_ROW-3; row++) { // Up-right diagonol
    for (int col = 3; col < MAX_COL; col++) {
      if (checkPiecesForWinner(m_board[row][col], m_board[row+1][col-1], m_board[row+2][col-2], m_board[row+3][col-3])) {
        printf ("ur\n");
	      return m_board[row][col];
      }     
    }
  } 

  // No winners found, return EMPTY
  return EMPTY;
}

// Used by winner() to make it easier to see if 4 pieces are equal and not empty
bool Board::checkPiecesForWinner(PositionPiece a, PositionPiece b, PositionPiece c, PositionPiece d) {
  return (
    a != EMPTY &&
    a == b     &&
    a == c     &&
    a == d
  );
}
