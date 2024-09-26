#include <iostream>

namespace {
const int kHoursMidDay = 12;
const int kMinutesMidDay = 0;
const int kHoursMidNights = 0;
const int kMinutesMidNight = 0;

const int kMinHours = 0;
const int kMaxHour = 23;
const int kMinMinutes = 0;
const int kMaxMinute = 59;

const int kHoursNominativeSingular = 1;
const int kHoursNominativePluralBegin = 2;
const int kHoursNominativePluralEnd = 4;
const int kHoursGenitivePluralBegin = 5;
const int kHoursGenitivePluralEnd = 12;

const int kMinutesNominativePluralBegin = 2;
const int kMinutesNominativePluralEnd = 4;
const int kMinutesGenitivePluralBegin = 11;
const int kHoursGenetivePluarEnd = 12;
const int kMinutesNominativeSingular = 1;
const int kMinutesGenitivePlural = 1;

const int kDecimalBase = 10;
const int kMeridiem = 12;

const int kNightBegin = 0;
const int kMorningBegin = 5;
const int kDayBegin = 12;
const int kEveningBegin = 18;
const int kEveningEnd = 24;
}  // namespace

int main(int, char**) {
    int hours = -1;
    int minutes = -1;
    std::cout << "Введите время в формате 0 <= часы < 24 и 0 <= минуты < 60\n";
    std::cin >> hours >> minutes;

    if (hours > kMaxHour || hours < kMinHours || minutes > kMaxMinute || minutes < kMinMinutes) {
        std::cout << "В вводе ошибка, введите время в формате 0 <= часы < 24 и 0 <= минуты < 60\n";
        return 1;
    }

    if (hours == kHoursMidNights && minutes == kMinutesMidNight) {
        std::cout << "полночь" << std::endl;
        return 0;
    } else if (hours == kHoursMidDay && minutes == kMinutesMidDay) {
        std::cout << "полдень" << std::endl;
        return 0;
    }

    int hoursFormatMeridiem = (hours > kMeridiem) ? (hours - kMeridiem) : hours;
    if ((hoursFormatMeridiem >= kHoursGenitivePluralBegin && hoursFormatMeridiem <= kHoursGenitivePluralEnd) ||
        hoursFormatMeridiem == kHoursMidNights) {
        std::cout << hoursFormatMeridiem << " часов ";
    } else if (hoursFormatMeridiem >= kHoursNominativePluralBegin && hoursFormatMeridiem <= kHoursNominativePluralEnd) {
        std::cout << hoursFormatMeridiem << " часа ";
    } else if (hoursFormatMeridiem == kHoursNominativeSingular) {
        std::cout << hoursFormatMeridiem << " час ";
    }

    if (minutes != kMinutesMidDay) {
        int lastDigitMinutes = minutes % kDecimalBase;
        int dozensMinutes = minutes / kDecimalBase;
        if (lastDigitMinutes == kMinutesNominativeSingular && minutes != kMinutesGenitivePluralBegin) {
            std::cout << minutes << " минута ";
        } else if (lastDigitMinutes >= kMinutesNominativePluralBegin && lastDigitMinutes <= kMinutesNominativePluralEnd &&
                    dozensMinutes != kMinutesGenitivePlural) {
            std::cout << minutes << " минуты ";
        } else {
            std::cout << minutes << " минут ";
        }
    }

    if (hours >= kMorningBegin && hours < kDayBegin) {
        std::cout << "утра";
    } else if (hours >= kDayBegin && hours < kEveningBegin) {
        std::cout << "дня";
    } else if (hours >= kEveningBegin && hours < kEveningEnd) {
        std::cout << "вечера";
    } else if (hours >= kNightBegin && hours < kMorningBegin) {
        std::cout << "ночи";
    }

    if (minutes == kMinutesMidDay) {
        std::cout << " ровно";
    }

    std::cout << std::endl;
    return 0;
}
