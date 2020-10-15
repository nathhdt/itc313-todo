#include <iostream>
#include "todo.h"

namespace todo
{
	Todo::Todo(std::string title, Category category, int priority, date::Date due_date, bool completed)
	: _title(title), _category(category), _priority(priority), _due_date(due_date), _completed(completed)
	{

	}

	std::string Todo::title() const
	{
		return _title;
	}

	Category Todo::category() const
	{
		return _category;
	}

	int Todo::priority() const
	{
		return _priority;
	}

	date::Date Todo::dueDate() const
	{
		return _due_date;
	}

	bool Todo::completed() const
	{
		return _completed;
	}

	void Todo::setTitle(std::string title)
	{
		_title = title;
	}

	void Todo::setCategory(Category category)
	{
		_category = category;
	}

	void Todo::setPriority(int priority)
	{
		_priority = priority;
	}

	void Todo::setDueDate(date::Date due_date)
	{
		_due_date = due_date;
	}

	void Todo::setCompleted(bool completed)
	{
		_completed = completed;
	}

	void Todo::display() const
	{
		// Completed or not
		if (_completed == false)
		{
			std::cout << "TODO: ";
		}
		else
		{
			std::cout << "DONE: ";
		}
		
		// Title & date
		std::cout << _title << " (" << _due_date.toString() << ")" << std::endl;
	}
}