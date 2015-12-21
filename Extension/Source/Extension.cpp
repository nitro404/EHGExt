#include "Extension.h"
#include "Settings Manager\SettingsManager.h"
#include "Logger/Logger.h"
#include "Extension Manager\ExtensionManager.h"
#include <windows.h>

bool APIENTRY DllMain(HMODULE hModule, DWORD ul_reason_for_call, LPVOID lpReserved) {
	switch(ul_reason_for_call) {
		case DLL_PROCESS_ATTACH:
			break;
		case DLL_THREAD_ATTACH:
			break;
		case DLL_THREAD_DETACH:
			break;
		case DLL_PROCESS_DETACH:
			break;
	}
	return true;
}

extern "C" {
	__declspec(dllexport) void __stdcall RVExtension(char * output, int outputSize, const char * function);
};

void __stdcall RVExtension(char * output, int outputSize, const char * function) {
	if(!SingletonManager::isCreated()) {
		SingletonManager::create();
		SettingsManager::createInstance();
		Logger::createInstance();
		ExtensionManager::createInstance();
		
		SettingsManager::getInstance()->load();
		Logger::getInstance()->init();
		ExtensionManager::getInstance()->init();
	}

	ExtensionManager::getInstance()->execute(function, output, outputSize);
}
