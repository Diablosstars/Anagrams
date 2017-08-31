// Anagrams.cpp
// Christian Ellison
#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>

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

			sort(anagramA.begin(), anagramA.end());
			sort(anagramB.begin(), anagramB.end());

			if (anagramA == anagramB)
				fout << "YES" << endl;
			else
				fout << "NO" << endl;

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