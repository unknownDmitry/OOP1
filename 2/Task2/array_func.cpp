#include "header.h"
#include <vector>
#include <iostream>
#include <fstream>
#include <string>
namespace ArrayFuncs {

	std::vector<double> a;

	// Вычисление результата
	static double array_mult(std::vector<double>& a) {
		if (a.size() == 0) {
			throw "Cause of zero length, array doesn't exist";
		}

		double result = 1.0;
		for (int i = 0; i < a.size(); i++) {
			result *= a[i];
		}
		return result;
	}

	//Вывод массива
	void print_array(const std::vector<double>& a) {
		for (int i = 0; i < a.size(); i++) {
			std::cout << a[i] << " ";
		}
	}

	//Сохранение массива с файл
	void save_array(const std::vector<double>& a, const std::string & file_name) {
		std::ofstream file(file_name);
		// Если файл открыт
		if (file.is_open()) {
			for (int i = 0; i < a.size(); i++) {
				file << a[i] << std::endl;
			}
			file.close();
		}
		else {
			std::cout << "Unable to open file";
		}
	}

	//Заполнение массива случайными числами 
	void fill_rand_array(std::vector<double>& a, double max, double min) {
		double range = max - min;
		for (int i = 0; i < a.size(); i++) {
			std::cout << i << std::endl;
			a[i] = (static_cast<double>(std::rand() / RAND_MAX * range + min));
		}
	}

	//Определение размера файла в виде числа строк. На входе имя файла в кавычках
	uint32_t file_size(const std::string& file_name) {
		std::string empty_line;
		uint32_t result = 0;
		std::ifstream file(file_name);
		if (!file.is_open()) {
			std::cout << "File not found:" << std::endl;
			return 0;
		}
		while (getline(file, empty_line)) {
			result++;
		}
		file.close();
		return result;
	}

	//Загрузка массива из файла
	void load_array(std::vector<double>& a, const std::string& file_name)
	{
		std::string load_line;
		std::ifstream file(file_name);
		if (!file.is_open()) {
			std::cout << "File not found: " << std::endl;
		}
		else {
			while (getline(file, load_line)) {
				a.push_back(stod(load_line));
			}
			file.close();
		}
	}

	// Сохранение массива из бинарного файла
	void save_array_bin(const std::vector<double>& a, const std::string& file_name) {
		std::ofstream file(file_name, std::ios::binary);
		if (!file.is_open()) {
			std::cout << "File opening error: " << std::endl;
		}
		else {
			file.write(reinterpret_cast<const char*>(a.size()), sizeof(a.size()));
			file.write(reinterpret_cast<const char*>(a.data()), sizeof(double) * a.size());
			file.close();
		}
	}

	// Создание и заполнение массива из бинарного файла 
	void load_array_bin(std::vector<double>& a, const std::string & file_name) {
		std::ifstream file(file_name, std::ios::binary);
		if (!file.is_open()) {
			std::cout << "File not found: " << std::endl;
		}
		else {
			file.read(reinterpret_cast<char*>(a.size()), sizeof(a.size()));
			a.resize(a.size());
			file.read(reinterpret_cast<char*>(a.data()), sizeof(double) * a.size());
			file.close();
		}
	}
};


namespace print_array_operations {
	void process_array_operations(std::vector<double>& a) {
		using namespace ArrayFuncs;
		std::string file_output, file_output_bin, test_on_txt;
		char load_check;
		uint32_t array_size;
		double max, min;

		std::cout << "Please, input file name: " << std::endl;
		std::cin >> file_output;

		if (file_output.length() < 4) {
			file_output = "save.txt";
			std::cout << "File name is too short, file name set by default as 'save.txt'" << std::endl;
		}
		test_on_txt = file_output.substr(file_output.length() - 4);
		if (test_on_txt != ".txt") {
			std::cout << "Your file doesn't have .txt extension, adding it automatically" << std::endl;
			file_output.append(".txt");
		}
		file_output_bin = file_output;
		file_output_bin.replace(file_output_bin.length() - 3, 3, "bin");

		std::cout << "For load from file write Y or y: " << std::endl;
		std::cin >> load_check;

		if (load_check == 'Y' || load_check == 'y') {
			std::cout << "For load from BIN write B or b: " << std::endl;
			std::cin >> load_check;
			if (load_check == 'B' || load_check == 'b') {
				load_array_bin(a, file_output_bin);
			}
			else {
				load_array(a, file_output);
			}
		}
		else {
			std::cout << "Input array length: " << std::endl;
			std::cin >> array_size;
			a.resize(array_size);
			std::cout << "Input min value: " << std::endl;
			std::cin >> min;
			std::cout << "Input max value: " << std::endl;
			std::cin >> max;
			fill_rand_array(a, max, min);
		}

		std::cout << "Your array: " << std::endl;
		print_array(a);
		std::cout << std::endl;

		try {
			std::cout << "The result is: " << array_mult(a) << std::endl;
		}
		catch (const char* error_message) {
			std::cout << error_message << std::endl;
		}

		save_array(a, file_output);
		save_array_bin(a, file_output_bin);
	}
}
