#include <iostream>
int main(int, char**){
    int chas;
    int minut;
    const int Min_Poln = 0;
    const int Chas_Poln = 0;
    const int Max_Chas = 24;
    const int Max_Minut = 60;
    const int Ok_Chas_Minuta = 1;

    const int Min_Ok_Chasa = 4;
    const int Max_Ok_Chasa = 21;
    const int iskl_ok_chasa_minut = 11;
    const int Min_Ok_Minuti = 2;
    const int Max_Ok_minuti = 4;

    const int iskl_minuti = 1;
    const int Chas_Pold = 12;
    const int Min_Pold = 0;
    const int ZeroChasov = 0;

    std::cin >> chas >> minut;

    if (chas > Max_Chas || minut > Max_Minut || chas < Min_Poln || minut < Chas_Poln){
        std::cout << "в вводе ошибка\n";
    }

    else
    {
        if (chas == Chas_Poln && minut == Min_Poln){
            std::cout << "полночь ";
        }
        else if(chas == Chas_Pold && minut == Min_Pold){
            std::cout << "полдень";
        }
        else
        {
            if ((chas % 10 == Ok_Chas_Minuta) && chas != iskl_ok_chasa_minut){
                std::cout << chas<< " час ";
            }
            else if((chas>Min_Ok_Chasa && chas < Max_Ok_Chasa)  || chas == ZeroChasov){
                std::cout << chas << " часов ";
            }
            else
            {
                std::cout << chas << " часа ";
            }

            if ((minut % 10 == Ok_Chas_Minuta) && minut != iskl_ok_chasa_minut){
                std::cout << minut << " минута";
            }
            else if(minut % 10 >= Min_Ok_Minuti && minut % 10 <= Max_Ok_minuti  && minut / 10 != iskl_minuti){
                std::cout << minut << " минуты";
            }
            else
            {
                std::cout << minut << " минут";
            }
        }
    }
    std::cout<<"\n";
    return 0;
}
