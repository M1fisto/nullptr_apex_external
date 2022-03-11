#include "../../includes.h"

void menu::present() {
	int lastKey = 0;

	while (GetAsyncKeyState(VK_INSERT)) {
		lastKey = VK_INSERT;
	}

	if (lastKey == VK_INSERT) {
		m_render = !m_render;

		long style = GetWindowLong(globals::overley::m_overlay_window, GWL_EXSTYLE);
		if (m_render == true) {
			style &= ~WS_EX_LAYERED;
			SetWindowLong(globals::overley::m_overlay_window, GWL_EXSTYLE, style);
			SetForegroundWindow(globals::overley::m_overlay_window);
		}
		else {
			style |= WS_EX_LAYERED;
			SetWindowLong(globals::overley::m_overlay_window, GWL_EXSTYLE, style);
			SetForegroundWindow(globals::overley::m_overlay_window);
		}
	}

	if (!m_render)
		return;

	const char* keys[2] = { xorstr_("Left Mouse"), xorstr_("Right Mouse") };
	const char* bones[3] = { xorstr_("Head"), xorstr_("Neck"), xorstr_("Chest") };

	ImGui::SetNextWindowSize(ImVec2(600, 500));
	ImGui::Begin(xorstr_("NULLPTR"), 0); {
		ImGui::Text(xorstr_("AIMBOT"));
		ImGui::Checkbox(xorstr_("Aimbot"), &vars::aim::enabled);
		//ImGui::Combo(xorstr_("Hotkey"), &vars::aim::key, keys, IM_ARRAYSIZE(keys));
		//ImGui::Combo(xorstr_("Hitboxes"), &vars::aim::bone, bones, IM_ARRAYSIZE(bones));
		ImGui::SliderInt(xorstr_("Fov amount"), &vars::aim::fov, 1.f, 180.f);
		ImGui::Checkbox(xorstr_("Smootch"), &vars::aim::smooth);
		if (vars::aim::smoothing) {
			ImGui::SliderInt(xorstr_("Smootch amount"), &vars::aim::smoothing, 1.f, 20.f);
		}
		ImGui::Checkbox(xorstr_("Bullet prediction"), &vars::aim::bullet_prediction);
		ImGui::Checkbox(xorstr_("No recoil"), &vars::aim::no_recoil);
		if (vars::aim::no_recoil) {
			ImGui::SliderInt(xorstr_("No recoil intensivity"), &vars::aim::no_recoil_intensivity, 0.f, 100.f);
		}

		ImGui::Spacing();
		ImGui::Spacing();
		
		ImGui::Text(xorstr_("VISUALS"));
		ImGui::Checkbox(xorstr_("Visuals"), &vars::visuals::enabled);
		ImGui::Checkbox(xorstr_("Player glow"), &vars::visuals::player_glow);
		if (vars::visuals::player_glow) {
			ImGui::SameLine();
			ImGui::ColorEdit4(xorstr_("visible"), (float*)&vars::visuals::colors::player_glow_vis, ImGuiColorEditFlags_NoInputs | ImGuiColorEditFlags_NoTooltip | ImGuiColorEditFlags_NoSidePreview | ImGuiColorEditFlags_NoOptions | ImGuiColorEditFlags_AlphaBar);
			ImGui::ColorEdit4(xorstr_("invisible"), (float*)&vars::visuals::colors::player_glow_invis, ImGuiColorEditFlags_NoInputs | ImGuiColorEditFlags_NoTooltip | ImGuiColorEditFlags_NoSidePreview | ImGuiColorEditFlags_NoOptions | ImGuiColorEditFlags_AlphaBar);
		}
		ImGui::Checkbox(xorstr_("Item glow"), &vars::visuals::item_glow);


	}ImGui::End();
}