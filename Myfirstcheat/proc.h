#pragma once

#include <Windows.h>
#include <TLHelp32.h>
#include <iostream>

DWORD GetProcessID(const wchar_t* procName);
DWORD GetModuleBaseAddress(DWORD procId, const wchar_t* modName);