// BeagleBall.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <vector>
#include <iostream>
using namespace std;

vector<int> soldiers;
vector<int> damages;
int soldiersLeft = 0;
int index = 0;
bool flag = true;
int currentTotal;
/*
5 5
1 2 1 2 1
3 10 1 1 1
*/
int throwBall(int power, vector<int> soldiersAux) {
	if (flag) {
		soldiersLeft = 0;
		if (power < currentTotal) {
			for (int i = 0; i < power; i++) {
				soldiers[index] -= 1;
				currentTotal--;
				if (soldiers[index] == 0) {
					index++;
				}
			}
			for (int i = 0; i < soldiers.size(); i++) {
				if (soldiers[i] != 0) {
					soldiersLeft++;
				}
			}
			if (soldiersLeft <= 0) {
				flag = false;
			}
		}
		else {
			soldiers = soldiersAux;
			index = 0;
			for (int i = 0; i < soldiers.size(); i++) {
				currentTotal += soldiers[i];
			}
			flag = true;
			return soldiers.size();
		}
	
	}
	else {
		soldiers = soldiersAux;
		index = 0;
		flag = true;
		return soldiers.size();
	}
	return soldiersLeft;
}
int main()
{
	int n, q;
	cin >> n >> q;
	vector<int>soldiersAux(n);
	int sol, p;
	//Fill the soldiers array
	for (int i = 0; i < n; i++) {
		cin >> sol;
		soldiers.push_back(sol);
		currentTotal += sol;
	}

	soldiersAux = soldiers;

	//Fill the power array
	for (int i = 0; i < q; i++) {
		cin >> p;
		damages.push_back(p);
	}

	for (int i = 0; i < damages.size(); i++) {
		cout << throwBall(damages[i], soldiersAux) << "\n";
	}
    return 0;
}