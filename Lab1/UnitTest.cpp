#include "pch.h"
#include "CppUnitTest.h"
#include "Dictionary.h"
#include <fstream>
#include <string>

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace DictionaryTest
{
	TEST_CLASS(DictionaryTest)
	{
	public:

		TEST_METHOD(InputFileTest)
		{
			Dictionary dict;
			std::wifstream inputFile("C:\\Users\\Kandaurova Maria\\Desktop\\BSUIR\\ppois\\Dictionary\\Dictionary\\1.txt");
			dict.addFromFile(inputFile);
			dict.print();
			int expected = 3;
			Assert::AreEqual(expected, dict.getWordsSize());
		}
		TEST_METHOD(CheckTest)
		{
			Dictionary dict;
			std::wifstream inputFile("C:\\Users\\Kandaurova Maria\\Desktop\\BSUIR\\ppois\\Dictionary\\Dictionary\\1.txt");
			dict.addFromFile(inputFile); 
			std::wstring expected = L"Da";
			Assert::AreEqual(expected, dict[L"Yes"]);
		}
		TEST_METHOD(AddElementTest)
		{
			Dictionary dict;
			dict += std::make_pair(L"Building", L"Zdanie");
			std::wstring expected = L"Zdanie";
			Assert::AreEqual(expected, dict[L"Building"]);
		}
		TEST_METHOD(DeleteTest1)
		{
			Dictionary dict;
			dict += std::make_pair(L"Building", L"Zdanie");
			dict += std::make_pair(L"Human", L"Chelovek");
			dict += std::make_pair(L"Cat", L"Coshka");
			dict -= L"Human";
			std::wstring expected = L"";
			Assert::AreEqual(expected, dict[L"Human"]);
		}
		TEST_METHOD(DeleteTest2)
		{
			Dictionary dict;
			dict += std::make_pair(L"Building", L"Zdanie");
			dict += std::make_pair(L"Human", L"Chelovek");
			dict += std::make_pair(L"Cat", L"Coshka");
			dict -= L"Building";
			std::wstring expected = L"";
			Assert::AreEqual(expected, dict[L"Building"]);
		}
		TEST_METHOD(DeleteTest3)
		{
			Dictionary dict;
			dict += std::make_pair(L"Building", L"Zdanie");
			dict += std::make_pair(L"Human", L"Chelovek");
			dict += std::make_pair(L"Cat", L"Coshka");
			dict += std::make_pair(L"Alphabet", L"Alfavit");
			dict -= L"Building";
			std::wstring expected = L"";
			Assert::AreEqual(expected, dict[L"Building"]);
		}
		
	};
}
