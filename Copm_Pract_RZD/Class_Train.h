#pragma once

using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Collections::Generic;

public ref class Train {

public:
	String^ From;
	String^ DepartTo;
	Int32 Status; //false is arriving; true is departing;
	DateTime DateFrom;
	DateTime DateDepartTo;
	Boolean AvailableSeats = false;
	Int32 SeatsKupe = 0;
	Int32 SeatsSleep = 0;
	Int32 SeatsPlatscart = 0;
	Dictionary<String^, String^> AllData;

	Train(String^ CityFrom, String^ CityTo, Int32 ArOrDep, String^ DateF, String^ DateD, Int32 Kupe, Int32 Sleep, Int32 Platscart) {
		From = CityFrom;
		DepartTo = CityTo;
		Status = ArOrDep;
		DateFrom = DateTime::Parse(DateF);
		DateDepartTo = DateTime::Parse(DateD);
		SeatsKupe = Kupe;
		SeatsSleep = Sleep;
		SeatsPlatscart = Platscart;
		SetStatusOfAvailableSeats();

		//Add keys and values in dictionary
		AllData.Add("From", Convert::ToString(From));
		AllData.Add("DepartTo", Convert::ToString(DepartTo));
		AllData.Add("Status", Convert::ToString(Status));
		AllData.Add("DateFrom", DateFrom.ToString("dd.MM.yyyy"));
		AllData.Add("DateDepartTo", DateDepartTo.ToString("dd.MM.yyyy"));
		AllData.Add("AvailableSeats", Convert::ToString(AvailableSeats));
		AllData.Add("SeatsKupe", Convert::ToString(SeatsKupe));
		AllData.Add("SeatsSleep", Convert::ToString(SeatsSleep));
		AllData.Add("SeatsPlatscart", Convert::ToString(SeatsPlatscart));
	}

private:
	void SetStatusOfAvailableSeats() {
		if (SeatsKupe != 0 || SeatsSleep != 0 || SeatsPlatscart || 0)
		{
			AvailableSeats = true;
		}
	}
};
