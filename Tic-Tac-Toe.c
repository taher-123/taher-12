#include <stdio.h>

int main() {

    printf("WELCOME TO PLAY TIC-TAC-TOE ( GAME )\n");


    char arr[9] = {'1','2','3','4','5','6','7','8','9'};
    int player_1;
    int player_2;

    for (int i = 0; i < 9; i++) {
        printf("Can't use one Number Twice  (0-8)\n");
        printf("Enter your position Player_1 (0-8)\n");
        scanf("%d", &player_1);

        printf("Can't use one Number Twice  (0-8)\n");
        printf("Enter your position Player_2 (0-8)\n");
        scanf("%d", &player_2);

        arr[player_1] = 'X';
        arr[player_2] = 'O';
    }


    printf("\n");
    printf(" %c | %c | %c\n", arr[0], arr[1], arr[2]);
    printf("---|---|---\n");
    printf(" %c | %c | %c\n", arr[3], arr[4], arr[5]);
    printf("---|---|---\n");
    printf(" %c | %c | %c\n", arr[6], arr[7], arr[8]);


    if ((arr[0]=='X' && arr[1]=='X' && arr[2]=='X') ||
        (arr[3]=='X' && arr[4]=='X' && arr[5]=='X') ||
        (arr[6]=='X' && arr[7]=='X' && arr[8]=='X') ||
        (arr[0]=='X' && arr[3]=='X' && arr[6]=='X') ||
        (arr[1]=='X' && arr[4]=='X' && arr[7]=='X') ||
        (arr[2]=='X' && arr[5]=='X' && arr[8]=='X') ||
        (arr[0]=='X' && arr[4]=='X' && arr[8]=='X') ||
        (arr[2]=='X' && arr[4]=='X' && arr[6]=='X')) {
        printf("CONGRATULATIONS PLAYER_1 (WIN)\n");
    }

    else if ((arr[0]=='O' && arr[1]=='O' && arr[2]=='O') ||
             (arr[3]=='O' && arr[4]=='O' && arr[5]=='O') ||
             (arr[6]=='O' && arr[7]=='O' && arr[8]=='O') ||
             (arr[0]=='O' && arr[3]=='O' && arr[6]=='O') ||
             (arr[1]=='O' && arr[4]=='O' && arr[7]=='O') ||
             (arr[2]=='O' && arr[5]=='O' && arr[8]=='O') ||
             (arr[0]=='O' && arr[4]=='O' && arr[8]=='O') ||
             (arr[2]=='O' && arr[4]=='O' && arr[6]=='O')) {
        printf("CONGRATULATIONS PLAYER_2 (WIN)\n");
    }
    else {
        printf("GAME DRW");
    }

    return 0;
}

