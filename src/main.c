/**
 * @file main.c
 * @author CLAUSS Gauvain
 * @brief File containing the main function.
 * @date 2022-06-17
 *
 */
#include "main.h"

void init(void)
{
    // Init the srand
    srand(time(NULL));
}

uint8_t ask_menu(uint8_t state_of_game)
{

    char *menu_text;
    if (state_of_game == 1)
        menu_text = "1. Continue the game\n2. Save the game\n3. Quit\n";
    else if (state_of_game == 0)
        menu_text = "1. Play a new game\n2. Resume a game\n3. Quit\n";
    // Manage the error
    ErrorManagement error = error_init("Error. ", "Please, enter a valid choice: ");
    // Ask while the user doesn't enter a valid choice
    uint8_t choice = 0;
    char *choice_str = NULL;
    while (choice < 1 || choice > 3)
    {
        // Clear the console
        printf("\e[1;1H\e[2J");

        // Print the menu
        printf("%s", menu_text);
        printf("%s", error.full_sentence);

        // Get the choice
        scanf("%ms", &choice_str);
        choice = atoi(choice_str);

        // Update the error message
        error_update(&error);
    }

    // Free the memory used by the error
    error_free(&error);
    return choice;
}

int main(void)
{
    // Init the parameters
    init();
    uint8_t choice = ask_menu(0);
    // If the player wants to quit
    if (choice == 3)
        return 0;
    // If the player wants to resume a game
    else if (choice == 2)
        choice = ask_menu(1);
    // If the player wants to play a new game
    if (choice == 1)
    {
        // Create the board
        Board board;

        // Manage the error
        ErrorManagement error = error_init("Error. ", "Please, enter the number of square on the board between 6 and 12: ");

        // Ask the user for the number of square on the board between 6 and 12
        uint8_t nb_square = 0;
        char *nb_square_str = NULL;
        while (nb_square < 6 || nb_square > 12)
        {
            // Clear the console
            printf("\e[1;1H\e[2J");

            // Print the sentence
            printf("%s", error.full_sentence);

            // Get the choice
            scanf("%ms", &nb_square_str);
            nb_square = atoi(nb_square_str);

            // Update the error message
            error_update(&error);
        }
        error_free(&error);

        // Create the board
        board_init_standard(&board, nb_square);

        // Manage the error
        error = error_init("Error. ", "Please, enter the square you want to play (like : A3): ");

        // The actual player
        COLOR player = WHITE;
        // Convert the COLOR to a char
        char player_char[2][6] = {"White", "Black"};

        // Variables used to manage the square the user wants to play
        char *square_str = NULL;
        Square *square = NULL;

        // While the game is not over
        while (1)
        {
            // Ask the user for the square he wants to play like this: "A3"
            while (square == NULL)
            {
                printf("\e[1;1H\e[2J");
                printf("Up to play, player %s\n", player_char[player]);
                board_display(&board);
                // print the sentence
                printf("%s", error.full_sentence);
                scanf("%ms", &square_str);
                // Convert the string to a square
                uint8_t x = (uint8_t)(square_str[0] - 65);
                uint8_t y = atoi(square_str + 1) - 1;
                // check if x and y are valid
                if (x < nb_square && y < nb_square)
                {
                    // Print x and y
                    printf("x: %d\ny: %d\n", x, y);
                    // If x and y are valid, check if the square is empty
                    square = board_get_square(&board, x, y);
                    // check if the square is empty
                    Piece *piece = square_get_piece(square);
                    if (piece == NULL || piece_get_color(piece) != player)
                        square = NULL;
                }
                error_update(&error);
                square_str = NULL;
            }
            // Reset the error message
            error_reset(&error);
            // Reset the square
            square = NULL;
        }

        error_free(&error);
    }
    return 0;
}