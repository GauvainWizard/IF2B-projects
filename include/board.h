/**
 * @file board.h
 * @author CLAUSS Gauvain
 * @brief File containing the definition of the board structure and the functions related to it.
 * @date 2022-06-17
 *
 */

#ifndef STRUCT_H
#define STRUCT_H

#include "square.h"
#include "stdint.h" // uint8_t
#include <stdio.h>  // printf
#include <stdlib.h> // malloc

/**
 * @brief Structure of a board.
 */
typedef struct
{
    /**
     * @brief 1D array of square.
     */
    Square *squares;

    /**
     * @brief Number of square on the board.
     */
    uint8_t nb_square;
} Board;

/**
 * @brief Init the board with a nb_square.
 * @param board The board to init.
 * @param nb_square The number of square on the board.
 */
void board_init_standard(Board *board, uint8_t nb_square);

/**
 * @brief Init the board with a file
 * @param board The board to init.
 * @param file The file to read.
 */
void board_init_from_file(Board *board, char *file);

/**
 * @brief Get the square of the board.
 * @param board The board.
 * @param x The x-coordinates of the square.
 * @param y The y-coordinates of the square.
 * @return The square.
 */
Square *board_get_square(Board *board, uint8_t x, uint8_t y);

/**
 * @brief Get the number of square on the board.
 * @param board The board.
 * @return The number of square on the board.
 */
uint8_t board_get_nb_square(Board *board);

/**
 * @brief Display the board.
 * @param board The board.
 */
void board_display(Board *board);

/**
 * @brief Free the memory used by the board.
 * @param board The board to free.
 */
void board_free(Board *board);

#endif // STRUCT_H