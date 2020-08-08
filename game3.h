
#ifndef UNTITLED_GAME3_H
#define UNTITLED_GAME3_H

#include <stdio.h>
#include <stdlib.h>

#define TRUE 1
#define FALSE 0

typedef int t_bool;

typedef enum	e_lvl
{
    FIRST,
    SECOND,
    THIRD
}				t_lvl;

/*
 * нужно найти минимум функции function (самое маленькое значение)
 * это единственная точка, координаты которой содержат значения типа int
 *
 * функция представляет из себя некий параболойд
 * function = (x[0] - x0[0])^2 + ... + (x[dim - 1] - x0[dim - 1])^2 + y0;
 * где dim - количество измерений
 * координаты точки минимума х0 и у0 выбираются случайно
 * для первого уровня сложности только одно измерение, где х0=0 с у0=0
 */

void    *init_game(t_lvl lvl);
int     get_game_dimension(void *game);
double  function(void *game, double *x);
t_bool  is_this_answer(void *game, double *x);
void    destroy_game(void **game);

#endif //UNTITLED_GAME3_H
