#include <iostream>

namespace {
const int kTimeHourMidDay = 12;
const int kTimeMinuteMidDay = 0;
const int kMinuteMidNight = 0;
const int kHourMidNight = 0;
const int kMaxQuantityHour = 23;
const int kMaxQuantityMinut = 59;

const int kForEndingHourNominativeSingularCase = 1;
const int kForEndingMinuteNominativeSingularCase = 1;
const int kMinEndingMinuteNominativeCasePlural = 2;
const int kMaxEndingMinuteNominativeCasePlural = 4;

const int kMinValueForPluarGenitiveCase = 4;
const int kMaxValueForPluarGenitiveCase = 21;

const int kExceptionEndingHourAndMinutTheGenitivePlural = 11;
const int kExceptionMinuteNominativeCaseSingular = 1;
const int kExceptionForHourGenitiveOfPlural = 0;

const int kDecimalBase = 10;
const int kForFindTimePostMeridiem = 12;

const int kStartNight = 0;
const int kStartMorning = 5;
const int kStartDay = 12;
const int kStartEvening = 18;
const int kFinishEvening = 23;
}  // namespace

int main(int, char**) {
    int hour = 0;
    int hourNight = 0;
    int minute = 0;
    std::cout << "Введите время в формате 0 <= часы < 24 и 0 <= минуты < 60\n";
    std::cin >> hour >> minute;

    if (hour > kMaxQuantityHour || minute > kMaxQuantityMinut || hour < kHourMidNight || minute < kMinuteMidNight) {
        std::cout << "В воде ошибка, введите время в формате 0 <= часы < 24 и 0 <= минуты < 60\n";
        return 0;
    }

    if (hour == kHourMidNight && minute == kMinuteMidNight) {
        std::cout << "полночь\n";
        return 0;
    } else if (hour == kTimeHourMidDay && minute == kTimeMinuteMidDay) {
        std::cout << "полдень\n";
        return 0;
    }

    if (hour != kTimeHourMidDay) {
        hourNight = hour % kForFindTimePostMeridiem;
        if ((hourNight % kDecimalBase == kForEndingHourNominativeSingularCase) && hourNight != kExceptionEndingHourAndMinutTheGenitivePlural) {
            std::cout << hourNight << " час ";
        } else if ((hourNight > kMinValueForPluarGenitiveCase && hourNight < kMaxValueForPluarGenitiveCase) || hourNight == kExceptionForHourGenitiveOfPlural) {
            std::cout << hourNight << " часов ";
        } else {
            std::cout << hourNight << " часа ";
        }
    } else {
        std::cout << "12 часов ";
    }

    if (minute != kTimeMinuteMidDay) {
        if ((minute % kDecimalBase == kForEndingMinuteNominativeSingularCase) && minute != kExceptionEndingHourAndMinutTheGenitivePlural) {
            std::cout << minute << " минута ";
        } else if (minute % kDecimalBase >= kMinEndingMinuteNominativeCasePlural && minute % kDecimalBase <= kMaxEndingMinuteNominativeCasePlural && minute / kDecimalBase != kExceptionMinuteNominativeCaseSingular) {
            std::cout << minute << " минуты ";
        } else {
            std::cout << minute << " минут ";
        }
    }

    if (hour >= kStartMorning && hour < kStartDay) {
        std::cout << "утра";
    } else if (hour >= kStartDay && hour < kStartEvening) {
        std::cout << "дня";
    } else if (hour >= kStartEvening && hour <= kFinishEvening) {
        std::cout << "вечера";
    } else if (hour > kStartNight && hour < kStartMorning) {
        std::cout << "ночи";
    }

    if (minute == kTimeMinuteMidDay) {
        std::cout << " ровно";
    }

    std::cout << "\n";
    return 0;
}
