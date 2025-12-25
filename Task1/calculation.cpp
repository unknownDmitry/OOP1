/*
Савин Дмитрий ИВТ-22
113б Пусть n - натуральное число и пусть n!! означает 1*3*5*...*n для нечетного n и
2*4*....*n для чётного n. Для заданного натурального n вычислить: (-1)^(n+1) * n!!
*/

#include "calculation.h"

/// Вычисляет значение на основе n (произведение четных/нечетных чисел с чередующимся знаком)
int calculation(int n) {
	// Проверка натурального n
	assert(n >= 1);

	// Вычисление n!!
	int mult = 1;

	// Цикл по четным (для четного n) или нечетным (для нечетного n) числам
	for (int i = (n % 2 == 0 ? 2 : 1); i <= n; i += 2) {
		mult *= i;
	}

	// Вычисление результата
	int result = pow(-1, n + 1) * mult;

	return result;
}

// Функция для запуска тестов
void tests() {
	// Тесты
	assert(calculation(1) == 1);
	assert(calculation(2) == -2);
	assert(calculation(3) == 3);
	assert(calculation(4) == -8);
	assert(calculation(5) == 15);

	std::cout << "All tests passed successfully!" << std::endl;
}