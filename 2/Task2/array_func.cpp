// Савин Дмитрий, ИВТ-22
// Задача номер 136б: Даны натуральное число n, действительные числа a1,..., an. Вычислить:  a1a2 ... an;

#include "header.h"

namespace array_operations {

	// Вычисление произведения элементов массива
	double array_mult(vector<double>& a) {
		if (a.empty()) throw "Array is empty!";
		double result = 1.0;
		for (double x : a) result *= x;
		return result;
	}

	// Вывод массива на экран
	void print_array(const vector<double>& a) {
		iterate_array(a, [](double val) { cout << val << " "; });
		cout << endl;
	}

	// Заполнение массива случайными числами в заданном диапазоне
	void fill_rand_array(vector<double>& a, double max, double min) {
		srand(static_cast<unsigned int>(time(nullptr))); // Инициализация генератора случайных чисел
		double range = max - min;
		for (auto& x : a) x = static_cast<double>(rand()) / RAND_MAX * range + min;
	}

	// Подсчёт строк в текстовом файле
	uint16_t file_size(const string& file_name) {
		uint16_t count = 0;
		bool success = safe_file_operation<ifstream>(file_name, [&count](ifstream& file) {
			string line;
			while (getline(file, line)) count++;
			}, ios::in);
		if (!success) cout << "Cannot read file " << file_name << " for size calculation" << endl;
		return count;
	}

	// Универсальное сохранение массива в текстовый или бинарный файл
	void save_array_unified(const vector<double>& a, const string& file_name, bool binary) {
		bool success = binary ?
			safe_file_operation<ofstream>(file_name, [&a](ofstream& file) {
			size_t size = a.size();
			file.write(reinterpret_cast<const char*>(&size), sizeof(size)); // Сохранение размера массива
			file.write(reinterpret_cast<const char*>(a.data()), sizeof(double) * a.size()); // Сохранение данных массива
				}, ios::binary | ios::out) :
			safe_file_operation<ofstream>(file_name, [&a](ofstream& file) {
					iterate_array(a, [&file](double val) { file << val << endl; }); // Сохранение в текстовом формате
				}, ios::out);
				cout << (success ? "Array successfully saved to " : "Failed to save array to ") << file_name << endl;
	}

	// Универсальная загрузка массива из текстового или бинарного файла
	void load_array_unified(vector<double>& a, const string& file_name, bool binary) {
		a.clear();
		bool success = binary ?
			safe_file_operation<ifstream>(file_name, [&a](ifstream& file) {
			size_t size;
			file.read(reinterpret_cast<char*>(&size), sizeof(size)); // Чтение размера массива
			a.resize(size);
			file.read(reinterpret_cast<char*>(a.data()), sizeof(double) * size); // Чтение данных массива
				}, ios::binary | ios::in) :
			safe_file_operation<ifstream>(file_name, [&a](ifstream& file) {
					string line;
					while (getline(file, line)) a.push_back(stod(line)); // Чтение из текстового файла
				}, ios::in);
				if (!success) {
					cout << "Failed to load array from " << file_name << ". Creating new array instead." << endl;
					create_new_array(a);
				}
				else {
					cout << "Array successfully loaded from " << file_name << endl;
				}
	}

	// Получение имени файла от пользователя с проверкой формата
	string get_file_name_from_user() {
		string name;
		cout << "Enter file name: ";
		cin >> name;
		if (name.size() < 4) {
			cout << "Too short, using default 'save.txt'\n";
			return "save.txt";
		}
		if (name.substr(name.size() - 4) != ".txt") {
			cout << "No .txt extension, added automatically.\n";
			name += ".txt";
		}
		return name;
	}

	// Загрузка массива из файла с выбором формата (текстовый/бинарный)
	void load_array_from_file(vector<double>& a, const string& file_name) {
		cout << "Load from BIN (B/b)? ";
		char c; cin >> c;
		bool binary = (c == 'B' || c == 'b');
		string fname = file_name;
		if (binary) fname.replace(fname.size() - 3, 3, "bin"); // Замена расширения на .bin
		load_array_unified(a, fname, binary);
	}

	// Создание нового массива с пользовательскими параметрами
	void create_new_array(vector<double>& a) {
		uint32_t n;
		double min, max;
		cout << "Array size: "; cin >> n;
		cout << "Min value: "; cin >> min;
		cout << "Max value: "; cin >> max;
		a.resize(n);
		fill_rand_array(a, max, min);
	}

	// Создание нового массива с параметрами из аргументов командной строки
	void create_new_array(vector<double>& a, uint32_t n, double min, double max) {
		a.resize(n);
		fill_rand_array(a, max, min);
	}

	// Вывод результатов работы с массивом
	void display_results(const vector<double>& a) {
		cout << "Your array:\n";
		print_array(a);
		try {
			vector<double> copy = a; // Создание копии для вычислений
			cout << "Product = " << array_mult(copy) << endl;
		}
		catch (const char* err) {
			cout << err << endl;
		}
	}

	// Сохранение массива в оба формата (текстовый и бинарный)
	void save_array_to_files(const vector<double>& a, const string& file_name) {
		string bin_name = file_name;
		bin_name.replace(bin_name.size() - 3, 3, "bin"); // Создание имени для бинарного файла
		save_array_unified(a, file_name, false); // Сохранение в текстовом формате
		save_array_unified(a, bin_name, true); // Сохранение в бинарном формате
	}


	// Вывод справки по использованию программы
	void print_help() {
		cout << "Usage:\n";
		cout << "  program.exe [options]\n\n";
		cout << "Options:\n";
		cout << "  -h, --help              Show this help message\n";
		cout << "  -f, --file <filename>   Specify input/output file (default: save.txt)\n";
		cout << "  -l, --load              Load array from file\n";
		cout << "  -b, --binary            Use binary format for loading/saving\n";
		cout << "  -n, --new <size>        Create new array with specified size\n";
		cout << "  -min <value>            Minimum value for random generation (default: 0)\n";
		cout << "  -max <value>            Maximum value for random generation (default: 10)\n";
		cout << "  -t, --test              Run tests only\n\n";
		cout << "Examples:\n";
		cout << "  program.exe -f data.txt -l          # Load array from data.txt\n";
		cout << "  program.exe -f data.bin -l -b       # Load array from data.bin (binary)\n";
		cout << "  program.exe -n 10 -min -5 -max 5    # Create new array with 10 elements from -5 to 5\n";
		cout << "  program.exe -t                      # Run tests only\n";
	}

	// Обработка аргументов командной строки
	bool parse_arguments(int argc, char* argv[], string& filename, bool& load_from_file,
		bool& binary_mode, bool& run_tests_only, uint32_t& array_size,
		double& min_val, double& max_val) {
		// Установка значений по умолчанию
		filename = "save.txt";
		load_from_file = false;
		binary_mode = false;
		run_tests_only = false;
		array_size = 0;
		min_val = 0.0;
		max_val = 10.0;

		for (int i = 1; i < argc; i++) {
			string arg = argv[i];

			if (arg == "-h" || arg == "--help") {
				print_help();
				return false; // Завершить выполнение после вывода справки
			}
			else if (arg == "-f" || arg == "--file") {
				if (i + 1 < argc) {
					filename = argv[++i];
					// Автоматически добавляем расширение только если не бинарный режим
					if (!binary_mode && (filename.size() < 4 || filename.substr(filename.size() - 4) != ".txt")) {
						filename += ".txt";
					}
				}
			}
			else if (arg == "-l" || arg == "--load") {
				load_from_file = true;
			}
			else if (arg == "-b" || arg == "--binary") {
				binary_mode = true;
				// Если файл уже указан и он текстовый, меняем расширение на .bin
				if (filename != "save.txt" && filename.size() >= 4 &&
					filename.substr(filename.size() - 4) == ".txt") {
					filename.replace(filename.size() - 4, 4, ".bin");
				}
			}
			else if (arg == "-t" || arg == "--test") {
				run_tests_only = true;
			}
			else if (arg == "-n" || arg == "--new") {
				if (i + 1 < argc) {
					array_size = std::stoul(argv[++i]);
				}
			}
			else if (arg == "-min") {
				if (i + 1 < argc) {
					min_val = std::stod(argv[++i]);
				}
			}
			else if (arg == "-max") {
				if (i + 1 < argc) {
					max_val = std::stod(argv[++i]);
				}
			}
		}

		// Если бинарный режим и файл не указан, устанавливаем имя по умолчанию
		if (binary_mode && filename == "save.txt") {
			filename = "save.bin";
		}

		return true;
	}

	// Тестирование функции вычисления произведения элементов
	void tests() {
		// Тест 1: Простые единицы
		{ vector<double> t = { 1, 1, 1 }; assert(abs(array_mult(t) - 1) <= 1e-9); }
		// Тест 2: Положительные числа
		{ vector<double> t = { 2, 2, 3 }; assert(abs(array_mult(t) - 12) <= 1e-9); }
		// Тест 3: Последовательные числа
		{ vector<double> t = { 1, 2, 3 }; assert(abs(array_mult(t) - 6) <= 1e-9); }
		// Тест 4: Десятичные дроби
		{ vector<double> t = { 0.5, 2, 4 }; assert(abs(array_mult(t) - 4) <= 1e-9); }
		// Тест 5: Отрицательные числа
		{ vector<double> t = { -1, 2, -3 }; assert(abs(array_mult(t) - 6) <= 1e-9); }
		cout << "All tests passed!" << endl;
	}
}