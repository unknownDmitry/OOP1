#include <cmath>
#include "header.h"
#include <cassert>

int calculation(int n) {
	// Проверка натурального n
	assert(n >= 1);

	int mult = 1;

	// Цикл по четным (для четного n) или нечетным (для нечетного n) числам
	for (int i = (n % 2 == 0 ? 2 : 1); i <= n; i += 2) {
		mult *= i;
	}

	// Вычисление результата
	int result = pow(-1, n + 1) * mult;

	return result;
}