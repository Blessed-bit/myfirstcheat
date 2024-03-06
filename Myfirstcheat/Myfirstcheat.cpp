#include "includes.h"


int main() {
	int health = 1000;
	int ammo = 1000;
	DWORD pID, baseModule, localPlayerPtr;
	pID = GetProcessID(L"ac_client.exe");
	baseModule = GetModuleBaseAddress(pID, L"ac_client.exe");
	std::cout << std::hex << pID;
	std::cout << std::hex << baseModule;

	HANDLE handle = OpenProcess(PROCESS_ALL_ACCESS, NULL, pID);
	ReadProcessMemory(handle, (LPCVOID)(baseModule + 0x17E254), &localPlayerPtr, sizeof(localPlayerPtr), nullptr);
	while (true) {
		WriteProcessMemory(handle, (LPVOID)(localPlayerPtr + 0xEC), &health, sizeof(health), nullptr);
		WriteProcessMemory(handle, (LPVOID)(localPlayerPtr + 0x00), &ammo, sizeof(ammo), nullptr);
	}
}