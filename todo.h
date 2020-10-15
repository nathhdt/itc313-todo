#ifndef TODO_H
#define TODO_H

#include <string>
#include "date.h"


namespace todo
{
	// Categories
	enum class Category
	{
		Personal, Work
	};

	// Class
	class Todo
	{
	public:
		Todo(std::string title, Category category, int priority, date::Date due_date, bool completed=false);
		std::string title() const;
		Category category() const;
		int priority() const;
		date::Date dueDate() const;
		bool completed() const;
		void setTitle(std::string title);
		void setCategory(Category category);
		void setPriority(int Priority);
		void setDueDate(date::Date due_date);
		void setCompleted(bool completed);
		void display() const;
	private:
		std::string _title;
		Category _category;
		int _priority;
		date::Date _due_date;
		bool _completed;
	};
}


#endif