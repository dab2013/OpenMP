#include "stdafx.h"
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <omp.h>
#include <sstream>
#include <string>

//int main(int argc, char* argv[])
//{
//	const int n = 10;
//	int a[n] = { 2, 20, 43, 1 , 10, 100, 97, 66, 21, 36 };
//	
//	//Bubble
//	for (int list_length = n; list_length >= 2; list_length--) {
//		for (int i = 0; i < list_length - 1; i++) {
//			if (a[i] > a[i + 1]) {
//				int temp = a[i];
//				a[i] = a[i + 1];
//				a[i + 1] = temp;
//			}
//		}
//	}
//
//	for (int i = n - 1; i >= 0; i--)
//		std::cout << a[i] << ", ";
//
//	std::cout << "\n\n";
//
//	int i, temp;
//	const int n_b = 10;
//	int b[n] = { 2, 20, 43, 1 , 10, 100, 97, 66, 21, 36 };
//
//	for (int phase = 0; phase < n_b; phase++) {
//		if (phase % 2 == 0){
//#pragma omp parallel for num_threads(8) default(none) shared (b, n_b) private(i, temp)
//			for (i = 1; i < n_b; i += 2) {
//				if (b[i - 1] > b[i]) {
//					temp = b[i - 1];
//					b[i - 1] = b[i];
//					b[i] = temp;
//				}
//			}
//		}
//		else {
//#pragma omp parallel for num_threads(8) default(none) shared (b, n_b) private(i, temp)
//			for (i = 1; i < n_b-1; i+=2) {
//				if (b[i] > b[i+1]) {
//					temp = b[i + 1];
//					b[i + 1] = b[i];
//					b[i] = temp;
//				}
//			}
//		}
//	}
//	
//
//	for (int i = n_b - 1; i >= 0; i--)
//		std::cout << b[i] << ", ";
//	
//	std::getchar();
//	return 0;
//}



