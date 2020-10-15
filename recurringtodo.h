#ifndef RECURRINGTODO_H
#define RECURRINGTODO_H

#include "date.h"
#include "todo.h"


namespace todo
{
	class RecurringTodo : public Todo
	{
		public:
			RecurringTodo(std::string title, Category category, int priority, date::Date due_date, int period, date::Date end_date, bool completed=false);
			int period() const;
			date::Date endDate() const;
			void setPeriod(int period);
			void setEndDate(date::Date end_date);
			void setCompleted(bool completed);
			void display();
		private:
			int _period;
			date::Date _end_date;
	};
}


#endif