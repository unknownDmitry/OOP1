//Савин Дмитрий ИВТ-22
//Класс Прямоугольник

#include "Rectangle_class.h"
#include <iostream>
#include <fstream>

using std::string;
using std::cout;
using std::endl;

int main() {

   // Запуск тестов
   tests();


   // 1.Статическое создание объектов
   Rectangle staticRect1(1.23, 12.3, -2.2, -3.2);
   Rectangle staticRect2(5.2, 6.1);


   // 2. Динамическое создание объекта
   Rectangle* dynamicRect = new Rectangle(7.0, 8.0);
   delete dynamicRect;


   // 3. Массив из объектов
   const int size1 = 3;
   Rectangle arrayRect[size1] = { Rectangle(1.0, 2.0), Rectangle(3.0, 4.0), Rectangle(5.0, 6.0) };
   for (int i = 0; i < size1; i++) {
      arrayRect[i].area();
   }


   // 4. Динамический массив из объектов
   int size2 = 3;
   Rectangle* dynamicArray = new Rectangle[size2]{
      Rectangle(10.0, 11.0),
      Rectangle(12.0, 13.0),
      Rectangle(14.0, 15.0)
   };
   for (int i = 0; i < size2; i++) {
      dynamicArray[i].perimeter();
   }
   delete[] dynamicArray;


   // 5. Массив из указателей на объекты
   const int size3 = 3;
   Rectangle* pointerArray[size3];
   pointerArray[0] = new Rectangle(20.0, 21.0);
   pointerArray[1] = new Rectangle(22.0, 23.0);
   pointerArray[2] = new Rectangle(24.0, 25.0);
   for (int i = 0; i < size3; i++) {
      pointerArray[i]->area();
   }
   for (int i = 0; i < size3; i++) {
      delete pointerArray[i];
   }


   // 6. Запись состояния объектов в файл и загрузка из файла
   string filename = "Rectangle.txt";
   
    // Сохранение нескольких объектов в файл
   std::ofstream file_write(filename);
   if (file_write.is_open()) {
      file_write << staticRect1.get_width() << " " << staticRect1.get_height() << endl;
      file_write << staticRect2.get_width() << " " << staticRect2.get_height() << endl;
      file_write.close();
   }


   // Загрузка объектов из файла
   Rectangle loadedRect1, loadedRect2;
   std::ifstream file_read(filename);
   if (file_read.is_open()) {
      float w, h;
      file_read >> w >> h;
      loadedRect1.set_width(w);
      loadedRect1.set_height(h);
      
      file_read >> w >> h;
      loadedRect2.set_width(w);
      loadedRect2.set_height(h);
      
      file_read.close();

      std::string square;

      cout << "Area of Rect1: " << loadedRect1.area() << endl;
      cout << "Perimeter of Rect1: " << loadedRect1.perimeter() << endl;
      cout << "Diagonal of Rect1: " << loadedRect1.diagonal() << endl;
      square = (loadedRect1.is_square() ? "Yes" : "No");
      cout << "Is square: " << ((loadedRect1.get_width() == 0 || loadedRect1.get_height() == 0) ? "Doesn't exist" : square) << endl;
      cout << endl;
      
      cout << "Area of Rect2: " << loadedRect2.area() << endl;
      cout << "Perimeter of Rect2: " << loadedRect2.perimeter() << endl;
      cout << "Diagonal of Rect2: " << loadedRect2.diagonal() << endl;
      square = (loadedRect2.is_square() ? "Yes" : "No");
      cout << "Is square: " << ((loadedRect2.get_width() == 0 || loadedRect2.get_height() == 0) ? "Doesn't exist" : square) << endl;
      cout << endl;
   }

   return 0;
}
