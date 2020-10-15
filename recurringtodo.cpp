#include <iostream>
#include "recurringtodo.h"


namespace todo
{
	RecurringTodo::RecurringTodo(std::string title, Category category, int priority, date::Date due_date, int period, date::Date end_date, bool completed)
	: Todo(title, category, priority, due_date, completed), _period(period), _end_date(end_date)
	{

	}

	int RecurringTodo::period() const
	{
		return _period;
	}

	date::Date RecurringTodo::endDate() const
	{
		return _end_date;
	}

	void RecurringTodo::setPeriod(int period)
	{
		_period = period;
	}

	void RecurringTodo::setEndDate(date::Date end_date)
	{
		_end_date = end_date;
	}

	void RecurringTodo::setCompleted(bool completed)
	{
		if (completed)
		{

			// Ajout de 1 jour * la période
			for (int i = 0; i < _period; i++)
			{
				date::Date nextDate = dueDate();
				nextDate.nextDay();
				Todo::setDueDate(nextDate);
			}

			// Vérifie qu'on a pas dépassé la end_date, sinon on complète
			if (Todo::dueDate() > _end_date)
			{
				Todo::setCompleted(completed);
			}
		}
	}

	void RecurringTodo::display()
	{
		// Completed or not
		if (Todo::completed() == false)
		{
			std::cout << "TODO: ";
			// Title & date
			std::cout << Todo::title() << " (" << Todo::dueDate().toString() << ") - every " << _period << " day(s) until " << _end_date.toString() << std::endl;
		}
		else
		{
			std::cout << "DONE: ";
			// Title & date
			std::cout << Todo::title() << " (" << endDate().toString() << ")" << std::endl;
		}
		
		
	}
}