///**** MakeChange class ****///

#include "MakeChange.h"

bool MakeChange::Prg1(float m) {
	int i = 0;
	int r;
	vector<int> R(n, 0);
	while (m >= 0 && i < n) {
		m = round(m * 100) / 100;
		r = (int)(m / L[i]);
		if (r > 0) {
			R[i] = r;
			m = fmod(m, L[i]);
		}
		i++;
	}
	if (m > 0) {
		cout << "No Solution" << endl;
		return false;
	}
	print_vector(R);
	cout << endl;
	return true;
}

void MakeChange::Prg3(float m, int i) {
	m = round(m * 100) / 100;
	if (m == 0) {
		print_vector(fifoVector);
		return;
	}
	if (i >= n) {
		return;
	}
	for (int j = 0; j <= (int)(m / L[i]); j++) {
		fifoVector.push_back(j);
		Prg3((float)m - (float)j * L[i], i + 1);
		fifoVector.pop_back();
	}
}

void MakeChange::Prg3bis(float m, int i) {
	m = round(m * 100) / 100;
	if (m == 0) {
		print_vector(fifoVector);
		return;
	}
	if (i >= n) {
		return;
	}
	for (int j = (int)(m / L[i]); j >= 0; j--) {
		fifoVector.push_back(j);
		Prg3((float)m - (float)j * L[i], i + 1);
		fifoVector.pop_back();
	}
}

void MakeChange::Prg4(float m, int i, vector<vector<int>>& tDArraySolutions) {
	m = round(m * 100) / 100;
	if (m == 0) {
		tDArraySolutions.push_back(fifoVector);
		return;
	}
	if (i >= n) {
		return;
	}
	for (int j = 0; j <= (int)(m / L[i]); j++) {
		fifoVector.push_back(j);
		Prg4((float)m - (float)j * L[i], i + 1, tDArraySolutions);
		fifoVector.pop_back();
	}
}

void MakeChange::Prg5(float m, int i) {
	m = round(m * 100) / 100;
	if (m == 0) {
		calculateMinCost();
		if (evaluateCost() <= minCost)
			print_vector(fifoVector);
		return;
	}
	if (i >= n) {
		return;
	}
	for (int j = 0; j <= (int)(m / L[i]); j++) {
		fifoVector.push_back(j);
		Prg5((float)m - (float)j * L[i], i + 1);
		fifoVector.pop_back();
	}
}

void MakeChange::Prg6(float m, int i, vector<int>& solution) {
	m = round(m * 100) / 100;
	if (m == 0) {
		if (calculateMinCost() <= minCost)
			solution = fifoVector;
		return;
	}
	if (i >= n) {
		return;
	}
	for (int j = 0; j <= (int)(m / L[i]); j++) {
		fifoVector.push_back(j);
		Prg6((float)m - (float)j * L[i], i + 1, solution);
		fifoVector.pop_back();
	}
}

void MakeChange::Prg7(float m, int i) {
	m = round(m * 100) / 100;
	if (m == 0) {
		calculateMinCost();
		if (evaluateCost() <= minCost)
			print_vector(fifoVector);
		return;
	}
	if (i >= n) {
		return;
	}
	for (int j = 0; j <= (int)(m / L[i]); j++) {
		fifoVector.push_back(j);
		if (evaluateCost() < minCost) //cut 
			Prg7((float)m - (float)j * L[i], i + 1);
		fifoVector.pop_back();
	}
}

void MakeChange::Prg7bis(float m, int i) {
	m = round(m * 100) / 100;
	if (m == 0) {
		calculateMinCost();
		if (evaluateCost() <= minCost)
			print_vector(fifoVector);
		return;
	}
	if (i >= n) {
		return;
	}
	for (int j = (int)(m / L[i]); j >= 0; j--) {
		fifoVector.push_back(j);
		if (evaluateCost() < minCost) //cut 
			Prg7bis((float)m - (float)j * L[i], i + 1);
		fifoVector.pop_back();
	}
}

void MakeChange::print_vector(vector<int> v) {
	float sum = 0, val = 0;
	int i = 0;
	for (vector<int>::iterator it = v.begin(); it != v.end(); it++) {
		sum += *it;
		val += *it * L[i];
		cout << *it << " times " << L[i++] << " , ";  

	}
	cout << "Coin Counts: " << sum << " ,value: " << val << endl; 
}

void MakeChange::resetMinCost() {
	minCost = 999;
}

int MakeChange::evaluateCost() {
	int c = 0;
	for (vector<int>::iterator it = fifoVector.begin(); it != fifoVector.end(); it++)
		c += *it;
	return c;
}

int MakeChange::calculateMinCost() {
	int c = evaluateCost();
	if (c < minCost)
		minCost = c;
	return c;
}

MakeChange::MakeChange(float MoneyList[], int nB) {
	L = MoneyList;
	n = nB;
}
