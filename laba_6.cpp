#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

int main() {
    // 1. Чтение из файла целочисленного одномерного вектора
    std::ifstream file("input.txt");
    if (!file.is_open()) {
        std::cerr << "Error opening file." << std::endl;
        return 1;
    }

    std::vector<int> vec;
    int num;
    while (file >> num) {
        vec.push_back(num);
    }
    file.close();

    // 2. Реверсируем последовательность элементов вектора
    std::reverse(vec.begin(), vec.end());
    std::cout << "Reversed vector:";
    for (int num : vec) {
        std::cout << " " << num;
    }

    // 3. Находим минимальный элемент
    int min_element = *std::min_element(vec.begin(), vec.end());

    std::cout << "\nMinimum element: " << min_element << "\n";

    // 4. Удаляем из вектора все четные элементы
    vec.erase(std::remove_if(vec.begin(), vec.end(), [](int x) { return x % 2 == 0; }), vec.end());

    std::cout << "New vector:";
    for (int num : vec) {
        std::cout << " " << num;
    }

    // 5. Сортируем вектор в убывающей последовательности
    std::sort(vec.begin(), vec.end(), std::greater<int>());

    // 6. Вставляем произвольный элемент, не нарушая сортировку
    int new_element = 17;
    vec.insert(std::upper_bound(vec.begin(), vec.end(), new_element, std::greater<int>()), new_element);

    // 7. Определяем индекс заданного элемента
    int target_element = 17;
    auto it = std::find(vec.begin(), vec.end(), target_element);
    int index = (it != vec.end()) ? std::distance(vec.begin(), it) : -1;
    std::cout << "\nIndex of element " << target_element << ": " << index << "\n";

    // 8. Удаляем дублированные элементы
    vec.erase(std::unique(vec.begin(), vec.end()), vec.end());

    std::cout << "New vector:";
    for (int num : vec) {
        std::cout << " " << num;
    }


    // Выводим результаты
    /*
    std::cout << "Reversed vector:";
    for (int num : vec) {
        std::cout << " " << num;
    }
    std::cout << "\nMinimum element: " << min_element << "\n";
    std::cout << "Vector without even elements and sorted in descending order:";
    for (int num : vec) {
        std::cout << " " << num;
    }
    std::cout << "\nIndex of element " << target_element << ": " << index << "\n";
    */
    return 0;
}
