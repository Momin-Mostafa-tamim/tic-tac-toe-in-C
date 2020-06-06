#include <stdio.h>
void board(char *array) //done
{
    printf("\n %c | %c | %c \n", *array, *(array + 1), *(array + 2));
    printf("-----------");
    printf("\n %c | %c | %c \n", *(array + 3), *(array + 4), *(array + 5));
    printf("-----------");
    printf("\n %c | %c | %c \n", *(array + 6), *(array + 7), *(array + 8));
}
void name(char *a, char *b) //done
{
    printf("Enter the name for player 1 : \n");
    scanf("%s", a);
    printf("Enter the name for second player : \n");
    scanf("%s", b);
    printf("%s is 'X' and %s is 'Y'", a, b);
}
void move(char *array, char marker) //done
{
    int temp;
    printf("Enter a number to place your marker : ");
    scanf("%d", &temp);
    // it will also have a if else condition to check if the move is taken or not//done
    if (*(array + temp) == 'X' || *(array + temp) == 'Y')
    {
        printf("\n\n\n\n\n\n\nYou are cheating, your move is canceled.\n\n\n\n\n\n\n");
    }
    else
    {
        //it will also change the array.(board)//done
        *(array + temp) = marker;
    }
}
char marker(int a) //done
{
    if (a % 2 == 0)
    {
        return 'X';
    }
    else
    {
        return 'Y';
    }
}
int winlogic(char *array) //done
{
    if (array[0] == 'X' && array[1] == 'X' && array[2] == 'X')
    {
        printf("player one won");
        return 1;
    }
    else if (array[3] == 'X' && array[4] == 'X' && array[5] == 'X')
    {
        printf("player one won");
        return 1;
    }
    else if (array[6] == 'X' && array[7] == 'X' && array[8] == 'X')
    {
        printf("player one won");
        return 1;
    }
    else if (array[0] == 'X' && array[4] == 'X' && array[8] == 'X')
    {
        printf("player one won");
        return 1;
    }
    else if (array[6] == 'X' && array[4] == 'X' && array[2] == 'X')
    {
        printf("player one won");
        return 1;
    }
    else if (array[0] == 'X' && array[3] == 'X' && array[6] == 'X')
    {
        printf("player one won");
        return 1;
    }
    else if (array[1] == 'X' && array[4] == 'X' && array[7] == 'X')
    {
        printf("player one won");
        return 1;
    }
    else if (array[2] == 'X' && array[5] == 'X' && array[8] == 'X')
    {
        printf("player one won");
        return 1;
    }
    else if (array[0] == 'Y' && array[1] == 'Y' && array[2] == 'Y')
    {
        printf("player two won");
        return 2;
    }
    else if (array[3] == 'Y' && array[4] == 'Y' && array[5] == 'Y')
    {
        printf("player two won");
        return 2;
    }
    else if (array[6] == 'Y' && array[7] == 'Y' && array[8] == 'Y')
    {
        printf("player two won");
        return 2;
    }
    else if (array[0] == 'Y' && array[4] == 'Y' && array[8] == 'Y')
    {
        printf("player two won");
        return 2;
    }
    else if (array[6] == 'Y' && array[4] == 'Y' && array[2] == 'Y')
    {
        printf("player two won");
        return 2;
    }
    else if (array[0] == 'Y' && array[3] == 'Y' && array[6] == 'Y')
    {
        printf("player two won");
        return 2;
    }
    else if (array[1] == 'Y' && array[4] == 'Y' && array[7] == 'Y')
    {
        printf("player two won");
        return 2;
    }
    else if (array[2] == 'Y' && array[5] == 'Y' && array[8] == 'Y')
    {
        printf("player two won");
        return 2;
    }
    else
    {
        return 0;
    }
}
int main()
{
    char array[20] = "0123456789";
    char name1[100];
    char name2[100];
    int a = 0; //needed for marker()
    int win = 0;
    name(name1, name2);
    board(array);

    while (a != 9 && win != 1 && win != 2)
    {
        win = winlogic(array);
        if (win == 1 || win == 2)
        {
            if (win == 1)
            {
                printf("\n%s is winner !\n", name1);
            }
            else
            {
                printf("\n%s is winner !\n", name2);
            }
        }
        else
        {

            char mark = marker(a);
            ++a;
            move(array, mark);
            board(array);
        }
    }

    return 0;
}