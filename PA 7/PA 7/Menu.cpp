#include "Menu.hpp"


void Menu::printMenu() {

	cout << "1. Import course List " << endl;
	cout << "2. Load master List " << endl;
	cout << "3. Store master List " << endl;
	cout << "4. Mark absences " << endl;
	cout << "5. BONUS: Edit absences " << endl;
	cout << "6. Generate report " << endl;
	cout << "7. Exit " << endl;
	cout << "Please choose an option\n>> " << endl;
}





void Menu::runMenu() {


	int option = 0;
	linkedlist<Data> MasterList;
	do {
		printMenu();
		cin >> option;

		if (option == 1) {//import course list
			MasterList.readClassList();
			MasterList.storeMasterList();
		}
		if (option == 2) {
			MasterList.readClassList();
		}
		if (option == 3) {
			MasterList.storeMasterList();
		}
		if (option == 4) {
			MasterList.markAbsences();
		}
		if (option == 5) {
			//
		}
		if (option == 6) {
			int genOpt = 0;
			cout << "Please select one of the following options: \n1. Generate report for all students\n2. Generate report for students with absences that match or exceed a given number" << endl;
			cout << ">>";
			cin >> genOpt;

			if (genOpt == 1) {
				MasterList.generateReport();
			}if (genOpt == 2) {
				cout << "Enter a number of absences: ";
				int value = 0;
				cin >> value;
				MasterList.generateSpecificReport(value);
			}
		}
		if (option == 7) {
			cout << " GoodBye!\n";
			break;
		}

		system("pause");
		system("cls");
	} while (option != 7);

}
