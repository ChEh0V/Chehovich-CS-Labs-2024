#include <iostream>
int main(int, char**) {
    int chas{};
    int minut{};

    const int Minut_Poln = 0;
    const int Chas_Poln = 0;
    const int Max_Chas = 23;
    const int Max_Minut = 59;
    const int Ok_Chas_Minuta = 1;

    const int Min_Okonch_Chasa = 4;
    const int Max_Okonch_Chasa = 21;
    const int Iskl_Okonch_Chasa_Minut = 11;
    const int Min_Okonch_Minuti = 2;
    const int Max_Okonch_minuti = 4;

    const int iskl_minuti = 1;
    const int Chas_Pold = 12;
    const int Min_Pold = 0;
    const int ZeroChasov = 0;
    const int PeremDlyOstatk = 10;

    const int Noch = 0;
    const int Ytro = 5;
    const int Den = 12;
    const int Vecher = 18;
    const int Vechte2 = 23;

    const int ChasDnya = 13;
    const int DvaDnya = 14;
    const int TriDnya = 15;
    const int ChetVecher = 16;
    const int PyatVecher = 17;
    const int SixVecher = 18;

    const int SevenVecher = 19;
    const int VosemVecher = 20;
    const int DevyatVecher = 21;
    const int DecVecher = 22;
    const int OdinVecher = 23;

    std::cout << "Введите время в формате 0 <= часы < 24 и 0 <= минуты < 60\n";
    std::cin >> chas >> minut;

    if (chas > Max_Chas || minut > Max_Minut || chas <= Minut_Poln || minut <= Chas_Poln) {
        std::cout << "В воде ошибка, введите время в формате 0 <= часы < 24 и 0 <= минуты < 60\n";
        return 0;
    }

    if (chas == Chas_Poln && minut == Minut_Poln) {
        std::cout << "полночь ";
        return 0;
    }

    else if (chas == Chas_Pold && minut == Min_Pold) {
        std::cout << "полдень";
        return 0;
    }

    if (chas >= Den) {
        switch (chas) {
            case ChasDnya:
                std::cout << "1 час ";
                break;
            case DvaDnya:
                std::cout << "2 часа ";
                break;
            case TriDnya:
                std::cout << "3 часа ";
                break;
            case ChetVecher:
                std::cout << "4 часа ";
                break;
            case PyatVecher:
                std::cout << "5 часов ";
                break;
            case SixVecher:
                std::cout << "6 часов ";
                break;
            case SevenVecher:
                std::cout << "7 часов ";
                break;
            case VosemVecher:
                std::cout << "8 часов ";
                break;
            case DevyatVecher:
                std::cout << "9 часов ";
                break;
            case DecVecher:
                std::cout << "10 часов ";
                break;
            case OdinVecher:
                std::cout << "11 часов ";
                break;
        }
    } else {
        if ((chas % PeremDlyOstatk == Ok_Chas_Minuta) && chas != Iskl_Okonch_Chasa_Minut) {
            std::cout << chas << " час ";
        }

        else if ((chas > Min_Okonch_Chasa && chas < Max_Okonch_Chasa) || chas == ZeroChasov) {
            std::cout << chas << " часов ";
        }

        else {
            std::cout << chas << " часа ";
        }
    }

    if (minut != Min_Pold) {
        if ((minut % PeremDlyOstatk == Ok_Chas_Minuta) && minut != Iskl_Okonch_Chasa_Minut) {
            std::cout << minut << " минута ";
        }

        else if (minut % PeremDlyOstatk >= Min_Okonch_Minuti && minut % PeremDlyOstatk <= Max_Okonch_minuti &&
                 minut / PeremDlyOstatk != iskl_minuti) {
            std::cout << minut << " минуты ";
        }

        else {
            std::cout << minut << " минут ";
        }
    }

    if (chas >= Ytro && chas < Den) {
        std::cout << "утра";
    }

    else if (chas > Den && chas < Vecher) {
        std::cout << "дня";
    }

    else if (chas >= Vecher && chas <= Vechte2) {
        std::cout << "вечера";
    }

    else if (chas > Noch && chas < Ytro) {
        std::cout << "ночи";
    }

    if (minut == Min_Pold) {
        std::cout << " ровно";
    }

    std::cout << "\n";
    return 0;
}
