#include <iostream>
int main(int, char**){
    int chas{};
    int minut{};
    char time[100];
    std:: cin >> chas >> minut;
    if (chas > 12 || minut > 60 || chas < 0 || minut < 0){
        std::cout << "в вводе ошибка";
    }
    return 0;
}
