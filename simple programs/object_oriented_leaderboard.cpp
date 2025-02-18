// Leaderboard project
// A sorted leaderboard in descending order based on score
//user inputs the name of the player and the score of the player
//user inputs 'y' to continue inputting players or 'n' to stop

#include<iostream>
#include<string>

using namespace std;

class leaderboardObj {
	private: int size;
	private: long long* values = nullptr;
	private: string* leaderboard = nullptr;

	//*COLLECTION TYPE LIST*
	// scores and names of players

	public: leaderboardObj() { 
		size = 10;
		values = new long long[size] { 1, 2, 33, 5, 1, 2, 3, 4, 1, 7 };
		leaderboard = new string[size];

		for (int i = 0; i < size; i++) {
			leaderboard[i] = "player_" + to_string(i + 1);
		}
	};

	//*PROCEDURE*
	// sorts given list of numbers from greatest to smallest
	// sorts given list of players according to their corresponding number
	public : void selectSort()
	{
		//*INTERATION*
		//*SELECTION*
		//*SEQUENCING*
		//iterates through list of scores
		for (int x = 0; x < size - 1; x++)
		{
			int maxValue = values[x], maxIndex = x;
			string maxName = leaderboard[x];

			// finds biggest value and swaps it to the front 
			for (int i = maxIndex + 1; i < size; i++)
			{
				if (values[i] > maxValue)
				{
					maxValue = values[i];
					maxName = leaderboard[i];
					maxIndex = i;
				}
			}
			values[maxIndex] = values[x];
			values[x] = maxValue;
			leaderboard[maxIndex] = leaderboard[x];
			leaderboard[x] = maxName;
		}
	}

	//*PROCEDURE*
	// adds new player and score
	private : pair<long long*, string*> sortNewLead(long long scor, string player)
	{
		int pos = size;
		int offset = 0;
		long long* newScores = new long long[size + 1];
		string* newLeads = new string[size + 1];

		//*INTERATION*
		//*SELECTION*
		// finds where to insert new score
		for (int i = 0; i < size; i++) {
			if (scor > values[i]) {
				pos = i;
				break;
			}
		}

		//*INTERATION*
		//*SELECTION*
		//*SEQUENCING*
		//adds old scores and players name to a new list
		for (int i = 0; i < size + 1; i++) {
			if (i != pos) {
				newScores[i] = values [i - offset] ;
				newLeads[i] = leaderboard[i - offset];
			}

			else {
				offset++;
			}
		}

		// adds new score and player
		newScores[pos] = scor;
		newLeads[pos] = player;

		// returns new lists
		return { newScores, newLeads };
	}

	//*PROCEDURE*
	//*INTERATION*
	//*OUTPUT*
	// displays the leaderboard
	public: void displayLead() {

		for (int i = 0; i < size; i++) {
			cout << "rank " << i + 1 << ' ' << leaderboard[i] << " score: " << values[i] << endl;
		}
	}

	//*PROCEDURE*
	// adding new players and scores until user decides to stop
	public: void loop() {
		long long score = 0;
		string name = "";
		bool cont = true;
		char reply = 'y';

		//*INTERATION*
		//*SELECTION*
		//*SEQUENCING*
		while (cont == true) {

			//*INPUT FROM USER*
			// user inputs new player and score
			cout << endl << "enter username" << endl;
			cin >> name;

			cout << endl << "enter your score: " << endl;
			cin >> score;
			cout << endl;


			pair<long long*, string*> arrays = sortNewLead(score, name);

			size++;

			//deletes old lists
			delete[] values;
			delete[] leaderboard;

			// pointers pointing to new lists
			values = arrays.first;
			leaderboard = arrays.second;

			cout << "-LEADERBOARD-" << endl;
			displayLead();

			cout << endl << "continue? (y/n)" << endl;
			cin >> reply;

			if (reply == 'n')
			{
				cont = false;
			}
		}

		// displays leaderboard at the end
		cout << endl << "-FINAL LEADERBOARD-" << endl;

		displayLead();
	}
};

int main() {
	leaderboardObj lead1;

	//sorts leaderboard
	lead1.selectSort();

	//displays leaderboard at start
	cout << "-LEADERBOARD-" << endl;
	lead1.displayLead();

	//user inputs new scores and players
	lead1.loop();

	return 0;
}
