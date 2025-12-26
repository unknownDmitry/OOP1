#pragma once
//Савин Дмитрий ИВТ-22
//Задача 136н: Даны натуральное число n, действительные числа a1,..., an. Вычислить Σ((√|a[i]| - a[i])^2)

#include <iostream>
#include <vector>
#include <cmath>
#include <iomanip>
#include <string>
#include <fstream>
#include <cassert>
#include <memory>
#include <cstdlib>

namespace math_and_files {

	// Заполнение массива arr длины n псевдослучайными числами от -50 до 50
	void fill_arr(std::vector <double>& arr);

	// Шаблонная функция заполнения массива arr длины n псевдослучайными числами от -50 до 50
	// Принимает: arr - массив, n - размер массива
	template<typename ArrayType>
	void fill_arr(ArrayType arr[], int n)
	{
		for (int i = 0; i < n; i++) {
			arr[i] = (rand() % 101 - 50) + ((rand() % 201 - 100) / 100.0);
		}
	}

	// Вывод массива arr в консоль через табуляцию
	void output_arr(std::vector<double>& arr);

	// Шаблонная функция вывода элементов массива arr длины n в консоль через табуляцию
	// Принимает: arr - массив, n - размер массива
	template<typename ArrayType>
	void output_arr(ArrayType arr[], int n)
	{
		for (int i = 0; i < n; i++) {
			std::cout << arr[i] << "\t";
		}
		std::cout << std::endl;
	}

	// Вычисление результата по формуле Σ((√|a[i]| - a[i])^2)
	double calc(std::vector <double>& arr);

	// Шаблонная функция вычисления суммы по формуле Σ((√|a[i]| - a[i])^2)
	// Принимает: arr - массив чисел, n - размер массива
	// Возвращает: ArrayType - результат вычисления
	template<typename ArrayType>
	ArrayType calc(ArrayType arr[], int n)
	{
		ArrayType result = 0.0;
		for (int i = 0; i < n; i++) {
			ArrayType temp = pow((sqrt(fabs(arr[i])) - arr[i]), 2);
			result += temp;
		}
		return result;
	}

	// Чтение массива длины n из файла с именем file_name
	std::vector<double> f_read_arr(const std::string& filename);
	std::unique_ptr<double[]> f_read_arr(int* n, const std::string& file_name);

	// Запись массива arr в файл с именем file_name
	void f_save_arr(std::vector<double>& arr, const std::string& file_name);

	// Шаблонная функция записи массива arr длины n в файл с именем file_name
	// Принимает: arr - массив для записи, n - размер массива, file_name - имя файла
	template<typename ArrayType>
	void f_save_arr(ArrayType arr[], int n, const std::string& file_name)
	{
		std::ofstream file_write(file_name);

		if (file_write.is_open()) {
			file_write << n << std::endl;

			for (int i = 0; i < n; i++) {
				file_write << arr[i] << " ";
			}
		}
		else {
			throw std::invalid_argument("Access error - unable to create file");
		}

		file_write.close();
	}

	// Чтение массива из бинарного файла
	std::vector<double> f_read_arr_bin(const std::string& file_name);
	std::unique_ptr<double[]> f_read_arr_bin(int* n, const std::string& file_name);

	// Запись массива в бинарный файл
	void f_save_arr_bin(std::vector<double>& arr, const std::string& file_name);
	void f_save_arr_bin(double arr[], int n, const std::string& file_name);

	void test();
}