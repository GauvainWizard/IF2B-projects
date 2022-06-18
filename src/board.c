/**
 * @file board.c
 * @author CLAUSS Gauvain
 * @brief File containing the functions to manage the board
 * @date 2022-06-17
 *
 */

#include "board.h"

void board_init_standard(Board *board, uint8_t nb_square)
{
    // Initialize the board

    // Initialize the nb_square squares
    board->nb_square = nb_square;

    // Allocate the memory for the squares
    board->squares = malloc(sizeof(Square) * nb_square * nb_square);

    // Initialize the squares
    for (uint8_t y = 0; y < nb_square; ++y)
        for (uint8_t x = 0; x < nb_square; ++x)
        {
            // Get the square
            Square *square = board_get_square(board, x, y);

            // Initialize the square at (i, j)
            square_init(square, x, y);

            // Set a piece for the square (i, j) if it is on the first / second line or on the before-last / last line
            if (y <= 1 || y >= nb_square - 2)
            {

                // Allocate the memory for the piece
                Piece *piece = malloc(sizeof(Piece));

                // Initialize the piece randomly
                piece_init_random(piece, y <= 1 ? BLACK : WHITE);

                // Set the piece on the square (i, j)
                square_set_piece(square, piece);
            }
        }
    // Setup randomly a king for each player on first line
    Square *square = board_get_square(board, rand() % nb_square, 0);
    Piece *piece = square_get_piece(square);
    piece_set_type(piece, KING);
    // Setup randomly a king for each player on last line
    square = board_get_square(board, rand() % nb_square, nb_square - 1);
    piece = square_get_piece(square);
    piece_set_type(piece, KING);
}

Square *board_get_square(Board *board, uint8_t x, uint8_t y)
{
    return &board->squares[y * board->nb_square + x];
}

uint8_t board_get_nb_square(Board *board)
{
    return board->nb_square;
}

void board_free(Board *board)
{
    // Free the memory used by the squares
    for (uint8_t i = 0; i < board->nb_square; ++i)
        for (uint8_t j = 0; j < board->nb_square; ++j)
            square_free(&board->squares[i * board->nb_square + j]);
    free(board->squares);
}

void board_display(Board *board)
{
    // Get the number of square on the board
    uint8_t nb_square = board_get_nb_square(board);
    // Display the board
    for (uint8_t y = 0; y < nb_square; ++y)
    {
        for (uint8_t x = 0; x < nb_square; ++x)
        {
            Square *square = board_get_square(board, x, y);
            Piece *piece = square_get_piece(square);

            if (piece != NULL)
                printf("%s", piece_get_type(piece) == KING ? "K" : "P");
            else
                printf(".");
        }
        printf("\n");
    }
}