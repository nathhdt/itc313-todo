#include <iostream>
#include "date.h"
#include "todo.h"
#include "recurringtodo.h"


#define HIGH 10
#define NORMAL 5
#define LOW 1


int main()
{
	std::cout << "### TESTS CLASSE DATE" << std::endl;
	{
		std::cout << "main1:" << std::endl << std::endl;

		std::cout << "On crée une date par défaut dDef" << std::endl;
		date::Date dDef; // Utilisation du constructeur par défaut
		std::cout << "dDef | " << dDef.toString() << std::endl << std::endl;

		std::cout << "On crée une date d1" << std::endl;
		date::Date d1 = date::Date(2020, 10, 15); // Utilisation du constructeur paramétré
		std::cout << "d1 | " << d1.toString() << std::endl << std::endl;

		{
			std::cout << "	main2:" << std::endl;
			std::cout << "		On crée une date d2" << std::endl;
			date::Date d2(2020, 10, 15); // Utilisation du constructeur paramétré d'une autre forme
			std::cout << "		d2 | " << d2.toString() << std::endl;
			std::cout << "	:end main2" << std::endl << std::endl;
		}

		std::cout << "On change le mois de d1 sur 4" << std::endl;
		d1.setMonth(4);

		std::cout << "On change le jour de d1 sur 20" << std::endl;
		d1.setDay(20);
	
		std::cout << "d1 | " << d1.toString() << std::endl << std::endl;

		std::cout << ":endmain1" << std::endl << std::endl << std::endl << std::endl;
	}

	std::cout << "### TESTS CLASSE TODO" << std::endl;
	{
		std::cout << "main1:" << std::endl << std::endl;

		std::cout << "On crée une todo todo1" << std::endl;
		std::string title = "Acheter un iPhone 12 mini";
		todo::Category category = todo::Category::Personal;
		int priority = HIGH;
		date::Date due_date(2020, 11, 6);
		todo::Todo todo1(title, category, priority, due_date);
		todo1.display();

		std::cout << std::endl << std::endl << std::endl << "	### TESTS CLASSE RECURRING_TODO" << std::endl;
		{
			std::cout << "	main2:" << std::endl;
			
			std::cout << "		On crée une todo récurrente recTodo1" << std::endl;
			std::string title = "Avoir de l'argent";
			todo::Category category = todo::Category::Personal;
			int priority = HIGH;
			date::Date due_date(2020, 11, 6);
			int period = 2;
			date::Date end_date(2020, 11, 9);
			todo::RecurringTodo recTodo1(title, category, priority, due_date, period, end_date);
			std::cout << "		";
			recTodo1.display();

			std::cout << std::endl << "		On complète la tâche et on l'affiche" << std::endl;
			recTodo1.setCompleted(true);
			std::cout << "		";
			recTodo1.display();

			std::cout << std::endl << "		On complète encore une fois la tâche et on l'affiche" << std::endl;
			recTodo1.setCompleted(true);
			std::cout << "		";
			recTodo1.display();

			std::cout << "	:endmain2" << std::endl << std::endl;
		}

		std::cout << ":endmain1" << std::endl << std::endl;
	}
	return 0;
}