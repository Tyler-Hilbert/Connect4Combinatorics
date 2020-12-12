# Connect 4 Combinatorics  
Calculates the number of unique connect 4 games that can be played.  
A game is considered unique by the order that the moves are made. This means that multiple unique games can result in the same board state if a different order of moves was made to get there.  

# How it works
This program uses a DFS to explore every possible unique game. The number of unique games will be equal to the number of leaf nodes in the DFS search tree.  

# Results
It was determined that the board size of Connect 4 is too large to do a complete DFS over.  
Various ways to decrease the search tree were investigated. It was determined that even when using symmetry to reduce the tree size the computation time was still too large to complete.
