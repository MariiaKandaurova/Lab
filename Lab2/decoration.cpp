#include "decoration.h"


void Decoration::ChangeColor(Color color) {
	_color = color;
}

void Decoration::Rename(const std::string& newName) {
	_name = newName;
}
