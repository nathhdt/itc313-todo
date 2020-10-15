#include <iostream>
#include "date.h"


namespace date
{
	Date::Date(int year, int month, int day)
	{
		bool status = checkDate(month, day);
		assert(status == true && "Date is not valid");
		_year = year;
		_month	= month;
		_day = day;
	}

	int Date::getDay() const
	{
		return _day;
	}

	int Date::getMonth() const
	{
		return _month;
	}

	int Date::getYear() const
	{
		return _year;
	}

	void Date::setDay(int day)
	{
		bool status = checkDate(_month, day);
		assert(status == true && "Day is not valid");
		_day = day;
	}

	void Date::nextDay()
	{
		setDay(getDay() + 1);
	}

	void Date::setMonth(int month)
	{
		assert((month >= 1) && (month <= 12));
		_month = month;
	}
	void Date::setYear(int year)
	{
		_year = year;
	}

	std::string Date::toString() const
	{
		std::string monthsList[12] = { "Jan", "Feb", "Mar", "Apr", "May", "Jun", "Jul", "Aug", "Sep", "Oct", "Nov", "Dec" };

		std::string str = std::to_string(getYear()) + "/" + monthsList[getMonth() - 1] + "/" + std::to_string(getDay());

		return str;
	}

	bool Date::checkDate(int month, int day) const
	{
		// On estime la date comme valide avant qu'elle passe par les conditions
		bool status = true;

		// Mois qui finissent par 31, vérifie si la date est bien entre 1 et 31
		if ((month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12) && (day > 31 || day < 1))
		{
			status = false;
		}
		// Mois qui finissent par 30, vérifie si la date est bien entre le 1 et le 30
		else if ((month == 4 || month == 6 || month == 9 || month == 11) && (day > 30 || day < 1))
		{
			status = false;
		}
		// Mois de Février, vérifie si la date est bien entre le 1 et le 28
		else if ((month == 2) && (day > 28 || day < 1))
		{
			status = false;
		}

		// Vérifie que le mois est valide
		if ((month > 12) || (month < 1))
		{
			status = false;
		}

		return status;
	}

	bool Date::operator>(const date::Date& compareDate) const
	{
		bool status = true;

		if (getYear() < compareDate.getYear())
		{
			status = false;
		}
		else
		{
			if (getMonth() < compareDate.getMonth())
			{
				status = false;
			}
			else
			{
				if (getDay() <= compareDate.getDay())
				{
					status = false;
				}
			}
		}

		return status;
	}

	Date::~Date()
	{
		//std::cout << "# Destructor called (date)" << std::endl;
	}
}