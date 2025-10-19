#include "header.h"

using namespace array_operations;

int main(int argc, char *argv[])
{   
    vector<double> a;
    
    // Получаем имя файла от пользователя
    string file_name = get_file_name_from_user();
    
    // Спрашиваем, загружать ли массив из файла
    char load_check;
    cout << "For load from file write Y or y: " << endl;
    cin >> load_check;

    if (load_check == 'Y' || load_check == 'y') {
        // Загружаем массив из файла
        load_array_from_file(a, file_name);
    }
    else {
        // Создаем новый массив
        create_new_array(a);
        // Сохраняем массив в оба формата только при создании нового
        save_array_to_files(a, file_name);
    }

    // Отображаем результаты
    display_results(a);
    
    // Запуск тестов после работы с массивом
    tests();
    
    return 0;
}