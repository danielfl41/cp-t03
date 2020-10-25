#ifndef DATE_H
#define DATE_H
#include <ctime>

class Date
{
private:
    time_t date;
    bool seted = false;

public:
    Date(time_t date = 0)
    {
        if (date == 0)
        {
            date = time(0);
        }
        else
        {
            this->seted = true;
        }
        this->date = date;
    }
    void addDays(int days)
    {
        tm *ltm = localtime(&this->date);
        const time_t sDays = days * 24 * 60 * 60;
        this->date = mktime(ltm) + sDays;
        return;
    }
    void clear()
    {
        this->date = time(0);
        this->seted = false;
    }
    void setDate(time_t date)
    {
        this->date = date;
        this->seted = true;
    }

    bool isLowerThan(time_t pDate)
    {
        return this->date < pDate;
    }
    bool isSeted()
    {
        return this->seted;
    }
    time_t getDate()
    {
        return this->date;
    }
};
#endif