/**
 * @file piece.h
 * @author CLAUSS Gauvain
 * @brief File containing the definition of the piece structure and the functions related to it.
 * @date 2022-06-17
 *
 */

#ifndef PIECE_H
#define PIECE_H

/**
 * @brief Enum of the different types of pieces in the game.
 */
typedef enum
{
    ROOK,
    KNIGHT,
    BISHOP,
    PAWN,
    QUEEN,
    KING
} TYPE;

/**
 * @brief Enum of the two colors in the game.
 */
typedef enum
{
    WHITE,
    BLACK
} COLOR;

/**
 * @brief Enum of the two states of a piece.
 */
typedef enum
{
    INITIAL,
    MOVED
} STATE;

/**
 * @brief Structure of a piece.
 */
typedef struct
{
    /**
     * @brief Type of the piece.
     */
    TYPE type;

    /**
     * @brief Color of the piece.
     */
    COLOR color;

    /**
     * @brief State of the piece.
     */
    STATE state;
} Piece;

/**
 * @brief Init the piece with random piece.
 * @param piece Pointer to the piece to init.
 * @param color Color of the piece.
 */
void piece_init_random(Piece *piece, COLOR color);

/**
 * @brief Init the piece with specific data
 * @param piece The piece to init.
 * @param type Type of the piece.
 * @param color Color of the piece.
 * @param state State of the piece.
 */
void piece_init_specific(Piece *piece, const TYPE type, const COLOR color, const STATE state);

/**
 * @brief Set the state of the piece.
 * @param piece The piece to change.
 * @param state The new state.
 */
void piece_set_state(Piece *piece, const STATE state);

/**
 * @brief Set the type of the piece.
 * @param piece The piece to change.
 * @param type The new type.
 */
void piece_set_type(Piece *piece, const TYPE type);

/**
 * @brief Get the type of the piece.
 * @param piece The piece to get the type.
 */
const TYPE piece_get_type(Piece *piece);

/**
 * @brief Get the color of the piece.
 * @param piece The piece to get the color.
 */
const COLOR piece_get_color(Piece *piece);

/**
 * @brief Get the state of the piece.
 * @param piece The piece to get the state.
 */
const STATE piece_get_state(Piece *piece);

/**
 * @brief Free the piece.
 * @param piece The piece to Free.
 */
void piece_free(Piece *piece);

#endif // PIECE_H