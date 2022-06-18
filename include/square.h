/**
 * @file square.h
 * @author CLAUSS Gauvain
 * @brief File containing the definition of the square structure and the functions related to it.
 * @date 2022-06-17
 *
 */

#ifndef SQUARE_H
#define SQUARE_H

#include "piece.h"
#include "stdint.h"

/**
 * @brief Structure of a square.
 */
typedef struct
{
    /**
     * @brief The x-coordinates of the square.
     */
    uint8_t x;

    /**
     * @brief The y-coordinates of the square.
     */
    uint8_t y;

    /**
     * @brief The piece of the square.
     */
    Piece *piece;
} Square;

/**
 * @brief Init the square.
 * @param square The square to init.
 * @param x The x-coordinates of the square.
 * @param y The y-coordinates of the square.
 */
void square_init(Square *square, uint8_t x, uint8_t y);

/**
 * @brief Allocate the memory and set the piece of the square.
 * @param square The square in which we set the piece.
 * @param piece The piece to set.
 */
void square_set_piece(Square *square, Piece *piece);

/**
 * @brief Remove the piece of the square.
 * @param square The square in which we remove the piece.
 */
void square_remove_piece(Square *square);

/**
 * @brief Get the piece of the square.
 * @param square The square.
 * @return The piece of the square.
 */
Piece *square_get_piece(Square *square);

/**
 * @brief Free the memory and delete the piece of the square.
 * @param square The square in which we delete the piece.
 */
void square_free(Square *square);

#endif // SQUARE_H