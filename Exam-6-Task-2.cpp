//////////////////////////////////////
// Task 2. 2.	Rotate and Sum
/////////////////////////////////////

#include <iostream>
#include <string>
#include <vector>
#include <cassert>
#include <sstream>
using namespace std;

int main() {

	vector<string> word;
	vector<int> digit;
	string text;
	int n;

	getline(cin, text);
	cin >> n;

	int length = text.length();

	word.push_back("");
	int count = 0;
	for (int index = 0; index < length; index++) {
		if(text[index] == ' ') {
			word.push_back("");
			count++;
			continue;
		}
		word[count] += text[index];
	}
    
	int * arr = new int[count];
	assert(arr);

	for (int i = 0; i < count + 1; i++) {
		istringstream buffer(word[i]);
		buffer >> arr[i];
	}

	int * sum = new int[count + 1];
	for (int i = 0; i <= count; i++) {
		sum[i] = 0;
		sum[i] += arr[i];
	}

	for (int i = 0; i < n - 1; i++) {
		for (int j = 0; j <= count; j++) {

			int c = (j - i)%(count + 1) > 0 ? (j - i)%(count + 1) - 1 : count - (i - j)%(count + 1);
			sum[j] += arr[c];

		}
	}

	for (int j = 0; j <= count; j++) {
		cout << sum[j] << " ";
	}
	cout << endl;
	system("pause");
	return 0;
}