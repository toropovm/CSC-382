#include <iostream>
#include <string>
#include <time.h>   
#include <ctime>
#include <iomanip>

using namespace std;

int const max = 13;
//recursive algo
int FiboR(int n);
//Non recursive algo
int FiboNR(int n);


int main() {



	clock_t time_req; //fib recursive
	


	int fibNums[max] = { 0,5,10,15,20,25,30,35,40,40,40,40,40 };

	int fibValuesR[max];
	float fibTimesR[max];

	int fibValuesNR[max];
	float fibTimesNR[max];

	cout << endl << "This program will compute the time (in seconds) diffrence between a Recursive  and Non-Recurisve Fibonacci sequence" << endl;
	cout << endl << endl << flush;

	system("pause");
	system("cls");


	cout << left << setw(25) << "INTEGER" << setw(25) << "FiboR(seconds)" << setw(25) << "FiboNR(seconds)" << setw(25) << "Fibo_Value_R" << setw(25) << "Fibo_Value_NR" << endl;
	cout << "-----------------------------------------------------------------------------------------------------------------" << endl;
	//recursive
	for (int i = 0; i < max; i++) {

		time_req = clock();

		fibValuesR[i] = FiboR(fibNums[i]);

		time_req = clock() - time_req;

		fibTimesR[i] = time_req;

	}

	//Non recursive 
	for (int i = 0; i < max; i++) {

		time_req = clock();

		fibValuesNR[i] = FiboNR(fibNums[i]);

		time_req = clock() - time_req;

		fibTimesNR[i] = time_req;

	}
	//output
	for (int i = 0; i < max; i++)
	{
		cout << left << setw(25) << fibNums[i] << setw(25) << (float)fibTimesR[i] / CLOCKS_PER_SEC << setw(25) << (float)fibTimesNR[i] / CLOCKS_PER_SEC << setw(25) << fibValuesR[i] << setw(25) << fibValuesNR[i] << endl;
	}

	

}


//recursive algo
int FiboR(int n) {
	if (n == 0 || n == 1)
		return(n);
	else
		return(FiboR(n - 1) + FiboR(n - 2));
}

//Non recursive iterative algo
int FiboNR(int n) {
	if (n <= 1) {
		return n;
	}
	int fibo = 1;
	int fiboPrev = 1;
	for (int i = 2; i < n; ++i) {
		int temp = fibo;
		fibo += fiboPrev;
		fiboPrev = temp;
	}
	return fibo;

}