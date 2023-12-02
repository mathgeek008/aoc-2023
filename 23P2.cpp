#include <iostream>
#include <vector>
#include <string>
#include <sstream>

using namespace std;
using pdt = vector<vector<vector<pair<int, string>>>>; // Problem Data Type

const string END_INPUT = "end"; // Token marking the end of input

// Problem Brainstorming

void solveP1(pdt data) {
	// 12 red cubes, 13 green cubes, 14 blue cubes
	int sum = 0;
	int gameNumber = 1;
	for (vector<vector<pair<int, string>>> fullGame : data) {
		bool possible = true;
		for (vector<pair<int, string>> game : fullGame) {
			for (pair<int, string> toss : game) {
				if (toss.second == "red" && toss.first > 12 ||
					toss.second == "green" && toss.first > 13 ||
					toss.second == "blue" && toss.first > 14) {
					possible = false;
				}
			}
		}
		if (possible) {
			sum += gameNumber;
		}
		gameNumber++;
	}
	cout << sum << endl;
}

void solveP2(pdt data) {
	int sum = 0;
	for (vector<vector<pair<int, string>>> fullGame : data) {
		int minRed = 0, minGreen = 0, minBlue = 0;
		for (vector<pair<int, string>> game : fullGame) {
			for (pair<int, string> toss : game) {
				if (toss.second == "red" && toss.first > minRed) minRed = toss.first;
				if (toss.second == "green" && toss.first > minGreen) minGreen = toss.first;
				if (toss.second == "blue" && toss.first > minBlue) minBlue = toss.first;
			}
		}
		int power = minRed * minGreen * minBlue;
		sum += power;
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
	pdt parsedInput;
	for (string line : input) {
		stringstream cur(line);
		vector<string> tokens;
		string curToken;
		while (cur >> curToken) {
			tokens.push_back(curToken);
		}
		vector<vector<pair<int, string>>> games;
		vector<pair<int, string>> curGame;
		for (int i = 2; i < tokens.size(); i += 2) {
			int num = stoi(tokens[i]);
			string color = tokens[i + 1];
			char last = color[color.size() - 1];
			if (last == ',' || last == ';') {
				color.erase(color.end() - 1);
			}
			curGame.push_back({ num, color });
			if (last != ',') {
				games.push_back(curGame);
				curGame.clear();
			}
		}
		parsedInput.push_back(games);
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
