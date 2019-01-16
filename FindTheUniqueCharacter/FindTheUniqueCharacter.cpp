// FindTheUniqueCharacter.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <string>
#include <iostream>

using namespace std;

char findUniqueCharacter(string s, int l, int r, int mid) {
	if (s[mid] != s[l] && s[mid] != s[r]) {
		return s[mid];
	}
	mid = mid + 1;
	return findUniqueCharacter(s, mid - 1, mid + 1, mid);
}

int main()
{
	string s;
	char c;
	int mid = 1;
	cin >> s;
	if (s.size() == 1 || s.size() == 2) {
		cout << s[0] << "\n";
		return 0;
	}
	if (s[0] != s[mid]) {
		cout << s[0] << "\n";
		return 0;
	}
	else if(s[s.size()] != s[s.size()-1]){
		cout << s[s.size()-1] << "\n";
		return 0;
	}
	cout << findUniqueCharacter(s, mid - 1, mid + 1, mid) << "\n";
    return 0;
}

