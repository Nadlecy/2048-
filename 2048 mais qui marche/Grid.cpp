#include <iostream>;
#include <string>;
#include "Grid.h";
#include "Box.h";


Grid::Grid() 
{
	array = {};
	for (int i = 0; i < 16; i++) {
		array.push_back(new Box());
	}

	playing = true;
};

void Grid::Display()
{
	system("cls");
	cout << "_____________________" << endl;
	for (int i = 0; i < 4; i++) {
		cout << "|";
		for (int u = 0; u < 4; u++) {
			if (array[i*4 + u]->box_value > 0)
			{

				int size = trunc(log10(array[i * 4 +u]->box_value));

				if (size == 4){

					cout << array[i * 4 +u]->box_value;

				} else {

					string space;

					for (int j = size +1; j < 4; j++){

						space += " ";

					}

					cout << space << array[i * 4 +u]->box_value <<"|";

				}
			}
			else {
				cout << "    |";
			}
		}
		cout << endl << "_____________________" << endl;
	}
}

void Grid::CreateNumber(bool isFirst)
{
	bool placing = true;
	int rng = rand() % 16;
	if (isFirst)
	{
		array[rng]->box_value = 2;
	} 
	else 
	{
		while (placing) {
			if (array[rng]->box_value == 0) {

				if (rand() % 10 == 9)
				{
					array[rng]->box_value = 4; 
				}
				else {
					array[rng]->box_value = 2;
				}
				placing = false;
			}
			else {
				rng = rand() % 16;
			}
		}
	}
}

void Grid::Movement()
{
	string playerAnswer;
	bool choosing = true;
	while (choosing) {
		cout << "Which direction do you want to play ?" << endl;
		cin >> playerAnswer;
		if (playerAnswer == "up" || playerAnswer == "left" || playerAnswer == "right" || playerAnswer == "down") {
			choosing = false;
		}
		else {
			cout << "Réponse invalide; veuillez choisir 'up', 'down', 'left' ou 'right'";
		}
	}

	vector<Box*> stacker(4);

	// up = -4, down = +4, left = -1, right = +1

	if(playerAnswer == "up"){
		for(int i =0; i < 16; i++){
			if (array[i]->box_value != 0){
				while (i-4 > 0 || array[i-4]->box_value != 0) {
					int j = array[i]->box_value;
					array[i]->box_value = 0;
					array[i-4]->box_value = j;
				}
				while (i-4 > 0 ) {
					if (array[i-4]->box_value == array[i]->box_value){
						int j = array[i]->box_value;
						array[i]->box_value = 0;
						array[i-4]->box_value += j;
					}
				}
			}
		}
	}
	else if(playerAnswer == "down"){
		for(int i =0; i < 16; i++){
			if (array[i]->box_value != 0){
				while (i+4 < 16 || array[i+4]->box_value != 0) {
					int j = array[i]->box_value;
					array[i]->box_value = 0;
					array[i+4]->box_value = j;
				}
				while (i+4 < 16 ) {
					if (array[i+4]->box_value == array[i]->box_value){
						int j = array[i]->box_value;
						array[i]->box_value = 0;
						array[i+4]->box_value += j;
					}
				}
			}
		}
	}
	else if(playerAnswer == "left"){
		for(int i =0; i < 16; i++){
			if (array[i]->box_value != 0){
				while (i-4 > 0 || array[i-4]->box_value != 0) {
					int j = array[i]->box_value;
					array[i]->box_value = 0;
					array[i-4]->box_value = j;
				}
				while (i-4 > 0 ) {
					if (array[i-4]->box_value == array[i]->box_value){
						int j = array[i]->box_value;
						array[i]->box_value = 0;
						array[i-4]->box_value += j;
					}
				}
			}
		}
	}
	else if(playerAnswer == "right"){
		for(int i =0; i < 16; i++){
			if (array[i]->box_value != 0){
				while (i-4 > 0 || array[i-4]->box_value != 0) {
					int j = array[i]->box_value;
					array[i]->box_value = 0;
					array[i-4]->box_value = j;
				}
				while (i-4 > 0 ) {
					if (array[i-4]->box_value == array[i]->box_value){
						int j = array[i]->box_value;
						array[i]->box_value = 0;
						array[i-4]->box_value += j;
					}
				}
			}
		}
	};
};

