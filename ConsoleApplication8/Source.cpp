#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<int> skipValue;

void createLookUp(string& pat) {


	for (int index = 0; index < pat.length(); index++) {


		skipValue.push_back(pat.length() - index - 1);

	}



}

int stringSearch(string txt, string pat) {
	int dummy;
	bool found =false;
	
	
	

	createLookUp(pat);
	int dum = pat.length();
	int j = pat.length() - 1;

	for (int i = pat.length() - 1; i <= txt.length()-1; i++) {

		//if the char of the text file doesnt match the pattern char at that position 
		if (txt[i] != pat[j]) {

			for (int a = 0; a < pat.length() - 1; a++) {

				//if it exists in the pattern string then skip according to the skipValue table and break out of the loop
				if (txt[i] == pat[a]) {
					i += skipValue[pat.length() - 1];
					found = true;
					break;
				}

			}


			//if it doesnt exist in the pattern string then skip past that char
			if (found == false) {
				i += pat.length();
			}

		}







		//if the txt char matches the pat char
		if (txt[i] == pat[j]) {
			int a = i - 1;
			int b = i - pat.length();
			
			int c = pat.length() - 2;
			//then check the previous txt chars
			for (int c = pat.length() - 2; c>0; c--) {
				

				if (txt[a] != pat[c]) {
					i += skipValue[pat.length() - 1];
					break;
				}


				
				
			}


			return i;



		}

		


	}



	return -1;



	


}

int main() {

	string txt;
	string pat;

	cout << "Please input the desired text";
	cin >> txt;
	cout << "Please input the pattern";
	cin >> pat;
	cout << stringSearch(txt, pat);
	int dummy;
	cin >> dummy;
}