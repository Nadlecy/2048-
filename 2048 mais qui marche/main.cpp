#include <iostream>;
#include <vector>;
using namespace std;

#include "Box.h";
#include "Grid.h";

int main()
{
	Grid* Grille = new Grid();

	Grille -> CreateNumber(true);
	

	while (Grille->playing == true) 
	{
		Grille -> CreateNumber(false);
		Grille->Display();
		Grille->Movement();
	}
	
	return 0;
}