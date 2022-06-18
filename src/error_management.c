/**
 * @file error_management.c
 * @author CLAUSS Gauvain
 * @brief File containing the functions related to the error management.
 * @date 2022-06-17
 *
 */

#include "error_management.h"

ErrorManagement error_init(char *error_sentence, char *base_sentence)
{
    ErrorManagement error_struct;
    error_struct.base_sentence = malloc(sizeof(char) * (strlen(base_sentence) + 1));
    error_struct.error_sentence = malloc(sizeof(char) * (strlen(error_sentence) + 1));
    error_struct.full_sentence = malloc(sizeof(char) * (strlen(base_sentence) + strlen(error_sentence) + 1));
    strcpy(error_struct.base_sentence, base_sentence);
    strcpy(error_struct.error_sentence, error_sentence);
    strcpy(error_struct.full_sentence, error_struct.base_sentence);
    return error_struct;
}

void error_update(ErrorManagement *error)
{
    strcpy(error->full_sentence, error->error_sentence);
    strcat(error->full_sentence, error->base_sentence);
}

void error_reset(ErrorManagement *error)
{
    strcpy(error->full_sentence, error->base_sentence);
}

void error_free(ErrorManagement *error)
{
    free(error->base_sentence);
    free(error->error_sentence);
    free(error->full_sentence);
}