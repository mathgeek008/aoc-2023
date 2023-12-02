#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;
using pdt = vector<string>; // Problem Data Type

const string END_INPUT = "end"; // Token marking the end of input

// Problem Brainstorming

void solveP1(pdt data) {
	vector<int> values;
	for (string s : data) {
		int a = s[s.find_first_of("0123456789")] - '0';
		int b = s[s.find_last_of("0123456789")] - '0';
		values.push_back(10 * a + b);
	}
	int tot = 0;
	for (int i : values) {
		tot += i;
	}
	cout << tot << endl;
}

int findFirstNumber(string s) {
	int len = s.size();
	for (int i = 0; i < len; i++) {
		if (::isdigit(s[i])) return (s[i] - '0');
		if (i < len - 2 && s.substr(i, 3) == "one") return 1;
		if (i < len - 2 && s.substr(i, 3) == "two") return 2;
		if (i < len - 4 && s.substr(i, 5) == "three") return 3;
		if (i < len - 3 && s.substr(i, 4) == "four") return 4;
		if (i < len - 3 && s.substr(i, 4) == "five") return 5;
		if (i < len - 2 && s.substr(i, 3) == "six") return 6;
		if (i < len - 4 && s.substr(i, 5) == "seven") return 7;
		if (i < len - 4 && s.substr(i, 5) == "eight") return 8;
		if (i < len - 3 && s.substr(i, 4) == "nine") return 9;
	}
	return 0;
}

int findLastNumber(string s) {
	int len = s.size();
	for (int i = len - 1; i >= 0; i--) {
		if (::isdigit(s[i])) return (s[i] - '0');
		if (i < len - 2 && s.substr(i, 3) == "one") return 1;
		if (i < len - 2 && s.substr(i, 3) == "two") return 2;
		if (i < len - 4 && s.substr(i, 5) == "three") return 3;
		if (i < len - 3 && s.substr(i, 4) == "four") return 4;
		if (i < len - 3 && s.substr(i, 4) == "five") return 5;
		if (i < len - 2 && s.substr(i, 3) == "six") return 6;
		if (i < len - 4 && s.substr(i, 5) == "seven") return 7;
		if (i < len - 4 && s.substr(i, 5) == "eight") return 8;
		if (i < len - 3 && s.substr(i, 4) == "nine") return 9;
	}
	return 0;
}

void solveP2(pdt data) {
	vector<int> values;
	for (string s : data) {
		values.push_back(10 * findFirstNumber(s) + findLastNumber(s));
	}
	int tot = 0;
	for (int i : values) {
		tot += i;
	}
	cout << tot << endl;
}

vector<string> getInput() {
	vector<string> lines;
	string curLine;
	do {
		getline(cin, curLine);
		lines.push_back(curLine);
	} while (curLine != END_INPUT);
	lines.pop_back();
	return lines;
}

pdt parseInput(vector<string> input) {
	pdt parsedInput = input;
	return parsedInput;
}

int main() {
	pdt data = parseInput(getInput());
	cout << endl;
	solveP1(data);
	solveP2(data);
	return 0;
}
