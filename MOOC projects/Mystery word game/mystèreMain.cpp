#include <iostream>
#include <string>
#include <ctime>
#include <cstdlib>
#include <vector>
#include "mystèreProto.h"
using namespace std;

int main()
{
	string choix;
	vector<int> score;
	do
	{
		string mot, mix;

		mot = pick();
		mix = mot;

		string guess;
		melange(mix);
		int tries(0), maxTries;
		cout << "\nBefore playing, please select the maximum number of tries per word (ex: ""3"")" << endl;
		cin >> maxTries;
		cin.ignore();
		int remainingTries(maxTries);

		do
		{
			cout << "\nWhat is this word randomly picked from a French dictionary? " << mix << endl << "You have " << remainingTries << " tries left." << endl;
			getline(cin, guess);
			tries++;
			remainingTries = maxTries - tries;

			if (mot != guess)
			{
				cout << "This is not the correct response !\n" << endl;
			}
			else { cout << "Bravo ! You found the right word after " << tries << " tries." << endl; }

			if (mot != guess && tries == maxTries)
			{
				cout << "\nYou don't have any try left. The correct word was: " << mot << " (Simple, no?)\n" << endl;
			}

		} while (mot != guess && tries != maxTries);

		score.push_back(tries);

		cout << "Would you like to start a new game? \"Yes\" or \"No\" " << endl;
		getline(cin, choix);

		if (choix == "No")
		{
			cout << "\n\nFinally, would you like to print your average number of tries per word? \"Yes\" or \"No\" " << endl;
			string choix2;
			getline(cin, choix2);
			if (choix2 == "Yes") { cout << "\nYour average score is " << moyenne(score) << endl << "\nAu Revoir !" << endl;; }
			else { cout << "Au Revoir !" << endl; }
		}

	} while (choix == "Yes");

	system("pause");
	return 0;
}