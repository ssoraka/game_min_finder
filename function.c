/*
 * поиск точки минимума на карте в многомерном пространстве
 * функция должна представлять из себя что-то вроде
 * y = (x1 - b1)^2 + (x2 - b2)^2 + (x3 - b3)^2 + (x4 - b4)^2 + (x5 - b5)^2 + (x6 - b6)^2
 */
#include "game3.h"
#define FIRST_LVL_DIM 1
#define SECOND_LVL_DIM 3
#define THIRD_LVL_DIM 10
#define MAX_DIM 10

char *messages[4] = {
        "NOT BAD! TRY LVL SECOND\n",
        "VERY GOOD! TRY LVL THIRD\n",
        "BRILLIANT! YOU ARE GENIUS\n",
        "IN THIS VERSION LVL CAN BE FIRST, SECOND, THIRD\n"
};

typedef struct		s_game
{
    int             dim;
    double          x0[MAX_DIM];
    double          y0;
}					t_game;

int     get_dimension(t_lvl lvl) {
    if (lvl == FIRST)
        return (FIRST_LVL_DIM);
    else if (lvl == SECOND)
        return (SECOND_LVL_DIM);
    else
        return (THIRD_LVL_DIM);
}

int     init_x0(t_lvl lvl) {
    if (lvl == FIRST)
        return (0);
    else
        return (rand());
}

int     init_y0(t_lvl lvl) {
    if (lvl == THIRD)
        return (rand());
    else
        return (0);
}

void    *init_game(t_lvl lvl){
    t_game *game;
    int i;

    if (lvl != FIRST && lvl != SECOND && lvl != THIRD) {
        printf(messages[1]);
        return (NULL);
    }
    if (!(game = (t_game *)malloc(sizeof(t_game))))
        return (NULL);
    game->dim = get_dimension(lvl);
    srand(time(NULL));
    i = 0;
    while(i < game->dim) {
        game->x0[i] = init_x0(lvl);
        i++;
    }
    game->y0 = init_y0(lvl);
    return (game);
}

int     get_game_dimension(void *game){
    return (((t_game *)game)->dim);
}

void    destroy_game(void **game){
    free(*game);
    *game = NULL;
}

double  pow(double x, int pow) {
    double d;

    d = 1.0;
    while (pow > 0) {
        d *= x;
        pow--;
    }
    return (d);
}

double  function(void *game, double *x) {
    double *x0;
    double y0;
    int dim;
    int i;
    double answer;

    dim = ((t_game *)game)->dim;
    x0 = ((t_game *)game)->x0;
    y0 = ((t_game *)game)->y0;
    answer = 0.0;
    i = 0;
    while (i < dim) {
        answer += pow(x[i] - x0[i], 2);
        i++;
    }
    return (answer + y0);
}

void    print_message(int dim) {
    if (dim == FIRST_LVL_DIM)
        printf(messages[0]);
    else if (dim == SECOND_LVL_DIM)
        printf(messages[1]);
    else if (dim == THIRD_LVL_DIM)
        printf(messages[2]);
}

t_bool  is_this_answer(void *game, double *x) {
    double *x0;
    int dim;
    int i;
    long range;
    int xx[2];

    dim = ((t_game *)game)->dim;
    x0 = ((t_game *)game)->x0;
    i = 0;
    while (i < dim) {
        xx[0] = (int)(x[i]);
        xx[1] = (int)(x0[i]);
        range = (xx[0] > xx[1]) ? xx[0] - xx[1] : xx[1] - xx[0];
        if (range > 2)
            return (FALSE);
        i++;
    }
    print_message(dim);
    return (TRUE);
}

#undef FIRST_LVL_DIM
#undef SECOND_LVL_DIM
#undef THIRD_LVL_DIM
#undef MAX_DIM