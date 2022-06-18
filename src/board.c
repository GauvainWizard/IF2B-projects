/**
 * @file board.c
 * @author CLAUSS Gauvain
 * @brief File containing the functions to manage the board
 * @date 2022-06-17
 *
 */

#include "board.h"

void board_init_standard(Board *board, const uint8_t nb_square)
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

Square *board_get_square(Board *board, const uint8_t x, const uint8_t y)
{
    return &board->squares[y * board->nb_square + x];
}

const uint8_t board_get_nb_square(Board *board)
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
    // Char used to to display the board
    char types[6][2] = {"Ro", "Kn", "Bi", "Pa", "Qu", "Ki"};
    char colors[2] = {'W', 'B'};
    // Get the number of square on the board
    uint8_t nb_square = board_get_nb_square(board);
    // Display the column letters
    printf("  ");
    for (uint8_t i = 0; i < nb_square; ++i)
        printf("   %c  ", i + 65); // 65 is the ascii code for 'A'
    printf("\n");
    // Display the board
    for (uint8_t y = 0; y < nb_square; ++y)
    {
        // Display a line -
        printf("  |");
        for (uint8_t i = 0; i < nb_square; ++i)
            printf("-----|");
        printf("\n");
        // Display the number of the line
        printf("%d |", y + 1);
        // Display the line
        for (uint8_t x = 0; x < nb_square; ++x)
        {
            // Get the square
            Square *square = board_get_square(board, x, y);
            // Get the piece on the square
            Piece *piece = square_get_piece(square);

            // If there is a piece on the square
            if (piece != NULL)
            {
                TYPE type = piece_get_type(piece);
                COLOR color = piece_get_color(piece);
                printf(" %c%c%c ", types[type][0], types[type][1], colors[color]);
                printf("|");
            }
            // If there is no piece on the square
            else
            {
                printf("     ");
                printf("|");
            }
        }
        printf("\n");
    }
    // Display a line -
    printf("  |");
    for (uint8_t i = 0; i < nb_square; ++i)
        printf("-----|");
    printf("\n");
}