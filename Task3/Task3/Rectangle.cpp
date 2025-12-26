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
   Rectangle staticRect1(4.5, -1);
   Rectangle staticRect2(5.0, 6.0);

   // 2. Динамическое создание объекта
   Rectangle* dynamicRect = new Rectangle(7.0, 8.0);
   delete dynamicRect;


   // 3. Массив из объектов
   Rectangle arrayRect[3] = { Rectangle(1.0, 2.0), Rectangle(3.0, 4.0), Rectangle(5.0, 6.0) };
   for (int i = 0; i < 3; i++) {
      arrayRect[i].area();
   }

   // 4. Динамический массив из объектов
   Rectangle* dynamicArray = new Rectangle[3];
   dynamicArray[0] = Rectangle(10.0, 11.0);
   dynamicArray[1] = Rectangle(12.0, 13.0);
   dynamicArray[2] = Rectangle(14.0, 15.0);
   for (int i = 0; i < 3; i++) {
      dynamicArray[i].perimeter();
   }
   delete[] dynamicArray;

   // 5. Массив из указателей на объекты
   Rectangle* pointerArray[3];
   pointerArray[0] = new Rectangle(20.0, 21.0);
   pointerArray[1] = new Rectangle(22.0, 23.0);
   pointerArray[2] = new Rectangle(24.0, 25.0);
   for (int i = 0; i < 3; i++) {
      pointerArray[i]->area();
   }
   for (int i = 0; i < 3; i++) {
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
   Rectangle loadedRect1, loadedRect2, loadedRect3;
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
      cout << "Area of Rect1: " << loadedRect1.area() << endl;
      cout << "Perimeter of Rect1: " << loadedRect1.perimeter() << endl;
      cout << endl;
      cout << "Area of Rect2: " << loadedRect2.area() << endl;
      cout << "Perimeter of Rect2: " << loadedRect2.perimeter() << endl;
      cout << endl;
   }

   return 0;
}
