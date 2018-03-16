#include "stdafx.h"
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <omp.h>
#include <sstream>
#include <string>

void Hello(void);

//int main(int argc, char* argv[])
//{
//	int temp;
//	std::cin >> temp;
//	std::string str = std::to_string(temp);
//
//	int thread_count = strtol(str.c_str(), NULL, 10);
//
//#pragma omp parallel num_threads(thread_count)
//	{
//		Hello();
//	}
//
//
//	std::getchar();
//	std::getchar();
//	return 0;
//}
//
//void Hello(void) {
//	int my_rank = omp_get_thread_num();
//	int thread_count = omp_get_num_threads();
//
//	printf("Hello from thread %d of %d\n", my_rank, thread_count);
//}

