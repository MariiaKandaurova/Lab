#include "Dictionary.h"
#include <iostream>
#include <fstream>
#include <codecvt>

void Dictionary::operator+=(const std::pair<std::wstring, std::wstring>& word) { 
	Node* node = createNode(word);
	Node* prev = findNodeInsert(word);

	if (!prev) {
		root = node;
		return;
	}

	if (isLess(word.first, prev)) {
		prev->left = node;
	}
	else {
		prev->right = node;
	}
}

int Dictionary::getWordsSize() {
	return size;
}

void Dictionary::operator-=(const std::wstring& string) {
	root = deleteElement(root, string);
}

std::wstring& Dictionary::operator[](const std::wstring& string) {
	Node* result = findNodeGet(root, string);
	if (result)
		return result->translation;
	std::wstring emptyString = L"";
	return emptyString;
}

const std::wstring& Dictionary::operator[](const std::wstring& string) const {
	Node* result = findNodeGet(root, string);
	if (result)
		return result->translation;
	return L"";
} 

Node* Dictionary::findNodeGet(Node* node, const std::wstring& word) const {
	if (!node)
		return nullptr;

	if (word == node->word)
		return node;

	if (isLess(word, node)) {
		return findNodeGet(node->left, word);
	}
	else {
		return findNodeGet(node->right, word);
	}
	
} 

Node* Dictionary::getMinNode(Node* node) {
	Node* current = node;
	while (current && current->left != nullptr) { 
		current = current->left;
	}
	return current;
}

Node* Dictionary::deleteElement(Node* node, const std::wstring& string) {
	if (node == nullptr) {
		return node;
	}

	if (string == node->word) {
		if (!node->left && !node->right)
			return nullptr;
		else if (!node->left) {
			Node* temp = node->right;
			delete node;
			size--;
			return temp;
		}
		else if (!node->right) {
			Node* temp = node->left;
			delete node;
			size--;
			return temp;
		}
		Node* temp = getMinNode(node->right);
		node->word = temp->word;
		node->translation = temp->translation;
		node->right = deleteElement(node->right, temp->word);
	}
	else if (isLess(string, node)) {
		node->left = deleteElement(node->left, string);
	}
	else {
		node->right = deleteElement(node->right, string);
	}
	return node;
}

void Dictionary::print() const {
	print(root);
}

void Dictionary::print(Node* node) const {
	if (!node)
		return;
	print(node->left);
	std::wcout << "word: " << node->word << " translation: " << node->translation << std::endl;
	print(node->right);
}

Node* Dictionary::createNode(const std::pair<std::wstring, std::wstring>& word) {
	return new Node(word.first, word.second);
}

void Dictionary::addFromFile(std::wifstream& inputFile) {
	inputFile.imbue(std::locale(std::locale::empty(), new std::codecvt_utf8<wchar_t>));
	std::wstring word, translation;
	while (inputFile >> word >> translation) {
		*this += std::make_pair(word, translation);
	}
}

bool Dictionary::isLess(const std::wstring& word, Node* node) const {
	int length = word.size() < node->word.size() ? word.size() : node->word.size();
	for (int i = 0; i < length; i++) {
		if (word[i] < node->word[i]) {
			return true;
		}
		if (word[i] > node->word[i]) {
			return false;
		}
	}
}

Node* Dictionary::findNodeInsert(const std::pair<std::wstring, std::wstring>& word) {
	if (!root) {
		size++;
		return nullptr;
	}

	Node* prev = nullptr;
	Node* temp = root;
	while (temp) {
		if (temp->word == word.first) {
			return prev;
		}
		if (isLess(word.first, temp)) {
			prev = temp;
			temp = temp->left;

		}
		else {
			prev = temp;
			temp = temp->right;
		}
	}
	size++;
	return prev;
}