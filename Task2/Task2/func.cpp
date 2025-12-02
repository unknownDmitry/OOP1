//Савин Дмитрий ИВТ-22
//Задача 136н: Даны натуральное число n, действительные числа a1,..., an. Вычислить Σ((√|a[i]| - a[i])^2)

#include "header.h"

namespace math_and_files {

	//Заполнение массива arr длины n псевдослучайными числами
	void fill_arr(std::vector<double>& arr)
	{
		for (unsigned i = 0; i < arr.size(); i++) {
			arr[i] = (rand() % 101 - 50) + ((rand() % 201 - 100) / 100.0);
		}
	}
	//Заполнение массива arr длины n псевдослучайными числами
	void fill_arr(double arr[], int n)
	{
		for (unsigned i = 0; i < n; i++) { // числа от -50 до 50 с 2 знаками после запятой
			arr[i] = (rand() % 101 - 50) + ((rand() % 201 - 100) / 100.0);
		}
	}

	//Вывод массива arr длины n
	void output_arr(std::vector<double>& arr)
	{
		for (unsigned i = 0; i < arr.size(); i++) {
			std::cout << arr[i] << '\t';
		}
		std::cout << std::endl;
	}
	//Вывод массива arr длины n
	void output_arr(double arr[], int n)
	{
		for (unsigned i = 0; i < n; i++) {
			std::cout << arr[i] << "\t";
		}
		std::cout << std::endl;
	}

	//Вычисление результата по формуле Σ((√|a[i]| - a[i])^2)
	double calc(std::vector <double>& arr)
	{
		double result = 0.0;
		for (unsigned i = 0; i < arr.size(); i++) {
			double temp = pow((sqrt(abs(arr[i])) - arr[i]), 2);
			result += temp;
		}
		return result;
	}
	//Вычисление результата по формуле Σ((√|a[i]| - a[i])^2)
	double calc(double arr[], int n)
	{
		double result = 0.0;
		for (unsigned i = 0; i < n; i++) {
			double temp = pow((sqrt(abs(arr[i])) - arr[i]), 2);
			result += temp;
		}
		return result;
	}

	// Чтение массива длины n из файла с именем file_name
	std::vector<double> f_read_arr(const std::string& file_name)
	{
		std::ifstream file_read(file_name);
		std::vector <double> a;
		int n{};
		if (file_read.is_open()) {
			file_read >> n;

			a.resize(n);

			for (unsigned i = 0; i < n; i++) {
				file_read >> a[i];
			}
		}
		else {
			throw std::invalid_argument("No such file in directory");
		}

		file_read.close();

		return a;
	}
	// Чтение массива длины n из файла с именем file_name
	double* f_read_arr(int& n, const std::string& file_name)
	{
		std::ifstream file_read(file_name);
		double* a;

		if (file_read.is_open()) {
			file_read >> n;

			a = new double[n]; // Выделение памяти для массива

			for (unsigned i = 0; i < n; i++) {
				file_read >> a[i];
			}
		}
		else {
			throw std::invalid_argument("No such file in directory");
		}

		file_read.close();

		return a;
	}

	//Запись массива arr длины n в файл с именем file_name
	void f_save_arr(std::vector<double>& arr, const std::string& file_name)
	{
		std::ofstream file_write(file_name);

		if (file_write.is_open()) {
			file_write << arr.size() << std::endl;

			for (unsigned i = 0; i < arr.size(); i++) {
				file_write << arr[i] << " ";
			}
		}
		else {
			throw std::invalid_argument("Access error - unable to create file");
		}

		file_write.close();
	}
	//Запись массива arr длины n в файл с именем file_name
	void f_save_arr(double arr[], int n, const std::string& file_name)
	{
		std::ofstream file_write(file_name);

		if (file_write.is_open()) {
			file_write << n << std::endl;

			for (unsigned i = 0; i < n; i++) {
				file_write << arr[i] << " ";
			}
		}
		else {
			throw std::invalid_argument("Access error - unable to create file");
		}

		file_write.close();
	}



	// Функция для сравнения double с заданной точностью
	bool nearly_equal(double a, double b, double epsilon = 0.01) {
		return std::fabs(a - b) < epsilon;
	}

	//Ассерты для функции логики
	void test() {
		// Простой тест 1: {4, 4}
		std::vector<double> a{ 4.0, 4.0 };
		// √4=2, (2-4)^2=4, (2-4)^2=4, сумма=8
		assert(nearly_equal(calc(a), 8.0));

		// Простой тест 2: {9, -9}
		a = { 9.0, -9.0 };
		// √9=3, (3-9)^2=36; √9=3, (3-(-9))^2=144; сумма=180
		assert(nearly_equal(calc(a), 180.0));

		// Простой тест 3: {0, 1}
		a = { 0.0, 1.0 };
		// √0=0, (0-0)^2=0; √1=1, (1-1)^2=0; сумма=0
		assert(nearly_equal(calc(a), 0.0));

		std::cout << "All tests passed!" << std::endl;

		a.clear();
	}
}