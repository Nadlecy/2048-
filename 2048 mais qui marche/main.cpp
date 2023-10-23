#include <iostream>;
#include <vector>;
using namespace std;

#include "Box.h";

int main()
{
	vector<int> array = {};
	for (int i = 0; i < 16; i++) {
		array.push_back(0);
	}

	for (int j = 0; j < 4; j++) {
		for (int i =0; i<4; i++){
			cout << array[i + j];
		}
		cout << endl;
	};
	return 0;
}