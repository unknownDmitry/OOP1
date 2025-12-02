//Савин Дмитрий ИВТ-22
//Задача 136н: Даны натуральное число n, действительные числа a1,..., an. Вычислить Σ((√|a[i]| - a[i])^2)

#include "header.h" // Подключение своего заголовочного файла
using namespace math_and_files; // Подключение своего пространства имён

int main(int argc, char* argv[])
{
   test();

   // Если передан аргумент командной строки - используем его как n
   if (argc > 1) {
      int n = atoi(argv[1]);
      if (n <= 0) {
         std::cout << "Error: n must be > 0" << std::endl;
         return 1;
      }

      std::vector<double> a; // Динамический массив

      a.resize(n);          // Переопределение размера массива

      fill_arr(a);         // Заполнение псевдослучайными числами

      output_arr(a);      // Вывод массива

      // Вывод результата вычислений
      std::cout << std::fixed << "The result is " << std::setprecision(2) << calc(a) << std::endl;

      char char_choice{}; // Переменная для ветвления

      // Предлагаем сохранить массив или завершить программу
      std::cout << "To save the array, enter 's': " << std::endl;
      std::cout << "To finish, enter an another key " << std::endl;
      std::cin >> char_choice;

      if (char_choice == 's' || char_choice == 'S') {
         std::string file_name;
         std::cout << "Input filename (*.txt): ";
         std::cin >> file_name;
         try {
            f_save_arr(a, file_name);   // Сохраняем массив в файл
         }
         catch (const std::invalid_argument& error) {
            std::cout << error.what(); // Если не получается, выдаём ошибку
         }
      }


      a.clear(); // Освобождение памяти
   }
   else {
      // Интерактивный режим, если аргументов нет
      srand(time(NULL)); //Генератор псевдослучайных чисел

      std::vector<double> a; // Динамический массив
      int n{};               // Размер массива
      char char_choice{};   // Переменная для ветвления

      std::cout << "To create a new array, enter: 'c'" << std::endl;       // Создать новый массив
      std::cout << "To read an array from file, enter: 'f'" << std::endl; //Прочитать массив из файла
      std::cin >> char_choice;

      if (char_choice == 'f' || char_choice == 'F') {

         std::string file_name;
         std::cout << "Input filename(*.txt): ";
         std::cin >> file_name;

         try {
            a = f_read_arr(file_name); // Чтение массива из файла
         }
         catch (const std::invalid_argument& error) {
            std::cout << error.what(); // Если не получается, выдаём ошибку
         }

      }
      else {

         while (n <= 0) {
            std::cout << "Input length of array (n>0): n = ";
            std::cin >> n;
         }

         a.resize(n); // Переопределение размера массива
         fill_arr(a); // Заполнение псевдослучайными числами

      }

      output_arr(a); // Вывод массива

      //Вывод результата вычислений
      std::cout << std::fixed << "The result of Σ((√|a[i]| - a[i])^2) is " << std::setprecision(2) << calc(a) << std::endl;

      //Если был создан новый массив, предлагаем его сохранить
      if (char_choice != 'f' && char_choice != 'F') {
         std::cout << "To save the array, enter 's': " << std::endl;
         std::cout << "To finish, enter an another key " << std::endl;
         std::cin >> char_choice;
      }

      if (char_choice == 's' || char_choice == 'S') {
         std::string file_name;
         std::cout << "Input filename (*.txt): ";
         std::cin >> file_name;

         try {
            f_save_arr(a, file_name);   // Сохраняем массив в файл
         }
         catch (const std::invalid_argument& error) {
            std::cout << error.what(); // Если не получается, выдаём ошибку
         }
      }

      a.clear(); // Освобождение памяти
   }

   return 0;
}