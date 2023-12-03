#include <iostream>
#include <vector>
#include <string>
#include <set>

using namespace std;
using pdt = vector<string>; // Problem Data Type

const string END_INPUT = "end"; // Token marking the end of input

// Problem Brainstorming

void solveP1(pdt data) {
	int sum = 0;
	for (int i = 0; i < data.size(); i++) {
		string line = data[i];
		string curRun = "";
		for (int j = 0; j <= line.size(); j++) {
			if (!::isdigit(line[j]) || j == line.size()) {
				if (curRun.size() > 0) {
					// Check around the number is all directions
					for (int k = j - curRun.size() - 1; k <= j; k++) {
						if (i - 1 >= 0 && k >= 0 && k < line.size() && !::isdigit(data[i - 1][k]) && data[i - 1][k] != '.') {
							sum += stoi(curRun);
						}
						if (k >= 0 && k < line.size() && !::isdigit(data[i][k]) && data[i][k] != '.') {
							sum += stoi(curRun);
						}
						if (i + 1 < data.size() && k >= 0 && k < line.size() && !::isdigit(data[i + 1][k]) && data[i + 1][k] != '.') {
							sum += stoi(curRun);
						}
					}
					curRun = "";
				}
				if (j == line.size()) break;
			} else {
				curRun += line[j];
			}
		}
	}
	cout << sum << endl;
}

void solveP2(pdt data) {
	int sum = 0;
	for (int i = 0; i < data.size(); i++) {
		string line = data[i];
		for (int j = 0; j < line.size(); j++) {
			if (line[j] == '*') {
				// Check around the gear for adjacent numbers
				set<int> adjacentNumbers;
				for (int k = i - 1; k <= i + 1; k++) {
					for (int l = j - 1; l <= j + 1; l++) {
						if (k >= 0 && k < data.size() && l >= 0 && l < line.size()) {
							if (::isdigit(data[k][l])) {
								string foundNum = string(1, data[k][l]);
								for (int m = l + 1; m < line.size(); m++) {
									if (::isdigit(data[k][m])) {
										foundNum += data[k][m];
									} else {
										break;
									}
								}
								for (int m = l - 1; m >= 0; m--) {
									if (::isdigit(data[k][m])) {
										foundNum = data[k][m] + foundNum;
									} else {
										break;
									}
								}
								adjacentNumbers.insert(stoi(foundNum));
							}
						}
					}
				}
				if (adjacentNumbers.size() == 2) {
					long long prod = 1;
					for (int adj : adjacentNumbers) {
						prod *= adj;
					}
					sum += prod;
				}
			}
		}
	}
	cout << sum << endl;
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
