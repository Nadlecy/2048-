#include <iostream>;
#include "Stacker.h";

Stacker::Stacker() {
	storage = {};

	for (int u = 0; u < 4; u++)
	{
		storage.push_back(new Box());
	}
	direction = 0; //	0 = up		1 = down	2 = left	3 = right
}

void Stacker::Retrieve(int slot,  Grid grid) {
	for (int boxes = 0; boxes < 4; boxes++) {
		if (direction == 0) {//up
			storage[boxes] = grid.array[boxes * 4 + slot];
		}
		else if (direction == 1) {//down
			storage[boxes] = grid.array[(12 - boxes * 4) + slot];
		}
		else if (direction == 2) {//left
			storage[boxes] = grid.array[boxes + slot * 4];
		}
		else if (direction == 3) {//right
			storage[boxes] = grid.array[4 - boxes + slot*4];
		}
	}
}

void Stacker::Squish() {
	for (int i = 0; i < 3; i++) {
		if (storage[i]->box_value == 0 && i<2) {
			rotate(storage[i], storage[i+1], storage[-1]);
		}
		if (storage[i]->box_value == storage[i + 1]->box_value) {
			storage[i]->box_value = storage[i]->box_value * 2;
			storage[i + 1]->box_value = 0;
		}
	}
}

void Stacker::Send(int slot, Grid grid) {
	for (int boxes = 0; boxes < 4; boxes++) {
		if (direction == 0) {//up
			grid.array[boxes * 4 + slot] = storage[boxes];
		}
		else if (direction == 1) {//down
			grid.array[(12 - boxes * 4) + slot] = storage[boxes];
		}
		else if (direction == 2) {//left
			grid.array[boxes + slot * 4] = storage[boxes];
		}
		else if (direction == 3) {//right
			grid.array[4 - boxes + slot*4] = storage[boxes];
		}
	}

}

void Stacker::Launch(int direction, Grid grid) {
	for (int slot = 0; slot < 4; slot++) {
		Retrieve(slot, grid);
		Send(slot, grid);
	}
}