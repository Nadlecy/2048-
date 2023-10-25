#include "Box.h";
#include "Grid.h";

#include <iostream>;
#include <vector>;

using namespace std;


int main()
{
	Grid* Grille = new Grid();

	Grille -> CreateNumber(true);
	

	while (Grille->playing == true) 
	{
		Grille->CreateNumber(false);
		if (not Grille->stacker.OverallCheck(Grille->array)) {
			cout << "loss";
			break;
		}

		Grille->Display();
		Grille->Movement();
		Grille->playing = Grille->Win();
		//Grille->playing = Grille->Defeat();

	}
	
	return 0;
}