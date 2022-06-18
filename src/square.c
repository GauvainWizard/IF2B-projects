/**
 * @file square.c
 * @author CLAUSS Gauvain
 * @brief File containing the functions to manage a square
 * @date 2022-06-17
 *
 */

#include "board.h"

void square_init(Square *square, uint8_t x, uint8_t y)
{
    square->x = x;
    square->y = y;
    square->piece = NULL;
}

void square_set_piece(Square *square, Piece *piece)
{
    square->piece = piece;
}

Piece *square_get_piece(Square *square)
{
    return square->piece;
}

void square_remove_piece(Square *square)
{
    square->piece = NULL;
}

void square_free(Square *square)
{
    piece_free(square->piece);
}