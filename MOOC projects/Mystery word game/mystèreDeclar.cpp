#include <string>
#include <ctime>
#include <cstdlib>
#include <vector>
#include <fstream>
#include <iostream>
#include "mystèreProto.h"
using namespace std;

void melange(string& mix)
{
	srand(time(0));

	for (int i = 0; i <= mix.size(); i++)
	{
		int randomNum = rand() % mix.size();
		mix.push_back(mix[randomNum]);
		mix.erase(randomNum, 1);
	}

}

string pick()
{
	ifstream randomWord("C:/Users/mathe/Documents/Cours et travail/Columbia/Preparatory courses/C++ Finance/Visual Studio 2017/Projects/RebuildMystere/dico.txt");

	if (randomWord)
	{
		string ligne;
		int tailleFichier(0);

		while (std::getline(randomWord, ligne))
		{
			tailleFichier++;
		}

		srand(time(0));
		int randomLine = rand() % tailleFichier;
		randomWord.clear();
		randomWord.seekg(0, ios::beg);
		int counter(0);

		while (counter<randomLine + 1)
		{
			std::getline(randomWord, ligne);
			counter++;
		}

		return ligne;
	}

}

double moyenne(vector<int> const& tableau)
{
	double somme(0);
	for (int i(0); i<tableau.size(); i++)
	{
		somme += tableau[i];
	}
	somme /= tableau.size();
	return somme;
}