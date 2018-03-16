// OpenMP.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <conio.h>
#include <omp.h>

void integral(void);
void sort(void);

static long num_steps = 100000;
double step, storedValues[100];
int placement = 0;
#define NUM_THREADS 2
int main()
{
	int value = 0;

	while (value != 3)
	{
		system("cls");
		std::cout << "1: Find the integral \n";
		std::cout << "2: Sort Values \n";
		std::cout << "3: Exit  \n";
		printf("Enter your choice: ");
		std::cin >> value;

		if (value == 1)
		{
			integral();
		}

		else if (value == 2)
		{
			sort();
		}
	}

    return 0;
}

void integral(void) {
	int i, nthreads, input_x, input_n;
	double x, answer, sum[NUM_THREADS];

	step = 1.0 / (double)num_steps;
	omp_set_num_threads(NUM_THREADS);
	std::cout << "This is only a integral calculator from 0 to 1 \n";
	std::cout << "1: nx \n";
	std::cout << "2: 1/(x+n)\n";
	std::cout << "3: 1/(x-n)\n";
	std::cout << "4: 1/(n-x)\n";
	std::cout << "5: x^n\n";
	std::cout << "Please select the type of x: ";
	std::cin >> input_x;
	std::cout << "Please input the value of n: ";
	std::cin >> input_n;
#pragma omp parallel
	{
		int i, id, nthrds;
		double x;
		id = omp_get_thread_num();
		nthrds = omp_get_num_threads();

		if (id == 0) nthreads = nthrds;
		for (i = id, sum[id] = 0.0; i < num_steps; i += nthrds)
		{
			x = (i + .5)*step;

			if (input_x == 5 && input_n == 0)
				sum[id] += input_n * 1;
			else if (input_n != 0) {
				if (input_x == 1)
					sum[id] += input_n * x;
				else if (input_x == 2)
					sum[id] += 1 / (input_n + x);
				else if (input_x == 3)
					sum[id] += 1 / (x - input_n);
				else if (input_x == 4)
					sum[id] += 1 / (input_n - x);
				else if (input_x == 5)
					sum[id] += pow(x, input_n);
			}
		}
	}

	for (i = 0, answer = 0.0; i < nthreads; i++)
	{
		answer += step * sum[i];
		//std::cout << "\n\n" << pi  << ", " << sum[i] << ", " << step << "\n";
	}

	std::cout << "\n\nThe integral is equal to: " << answer;

	char store = 'n';
	std::cout << "\nWould you like to store this value? [y/n] ";
	std::cin >> store;
	if (store == 'y' || store == 'Y') {
		storedValues[placement] = answer;
		if (placement == 99)
			placement = 0;
		else
			placement++;
	}
	
	std::cout << "\n\nPress enter to continue.... ";

	std::getchar();	std::getchar();

}

void sort(void) {

	int i, sortInput, loopValue = 0;
	const int n_b = 100;
	double b[n_b] = { };
	std::cout << "1: Input Values \n";
	std::cout << "2: Use Stored Integral Values\n";
	std::cout << "3: Randomize\n";
	std::cout << "\nPlease select which one you would like to do: ";
	std::cin >> sortInput;

	if (sortInput == 1) {
		std::cout << "Please select a number from 1 - 10 for length: ";
		std::cin >> loopValue;
		for (int i = 0; i < loopValue; i++) {
			double temp1;
			std::cout << "Please choose a number: ";
			std::cin >> temp1;
			b[i] = temp1;
		}
	}
	else if (sortInput == 2) {
		memcpy(b, storedValues, sizeof(storedValues));
		loopValue = placement;
	}
	else if (sortInput == 3) {
		std::cout << "Please select a number from 1 - 100 for length: ";
		std::cin >> loopValue;
		double temp[100];
		for (int i = 0; i < loopValue; i++) {
			double temp1 = (rand() % 200);
			b[i] = temp1;
		}
	}

	for (int phase = 0; phase < n_b; phase++) {
		if (phase % 2 == 0) {
#pragma omp parallel for num_threads(8) default(none) shared (b, n_b) private(i)
			for (i = 1; i < n_b; i += 2) {
				if (b[i - 1] > b[i]) {
					double temp = b[i - 1];
					b[i - 1] = b[i];
					b[i] = temp;
				}
			}
		}
		else {
#pragma omp parallel for num_threads(8) default(none) shared (b, n_b) private(i)
			for (i = 1; i < n_b - 1; i += 2) {
				if (b[i] > b[i + 1]) {
					double temp = b[i + 1];
					b[i + 1] = b[i];
					b[i] = temp;
				}
			}
		}
	}


	for (int i = loopValue - 1; i >= 0; i--)
	{
		std::cout << b[i];
		if (i != 0)
			std::cout << ", ";
	}

	std::cout << "\n\nPress enter to continue.... ";

	std::getchar();	std::getchar();
}



