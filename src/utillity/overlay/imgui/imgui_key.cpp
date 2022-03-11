#include "../imgui/imgui.hpp"
#include "../imgui/imgui_key.hpp"

#include <windows.h>
#include <iostream>

namespace ImGui
{

namespace detail
{

const char* m_array[] =
{
	 "none",
	 "mouse 1",
	 "mouse 2",
	 "none",
	 "mouse 3",
	 "mouse 4",
	 "mouse 5",
	 "none",
	 "backspace",
	 "tab",
	 "none",
	 "none",
	 "none",
	 "enter",
	 "none",
	 "none",
	 "shift",
	 "ctrl",
	 "alt",
	 "pause",
	 "caps lock",
	 "none",
	 "none",
	 "none",
	 "none",
	 "none",
	 "none",
	 "escape",
	 "none",
	 "none",
	 "none",
	 "none",
	 "space",
	 "page up",
	 "page down",
	 "end",
	 "home",
	 "left",
	 "up",
	 "right",
	 "down",
	 "none",
	 "none",
	 "none",
	 "print",
	 "insert",
	 "delete",
	 "none",
	 "0",
	 "1",
	 "2",
	 "3",
	 "4",
	 "5",
	 "6",
	 "7",
	 "8",
	 "9",
	 "none",
	 "none",
	 "none",
	 "none",
	 "none",
	 "none",
	 "none",
	 "a",
	 "b",
	 "c",
	 "d",
	 "e",
	 "f",
	 "g",
	 "h",
	 "i",
	 "j",
	 "k",
	 "l",
	 "m",
	 "n",
	 "o",
	 "p",
	 "q",
	 "r",
	 "s",
	 "t",
	 "u",
	 "v",
	 "w",
	 "x",
	 "y",
	 "z",
	 "none",
	 "none",
	 "none",
	 "none",
	 "none",
	 "numpad 0",
	 "numpad 1",
	 "numpad 2",
	 "numpad 3",
	 "numpad 4",
	 "numpad 5",
	 "numpad 6",
	 "numpad 7",
	 "numpad 8",
	 "numpad 9",
	 "multiply",
	 "add",
	 "none",
	 "subtract",
	 "decimal",
	 "divide",
	 "f1",
	 "f2",
	 "f3",
	 "f4",
	 "f5",
	 "f6",
	 "f7",
	 "f8",
	 "f9",
	 "f10",
	 "f11",
	 "f12",
};

}

std::uint32_t get_from_name( const char* name )
{
	const auto size = sizeof( detail::m_array ) / sizeof( *detail::m_array );

	for( auto code = 0u; code < size; code++ )
	{
		if( strstr( name, detail::m_array[ code ] ) )
			return code;
	}

	return 0u;
}

const char* get_from_code( const std::uint32_t code )
{
	if( code >= 124 )
		return "none";

	return detail::m_array[ code ];
}

bool KeyBox( const char* label, int* code, const ImVec2& size /*= { 0.f, 0.f }*/ )
{
	static bool key_input = false;
	static int* key_output = nullptr;

	auto text = "none";
	auto changed = false;

	if( key_input && key_output == code )
	{
		text = "...";

		static const int mouse_code_array[ 5 ] =
		{
			1, 2, 4, 5, 6,
		};

		for( int i = 0; i < 5; i++ )
		{
			if( IsMouseReleased( i ) )
			{
				changed = true;
				key_input = false;
				*code = mouse_code_array[ i ];
				break;
			}
		}

		for( int i = 5; i < 124; i++ )
		{
			if( IsKeyReleased( i ) )
			{
				changed = true;
				key_input = false;

				if( i != VK_ESCAPE )
					*code = i;

				break;
			}
		}
	}
	else
	{
		auto name = get_from_code( *code );
		text = name;
	}

	auto& style = GetStyle();

	PushStyleColor( ImGuiCol_Button, style.Colors[ ImGuiCol_FrameBg ] );
	PushStyleColor( ImGuiCol_ButtonHovered, style.Colors[ ImGuiCol_FrameBgHovered ] );
	PushStyleColor( ImGuiCol_ButtonActive, style.Colors[ ImGuiCol_FrameBgActive ] );

	if( Button( text, size ) )
	{
		if( !changed )
		{
			key_input = true;
			key_output = code;
		}
	}

	ImGui::SameLine();
	ImGui::Text( label );

	PopStyleColor( 3 );

	return false;
}

}