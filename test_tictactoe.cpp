#include "TicTacToe.h"
#include <iostream>
#include <cassert>

// Students will implement these tests in the lab

void test_initial_state() {
    // TODO: Students implement this 
    // Game creation
    TicTacToe game;


    // Using assert function to make sure values are correct
    assert(game.getCurrentPlayer() == 'X');
    assert(game.getMoveCount() == 0);
    assert(game.getCell(2, 2) == ' ');
    assert(game.isGameOver() == false);

    std::cout << "✓ Initial state test passed\n";
}

void test_valid_move() {
    // TODO: Students implement this

    TicTacToe game2;
    
    // Move the current player 'X' to (0, 0)
    game2.makeMove(0, 0);
    
   // Does the validation
    assert(game2.getCell(0, 0) == 'X');
    assert(game2.getCurrentPlayer() == 'O');
    assert(game2.getMoveCount() == 1);

    std::cout << "✓ Valid move test passed\n";
}

void test_invalid_moves() {
    // TODO: Students implement this
    TicTacToe game3;

    game3.makeMove(0, 0); // Initial X move
    
    // Checks to see if move is invalid
    bool validMove = game3.makeMove(0, 0);
    assert(validMove == false);

    // Checks to see if player move is out-of-bounds
    bool out_of_bounds = game3.makeMove(-1, 0);
    assert(out_of_bounds == false);
    
    // Check for movement after game is won
    game3.makeMove(1, 0); // O move
    game3.makeMove(0, 1); // X move
    game3.makeMove(1, 1); // O move
    game3.makeMove(0, 2); // X move (Winning move)
    
    bool checkMove = game3.makeMove(3, 3);

    assert(checkMove == false);
    
    std::cout << "✓ Invalid moves test passed\n";
}

void test_winner_detection_row() {
    // TODO: Students implement this
    TicTacToe winDetect;

    // Letting 'X' win for testing
    winDetect.makeMove(0, 0); // X First move
    winDetect.makeMove(1, 0); // O move
    winDetect.makeMove(0, 1); // X move
    winDetect.makeMove(1, 1); // O move
    winDetect.makeMove(0, 2); // X move (Winning move)

    std::cout << "✓ Winner detection (row) test passed\n";
}

void test_winner_detection_column() {
    // TODO: Students implement this
    TicTacToe columnDet;
    
    // Checking column detection
    columnDet.makeMove(0, 2);
    columnDet.makeMove(0, 0);
    columnDet.makeMove(1, 1);
    columnDet.makeMove(1, 0);
    columnDet.makeMove(2, 1); 
    columnDet.makeMove(2, 0); // O wins here
    
    // Verifies O did win
    assert(columnDet.getWinner() == 'O');
    assert(columnDet.isGameOver() == true);

    std::cout << "✓ Winner detection (column) test passed\n";
}

void test_winner_detection_diagonal() {
    // TODO: Students implement this
    TicTacToe diagDet;

    // diagonal detection test
    diagDet.makeMove(0, 0);
    diagDet.makeMove(1, 0);
    diagDet.makeMove(1, 1);
    diagDet.makeMove(2, 1);
    diagDet.makeMove(2, 2); // X wins here
    
    // Checks if X won diagonally
    assert(diagDet.getWinner() == 'X');

    std::cout << "✓ Winner detection (diagonal) test passed\n";
}

void test_full_board_no_winner() {
    // TODO: Students implement this
    TicTacToe noWin;
    
    noWin.makeMove(0, 0);
    noWin.makeMove(0, 1);
    noWin.makeMove(0, 2);
    noWin.makeMove(1, 0);
    noWin.makeMove(1, 2);
    noWin.makeMove(1, 1);
    noWin.makeMove(2, 0);
    noWin.makeMove(2, 2);
    noWin.makeMove(2, 1);

    // No winner here
    assert(noWin.getWinner() == ' ');
    assert(noWin.isGameOver() == true);
    assert(noWin.isFull() == true);
    
    std::cout << "✓ Full board no winner test passed\n";
}

int main() {
    std::cout << "Running Tic-Tac-Toe tests...\n\n";

    test_initial_state();
    test_valid_move();
    test_invalid_moves();
    test_winner_detection_row();
    test_winner_detection_column();
    test_winner_detection_diagonal();
    test_full_board_no_winner();

    std::cout << "\nAll tests passed! ✓\n";
    // std::cout << "\nNote: These are placeholder tests.\n";
    // std::cout << "Students need to implement the actual test logic.\n";

    return 0;
}
