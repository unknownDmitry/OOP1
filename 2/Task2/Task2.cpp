// Савин Дмитрий, ИВТ-22
// Задача номер 136б: Даны натуральное число n, действительные числа a1,..., an. Вычислить:  a1a2 ... an;

#include "header.h"

using namespace array_operations;

int main(int argc, char *argv[]) {   
    vector<double> a; // Основной массив для работы
    string file_name = get_file_name_from_user(); // Получение имени файла от пользователя
    char load_check; // Переменная для проверки выбора пользователя
    
    // Предложение пользователю загрузить массив из файла
    cout << "For load from file write Y or y: " << endl;
    cin >> load_check;
    
    // Загрузка массива из файла или создание нового
    if (load_check == 'Y' || load_check == 'y') {
        load_array_from_file(a, file_name); // Загрузка массива из файла
    } else {
        create_new_array(a); // Создание нового массива
        save_array_to_files(a, file_name); // Сохранение массива в файлы
    }
    
    display_results(a); // Вывод результатов работы с массивом
    tests(); // Запуск тестирования функций
    return 0; 
}