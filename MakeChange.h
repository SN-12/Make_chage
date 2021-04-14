
///**** MakeChange class header****///


#include <iostream>
#include <vector>
#include <chrono>
using namespace std;



class MakeChange {
private:
	vector<int> fifoVector;
	int n; //number of changes
	int minCost = 999;
	float* L;

	int evaluateCost();
	int calculateMinCost();
public:
	MakeChange(float L[], int n);
	void print_vector(vector<int> v);
	void resetMinCost();
	bool Prg1(float m); //Greedy approach
	void Prg3(float m, int i);
	void Prg3bis(float m, int i);
	void Prg4(float m, int i, vector<vector<int>>& tDArraySolutions);
	void Prg5(float m, int i);
	void Prg6(float m, int i, vector<int>& solution);
	void Prg7(float m, int i);
	void Prg7bis(float m, int i);
};

