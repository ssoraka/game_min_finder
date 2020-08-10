//
// Created by ssoraka on 10.08.2020.
//
#include "game3.h"

/*
 * тема градиентный спуск
 * глянь на досуге
 * http://www.machinelearning.ru/wiki/index.php?title=%D0%9C%D0%B5%D1%82%D0%BE%D0%B4_%D0%B3%D1%80%D0%B0%D0%B4%D0%B8%D0%B5%D0%BD%D1%82%D0%BD%D0%BE%D0%B3%D0%BE_%D1%81%D0%BF%D1%83%D1%81%D0%BA%D0%B0
 * нас интересует первая формула
 *
 * и поищи более понятные объяснения
 *
 * суть в том, что
 * X{x0(i + 1), x1(i + 1),...} = X{x0(i) - a * df(x0)/dx0, x1(i) - a * df(x1)/dx1} =
 * X{
 * 		x0(i) - a * (f(x0(i), x1(i)) - f(x0(i - 1)), x1(i))/(x0(i) - x0(i - 1)),
 * 		x1(i) - a * (f(x0(i), x1(i)) - f(x0(i), x1(i - 1)))/(x1(i) - x1(i - 1)),...
 * }, где а - маленький размер шага
 *
 */

int main() {

	//инициализировал поле
	void *game = init_game(FIRST );
	//получил количество измерений - 1 для уровня FIRST
	int dim = get_game_dimension(game);

	srand(time(NULL));
	double x[1] = {rand()};

	printf("мое случайное значение x=%lf, f(x)=%lf\n", x[0], function(game, x));

	while (!is_this_answer(game, x)) {

		x[0] = 0.0;
		printf("в результате сложных поисков x=%lf, f(x)=%lf\n", x[0], function(game, x));
	}

	destroy_game(&game);
	return 0;
}