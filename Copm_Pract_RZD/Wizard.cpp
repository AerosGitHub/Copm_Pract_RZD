#include "Wizard.h"
#include "DataBaseViewer.h"
#include "Variables.h"

using namespace System;
using namespace System::Windows::Forms;

[STAThreadAttribute]

int main(array<String^>^ args) {
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);
	CopmPractRZD::Wizard Wizard_form;
	CopmPractRZD::DataBaseViewer DataBade_form;
	Application::Run(% Wizard_form);
	switch (cheacker) {
		case 1 : Application::Run(% DataBade_form); break;
	}
}

