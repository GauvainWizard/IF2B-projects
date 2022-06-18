#include <stdio.h>

#include "board.h"
#include "time.h"

int main(void)
{
    Board board;
    srand(time(NULL));
    board_init_standard(&board, 8);
    board_display(&board);
    return 0;
}