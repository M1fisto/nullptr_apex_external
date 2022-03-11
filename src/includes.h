#pragma once
#pragma warning( disable : 4307 ) // '*': integral constant overflow
#pragma warning( disable : 4244 ) // possible loss of data
#pragma warning( disable : 4800 ) // forcing value to bool 'true' or 'false'
#pragma warning( disable : 4838 ) // conversion from '::size_t' to 'int' requires a narrowing conversion

#define IMGUI_DEFINE_MATH_OPERATORS

#include <map>
#include <thread>
#include <random>
#include <stdio.h>
#include <conio.h>
#include <iostream>
#include <Windows.h>
#include <TlHelp32.h>
#include <unordered_map>

#define ERROR(msg) std::cout << "[-] " << msg << std::endl; std::cin.get(); exit(EXIT_FAILURE);
#define ASSERT(cond, msg) if (!cond) { ERROR(msg) }

//directX
#include <d3d9.h>
#include <d3dx9.h>
#include <dwmapi.h>
#include <d3dx9core.h>
#include <DirectXMath.h>
#pragma comment(lib, "d3dx9.lib")
#pragma comment(lib, "dwmapi.lib")

//mhyprot
#include "mhyprot/baseadress.h"

//globals
#include "globals.h"

//obfuscation & security
#include "utillity/obfuscation/singleton.h"
#include "utillity/obfuscation/xor.h"
#include "utillity/utillity.h"
#include "security/security.h"

//gui
#include "utillity/overlay/imgui/imgui.hpp"
#include "utillity/overlay/imgui/imgui_impl_dx9.hpp"
#include "utillity/overlay/imgui/imgui_impl_win32.hpp"

//overlay
#include "utillity/overlay/overlay.h"

//sdk -> apex  && csgo 
#include "hacks/apex/offsets.h"
#include "hacks/apex/sdk/vectors.h"
#include "hacks/apex/sdk/sdk.h"


//cfg
#include "utillity/cfg/vars.h"

//menu
#include "utillity/menu/menu.h"

//features -> apex && csgo 
#include "hacks/apex/features/aim.h"
#include "hacks/apex/features/esp.h"
#include "hacks/apex/features/misc.h"

//main -> apex && csgo 
#include "hacks/apex/apex.h"