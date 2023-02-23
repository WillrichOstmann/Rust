#pragma warning(disable : 4530)
#define WIN32_LEAN_AND_MEAN

#include <Windows.h>
#include <psapi.h>
#include <d3d11.h>
#include <iostream>
#include <string>
#include <cassert>
#include <emmintrin.h>
#include <tlhelp32.h>
#include <winternl.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <float.h>
#include <windows.h>

#include "resourcedriv.h"
#include "Offsets.h"

#include "sdk_new/math.h"
#include "vars/vars.h"
#include "junkcode.h"
#include "xor.hpp"

SOCKET g_Sock;
DWORD g_PID;
uint64_t u_Base;
uint64_t g_Base;
bool g_Locked;

#include "sdk/sdkGameC.h"

#include "cheat_funcs/Aim.h"
#include "cheat_funcs/Other.h"
#include <thread>
#include <vector>
#include <chrono>

DWORD GetPID(const std::wstring& procname);
DWORD RPid();



using namespace std;

void EntityZaLoop();
void MainLoop();
BasePlayer* Fetch();

long long firstentry = 0;

UINT64 TodCycle = 0;


std::string getGUIDuser()
{
	std::string ret;
	char value[64];
	DWORD size = _countof(value);
	DWORD type = REG_SZ;
	HKEY key;
	LONG retKey = ::RegOpenKeyExA(HKEY_LOCAL_MACHINE, "SOFTWARE\\Microsoft\\Cryptography", 0, KEY_READ | KEY_WOW64_64KEY, &key);
	LONG retVal = ::RegQueryValueExA(key, "MachineGuid", nullptr, &type, (LPBYTE)value, &size);
	if (retKey == ERROR_SUCCESS && retVal == ERROR_SUCCESS) {
		ret = value;
	}
	::RegCloseKey(key);
	return ret;
}


#include <sstream>
#include <Wininet.h>
#pragma comment(lib, "wininet.lib")

string replaceAll(string subject, const string& search,
	const string& replace) {
	size_t pos = 0;
	while ((pos = subject.find(search, pos)) != string::npos) {
		subject.replace(pos, search.length(), replace);
		pos += replace.length();
	}
	return subject;
}


void main()
{

	system("CLS");
	try {
		JU();
		cout << "Init...";
		maindriv::initialize();
		cout << "OK" << endl;
		g_Locked = false;
		cout << "Connecting...";
		
		g_Sock = maindriv::connect();
		if (g_Sock == INVALID_SOCKET)
		{
			cout << "Connection fail!\n";
			cout << WSAGetLastError();
			cin.get();
			
			return;
		}
		cout << "OK" << endl;
	}
	catch (...){
		cout << "Driver ERROR!" << endl;
		cin.get();
		return;
	}
	g_PID = RPid();
	cout << "pid: " << g_PID << endl;
	cout << "Getting base address...";
	u_Base = maindriv::get_process_base_address(g_Sock, g_PID, 0); //0 - UnityPlayer.dll, 
	g_Base = maindriv::get_process_base_address(g_Sock, g_PID, 1); //1 - GameAssembly.dll
	if (u_Base == 0 || g_Base == 0)
	{
		cout << "Failed to get base addr...\n";
		cin.get();
		return;
	}
	//Test();
	//auto begin = std::chrono::steady_clock::now();
	//auto begin = std::chrono::steady_clock::now();
	EntityZaLoop();
	//auto end = std::chrono::steady_clock::now();
	//auto elapsed_ms = std::chrono::duration_cast<std::chrono::milliseconds>(end - begin);
	//cout << "EntityLoop OK in " << elapsed_ms.count() << " ms\n";
	
	MainLoop();
}

void EntityZaLoop()
{
	long long i = 0;
	UINT64  ObjMgr = mem_read(u_Base + oGameObjectManager, UINT64);
	UINT64  Obj = mem_read(ObjMgr + 0x8, UINT64);
	//std::cout << "ObjMgr " << ObjMgr << std::endl;

	bool LP_isValid = false;
	std::cout << "Loading..." << std::endl;
	for (UINT64 Obj = mem_read(ObjMgr + 0x8, UINT64); (Obj && (Obj != mem_read(ObjMgr, UINT64))); Obj = mem_read(Obj + 0x8, UINT64))
	{
		//std::cout << "Ent" << endl;
		UINT64 GameObject = mem_read(Obj + 0x10, UINT64);
		WORD Tag = mem_read(GameObject + 0x54, WORD);

		if (Tag == 6)
		{
			UINT64 ObjClass = mem_read(GameObject + 0x30, UINT64);
			UINT64 Entity = mem_read(ObjClass + 0x18, UINT64);

			BasePlayer* Player = (BasePlayer*)mem_read(Entity + oBasePlayerPlayer, UINT64);

			if (!Player->IsValid()) continue;
			std::cout << "BASEPLAYER FOUND" << endl;
			std::cout << "ID: " << Player->GetSteamID() << endl;
			if (mem_read(mem_read(GameObject + 0x60, UINT64), UINT64) == 0x616C506C61636F4C)
			{
				LP_isValid = true;
				LocalPlayer.BasePlayer = Player;
				firstentry = Obj;
				if (TodCycle && LocalPlayer.pViewMatrix) return;
			}
		}
		else if (Tag == 5) {
			UINT64 ObjClass = mem_read(GameObject + 0x30, UINT64);
			UINT64	Entity = mem_read(ObjClass + 0x18, UINT64);
			LocalPlayer.pViewMatrix = (Matrix4x4*)(Entity + 0xDC);
		}
		else if (Tag == 20011) {
			UINT64 ObjClass = mem_read(GameObject + 0x30, UINT64);
			UINT64	Entity = mem_read(ObjClass + 0x18, UINT64);
			UINT64 Dome = mem_read(Entity + 0x28, UINT64);
			TodCycle = mem_read(Dome + 0x38, UINT64);
		}
	NextEnt: continue;
	}
	if (!TodCycle || !LP_isValid || LocalPlayer.BasePlayer->IsMenu()) {
		std::cout << "Cant find players, youre in menu..." <<TodCycle << " "<< LP_isValid <<" " << LocalPlayer.BasePlayer->IsMenu() << endl;
		std::cin.get();
		exit(1);
	}
}


void MainLoop() {
	//Test();
	std::cout << "Loaded!\n";
	int last = -1;
	while (true) {
		RPid();
		Misc(TodCycle);
		if (LocalPlayer.BasePlayer->IsDead()) {
			last = 0;
			continue;
		}
		WeaponData* active = LocalPlayer.BasePlayer->GetActiveWeapon();
		if (last && last != active->GetUID()) {
			std::cout << "Weapon patching ";
			std:cout << "id " << active->GetID() << std::endl;
			last = active->GetUID();
			if (last) {
				WeaponPatch(active);
			}
		}
		else if (!last)
			last = active->GetUID();
	}
}

BasePlayer* Fetch() {
	DWORD64 Id = LocalPlayer.BasePlayer->GetActiveWeapon()->GetID();
	if (!Id || Id == 1525520776 || Id == 200773292) return nullptr; //building plan, hammer(киянка)
	UINT64 BaseNetworkable = mem_read(g_Base + oBaseNetworkable, UINT64);
	UINT64 EntityRealm = mem_read(BaseNetworkable + 0xB8, UINT64);
	UINT64 ClientEntities = mem_read(EntityRealm, UINT64);
	UINT64 ClientEntities_list = mem_read(ClientEntities + 0x10, UINT64);
	UINT64 ClientEntities_values = mem_read(ClientEntities_list + 0x28, UINT64);
	int EntityCount = mem_read(ClientEntities_values + 0x10, int);
	//cout << "Entites " << EntityCount << endl;
	if (!EntityCount) return nullptr;
	UINT64 EntityBuffer = mem_read(ClientEntities_values + 0x18, UINT64);
	
	for (int i = EntityCount-1; i >= EntityCount/4; i--)
	{
		UINT64 Entity = mem_read(EntityBuffer + 0x20 + (i * 0x8), UINT64);
		UINT64 Object = mem_read(Entity + 0x10, UINT64);

		BasePlayer* Player = (BasePlayer*)mem_read(Object + oBasePlayerPlayer, UINT64);
		if (!Player->IsValid()) continue; //4 чтения

		if (Vars::AimBot::VisibleCheck) { if (!Player->IsVisible()) continue; } //2 чтения

		if (Vars::AimBot::IgnoreTeam) {
			UINT64 EntitySID = Player->GetSteamID();
			int size = LocalPlayer.BasePlayer->GetTeamSize(); //3
			for (int j = 0; j < size; j++) { 
				UINT64 SlotSID = LocalPlayer.BasePlayer->IsTeamMate(j);       //5
				if (SlotSID == EntitySID) continue;
			}
		}

		if (GetFov(Player, BoneList(Vars::Global::BoneToAim)) <= Vars::AimBot::Fov) {
			Vector3 pos = Player->GetPosition();
			float dist = Math::Calc3D_Dist(LocalPlayer.BasePlayer->GetPosition(), pos);
			if (dist && dist <= Vars::AimBot::Range) {
				std::cout << "cycles " << i << endl;
				return Player;
			}
		}
	}
	return nullptr;
}

DWORD RPid() {
	if (g_PID) {
		if (!mem_read(g_Base, int)) {
			std::cout << "Rust closed...(or driver fail)" << std::endl;
			std::cin.get();
			exit(1);
		}
		return g_PID;
	}
	else {
		DWORD pid = GetPID(L"RustClient.exe");
		if (!pid) {
			std::cout << "Rust closed..." << std::endl;
			std::cin.get();
			exit(1);
		}
		return pid;
	}
}
DWORD GetPID(const std::wstring& procname)
{
	PROCESSENTRY32 processInfo;
	processInfo.dwSize = sizeof(processInfo);

	HANDLE processesSnapshot = CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, NULL);
	if (processesSnapshot == INVALID_HANDLE_VALUE) {
		return 0;
	}

	Process32First(processesSnapshot, &processInfo);
	if (!procname.compare(processInfo.szExeFile))
	{
		CloseHandle(processesSnapshot);
		return processInfo.th32ProcessID;
	}

	while (Process32Next(processesSnapshot, &processInfo))
	{
		if (!procname.compare(processInfo.szExeFile))
		{
			CloseHandle(processesSnapshot);
			return processInfo.th32ProcessID;
		}
	}

	CloseHandle(processesSnapshot);
	return 0;
}




