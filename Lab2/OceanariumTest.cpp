#include "pch.h"
#include "CppUnitTest.h"
#include "Oceanarium.h"
#include <string>

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace OceanariumTest
{
	TEST_CLASS(OceanariumTest)
	{
	public:
		
		TEST_METHOD(CreateOceanarium)
		{
			Oceanarium ocean("Oceanarium", 100);
			std::string expected = "Oceanarium";
			Assert::AreEqual(expected, ocean.GetName());
		}

		TEST_METHOD(CheckMoney)
		{
			Oceanarium ocean("Oceanarium", 100);
			int expected = 100;
			Assert::AreEqual(expected, ocean.GetMoney());
		}

		TEST_METHOD(ClientTestMoney)
		{
			Oceanarium ocean("Oceanarium", 100);
			Client client("James", 200);
			client.AddMoney(100);
			ocean.BuyTicket(client);
			int expected = 200;
			Assert::AreEqual(expected, client.GetMoney());
		}

		TEST_METHOD(ClientTestTickets)
		{
			Oceanarium ocean("Oceanarium", 100);
			Client client("James", 200);
			ocean.BuyTicket(client);
			client.UseTicket();
			int expected = 0;
			Assert::AreEqual(expected, client.GetTickets());
		}

		TEST_METHOD(AddTanks) 
		{
			Oceanarium ocean("Oceanarium", 100);
			ocean.AddTank();
			ocean.AddTank();
			ocean.AddTank();
			ocean.PrintTanks();
			Fish* expected = new Fish("shark", 100, 100);
			ocean.AddFishToTank(expected, 1);
			ocean.PrintTanks();
			Fish* actual = ocean.GetFish(1, 1);
			Assert::AreEqual(expected->ToString(), actual->ToString());
		}
		TEST_METHOD(UpdateDay)
		{
			Oceanarium ocean("Oceanarium", 100);
			ocean.AddTank();
			Fish* shark = new Fish("shark", 100, 100);
			ocean.AddFishToTank(shark, 1);
			ocean.UpdateDay();
			std::wstring expected = L"Species: shark dead ";
			Assert::AreEqual(expected, shark->ToString());
		}
		TEST_METHOD(UpdateDayAndFeed)
		{
			Oceanarium ocean("Oceanarium", 100);
			ocean.AddTank();
			Fish* shark = new Fish("shark", 100, 100);
			ocean.AddFishToTank(shark, 1);
			ocean.FillAllFood(100);
			ocean.UpdateDay();
			std::wstring expected = L"Species: shark food ration: 100 size: 100 weight: 100 dirtiness: 1000";
			Assert::AreEqual(expected, shark->ToString());
		}
		TEST_METHOD(DirtinessTest)
		{
			Oceanarium ocean("Oceanarium", 100);
			ocean.AddTank();
			Fish* shark = new Fish("shark", 100, 100);
			ocean.AddFishToTank(shark, 1);
			shark->ChangeFoodRation(100);
			ocean.FillAllFood(100);
			ocean.UpdateDay();
			int actual = ocean.GetDirtiness(1);
			int expected = 1000;
			Assert::AreEqual(expected, actual);
		}
		TEST_METHOD(ClearDirtinessTest)
		{
			Oceanarium ocean("Oceanarium", 100);
			ocean.AddTank();
			Fish* shark = new Fish("shark", 100, 100);
			ocean.AddFishToTank(shark, 1);
			shark->ChangeFoodRation(100);
			ocean.FillAllFood(100);
			ocean.UpdateDay();
			ocean.CleanAllTanks();
			int actual = ocean.GetDirtiness(1);
			int expected = 0;
			Assert::AreEqual(expected, actual);
		}
		TEST_METHOD(AddDecorationTest)
		{
			Oceanarium ocean("Oceanarium", 100);
			ocean.AddTank();
			Decoration* dec = new Decoration("Corals");
			dec->ChangeColor(Color::Blue);
			ocean.AddDecorationToTank(dec, 1);
			Decoration* expected = ocean.GetDecoration(1, 1);
			Decoration* actual = dec;
			Assert::AreEqual(expected->Name(), actual->Name());
		}
		TEST_METHOD(RenameDecoration)
		{
			Oceanarium ocean("Oceanarium", 100);
			ocean.AddTank();
			Decoration* dec = new Decoration("Corals");
			dec->Rename("other");
			std::string expected = "other";
			Assert::AreEqual(expected, dec->Name());
		}
		TEST_METHOD(Lighting)
		{
			Oceanarium ocean("Oceanarium", 100);
			ocean.AddTank();
			bool expected = false;
			Assert::AreEqual(expected, ocean.GetLightStatus(1));
		}
		TEST_METHOD(LightingToggle)
		{
			Oceanarium ocean("Oceanarium", 100);
			ocean.AddTank();
			ocean.ToggleLight(1);
			bool expected = true;
			Assert::AreEqual(expected, ocean.GetLightStatus(1));
		}
		TEST_METHOD(LightingOn)
		{
			Oceanarium ocean("Oceanarium", 100);
			ocean.AddTank();
			ocean.TurnOnLight(1);
			bool expected = true;
			Assert::AreEqual(expected, ocean.GetLightStatus(1));
		}
		TEST_METHOD(LightingOff)
		{
			Oceanarium ocean("Oceanarium", 100);
			ocean.AddTank();
			ocean.TurnOffLight(1);
			bool expected = false;
			Assert::AreEqual(expected, ocean.GetLightStatus(1));
		}
		TEST_METHOD(TemperatureTest)
		{
			Oceanarium ocean("Oceanarium", 100);
			ocean.AddTank();
			int expected = 0;
			Assert::AreEqual(expected, ocean.GetTemperature(1));
		}
		TEST_METHOD(SetTemperatureTest)
		{
			Oceanarium ocean("Oceanarium", 100);
			ocean.AddTank();
			ocean.SetTemperature(10, 1);
			int expected = 10;
			Assert::AreEqual(expected, ocean.GetTemperature(1));
		}
		TEST_METHOD(AddTemperatureTest)
		{
			Oceanarium ocean("Oceanarium", 100);
			ocean.AddTank();
			ocean.AddTemperature(5, 1);
			int expected = 5;
			Assert::AreEqual(expected, ocean.GetTemperature(1));
		}
	};
}
