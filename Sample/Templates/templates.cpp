/*
 * templates.cpp
 *
 *  Created on: 25-Apr-2018
 *      Author: murkarth
 */

#include <iostream>
#include "templates.hpp"

using namespace std;

template <int n> struct fact;

template <>
struct fact<0> {
	const static int val=1;
};

template <int n>
struct fact {
	const static int val=n * fact<n-1>::val;
};

template <int n, int k> struct probab;

template <int n>
struct probab<n, 0> {
	const static int val = 1;
};

template <int n>
struct probab<n, n> {
	const static int val = 1;
};

template <int n, int k>
struct probab {
	const static int val = probab<n-1,k-1>::val + probab<n-1,k>::val;
};

void
TemplatesApp::run() {
	cout << "factorial of 5: " << fact<5>::val << endl;
	cout << "from 1 choose 2: " << probab<2,2>::val << endl;
	return;
}



