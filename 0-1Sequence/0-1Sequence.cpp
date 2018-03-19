// 0-1Sequence.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>
#include <vector>
#include <utility>
#include <unordered_map>

using namespace std;

vector<string> allbinary = {};
unordered_map<string, int> hashes;

string s1 = "";
string s2 = "";
int sum = 0;

void AllPossibs(string input)
{
	int QM = input.find_last_of("?"); //QM = first question mark location found from the left
	if (QM != -1)
	{
		input.at(QM) = '1';
		AllPossibs(input);
		input.at(QM) = '0';
		AllPossibs(input);
	}
	else
	{
		allbinary.push_back(input);
		cout << "possible binary: " << input << endl;
	}
};
string testInput; //input to change things with, while keeping the orignial
void Moving1Over(string input)
{
	int swaps = 0;
	string one = "1";
	
	while (input.find_first_of('1') < input.find_last_of('0')) //0 or 0s are at the end
	{
		cout << "before alterations: " << input << endl;
		swaps = input.find_last_of('0') - input.find_first_of('1');
		//cout << "last of one: " << input.find_last_of('1') << endl;
		input.erase(input.find_first_of('1'), 1);
		input = input + one;
		cout << "after alterations: " << input << endl;
		sum = swaps + sum;
	}
}

int main()
{
	AllPossibs("10?0");
	//for (string s : allbinary)
	//{
		//Moving1Over(s);
	//}
	Moving1Over("1010011");
	cout << "sum " << sum << endl;
    return 0;
}

