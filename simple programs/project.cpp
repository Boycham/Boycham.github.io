// Leaderboard project
// A sorted leaderboard in descending order based on score
//user inputs the name of the player and the score of the player
//user inputs 'y' to continue inputting players or 'n' to stop

#include<iostream>
#include<string>

using namespace std;

//*PROCEDURE*
// sorts given list of numbers from greatest to smallest
// sorts given list of players according to their corresponding number
void selectSort(long long arr[], string lead[], int siz)
{	
	//*INTERATION*
	//*SELECTION*
	//*SEQUENCING*
	//iterates through list of scores
	for (int x = 0; x < siz - 1; x++)
	{
		int maxValue = arr[x], maxIndex = x;
		string maxName = lead[x];

		// finds biggest value and swaps it to the front 
		for (int i = maxIndex + 1; i < siz; i++)
		{
			if (arr[i] > maxValue)
			{
				maxValue = arr[i];
				maxName = lead[i];
				maxIndex = i;
			}
		}
		arr[maxIndex] = arr[x];
		arr[x] = maxValue;
		lead[maxIndex] = lead[x];
		lead[x] = maxName;
	}
}

//*PROCEDURE*
// adds new player and score
pair<long long*, string*> sortNewLead(long long arr[], string lead[], long long scor, string player, int siz)
{
	int pos = siz;
	int offset = 0;
	long long* newScores = new long long[siz + 1];
	string* newLeads = new string[siz + 1];

	//*INTERATION*
	//*SELECTION*
	// finds where to insert new score
	for (int i = 0; i < siz; i++) {
		if (scor > arr[i]) {
			pos = i;
			break;
		}
	}

	//*INTERATION*
	//*SELECTION*
	//*SEQUENCING*
	//adds old scores and players name to a new list
	for (int i = 0; i < siz + 1; i++) {
		if (i != pos) {
			newScores[i] = arr[i - offset];
			newLeads[i] = lead[i - offset];
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
void displayLead(long long arr[], string lead[], int siz) {

	for (int i = 0; i < siz; i++) {
		cout << "rank " << i + 1 << ' ' << lead[i] << " score: " << arr[i] << endl;
	}
}

//*PROCEDURE*
// adding new players and scores until user decides to stop
void loop(long long vals[], string leads[], int siz) {
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


		pair<long long*, string*> arrays = sortNewLead(vals, leads, score, name, siz);

		siz++;

		//deletes old lists
		delete[] vals;
		delete[] leads;

		// pointers pointing to new lists
		vals = arrays.first;
		leads = arrays.second;

		cout << "-LEADERBOARD-" << endl;
		displayLead(vals, leads, siz);

		cout << endl << "continue? (y/n)" << endl;
		cin >> reply;

		if (reply == 'n')
		{
			cont = false;
		}
	}

	// displays leaderboard at the end
	cout << endl << "-FINAL LEADERBOARD-" << endl;

	displayLead(vals, leads, siz);
}

int main() {
	int size = 10;

	long long* values = nullptr;
	string* leaderboard = nullptr;

	//*COLLECTION TYPE LIST*
	// scores and names of players
	values = new long long[size] { 1, 2, 33, 5, 1, 2, 3, 4, 1, 7 };
	leaderboard = new string[size];

	for (int i = 0; i < size; i++) {
		leaderboard[i] = "player_" + to_string(i + 1);
	}

	//sorts leaderboard
	selectSort(values, leaderboard, size);

	//displays leaderboard at start
	cout << "-LEADERBOARD-" << endl;
	displayLead(values, leaderboard, size);

	//user inputs new scores and players
	loop(values, leaderboard, size);

	return 0;	
}