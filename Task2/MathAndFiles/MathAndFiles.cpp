// MathAndFiles.cpp : Defines the functions for the static library.
//

#include "pch.h"
#include "framework.h"

//Савин Дмитрий ИВТ-22
//Задача 136н: Даны натуральное число n, действительные числа a1,..., an. Вычислить Σ((√|a[i]| - a[i])^2)

#include "header.h"

namespace math_and_files {

	//Заполняет массив arr псевдослучайными числами от -50 до 50.
	//Принимает: arr - вектор для заполнения.
	void fill_arr(std::vector<double>& arr)
	{
		for (unsigned i = 0; i < arr.size(); i++) {
			arr[i] = (rand() % 101 - 50) + ((rand() % 201 - 100) / 100.0);
		}
	}


	// Заполняет массив arr длины n псевдослучайными числами от -50 до 50.
	// Принимает: arr - массив, n - размер массива.
	void fill_arr(double arr[], int n)
	{
		for (unsigned i = 0; i < n; i++) { // числа от -50 до 50 с 2 знаками после запятой
			arr[i] = (rand() % 101 - 50) + ((rand() % 201 - 100) / 100.0);
		}
	}

	// Выводит элементы массива arr в консоль через табуляцию.
	// Принимает: arr - вектор для вывода.
	void output_arr(std::vector<double>& arr)
	{
		for (unsigned i = 0; i < arr.size(); i++) {
			std::cout << arr[i] << '\t';
		}
		std::cout << std::endl;
	}

	// Выводит элементы массива arr длины n в консоль через табуляцию.
	// Принимает: arr - массив, n - размер массива.
	void output_arr(double arr[], int n)
	{
		for (unsigned i = 0; i < n; i++) {
			std::cout << arr[i] << "\t";
		}
		std::cout << std::endl;
	}

	// Вычисляет сумму по формуле Σ((√|a[i]| - a[i])^2).
	// Принимает: arr - вектор чисел.
	// Возвращает: double - результат вычисления.
	double calc(std::vector <double>& arr)
	{
		double result = 0.0;
		for (unsigned i = 0; i < arr.size(); i++) {
			double temp = pow((sqrt(abs(arr[i])) - arr[i]), 2);
			result += temp;
		}
		return result;
	}

	// Вычисляет сумму по формуле Σ((√|a[i]| - a[i])^2).
	// Принимает: arr - массив чисел, n - размер массива.
	// Возвращает: double - результат вычисления.
	double calc(double arr[], int n)
	{
		double result = 0.0;
		for (unsigned i = 0; i < n; i++) {
			double temp = pow((sqrt(abs(arr[i])) - arr[i]), 2);
			result += temp;
		}
		return result;
	}

	// Читает массив из файла.
	// Принимает: file_name - имя файла.
	// Возвращает: std::vector<double> - прочитанный массив.
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

	// Читает массив из файла и записывает размер в n.
	// Принимает: n - указатель на переменную для размера, file_name - имя файла.
	// Возвращает: std::unique_ptr<double[]> - умный указатель на прочитанный массив.
	std::unique_ptr<double[]> f_read_arr(int* n, const std::string& file_name)
	{
		if (n == nullptr) {
			throw std::invalid_argument("Pointer to n cannot be nullptr");
		}

		std::ifstream file_read(file_name);
		std::unique_ptr<double[]> a;

		if (file_read.is_open()) {
			file_read >> *n;

			a = std::make_unique<double[]>(*n); // Выделение памяти для массива через unique_ptr

			for (unsigned i = 0; i < *n; i++) {
				file_read >> a[i];
			}
		}
		else {
			throw std::invalid_argument("No such file in directory");
		}

		file_read.close();

		return a;
	}

	// Записывает массив arr в файл.
	// Принимает: arr - вектор для записи, file_name - имя файла.
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

	// Записывает массив arr длины n в файл.
	// Принимает: arr - массив для записи, n - размер массива, file_name - имя файла.
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

	// Сравнивает два числа типа double с заданной точностью.
	// Принимает: a - первое число, b - второе число, epsilon - точность (по умолчанию 0.01).
	// Возвращает: bool - true если числа равны с заданной точностью.
	bool nearly_equal(double a, double b, double epsilon = 0.01) {
		return std::fabs(a - b) < epsilon;
	}

	// Читает массив из бинарного файла.
	// Принимает: file_name - имя файла.
	// Возвращает: std::vector<double> - прочитанный массив.
	std::vector<double> f_read_arr_bin(const std::string& file_name)
	{
		std::ifstream file_read(file_name, std::ios::binary);
		std::vector<double> a;
		int n{};

		if (file_read.is_open()) {
			file_read.read(reinterpret_cast<char*>(&n), sizeof(int));

			if (n > 0) {
				a.resize(n);
				file_read.read(reinterpret_cast<char*>(a.data()), n * sizeof(double));
			}
		}
		else {
			throw std::invalid_argument("No such file in directory");
		}

		file_read.close();

		return a;
	}

	// Читает массив из бинарного файла и записывает размер в n.
	// Принимает: n - указатель на переменную для размера, file_name - имя файла.
	// Возвращает: std::unique_ptr<double[]> - умный указатель на прочитанный массив.
	std::unique_ptr<double[]> f_read_arr_bin(int* n, const std::string& file_name)
	{
		if (n == nullptr) {
			throw std::invalid_argument("Pointer to n cannot be nullptr");
		}

		std::ifstream file_read(file_name, std::ios::binary);
		std::unique_ptr<double[]> a;

		if (file_read.is_open()) {
			file_read.read(reinterpret_cast<char*>(n), sizeof(int));

			if (*n > 0) {
				a = std::make_unique<double[]>(*n);
				file_read.read(reinterpret_cast<char*>(a.get()), *n * sizeof(double));
			}
		}
		else {
			throw std::invalid_argument("No such file in directory");
		}

		file_read.close();

		return a;
	}

	// Записывает массив arr в бинарный файл.
	// Принимает: arr - вектор для записи, file_name - имя файла.
	void f_save_arr_bin(std::vector<double>& arr, const std::string& file_name)
	{
		std::ofstream file_write(file_name, std::ios::binary);

		if (file_write.is_open()) {
			int n = static_cast<int>(arr.size());
			file_write.write(reinterpret_cast<const char*>(&n), sizeof(int));

			if (n > 0) {
				file_write.write(reinterpret_cast<const char*>(arr.data()), n * sizeof(double));
			}
		}
		else {
			throw std::invalid_argument("Access error - unable to create file");
		}

		file_write.close();
	}

	// Записывает массив arr длины n в бинарный файл.
	// Принимает: arr - массив для записи, n - размер массива, file_name - имя файла.
	void f_save_arr_bin(double arr[], int n, const std::string& file_name)
	{
		std::ofstream file_write(file_name, std::ios::binary);

		if (file_write.is_open()) {
			file_write.write(reinterpret_cast<const char*>(&n), sizeof(int));

			if (n > 0) {
				file_write.write(reinterpret_cast<const char*>(arr), n * sizeof(double));
			}
		}
		else {
			throw std::invalid_argument("Access error - unable to create file");
		}

		file_write.close();
	}

	// Запускает тесты для функции calc с различными входными данными.
	// Принимает: ничего.
	void test() {
		// Тест 1: {4, 4}
		std::vector<double> a{ 4.0, 4.0 };
		// √4=2, (2-4)^2=4, (2-4)^2=4, сумма=8
		assert(nearly_equal(calc(a), 8.0));

		// Тест 2: {9, -9}
		a = { 9.0, -9.0 };
		// √9=3, (3-9)^2=36; √9=3, (3-(-9))^2=144; сумма=180
		assert(nearly_equal(calc(a), 180.0));

		// Тест 3: {0, 1}
		a = { 0.0, 1.0 };
		// √0=0, (0-0)^2=0; √1=1, (1-1)^2=0; сумма=0
		assert(nearly_equal(calc(a), 0.0));

		std::cout << "All tests passed!" << std::endl;

		a.clear();
	}
}