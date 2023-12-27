#pragma once
#include <string> 

enum class Color {
	Default, Red, Blue, Orange, Pink, Black, Green, White, Violet, Magenta, Crimson, Navy, Maroon
};

class Decoration {
public:
	Decoration(const std::string& name) : _name(name), _color(Color::Default) { }
	void ChangeColor(Color color);
	void Rename(const std::string& newName);
	std::string Name() { return _name; }
private:
	std::string _name;
	Color _color;
};
