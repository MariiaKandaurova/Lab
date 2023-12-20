#pragma once
#include <string>

struct Node {
	Node(const std::wstring& word, const std::wstring& translation) :
		word(word), translation(translation), left(nullptr), right(nullptr) {}
	std::wstring word;
	std::wstring translation;
	Node* left;
	Node* right;
};

class Dictionary {
public:
	void operator+=(const std::pair<std::wstring, std::wstring>& word);
	void print() const;
	void operator-=(const std::wstring& string);
	std::wstring& operator[](const std::wstring& string);
	const std::wstring& operator[] (const std::wstring& string) const;
	int getWordsSize();
	void addFromFile(std::wifstream& inputFile);
private:
	void print(Node* node) const;
	Node* deleteElement(Node* node, const std::wstring& string);
	Node* getMinNode(Node* node);
	Node* createNode(const std::pair<std::wstring, std::wstring>& word);
	Node* findNodeGet(Node* node, const std::wstring& word) const;
	Node* findNodeInsert(const std::pair<std::wstring, std::wstring>& word);
	bool isLess(const std::wstring& word, Node* node) const;
	Node* root = nullptr;
	size_t size = 0;
};