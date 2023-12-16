#pragma once

using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Collections::Generic;

public ref class Train {

public:
	String^ From;
	String^ DepartTo;
	Boolean Status; //0 is arriving; 1 is departing;
	Int32 DateFrom;
	Int32 DateDepartTo;
	Int32 AvailableSeats;
	String^ TypeOfTrain;

	Train(String^ CityFrom, String^ CityTo, Boolean ArOrDep, Int32 DateF, Int32 DateD, Int32 Seats, String^ TrainType) {
		From = CityFrom;
		DepartTo = CityTo;
		Status = ArOrDep;
		DateFrom = DateF;
		DateDepartTo = DateD;
		AvailableSeats = Seats;
		TypeOfTrain = TrainType;
	}
};
