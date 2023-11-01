#include "TestManager.h"
#include "Test.h"
#include "Box.h"

TestManager::TestManager() {
	testList = {};
	stacker = Stacker();

	//directions	up = 0		 down = 1	 left = 2	 right =3
	testList.push_back( Test("Template", 0, { 0,0,0,0, 0,0,0,0, 0,0,0,0, 0,0,0,0 }, { 0,0,0,0, 0,0,0,0, 0,0,0,0, 0,0,0,0 }));
	testList.push_back( Test("Template Failure", 0, { 0,0,0,0, 0,0,0,0, 0,0,0,0, 0,0,0,0 }, { 2,0,0,0, 0,0,0,0, 0,0,0,0, 0,0,0,0 }, false));

	testList.push_back(Test("Slide Up", 0, { 2,0,0,0, 0,2,0,0, 0,0,2,0, 0,0,0,2 }, { 2,2,2,2, 0,0,0,0, 0,0,0,0, 0,0,0,0 }));
	testList.push_back( Test("Slide Down", 1, { 0,0,0,0, 0,0,0,0, 0,0,0,2, 0,0,0,0 }, { 0,0,0,0, 0,0,0,0, 0,0,0,0, 0,0,0,2 }));
	testList.push_back( Test("Slide Left", 2, { 0,2,2,0, 0,0,2,0, 0,0,0,2, 0,0,0,0 }, { 4,0,0,0, 2,0,0,0, 2,0,0,0, 0,0,0,0 }));
	testList.push_back( Test("Slide Right", 3, { 0,0,0,0, 0,2,0,0, 2,0,0,0, 0,0,0,0 }, { 0,0,0,0, 0,0,0,2, 0,0,0,2, 0,0,0,0 }));

	testList.push_back( Test("One fusion with gap", 3, { 0,2,0,2, 0,0,0,0, 0,0,0,0, 0,0,0,0 }, { 0,0,0,4, 0,0,0,0, 0,0,0,0, 0,0,0,0 }));
	testList.push_back( Test("Two different fusions at once", 3, { 2,2,2,2, 0,0,0,0, 0,0,0,0, 0,0,0,0 }, { 0,0,4,4, 0,0,0,0, 0,0,0,0, 0,0,0,0 }));
	testList.push_back( Test("One fusion, one leftover", 2, { 0,2,2,2, 0,0,0,0, 0,0,0,0, 0,0,0,0 }, { 4,2,0,0, 0,0,0,0, 0,0,0,0, 0,0,0,0 }));
}

bool TestManager::TryTests() {
	for (int i = 0; i < testList.size(); i++) {
		stacker.Launch(testList[i].testDirection, testList[i].situationArray);
		cout << testList[i].testName;
		bool error = false;
		for (int j = 0; j < 16; j++) {
			if (testList[i].resultArray[j].box_value != testList[i].situationArray[j].box_value) {
				error = true;
			}
		}
		if (error) {
			cout << " failure !";
		}
		else {
			cout << " success !";
		}
		cout << endl;
	}

	return true;
}