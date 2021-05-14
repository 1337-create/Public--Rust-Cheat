#pragma once

int M_Index = 0;
int Changes = 0;
bool updated = false;
string bools[2] = { "OFF", "ON" };


const int IAdminMode = 8;
const int IAutomat = 7;
const int IAntiSpread = 6;
const int INoRecoil = 5;
const int ISpiderMan = 4;
const int IAwaysDay = 3;
const int ITimeOfDay = 2;
const int IHighJump = 1;
const int IJumpValue = 0;


void SetColour(int ForgC) // got online
{
	WORD wColor;

	HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_SCREEN_BUFFER_INFO csbi;

	//We use csbi for the wAttributes word.
	if (GetConsoleScreenBufferInfo(hStdOut, &csbi))
	{
		//Mask out all but the background attribute, and add in the forgournd color
		wColor = (csbi.wAttributes & 0xF0) + (ForgC & 0x0F);
		SetConsoleTextAttribute(hStdOut, wColor);
	}
	return;
}

void AddContainsToggleMenu(const char* text, const int index, bool Functions)
{
	if (M_Index == index)
	{
		SetColour(10);
		cout << "> " << text << "=\t" << bools[Functions] << endl;
	}
	else
	{
		SetColour(15);
		cout << text << "=\t" << bools[Functions] << endl;
	}
}

void Navigation()
{
	for (int i = 2; i < 360; i++)
	{
		if (GetAsyncKeyState(i) & 0x8000)
		{
			switch (i)
			{
			case 38: // UP ARROW
				if (M_Index < 9)
					M_Index++;
				Changes++;
				updated = true;
				break;
			case 40: // DOWN ARROW
				if (M_Index > 0)
					M_Index--;
				Changes++;
				updated = true;
				break;
			case 37: // LEFT ARROW
				Switch(M_Index);
				Changes++;
				updated = true;
				break;
			case 39: // RIGHT ARROW
				Switch(M_Index);
				Changes++;
				updated = true;
				break;
			}
		}
	}
}

void Switch(int index)
{
	if (index == IAdminMode)
	{
		Vars::Misc::FakeAdmin = !Vars::Misc::FakeAdmin;
	}
	if (index == IAutomat)
	{
		Vars::Misc::automatic = !Vars::Misc::automatic;
	}
	if (index == IAntiSpread)
	{
		Vars::Misc::anti_spread = !Vars::Misc::anti_spread;
	}
	if (index == INoRecoil)
	{
		Vars::Misc::no_recoil = !Vars::Misc::no_recoil;
	}
	if (index == ISpiderMan)
	{
		Vars::Misc::SpiderMan = !Vars::Misc::SpiderMan;
	}
	if (index == IAwaysDay)
	{
		Vars::Misc::AlwaysDay = !Vars::Misc::AlwaysDay;
	}
	if (index == ITimeOfDay)
	{
		if (GetAsyncKeyState(37))
		{
			if (Vars::FloatAntInt::TimeOfDay > 1)
			{
				Vars::FloatAntInt::TimeOfDay --;
			}
		}
		else if (GetAsyncKeyState(39))
		{
			if (Vars::FloatAntInt::TimeOfDay < 24)
			{
				Vars::FloatAntInt::TimeOfDay ++;
			}
		}
	}
	if (index == IHighJump)
	{
		Vars::Misc::SetGravitu = !Vars::Misc::SetGravitu;
	}
	if (index == IJumpValue)
	{
		if (GetAsyncKeyState(37))
		{
			if (Vars::FloatAntInt::JumpValue > 1)
			{
				Vars::FloatAntInt::JumpValue -= 0.1;
			}
		}
		else if (GetAsyncKeyState(39))
		{
			if (Vars::FloatAntInt::JumpValue < 2)
			{
				Vars::FloatAntInt::JumpValue += 0.1;
			}
		}
	}
}

void UpdateMenu()
{
	int temp = -1;
	if (temp != Changes)
	{
		temp = Changes;
		system("CLS");
		SetColour(1);
		cout << "  \n\n\n \t\t\t\t\t\t\t>> MENU <<" << endl;
		SetColour(15);
		cout << "________________________________________________________________________________________________________________________" << endl << endl;

		
		AddContainsToggleMenu("Admin Mode\t\t\t", IAdminMode, Vars::Misc::FakeAdmin);

		//--------------
		
		AddContainsToggleMenu("Automatic\t\t\t", IAutomat, Vars::Misc::automatic);
		
		//--------------
		
		

		//--------------
		
		

		//--------------
		
		AddContainsToggleMenu("Spider Man\t\t\t", ISpiderMan, Vars::Misc::SpiderMan);

		//--------------
		
		AddContainsToggleMenu("Always Day\t\t\t", IAwaysDay, Vars::Misc::AlwaysDay);

		//--------------

		if (M_Index == ITimeOfDay)
		{
			SetColour(10);
			cout << "> Time of day\t\t\t=\t[" << Vars::FloatAntInt::TimeOfDay << "] " << endl;
		}
		else
		{
			SetColour(15);
			cout << "Time of day\t\t\t=\t[" << Vars::FloatAntInt::TimeOfDay << "] " << endl;
		}

		//--------------

		

		//--------------

		
	}
}


