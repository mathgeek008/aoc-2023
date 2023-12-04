#include <iostream>
#include <vector>
#include <string>

using namespace std;
using pdt = vector<pair<vector<int>, vector<int>>>; // Problem Data Type

const string END_INPUT = "end"; // Token marking the end of input

// Problem Brainstorming

void solveP1(pdt data) {
	int sum = 0;
	for (pair<vector<int>, vector<int>> card : data) {
		double tot = 0.5;
		for (int i : card.second) {
			for (int j : card.first) {
				if (i == j) tot *= 2;
			}
		}
		sum += (int) tot;
	}
	cout << sum << endl;
}

void solveP2(pdt data) {
	int sum = 0;
	vector<int> numCards(data.size(), 1);
	int it = 0;
	for (pair<vector<int>, vector<int>> card : data) {
		int numMatches = 0;
		for (int i : card.second) {
			for (int j : card.first) {
				numMatches += (int) (i == j);
			}
		}
		for (int i = it + 1; i < data.size() && i <= it + numMatches; i++) {
			numCards[i] += numCards[it];
		}
		it++;
	}
	for (int i : numCards) sum += i;
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

vector<string> splitBySpace(string s) {
	vector<string> ret;
	string cur = "";
	for (char c : s) {
		if (c == ' ' && cur.size() > 0) {
			ret.push_back(cur);
			cur = "";
		} else if (c != ' ') {
			cur += c;
		}
	}
	if (cur.size() > 0) {
		ret.push_back(cur);
	}
	return ret;
}

pdt parseInput(vector<string> input) {
	pdt parsedInput;
	for (string line : input) {
		vector<string> tokens = splitBySpace(line);
		vector<int> winNums;
		vector<int> haveNums;
		int it = 0;
		for (int i = 2; tokens[i] != "|"; i++) {
			winNums.push_back(stoi(tokens[i]));
			it = i;
		}
		for (int i = it + 2; i < tokens.size(); i++) {
			haveNums.push_back(stoi(tokens[i]));
		}
		parsedInput.push_back({ winNums, haveNums });
	}
	return parsedInput;
}

int main() {
	pdt data = parseInput(getInput());
	cout << endl;
	solveP1(data);
	solveP2(data);
	return 0;
}
