/**
 * @file main.h
 * @author CLAUSS Gauvain
 * @brief File containing the definition of the main file.
 * @date 2022-06-17
 *
 */

#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include "board.h"
#include "error_management.h"
#include "time.h"
#include <inttypes.h> // for uint8_t in printf

/**
 * @brief Init the srand
 *
 */
void init(void);

/**
 * @brief Ask menu to the user
 * @param state_of_game
 * @return uint8_t the choice
 */
uint8_t ask_menu(uint8_t state_of_game);

#endif // MAIN_H