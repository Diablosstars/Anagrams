// Anagrams.cpp
// Christian Ellison
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

void main() {
	ifstream fin("anagrams.in");
	if (fin.is_open()) {
		ofstream fout("anagrams.out");

		bool   isAlphaFlag;
		string anagramA,
			   anagramB;
		getline(fin, anagramA);
		getline(fin, anagramB);


		while (anagramA != "<end>" && anagramB != "<end>")
		{
			for (int i = 0; i < anagramA.size(); i++)
			{
				if (isalpha(anagramA[i]))
					anagramA[i] = tolower(anagramA[i]);
				else
				{
					anagramA.erase(i, 1);
					i--;
				}

			}
			for (int i = 0; i < anagramB.size(); i++)
			{
				if (isalpha(anagramB[i]))
					anagramB[i] = tolower(anagramB[i]);
				else
				{
					anagramB.erase(i, 1);
					i--;
				}
			}

			if (anagramA.size() != anagramB.size())
				fout << "NO";

			cout << anagramA << endl;
			cout << anagramB << endl;

			getline(fin, anagramA);
			getline(fin, anagramB);
		}

		cout << anagramA << endl;
		cout << anagramB << endl;

		fout.close();
		fin.close();
	}
	else {
		cout << "Input file not found." << endl;
	}
}