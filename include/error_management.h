/**
 * @file error_management.h
 * @author CLAUSS Gauvain
 * @brief File containing the definition of the error_management struct
 * @date 2022-06-17
 *
 */

#ifndef ERROR_MANAGEMENT_H
#define ERROR_MANAGEMENT_H

#include <string.h>
#include <stdlib.h>

/**
 * @brief Structure of an error management
 *
 */
typedef struct
{
    /**
     * @brief The base sentence
     */
    char *base_sentence;

    /**
     * @brief Error message
     */
    char *error_sentence;

    /**
     * @brief The full sentence
     */
    char *full_sentence;
} ErrorManagement;

/**
 * @brief Initialize an Error structure.
 * @param error_sentence The error to print.
 * @param base_sentence The sentence to print.
 * @return An Error structure.
 */
ErrorManagement error_init(char *error_sentence, char *base_sentence);

/**
 * @brief Update the full sentence with the error message.
 * @param error The ErrorManagement structure.
 */
void error_update(ErrorManagement *error);

/**
 * @brief Reset the full sentence with the base sentence.
 * @param error The ErrorManagement structure.
 */
void error_reset(ErrorManagement *error);

/**
 * @brief Free the memory used by an ErrorManagement structure.
 * @param error The ErrorManagement structure.
 */
void error_free(ErrorManagement *error);

#endif // ERROR_MANAGEMENT_H