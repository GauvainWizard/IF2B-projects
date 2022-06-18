/**
 * @file piece.c
 * @author CLAUSS Gauvain
 * @brief File containing the functions to manage a piece
 * @date 2022-06-17
 *
 */

#include "piece.h"
#include <stdlib.h>

void piece_init_random(Piece *piece, COLOR color)
{
    piece_init_specific(piece, rand() % 5, color, INITIAL);
}

void piece_init_specific(Piece *piece, PIECE type, COLOR color, STATE state)
{
    piece->state = state;
    piece->color = color;
    piece->type = type;
}

void piece_set_state(Piece *piece, STATE state)
{
    piece->state = state;
}

void piece_set_type(Piece *piece, PIECE type)
{
    piece->type = type;
}

STATE piece_get_state(Piece *piece)
{
    return piece->state;
}

PIECE piece_get_type(Piece *piece)
{
    return piece->type;
}

COLOR piece_get_color(Piece *piece)
{
    return piece->color;
}

void piece_free(Piece *piece)
{
    free(piece);
}