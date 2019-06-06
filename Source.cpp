#include <iostream>
#include <sstream>
#include <map>

#define COUNT 5

using namespace std;

class Competition {
protected:
	string nameOfCompetition;
	string date;
public:
	Competition() {}

	Competition(string nameOfCompetition, string date) {
		this->nameOfCompetition = nameOfCompetition;
		this->date = date;
	}

	virtual string whoWin() {
		return "not example of match class!";
	}
	virtual void getInfo() {
		cout << nameOfCompetition << " " << date << " ";
	}
};

class Match : public Competition {
public:
	string nameOfFirst;
	int scoreOfFirst;
	string nameOfSecond;
	int scoreOfSecond;
public:
	Match(const string& nameOfCompetition, const string& date, const string& nameOfFirst, int scoreOfFirst,
		const string& nameOfSecond, int scoreOfSecond) : Competition(nameOfCompetition, date),
		nameOfFirst(nameOfFirst), scoreOfFirst(scoreOfFirst),
		nameOfSecond(nameOfSecond), scoreOfSecond(scoreOfSecond) {}

	string whoWin() {
		if (scoreOfFirst > scoreOfSecond) {
			return nameOfFirst;
		}
		else if (scoreOfFirst < scoreOfSecond) {
			return nameOfSecond;
		}
		return "noone";
	}
	void getInfo() {
		cout << nameOfCompetition << " " << date << " " << "MATCH " << nameOfFirst << " " << scoreOfFirst << " " << scoreOfSecond << " " << nameOfSecond << endl;
	}
};

class Run : public Competition {
public:
	string loser;
	int scoreOfLoser;
	string winner;
	int scoreOfWinner;
public:
	Run(const string& nameOfCompetition, const string& date, const string& loser, int scoreOfLoser,
		const string& winner, int scoreOfWinner) : Competition(nameOfCompetition, date), loser(loser),
		scoreOfLoser(scoreOfLoser), winner(winner),
		scoreOfWinner(scoreOfWinner) {}

	string whoWin() {
		return winner;
	}
	void getInfo() {
		cout << nameOfCompetition << " " << date << " " << "RUN " << winner << " " << scoreOfWinner << " " << scoreOfLoser << " " << loser << endl;
	}
};

void countWins(Competition* arrayOfMembers[COUNT], int arrayOfWins[3][3]) {
	for (int i = 0; i < COUNT; i++) {
		string result = arrayOfMembers[i]->whoWin();
		if (result == "TeamLol") {
			arrayOfWins[0][0]++;
		}
		else if (result == "Oreol") {
			arrayOfWins[1][0]++;
		}
		else if (result == "Soma") {
			arrayOfWins[2][0]++;
		}
	}
}

void sortSum(int arrayOfWins[3], string arrayOfTeams[3]) {
	int temp;
	string nameTemp;
	for (int i = 0; i < 3 - 1; i++) {
		for (int j = 0; j < 3 - i - 1; j++) {
			if (arrayOfWins[j] > arrayOfWins[j + 1]) {
				temp = arrayOfWins[j];
				arrayOfWins[j] = arrayOfWins[j + 1];
				arrayOfWins[j + 1] = temp;
				nameTemp = arrayOfTeams[j];
				arrayOfTeams[j] = arrayOfTeams[j + 1];
				arrayOfTeams[j + 1] = nameTemp;
			}
		}
	}
}

void printTeams(int arrayOfWins[3], string arrayOfTeams[3]) {
	for (int i = 0; i < 3; i++) {
		cout << arrayOfTeams[i] << " wins -> " << arrayOfWins[i] << endl;
	}
	cout << endl;
}

void printInfo(Competition* arrayOfMembers[COUNT]) {
	cout << "Info about members of competition" << endl;
	for (int i = 0; i < COUNT; i++) {
		arrayOfMembers[i]->getInfo();
	}
	cout << endl;
}