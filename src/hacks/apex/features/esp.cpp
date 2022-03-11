#include "../sdk/item.h"
#include "../../../includes.h"

void visuals::esp() {
	if (!vars::visuals::enabled)
		return;

	sdk::view_matrix_t view_matrix = read<sdk::view_matrix_t>(globals::apex::m_view_matrix);
	for (int i = 0; i <= 60; i++) {
		uintptr_t entity = read<uintptr_t>(globals::m_base + OFFSET_ENTITYLIST + ((uintptr_t)i << 5));
		if (!entity || entity == globals::apex::m_local)
			continue;

		if (!sdk::entity::is_player(globals::apex::m_local))
			continue;

		this->item_glow(entity);

		if (sdk::entity::get_team(entity) != sdk::entity::get_team(globals::apex::m_local)) {

			this->player_glow(entity, sdk::entity::is_visible(entity, i));

			if (sdk::entity::get_origin(globals::apex::m_local).distance_to(sdk::entity::get_origin(entity)) * 0.01905f > 200) // 200m
				continue;

			auto head_pos = sdk::entity::get_bone_pos(entity, 8);
			vec2_t head_pos_2d{};
			if (!sdk::world_to_screen(view_matrix.matrix, head_pos, head_pos_2d))
				continue;

			auto origin_pos = sdk::entity::get_origin(entity);
			vec2_t origin_pos_2d{};
			if (!sdk::world_to_screen(view_matrix.matrix, origin_pos, origin_pos_2d))
				continue;

			//render dx wh
		}
	}
}

void visuals::player_glow(uintptr_t player, bool visible) {
	sdk::color colors = { 0.f, 0.f, 0.f , 0.f };

	if (vars::visuals::player_glow) {
		write<int>(player + OFFSET_GLOW_ENABLE, 1);
		write<int>(player + OFFSET_GLOW_THROUGH_WALLS, 2);

		write<sdk::glow_settings>(player + OFFSET_GLOW_MODE, { 101, 102, 50, 100 });

		if (visible) {
			colors = vars::visuals::colors::player_glow_vis;
			write<sdk::color>(player + OFFSET_GLOW_COLOR,  colors);
		}
		else {
			colors = vars::visuals::colors::player_glow_invis;
			write<sdk::color>(player + OFFSET_GLOW_COLOR, colors);
		}
	}
	else {
		write<int>(player + OFFSET_GLOW_ENABLE, 2);
		write<int>(player + OFFSET_GLOW_THROUGH_WALLS, 5);

		write<sdk::glow_settings>(player + OFFSET_GLOW_MODE, { 0, 0, 0 , 0 });

		write<sdk::color>(player + OFFSET_GLOW_COLOR, colors);
	}
}

void visuals::item_glow(uintptr_t entity) {
	sdk::color colors = { 0.f, 0.f, 0.f , 0.f };

	if (vars::visuals::item_glow) {
		if (sdk::entity::get_signifier(entity) == xorstr_("prop_survival") && sdk::entity::get_item_id(entity) >= 1 && sdk::entity::get_item_id(entity) <= 240) {
			write<int>(entity + OFFSET_GLOW_ENABLE, 1);
			write<int>(entity + OFFSET_GLOW_THROUGH_WALLS, 2);
			write<sdk::glow_settings>(entity + OFFSET_GLOW_MODE, { 0, 118, 100, 100 });

			for (auto const& [key, val] : items::item_list) {
				if (sdk::entity::get_item_id(entity) == key) {
					switch (val.m_rarity) {
					case items::COMMON:
						colors = { 255.f, 255.f, 255.f ,  255.f };
						break;
					case items::RARE:
						colors = { 0.f, 0.f, 255.f ,  255.f };
						break;
					case items::EPIC:
						colors = { 128.f, 0.f, 128.f ,  255.f };
						break;
					case items::LEGENDARY:
						colors = { 255.f, 255.f, 0.f , 255.f };
						break;
					case items::HEIRLOOM:
						colors = { 255.f, 0.f, 0.f , 255.f };
						break;
					}
				}
			}
			write<sdk::color>(entity + OFFSET_GLOW_COLOR, colors);
		}
	}
	else {
		write<int>(entity + OFFSET_GLOW_ENABLE, 2);
		write<int>(entity + OFFSET_GLOW_THROUGH_WALLS, 5);
		write<sdk::glow_settings>(entity + OFFSET_GLOW_MODE, { 0, 0, 0, 0 });
		write<sdk::color>(entity + OFFSET_GLOW_COLOR, colors);
	}
}