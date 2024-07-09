
#include "QueueTest.hpp"
#include "Simulations.h"


void simulationApp::testEmptyQue()
{
	int success = 0;
	Queue random;
	Data customerIn(1, randomGenerator() % 6 + 1, randomGenerator() % 6 + 1);

	random.enqeue(customerIn);



	if (random.getHead()->getData()->getNumber() == customerIn.getNumber()) {
		//Essentially checking if the queue has the same data as the data inserted, by comparing customer numbers.

		if (random.getTail()->getData()->getNumber() == random.getHead()->getData()->getNumber()) {
			//Since it's only one thing in the queue, the data for the tail should be the same as the data for the head.
			success = 1;
			timeDelay(random.getHead()->getData()->getTotal());
			testPrintQueue(random.getHead());
			cout << "TEST PASSED For emptyQueue !!!!!\n";
		}
	}
	else {
		cout << "TEST FAILED For emptyQueue !!!\n";
	}
}

void simulationApp::testSingleEnqueue() {

	double success = 0.0;

	Queue singleQueue;

	int temp_total_time = randomGenerator() % 6 + 1;

	Data previousCustomer(1, temp_total_time, temp_total_time);
	singleQueue.enqeue(previousCustomer);
	//Previous customer has been added to the queue;

	if (previousCustomer.getNumber() == singleQueue.getHead()->getData()->getNumber()) {

		//At this point there is only one node in the queue:

		success = 0.5;
		testPrintQueue(singleQueue.getHead());

		int enterCustomerNumber = 0, enterServiceTime = 0;


		cout << "Enter  new Customer Number: ";
		cin >> enterCustomerNumber;

		cout << "Enter new Service Number: ";
		cin >> enterServiceTime;

		int enterTotalTime = enterServiceTime;



		//INSERTING THE SECOND DATA INTO THE QUEUE AT THE TAIL ptr:
		Data currentCustomer(enterCustomerNumber, enterServiceTime, (enterServiceTime + previousCustomer.getService()));
		singleQueue.enqeue(currentCustomer);

		//CHECKING IF THE NEW DATA MATCHES WHAT'S INSIDE THE QUEUE:
		if (singleQueue.getTail()->getData()->getNumber() == enterCustomerNumber) {


			success = 1.0;
			timeDelay(enterTotalTime);
			testPrintQueue(singleQueue.getHead());

			cout << "TEST PASSED FOR SingleQueue !!!\n";

		}
	}
	else {
		cout << "TEST FAILED FOR SingleQueue !!\n";
	}
}



void simulationApp::testSingleDequeue() {

	int success = 0;
	Queue random;

	Data customerIn(1, randomGenerator() % 6 + 1, randomGenerator() % 6 + 1);

	random.enqeue(customerIn);


	timeDelay(random.getHead()->getData()->getTotal());
	random.dequeue();

	if (random.getHead() == nullptr) {
		cout << "TEST PASSED for single Dequeue!!\n";
		success = 1;
	}
	else {
		cout << "TEST FAILED for single Dequeue!!\n";
	}

}


void simulationApp::testDoubleDequeue() {

	double success = 0.0;

	Queue multiQueue;

	Data previousCustomer(1, randomGenerator() % 6 + 1, randomGenerator() % 6 + 1);
	multiQueue.enqeue(previousCustomer);

	Data currentCustomer(2, randomGenerator() % 6 + 1, randomGenerator() % 6 + 1);
	multiQueue.enqeue(currentCustomer);

	//At this point both queue's have successfully been inserted;


	timeDelay(multiQueue.getHead()->getData()->getTotal());
	//removing previousCustomer
	multiQueue.dequeue();

	if (multiQueue.getHead() == multiQueue.getTail()) {
		success = 0.5;
		timeDelay(multiQueue.getHead()->getData()->getTotal());

		//removing current Customer
		multiQueue.dequeue();
		if (multiQueue.getHead() == nullptr) {


			success = 1.0;
			cout << "TEST PASSED for Double Dequeue!!\n";
		}
	}
	else {
		cout << "TEST FAILED for Double Dequeue!!\n";
	}

}

void simulationApp::runAppFor24() {

	continueMenu();

	cout << "\nNote:\t\t\t\n\n\t\t\tThis Program is designed to run both Express lanes and Normal lanes for [24 hours]\n\t\t\tHowever 1 hr will represent a second in real time!\n\t\t\tEssentially, it will run for 24 seconds\n";
	continueMenu();
	expressLaneFor24();
	normalLaneFor24();



}

void simulationApp::expressLaneFor24()
{


	Queue Express;

	const int expressRunTime = 24;
	int finalERT = 0;

	//SIMULATION FOR EXPRESS LANE

	cout << " \nLoading Express Lane ...\n";
	while (finalERT < expressRunTime) //2 represents number of times run 
	{
		printf("Iteration %d of the 12hour period [Express Lane] ", finalERT + 1);
		timeDelay(expressRunTime / 2);

		ExpressLane(Express);
		extraSpace(3);

		finalERT++;
	}
}

void simulationApp::normalLaneFor24()
{

	Queue Normal;

	const int normalRunTime = 24;

	int finalNRT = 0;




	//SIMULATION FOR NORMAL LANE:

	cout << " \nLoading Normal Lane ...\n";
	while (finalNRT < normalRunTime) //2 represents number of time run
	{

		printf("Iteration %d of the 12hour period [Normal Lane]\n", finalNRT + 1);
		timeDelay(normalRunTime / 2);

		NormalLane(Normal);
		extraSpace(3);

		finalNRT++;
	}
}

void simulationApp::testPrintQueue(QueueNode* pHead) {


	QueueNode* pCur = pHead;
	QueueNode* pPrev = nullptr;


	while (pCur != nullptr) {


		cout << "Customer " << pCur->getData()->getNumber() << " spent: " << pCur->getData()->getService() << "min(s) being attended too and waited for " << pCur->getData()->getTotal() << "min(s) all together.";

		pPrev = pCur;
		pCur = pCur->getNext();

		putchar('\n');
		putchar('\n');
	}

}



void simulationApp::testMenu(void) {

	cout << "\t\t\t\tWelcome to Test Menu!!\n";
	cout << "1. test empty queue.\n";
	cout << "2. test single queue.\n";
	cout << "3. test single dequeue.\n";
	cout << "4. test double dequeue.\n";
	cout << "5. run Simulation for 24 hrs.\n";
	cout << ">>";
}


