#include "Simulations.h"
#include "QueueTest.hpp"

/*
Name:Darasimi Ogunbinu-PEters


Description:   *[PA 5]
				This is a program which simulates two lines in a grocery store,
				The express lane and Normal Lane.
				The express lane takes about 1 -5 mins to attend to all it's customers,
				while the Normal lane takes about 3-8 mins to do so.
				Each lane is printed out every 10 mins but 20 mins in total, since we are only simulating the experience twice.
				However, in the runAppfor24() found in "QueueTest.hpp" it is printed out every 12 hours(half a day).

				This program has the option to run the simulation naturally and the option to run the simulation for 24hrs(24s in real time).
				This program took 5 header files and 6 source files to complete, which is 13 files all together.



*/

int main(void) {

	simulationApp application;

	int option = 0;


	do
	{
		displayMenu();
		cin >> option;

		if (option == 1) {
			//RUN SIMULATION:

			clearScreen();

			//SIMULATION FOR EXPRESS LANE:
			runExpress_LaneSimulation();

			continueMenu();
			//SIMULATION FOR NORMAL LANE:
			runNormal_LaneSimulation();

			continueMenu();
		}
		if (option == 2) { // RUN TEST CASES:
			clearScreen();

			int Second_option = 0;
			application.testMenu();
			cin >> Second_option;

			if (Second_option == 1) {
				//EMPTY QUEUE TEST:
				application.testEmptyQue();
			}
			if (Second_option == 2) {
				//SINGLE QUEUE TEST:
				application.testSingleEnqueue();
			}
			if (Second_option == 3) {
				//single dequeue test.
				application.testSingleDequeue();
			}
			if (Second_option == 4) {
				application.testDoubleDequeue();

			}
			if (Second_option == 5) {

				application.runAppFor24();
			}

			continueMenu();
		}
		if (option == 3) { //EXIT:
			clearScreen();
			cout << "\t\t\t\tGood bye!\n";

		}
	} while (option != 3);


	return 0;
}


