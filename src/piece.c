/**
 * @file piece.c
 * @author CLAUSS Gauvain
 * @brief File containing the functions to manage a piece
 * @date 2022-06-17
 *
 */

#include "piece.h"
#include <stdlib.h>

void piece_init_random(Piece *piece, const COLOR color)
{
    piece_init_specific(piece, rand() % 5, color, INITIAL);
}

void piece_init_specific(Piece *piece, const TYPE type, const COLOR color, const STATE state)
{
    piece->state = state;
    piece->color = color;
    piece->type = type;
}

void piece_set_state(Piece *piece, const STATE state)
{
    piece->state = state;
}

void piece_set_type(Piece *piece, const TYPE type)
{
    piece->type = type;
}

const STATE piece_get_state(Piece *piece)
{
    return piece->state;
}

const TYPE piece_get_type(Piece *piece)
{
    return piece->type;
}

const COLOR piece_get_color(Piece *piece)
{
    return piece->color;
}

void piece_free(Piece *piece)
{
    free(piece);
}