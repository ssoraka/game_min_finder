#include "game3.h"

/*
 * поиск точки минимума на карте в многомерном пространстве
 * функция должна представлять из себя что-то вроде
 * y = (x1 - b1)^2 + (x2 - b2)^2 + (x3 - b3)^2 + (x4 - b4)^2 + (x5 - b5)^2 + (x6 - b6)^2
 */


#define ALPHA 0.000005

void init(double *x, int dim) {
    int i = 0;
    while (i < dim) {
        x[i] = rand();
        i++;
    }
}

void init_prev(double *x, int dim) {
    int i = 0;
    while (i < dim) {
        x[i] += 100;
        i++;
    }
}

void    get_dx(void *game, double y, double *dx, double *x, double *x_prev, int dim) {
    int i;
    double tmp;
    double delta;

    i = 0;
    while (i < dim) {
        tmp = x[i];
        x[i] = x_prev[i];
        delta = (y - function(game, x)) / (tmp - x_prev[i]);
        if (delta == delta)
            dx[i] = delta;
        x[i] = tmp;
        i++;
    }
}

void    copy(double *x_prev, double *x, int dim) {
    int i;

    i = 0;
    while (i < dim) {
        x_prev[i] = x[i];
        i++;
    }
}

void    new_x(double *x, double *dx, int dim) {
    int i;

    i = 0;
    while (i < dim) {
        x[i] -= ALPHA * dx[i];
        i++;
    }
}

void    print(double *x, int dim) {
    int i;

    i = 0;
    while (i < dim) {
        printf("%lf_", x[i]);
        i++;
    }
    printf("\n");
}

int main() {

    double x[10];
    double x_prev[10];


    void *game = init_game(0);
    int dim = get_game_dimension(game);
    init(x, dim);
    init_prev(x_prev, dim);


    double f_prev = function(game, x_prev);
    double f = function(game, x);

    double dx[10];
    while (!is_this_answer(game, x)) {
        get_dx(game, f, dx, x, x_prev, dim);

        f_prev = f;
        copy(x_prev, x, dim);
        new_x(x, dx, dim);
        f = function(game, x);
        print(x, dim);
    }

    destroy_game(&game);

    return 0;
}
