#include "Simulations.h"
#include "QueueTest.hpp"



void runExpress_LaneSimulation() {
	Queue Express;

	int expressRunTime = 0, finalERT = 0;

	//SIMULATION FOR EXPRESS LANE
	cout << "Enter desired simulation time for Express lane[in minutes(in seconds real time)]: ";
	cin >> expressRunTime;

	while (finalERT < expressRunTime) //2 represents number of time run
	{

		cout << "Iteration " << finalERT + 1 << "   [Normal Lane]\n";
		timeDelay(1.5);



		ExpressLane(Express);
		extraSpace(2);

		finalERT++;
	}

}

void runNormal_LaneSimulation() {


	Queue Normal;

	int normalRunTime = 0, finalNRT = 0;




	//SIMULATION FOR NORMAL LANE:
	cout << "Enter desired simulation time for NORMAL lane[in minutes(in seconds real time)]: ";
	cin >> normalRunTime;
	cout << " \nLoading Normal Lane ...\n";
	while (finalNRT < normalRunTime) //2 represents number of time run
	{

		cout << "Iteration " << finalNRT + 1 << "   [Normal Lane]\n";
		timeDelay(1.5);


		NormalLane(Normal);
		extraSpace(3);

		finalNRT++;
	}
}

void ExpressLane(Queue normalQueue) {
	cout << " \nLoading Express Lane ...\n";

	srand((unsigned int)time(NULL)); //time seed: responsible for having various random numbers.

	//Queue Express, Normal;
	int total_time_spent = 0;
	int randy = randomGenerator();
	int totalcustomers = (randy % 20) + 1;

	for (int i = 0; i < totalcustomers; i++) { //Express lane | 5 instances
		int tempService_time = (randomGenerator() % 5) + 1; //min: 1 , max: 5

		Data exCustomer(i + 1, tempService_time, total_time_spent);
		total_time_spent += tempService_time;
		normalQueue.enqeue(exCustomer);
		cout << "\n---------------------------\n";
		normalQueue.printQueue(normalQueue.getHead(), totalcustomers);


	}
	//system("cls");
	extraSpace(3);
	cout << "\tEXPRESS LANE\n";
	//normalQueue.printQueue(normalQueue.getHeadptr(), totalcustomers);
}


void NormalLane(Queue expressQueue) {


	srand((unsigned int)time(NULL)); //time seed: responsible for having various random numbers.

	//Queue Express, Normal;
	int total_time_spent = 0;

	int totalcustomers = (randomGenerator() % 40) + 1;

	for (int i = 0; i < totalcustomers; i++) { //Normal lane | 5 instances
		int tempService_time = (randomGenerator() % 6) + 3; //min: 3 , max: 8

		Data exCustomer(i + 1, tempService_time, total_time_spent);
		total_time_spent += tempService_time;
		expressQueue.enqeue(exCustomer);



	}
	cout << "\tNORMAL LANE\n";
	expressQueue.printQueue(expressQueue.getHead(), totalcustomers);
}

void timeDelay(int Seconds) { //Code from geeksforgeeks.com / delay() in c

	int milliSeconds = 1000 * Seconds;

	clock_t startTime = clock();

	while (clock() < startTime + milliSeconds);

}

void extraSpace(int lines) {


	for (int i = 0; i < lines; i++) {
		putchar('\n');
	}

}

void displayMenu(void) {
	cout << "\t\t\tWELCOME!\n\n";
	cout << "Please select an option.\n";
	cout << "1. Run Both Simulations.\n";
	cout << "2. Run the test cases Simulations.\n";
	cout << "3. Exit.\n";
	cout << ">>";
}

void continueMenu(void) {
	system("pause");
	system("cls");
}

void clearScreen(void) {
	system("cls");
}

int randomGenerator()
{
	
		int roll = 0;
		roll = (rand() % 8) + 1;
		return roll;

}


