/*
Савин Дмитрий ИВТ-22
113б Пусть n - натуральное число и пусть n!!означает 1*3*5*...*n для нечетного n и
2*4*....*n для чётного n. Для заданного натурального n вычислить: (-1)n + 1n!!
*/

#include <iostream>
#include <cstdlib>
#include "header.h"
#include <cassert>

int main(int argc, char* argv[]) {

	// Тесты
	assert(calculation(1) == 1);
	assert(calculation(2) == -2);
	assert(calculation(3) == 3);
	assert(calculation(4) == -8);
	assert(calculation(5) == 15);

	// Получение аргумента n из командной строки
	int n = atoi(argv[1]);

	// Вычисление результата
	int result = calculation(n);

	// Вывод
	std::cout << "The result is: " << result << std::endl;

	// Пауза для просмотра вывода
	system("pause");

	return 0;
}
