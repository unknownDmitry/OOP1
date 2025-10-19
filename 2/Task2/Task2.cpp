// Савин Дмитрий, ИВТ-22
// Задача номер 136б: Даны натуральное число n, действительные числа a1,..., an. Вычислить:  a1a2 ... an;

#include "header.h"

using namespace array_operations;

int main(int argc, char* argv[]) {
    vector<double> a; // Основной массив для работы

    // Переменные для хранения параметров из аргументов командной строки
    string filename;
    bool load_from_file, binary_mode, run_tests_only;
    uint32_t array_size;
    double min_val, max_val;

    // Обработка аргументов командной строки
    if (!parse_arguments(argc, argv, filename, load_from_file, binary_mode, run_tests_only, array_size, min_val, max_val)) {
        return 0; // Завершить программу если была показана справка
    }

    // Если указан флаг --test, запустить только тесты и завершить работу
    if (run_tests_only) {
        tests();
        return 0;
    }

    // Если аргументы не переданы, использовать интерактивный режим
    if (argc == 1) {
        filename = get_file_name_from_user(); // Получение имени файла от пользователя
        char load_check; // Переменная для проверки выбора пользователя

        // Предложение пользователю загрузить массив из файла
        cout << "For load from file write Y or y: " << endl;
        cin >> load_check;

        // Загрузка массива из файла или создание нового
        if (load_check == 'Y' || load_check == 'y') {
            load_array_from_file(a, filename); // Загрузка массива из файла с выбором формата
        }
        else {
            create_new_array(a); // Создание нового массива
            save_array_to_files(a, filename); // Сохранение массива в ОБА формата
        }
    }
    else {
        // Режим с аргументами командной строки
        if (load_from_file) {
            // Используем существующую функцию загрузки с поддержкой бинарного формата
            load_array_unified(a, filename, binary_mode);
        }
        else {
            // Если размер массива указан в аргументах, использовать его
            if (array_size > 0) {
                create_new_array(a, array_size, min_val, max_val);
            }
            else {
                // Иначе запросить параметры у пользователя
                create_new_array(a);
            }

            // Сохранить созданный массив
            if (binary_mode) {
                // Сохраняем только в бинарный файл
                save_array_unified(a, filename, true);
            }
            else {
                // Сохраняем в оба формата (текстовый и бинарный) как в оригинальной версии
                save_array_to_files(a, filename);
            }
        }
    }

    display_results(a); // Вывод результатов работы с массивом
    tests(); // Запуск тестирования функций
    return 0;
}