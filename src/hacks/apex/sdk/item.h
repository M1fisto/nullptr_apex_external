#pragma once
#include "../../../includes.h"

namespace items {
	enum rarity { HEIRLOOM, LEGENDARY, EPIC, RARE, COMMON };

	struct c_prop {
		std::string item_name;
		rarity m_rarity;
	};

	std::map<uint32_t, c_prop> item_list = {
		{ 1, { xorstr_("Kraber"), rarity::HEIRLOOM }},
		{ 2, { xorstr_("Mastiff"), rarity::COMMON }},
		{ 6, { xorstr_("Mastiff Gold"), rarity::LEGENDARY }},
		{ 7, { xorstr_("LStar"), rarity::COMMON }},
		{ 11, { xorstr_("LStar Gold"), rarity::LEGENDARY }},
		{ 12, { xorstr_("Havoc"), rarity::COMMON }},
		{ 16, { xorstr_("Havoc Gold"), rarity::LEGENDARY }},
		{ 17, { xorstr_("Devotion"), rarity::COMMON }},
		{ 21, { xorstr_("Devotion Gold"), rarity::LEGENDARY }},
		{ 22, { xorstr_("Triple Take"), rarity::HEIRLOOM }},
		{ 23, { xorstr_("Flatline"), rarity::COMMON }},
		{ 27, { xorstr_("Flatline Gold"), rarity::LEGENDARY }},
		{ 28, { xorstr_("Hemlock"), rarity::COMMON }},
		{ 32, { xorstr_("Hemlock Gold"), rarity::LEGENDARY }},
		{ 33, { xorstr_("G7 Scout"), rarity::COMMON }},
		{ 37, { xorstr_("G7 Scout Gold"), rarity::LEGENDARY }},
		{ 38, { xorstr_("Alternator"), rarity::HEIRLOOM }},
		{ 39, { xorstr_("R99"), rarity::COMMON }},
		{ 43, { xorstr_("R99 Gold"), rarity::LEGENDARY }},
		{ 44, { xorstr_("Prowler"), rarity::COMMON }},
		{ 48, { xorstr_("Prowler Gold"), rarity::LEGENDARY }},
		{ 49, { xorstr_("Volt"), rarity::COMMON }},
		{ 53, { xorstr_("Volt Gold"), rarity::LEGENDARY }},
		{ 54, { xorstr_("Longbow"), rarity::COMMON }},
		{ 58, { xorstr_("Longbow Gold"), rarity::LEGENDARY }},
		{ 59, { xorstr_("Charge Rifle"), rarity::COMMON }},
		{ 63, { xorstr_("Charge Rifle Gold"), rarity::LEGENDARY }},
		{ 64, { xorstr_("Spitfire"), rarity::HEIRLOOM }},
		{ 65, { xorstr_("R301"), rarity::COMMON }},
		{ 69, { xorstr_("R301 Gold"), rarity::LEGENDARY }},
		{ 70, { xorstr_("Eva-8 Auto"), rarity::COMMON }},
		{ 74, { xorstr_("Eva-8 Auto Gold"), rarity::LEGENDARY }},
		{ 75, { xorstr_("Peacekeeper"), rarity::COMMON }},
		{ 79, { xorstr_("Peacekeeper Gold"), rarity::LEGENDARY }},
		{ 80, { xorstr_("Mozambique"), rarity::COMMON }},
		{ 84, { xorstr_("Mozambique Gold"), rarity::LEGENDARY }},
		{ 85, { xorstr_("Wingman"), rarity::COMMON }},
		{ 89, { xorstr_("Wingman Gold"), rarity::LEGENDARY }},
		{ 90, { xorstr_("P2020"), rarity::COMMON }},
		{ 94, { xorstr_("P2020 Gold"), rarity::LEGENDARY }},
		{ 95, { xorstr_("RE45"), rarity::COMMON }},
		{ 99,  {xorstr_("RE45 Gold"), rarity::LEGENDARY }},
		{ 100, { xorstr_("Sentinel"), rarity::COMMON }},
		{ 104, { xorstr_("Sentinel Gold"), rarity::LEGENDARY }},
		{ 105, { xorstr_("Bocek Bow"), rarity::COMMON }},
		{ 109, { xorstr_("Bocek Bow Gold"), rarity::LEGENDARY }},
		{ 110, { xorstr_("30 30 Repeater"), rarity::COMMON }},
		{ 114, { xorstr_("30 30 Repeater Gold"), rarity::LEGENDARY }},

		{ 115, { xorstr_("Light Ammo"), rarity::COMMON }},
		{ 116, { xorstr_("Energy Ammo"), rarity::COMMON }},
		{ 117, { xorstr_("Shotgun Ammo"), rarity::COMMON }},
		{ 118, { xorstr_("Heavy Ammo"), rarity::COMMON }},
		{ 119, { xorstr_("Sniper Ammo"), rarity::COMMON }},
		{ 120, { xorstr_("Arrow"), rarity::COMMON }},

		{ 121, { xorstr_("Rampage"), rarity::COMMON }},
		{ 125, { xorstr_("Rampage Gold"), rarity::LEGENDARY }},

		{ 151, { xorstr_("Ultimate Accelerant"), rarity::RARE }},
		{ 152, { xorstr_("Pheonix Kit"), rarity::EPIC }},
		{ 153, { xorstr_("Med Kit"), rarity::RARE }},
		{ 154, { xorstr_("Syringe"), rarity::COMMON }},
		{ 155, { xorstr_("Shield Battery"), rarity::RARE }},
		{ 156, { xorstr_("Shield Cell"), rarity::COMMON }},

		{ 157, { xorstr_("Helmet"), rarity::COMMON }},
		{ 158, { xorstr_("Helmet"), rarity::RARE }},
		{ 159, { xorstr_("Helmet"), rarity::EPIC }},
		{ 160, { xorstr_("Helmet"), rarity::LEGENDARY }},

		{ 161, { xorstr_("Body Armor"), rarity::COMMON }},
		{ 162, { xorstr_("Body Armor"), rarity::RARE }},
		{ 163, { xorstr_("Body Armor"), rarity::EPIC }},
		{ 164, { xorstr_("Body Armor"), rarity::LEGENDARY }},
		{ 165, { xorstr_("Body Armor"), rarity::HEIRLOOM }},

		{ 166, { xorstr_("Evo Body Armor"), rarity::COMMON }},
		{ 167, { xorstr_("Evo Body Armor"), rarity::RARE }},
		{ 168, { xorstr_("Evo Body Armor"), rarity::EPIC }},
		{ 169, { xorstr_("Evo Body Armor"), rarity::HEIRLOOM }},

		{ 170, { xorstr_("Heat Shield"), rarity::HEIRLOOM }},

		{ 171, { xorstr_("Knockdown Shield"), rarity::COMMON }},
		{ 172, { xorstr_("Knockdown Shield"), rarity::RARE }},
		{ 173, { xorstr_("Knockdown Shield"), rarity::EPIC }},
		{ 174, { xorstr_("Knockdown Shield"), rarity::LEGENDARY }},

		{ 175, { xorstr_("Backpack"), rarity::COMMON }},
		{ 176, { xorstr_("Backpack"), rarity::RARE }},
		{ 177, { xorstr_("Backpack"), rarity::EPIC }},
		{ 178, { xorstr_("Backpack"), rarity::LEGENDARY }},

		{ 179, { xorstr_("Thermite Grenade"), rarity::COMMON }},
		{ 180, { xorstr_("Frag Grenade"), rarity::COMMON }},
		{ 181, { xorstr_("Arc Star"), rarity::COMMON }},

		{ 182, { xorstr_("1x HCOG 'Classic'"), rarity::COMMON }},
		{ 183, { xorstr_("2x HCOG 'Bruiser'"), rarity::RARE }},
		{ 184, { xorstr_("1x Holo"), rarity::COMMON }},
		{ 185, { xorstr_("1x-2x Variable Holo"), rarity::RARE }},
		{ 186, { xorstr_("1x Digital Threat"), rarity::LEGENDARY }},
		{ 187, { xorstr_("3x HCOG 'Ranger'"), rarity::EPIC }},
		{ 188, { xorstr_("2x-4x Variable AOG"), rarity::EPIC }},
		{ 189, { xorstr_("6x Sniper"), rarity::RARE }},
		{ 190, { xorstr_("4x-8x Variable Sniper"), rarity::EPIC }},
		{ 191, { xorstr_("4x-10x Digital Sniper Threat"), rarity::LEGENDARY }},

		{ 192, { xorstr_("Barrel Stabilizer"), rarity::COMMON }},
		{ 193, { xorstr_("Barrel Stabilizer"), rarity::RARE }},
		{ 194, { xorstr_("Barrel Stabilizer"), rarity::EPIC }},
		{ 195, { xorstr_("Barrel Stabilizer"), rarity::LEGENDARY }}, // Unobtainable?

		{ 196, { xorstr_("Light Magazine"), rarity::COMMON }},
		{ 197, { xorstr_("Light Magazine"), rarity::RARE }},
		{ 198, { xorstr_("Light Magazine"), rarity::EPIC }},
		{ 199, { xorstr_("Light Magazine"), rarity::LEGENDARY }},

		{ 200, { xorstr_("Heavy Magazine"), rarity::COMMON }},
		{ 201, { xorstr_("Heavy Magazine"), rarity::RARE }},
		{ 202, { xorstr_("Heavy Magazine"), rarity::EPIC }},
		{ 203, { xorstr_("Heavy Magazine"), rarity::LEGENDARY }},

		{ 204, { xorstr_("Energy Magazine"), rarity::COMMON }},
		{ 205, { xorstr_("Energy Magazine"), rarity::RARE }},
		{ 206, { xorstr_("Energy Magazine"), rarity::EPIC }},
		{ 207, { xorstr_("Energy Magazine"), rarity::LEGENDARY }},

		{ 208, { xorstr_("Sniper Magazine"), rarity::COMMON }},
		{ 209, { xorstr_("Sniper Magazine"), rarity::RARE }},
		{ 210, { xorstr_("Sniper Magazine"), rarity::EPIC }},
		{ 211, { xorstr_("Sniper Magazine"), rarity::LEGENDARY }},

		{ 212, { xorstr_("Shotgun Bolt"), rarity::COMMON }},
		{ 213, { xorstr_("Shotgun Bolt"), rarity::RARE }},
		{ 214, { xorstr_("Shotgun Bolt"), rarity::EPIC }},

		{ 215, { xorstr_("Standard Stock"), rarity::COMMON }},
		{ 216, { xorstr_("Standard Stock"), rarity::RARE }},
		{ 217, { xorstr_("Standard Stock"), rarity::EPIC }},

		{ 218, { xorstr_("Sniper Stock"), rarity::COMMON }},
		{ 219, { xorstr_("Sniper Stock"), rarity::RARE }},
		{ 220, { xorstr_("Sniper Stock"), rarity::EPIC }},

		{ 221, { xorstr_("Turbocharger"), rarity::LEGENDARY }},
		{ 222, { xorstr_("Skull Piercer"), rarity::LEGENDARY }},
		{ 223, { xorstr_("Hammer Point"), rarity::EPIC }},
		{ 224, { xorstr_("Anvil Receiver"), rarity::LEGENDARY }},
		{ 225, { xorstr_("Graffiti Mod"), rarity::COMMON }},
		{ 226, { xorstr_("Paintball 1"), rarity::HEIRLOOM }}, // TODO: Find this rarity
		{ 227, { xorstr_("Paintball 2"), rarity::HEIRLOOM }}, // TODO: Find this rarity
		{ 228, { xorstr_("Deadeye's Tempo"), rarity::EPIC }},
		{ 229, { xorstr_("Quickdraw Holster"), rarity::EPIC }}, // Might be 229
		{ 230, { xorstr_("Shatter Caps"), rarity::EPIC }},
		{ 231, { xorstr_("Boosted Loader"), rarity::LEGENDARY }},
		{ 232, { xorstr_("Mobile Respawn Beacon"), rarity::RARE }},
		{ 233, { xorstr_("Vault Key"), rarity::HEIRLOOM }},
		{ 234, { xorstr_("Steel Cut"), rarity::HEIRLOOM }}, // Might be overwritten every season/every time there's a new charm.
		{ 235, { xorstr_("Treasure Pack"), rarity::HEIRLOOM }},
		{ 236, { xorstr_("Survival Doubler"), rarity::HEIRLOOM }}, // TODO: Find this rarity
		{ 237, { xorstr_("Survival Quadrupler"), rarity::HEIRLOOM }}, // TODO: Find this rarity
		{ 238, { xorstr_("Heat Shield"), rarity::RARE }},
		{ 239, { xorstr_("Mobile Respawn Beacon 2"), rarity::RARE }},
		{ 240, { xorstr_("MRVN Arm"), rarity::EPIC }},
		{ 241, { xorstr_("Vault Key"), rarity::HEIRLOOM }}
	};
}