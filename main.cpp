#pragma warning(disable : 4530)
#define WIN32_LEAN_AND_MEAN
#define _CRT_SECURE_NO_WARNINGS

#define safe_read(Addr, Type) driver::read<Type>(g_Sock, g_PID, Addr)
#define safe_write(Addr, Data, Type) driver::write<Type>(g_Sock, g_PID, Addr, Data)
#define safe_memcpy(Dst, Src, Size) driver::write_memory(g_Sock, g_PID, Dst, driver::read_memory(g_Sock, g_PID, Src, 0, Size), Size)

#include <Windows.h>
#include <psapi.h>
#include <d3d11.h>
#include <iostream>
#include <string>
#include <cassert>
#include <emmintrin.h>
#include <tlhelp32.h>
#include <winternl.h>

#include <stdio.h>
#include <stdlib.h>
#include <float.h>

#include "Vars.h"
#include "driver.h"
#include "Offsets.h"
#include "Math.h"


SOCKET g_Sock;
DWORD g_PID;
uint64_t u_Base;
uint64_t g_Base;
bool g_Locked;

#include "WeaponsData.h"
#include "BasePlayer.h"
#include "MiscFuncs.h"
#include "Weapon.h"
#include "Aim.h"

#include <thread>

#include <chrono>
#include <random>





DWORD FindProcessId(const char* processname);
DWORD RPid();
BasePlayer* AimEntity = nullptr;


#define AllocCons 0
using namespace std;

void InitCheat();
void InitLockalPlayer();
void MainLoop();
void Switch(int index);
BasePlayer* Fetch();


long long firstentry = 0;

UINT64 TodCycle = 0;
bool panic = false;

//FACE AddUtils


#define _CRT_SECURE_NO_WARNINGS
#include <Windows.h>
#include <string>
#include <iostream>

#include <string>
#include <sstream>
#include <algorithm>
#include <iterator>
#include <iomanip>
#include <vector>


#include "ConsoleModded.h"
//#include "MinHook.h"
//#include "Hook.h"


using namespace std;

string replaceAll(string subject, const string& search,
	const string& replace) {
	size_t pos = 0;
	while ((pos = subject.find(search, pos)) != string::npos) {
		subject.replace(pos, search.length(), replace);
		pos += replace.length();
	}
	return subject;
}

void randomizetitle()
{
	std::random_device rd;
	std::mt19937 mt(rd());
	std::uniform_int_distribution<> distr(0, 51);
	std::string name = "";
	char alphabet[] = { 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z',
	'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z' };
	for (int i = 0; i < 15; ++i)
	{
		name = name + alphabet[distr(mt)];
		SetConsoleTitleA(name.c_str());
	}

}


#include "hMain.h"

int Width = GetSystemMetrics(SM_CXSCREEN);
int Height = GetSystemMetrics(SM_CYSCREEN);

const MARGINS Margin = { 0, 0, Width, Height };

char lWindowName[256] = "OneUp Rust";
HWND hWnd;

char tWindowName[256] = "Rust"; /* tWindowName ? Target Window Name */
HWND tWnd;
RECT tSize;
MSG Message;

Matrix4x4* pViewMatrix = nullptr;
bool WorldToScreen(const Vector3& EntityPos, Vector2& ScreenPos)
{
	if (!pViewMatrix) return false;
	Vector3 TransVec = Vector3(pViewMatrix->_14, pViewMatrix->_24, pViewMatrix->_34);
	Vector3 RightVec = Vector3(pViewMatrix->_11, pViewMatrix->_21, pViewMatrix->_31);
	Vector3 UpVec = Vector3(pViewMatrix->_12, pViewMatrix->_22, pViewMatrix->_32);
	float w = Math::Dot(TransVec, EntityPos) + pViewMatrix->_44;
	if (w < 0.098f) return false;
	float y = Math::Dot(UpVec, EntityPos) + pViewMatrix->_42;
	float x = Math::Dot(RightVec, EntityPos) + pViewMatrix->_41;
	ScreenPos = Vector2((Width / 2) * (1.f + x / w), (Height / 2) * (1.f - y / w));
	return true;
}
BasePlayer* Player;
Vector2 Sc;

void main(HINSTANCE hInstance, HINSTANCE hSecInstance, LPSTR nCmdLine, INT nCmdShow)
{
	randomizetitle();
	
	SetColour(1);


		system("cls");
	SetColour(15);


		try
		{
			cout << "[OneUp]Welcome: " << getenv("USERNAME") << endl;;
			cout << "[OneUp]Loading...";
			driver::initialize();
			cout << "OK" << endl;
			g_Locked = false;
			cout << "[OneUp]Connecting...";
			g_Sock = driver::connect();
			if (g_Sock == INVALID_SOCKET)
			{
				cout << "[OneUp]Connection fail!\n";
				cin.get();
				return;
			}
			cout << "Successfull" << endl;
		}
		catch (...) {
			cout << "[OneUp]Driver ERROR!" << endl;
			cin.get();
			return;
		}
		g_PID = RPid();
		cout << "[OneUp]pid: " << g_PID << endl;
		cout << "[OneUp]Getting base address...";
		u_Base = driver::get_process_base_address(g_Sock, g_PID, 0); 
		g_Base = driver::get_process_base_address(g_Sock, g_PID, 1);
		if (u_Base == 0 || g_Base == 0)
		{
			cout << "[OneUp]Failed to get base addr...\n";
			cin.get();
			return;
		}
		//InitHook();
		//D3d9 Start
		InitLockalPlayer();
		UpdateMenu();
		CreateThread(0, 0, (LPTHREAD_START_ROUTINE)SetWindowToTarget, 0, 0, 0);
		WNDCLASSEX wClass;
		wClass.cbClsExtra = NULL;
		wClass.cbSize = sizeof(WNDCLASSEX);
		wClass.cbWndExtra = NULL;
		wClass.hbrBackground = (HBRUSH)CreateSolidBrush(RGB(0, 0, 0));
		wClass.hCursor = LoadCursor(0, IDC_ARROW);
		wClass.hIcon = LoadIcon(0, IDI_APPLICATION);
		wClass.hIconSm = LoadIcon(0, IDI_APPLICATION);
		wClass.hInstance = hInstance;
		wClass.lpfnWndProc = WinProc;
		wClass.lpszClassName = lWindowName;
		wClass.lpszMenuName = lWindowName;
		wClass.style = CS_VREDRAW | CS_HREDRAW;

		if (!RegisterClassEx(&wClass))
			exit(1);

		tWnd = FindWindow(0, tWindowName);
		if (tWnd)
		{
			GetWindowRect(tWnd, &tSize);
			Width = tSize.right - tSize.left;
			Height = tSize.bottom - tSize.top;
			hWnd = CreateWindowEx(WS_EX_TOPMOST | WS_EX_TRANSPARENT | WS_EX_LAYERED, lWindowName, lWindowName, WS_POPUP, 1, 1, Width, Height, 0, 0, 0, 0);
			SetLayeredWindowAttributes(hWnd, 0, 1.0f, LWA_ALPHA);
			SetLayeredWindowAttributes(hWnd, 0, RGB(255, 0, 255), LWA_COLORKEY);
			ShowWindow(hWnd, SW_SHOW);
		}
		DirectXInit(hWnd);
		//D3d9 END
		for (;;)
		{
			if (PeekMessage(&Message, hWnd, 0, 0, PM_REMOVE))
			{
				DispatchMessage(&Message);
				TranslateMessage(&Message);
			}
			int WeaponId = 0;
			int last = -1;
			Misc(TodCycle);
			auto k = Fetch();
			WeaponData* active = LocalPlayer.BasePlayer->GetActiveWeapon();
			if (last && last != active->GetUID() && active->GetUID() != 0)
			{
				if (WeaponId != active->GetItemID())
				{
					//std::cout << "Weapon patching ";
					//std:cout << "id " << active->GetID() << std::endl;
					if (Vars::Aim::AimBot && (GetAsyncKeyState(VK_RBUTTON) || GetAsyncKeyState(VK_LBUTTON))) (Aim(k));
					/*WeaponData* active = LocalPlayer.BasePlayer->GetActiveWeapon();
					if (last && last != active->GetUID()) {*/
					WeaponId = active->GetItemID();
				}

				last = active->GetUID();
				if (last)
				{
					WeaponFix(active);
				}
			}
			else if (!last)
				last = active->GetUID();
			Navigation();
			if (updated == true)
			{
				updated = false;
				UpdateMenu();
			}
		}

}

char* floattochar(float float_)
{
	stringstream iostr;
	char* char_, * ss;

	int int_ = 5;
	int_ = (int)float_;

	char_ = new char[10];

	iostr << int_;
	iostr >> char_;

	return char_;
}
BasePlayer* Fetch() {
	DWORD64 Id = LocalPlayer.BasePlayer->GetActiveWeapon()->GetItemID();
	if (Id == 1525520776 || Id == 200773292) return nullptr; //building plan, hammer(киянка) fix крашей от киянки

	static UINT64 oPlayerList = 0;
	if (!oPlayerList) {
		UINT64 val = safe_read(g_Base + oBaseNetworkable, UINT64); // BasePlayer_c* class
		UINT64 st = safe_read(val + 0xB8, UINT64);
		UINT64 list = safe_read(st + 0x8, UINT64);
		oPlayerList = safe_read(list + 0x28, UINT64);
	}

	int EntityCount = safe_read(oPlayerList + 0x10, int);
	UINT64 EntityBuffer = safe_read(oPlayerList + 0x18, UINT64);
	for (int i = 0; i < EntityCount; i++)
	{
		Player = (BasePlayer*)safe_read(EntityBuffer + 0x20 + (i * 0x8), UINT64);
		if (!Player || Player == LocalPlayer.BasePlayer || !Player->IsValid())
			continue; //4 чтения
		LocalPlayer.WorldToScreen(Player->GetBoneByID(), Sc);
		if(Vars::Visuals::Line)	DrawLine(Vars::Other::Width / 2, Vars::Other::Height, Sc.x, Sc.y, 255, 0, 255, 255);
		if (Vars::Visuals::Line)	DrawString(floattochar(Player->GetHealth()), Sc.x + 10, Sc.y + 15, 255, 0, 255, pFontSmall);
		//DrawString(stringtochar(Player->GetPName()), Sc.x + 10, Sc.y, 255, 0, 255, pFontSmall);
		p_Device->EndScene();
		p_Device->PresentEx(0, 0, 0, 0, 0);
		if (Vars::Aim::VisibleCheck) {
			if (!Player->IsVisible())
				continue;
		} //2 чтения
		if (AimFov(Player) > Vars::Aim::Fov) continue;
		if (Vars::Aim::IgnoreTeam) {
			UINT64 EntitySID = Player->GetSteamID();
			int size = LocalPlayer.BasePlayer->GetTeamSize(); //3
			for (int j = 0; j < size; j++) {
				UINT64 SlotSID = LocalPlayer.BasePlayer->IsTeamMate(j);       //5
				if (SlotSID == EntitySID)
					continue;
			}
		}
		return Player;
	}
	return nullptr;
}

void InitCheat()
{
	for (;;)
	{
		Misc(TodCycle);
	}
}

void InitLockalPlayer()
{
	long long i = 0;
	UINT64  ObjMgr = safe_read(u_Base + oGameObjectManager, UINT64);
	UINT64  Obj = safe_read(ObjMgr + 0x8, UINT64); // change to 0x8 if any issues

	//std::cout << "ObjMgr " << ObjMgr << std::endl;
	bool LP_isValid = false;
	std::cout << "Loading..." << std::endl;

	for (UINT64 Obj = safe_read(ObjMgr + 0x8, UINT64); (Obj && (Obj != safe_read(ObjMgr, UINT64))); Obj = safe_read(Obj + 0x8, UINT64))// change to 0x8 if any issues
	{
		//std::cout << "Ent" << endl;
		UINT64 GameObject = safe_read(Obj + 0x10, UINT64);
		WORD Tag = safe_read(GameObject + 0x54, WORD);

		if (Tag == 6 || Tag == 5 || Tag == 20011)
		{
			UINT64 ObjClass = safe_read(GameObject + 0x30, UINT64);
			UINT64 Entity = safe_read(ObjClass + 0x18, UINT64);

			if (Tag == 6)
			{
				BasePlayer* Player = (BasePlayer*)safe_read(Entity + 0x28, UINT64);
				//if (!Player->IsValid())continue;
				std::cout << "BASEPLAYER FOUND" << endl;
				std::cout << "ID: " << Player->GetSteamID() << endl;

				if (safe_read(safe_read(GameObject + 0x60, UINT64), UINT64) == 0x616C506C61636F4C)
				{

					LP_isValid = true;
					LocalPlayer.BasePlayer = Player;
					firstentry = Obj;
					AimEntity = Player;
					if (TodCycle && LocalPlayer.pViewMatrix)
						return;
				}
			}
			else if (Tag == 5)
			{
				UINT64 ObjClass = safe_read(GameObject + 0x30, UINT64);
				UINT64	Entity = safe_read(ObjClass + 0x18, UINT64);
				LocalPlayer.pViewMatrix = (Matrix4x4*)(Entity + 0x2E4);
			}
			else if (Tag == 20011)
			{
				UINT64 ObjClass = safe_read(GameObject + 0x30, UINT64);
				UINT64	Entity = safe_read(ObjClass + 0x18, UINT64);
				UINT64 Dome = safe_read(Entity + 0x28, UINT64);
				TodCycle = safe_read(Dome + 0x38, UINT64);
			}
		}

	NextEnt:
		continue;
	}
	if (!TodCycle || !LP_isValid || LocalPlayer.BasePlayer->IsMenu()) {

		std::cout << "[OneUp]ERROR:  You're in the menu, please load into the server and try again." << TodCycle << " " << LP_isValid << " " << LocalPlayer.BasePlayer->IsMenu() << endl;
		std::cin.get();
		exit(1);
	}
	Sleep(200);
}



DWORD RPid() 
{
	if (g_PID) {
		if (!safe_read(g_Base, int)) {
			std::cout << "[OneUp]Driver Fail..." << std::endl;
			std::cin.get();
			exit(1);
		}
		return g_PID;
	}
	else {
		DWORD pid = FindProcessId("RustClient.exe");

		if (!pid) {
			std::cout << "[OneUp]Rust closed..." << std::endl;
			std::cin.get();
			exit(1);
		}
		return pid;
	}
}
/*
DWORD GetPID(const std::wstring& procname)
{
	PROCESSENTRY32 processInfo;
	processInfo.dwSize = sizeof(processInfo);

	HANDLE processesSnapshot = CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, NULL);
	if (processesSnapshot == INVALID_HANDLE_VALUE) {
		return 0;
	}
	std::wstring procnamee = procname;
	Process32First(processesSnapshot, &processInfo);
	if (!procnamee->compare(processInfo.szExeFile))
	{
		CloseHandle(processesSnapshot);
		return processInfo.th32ProcessID;
	}

	while (Process32Next(processesSnapshot, &processInfo))
	{
		if (!procnamee.compare(processInfo.szExeFile))
		{
			CloseHandle(processesSnapshot);
			return processInfo.th32ProcessID;
		}
	}

	CloseHandle(processesSnapshot);
	return 0;
}
*/

DWORD FindProcessId(const char* processname)
{
	HANDLE hProcessSnap;
	PROCESSENTRY32 pe32;
	DWORD result = NULL;

	// Take a snapshot of all processes in the system.
	hProcessSnap = CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, 0);
	if (INVALID_HANDLE_VALUE == hProcessSnap) return(FALSE);

	pe32.dwSize = sizeof(PROCESSENTRY32); // <----- IMPORTANT

	// Retrieve information about the first process,
	// and exit if unsuccessful
	if (!Process32First(hProcessSnap, &pe32))
	{
		CloseHandle(hProcessSnap);          // clean the snapshot object
		printf("!!! Failed to gather information on system processes! \n");
		return(NULL);
	}

	do
	{
		//printf("Checking process %ls\n", pe32.szExeFile);
		if (0 == strcmp(processname, pe32.szExeFile))
		{
			result = pe32.th32ProcessID;
			break;
		}
	} while (Process32Next(hProcessSnap, &pe32));

	CloseHandle(hProcessSnap);

	return result;
}

LRESULT CALLBACK WinProc(HWND hWnd, UINT Message, WPARAM wParam, LPARAM lParam)
{
	switch (Message)
	{
	case WM_PAINT:
		Render();
		break;

	case WM_CREATE:
		DwmExtendFrameIntoClientArea(hWnd, &Margin);
		break;

	case WM_DESTROY:
		PostQuitMessage(1);
		return 0;

	default:
		return DefWindowProc(hWnd, Message, wParam, lParam);
		break;
	}
	return 0;
}

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hSecInstance, LPSTR nCmdLine, INT nCmdShow)
{


	for(;;)
	{

	}
	return 0;
}

void SetWindowToTarget()
{
	while (true)
	{
		tWnd = FindWindow(0, tWindowName);
		if (tWnd)
		{
			GetWindowRect(tWnd, &tSize);
			Width = tSize.right - tSize.left;
			Height = tSize.bottom - tSize.top;
			DWORD dwStyle = GetWindowLong(tWnd, GWL_STYLE);
			if (dwStyle & WS_BORDER)
			{
				tSize.top += 23;
				Height -= 23;
			}
			MoveWindow(hWnd, tSize.left, tSize.top, Width, Height, true);
		}
		else
		{
			char ErrorMsg[125];
			sprintf(ErrorMsg, "Make sure %s is running!", tWindowName);
			MessageBox(0, ErrorMsg, "Error - Cannot find the game!", MB_OK | MB_ICONERROR);
			exit(1);
		}
		Sleep(100);
	}
}