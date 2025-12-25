/*
Савин Дмитрий ИВТ-22
113б Пусть n - натуральное число и пусть n!!означает 1*3*5*...*n для нечетного n и
2*4*....*n для чётного n. Для заданного натурального n вычислить: (-1)^(n+1) * n!!
*/

#include "calculation.h"

int main(int argc, char* argv[]) {

	tests();

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
//Для компиляции программы:
//gcc 113b.cpp func.cpp -lstdc++ -o 113.exe