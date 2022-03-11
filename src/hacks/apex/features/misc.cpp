#include "../../../includes.h"

void miscellanea::misc() {
    if (vars::misc::enabled)
        return;

    if (!sdk::entity::is_player(globals::apex::m_local) && sdk::entity::is_alive(globals::apex::m_local))
        return;

   this->rapidfire();
   this->fakelags();
}

void miscellanea::rapidfire() {
   // if (!vars::misc::rapidfire || !sdk::entity::is_player(globals::apex::m_local) || !GetAsyncKeyState(VK_LBUTTON)) {
   //     if (m_last_time_scale != 1.f)
   //         write<float>(globals::m_base + OFFSET_INPUT + 0x18, 1);
   //    
   //     m_last_time_scale = 1.f;
   //     return;
   // }

   // uintptr_t active_weapon_id = read<uintptr_t>(globals::apex::m_local + OFFSET_WEAPON) & 0xFFFF;
   // uintptr_t current_weapon = read<uintptr_t>(globals::apex::m_local + OFFSET_ENTITYLIST + (active_weapon_id << 5));

   // int ammo_in_clip = read<int>(current_weapon + 0x16c4); //ammoInClip
   // if (ammo_in_clip <= 0)
   //     return;

   //write<float>(globals::m_base + OFFSET_INPUT + 0x18, vars::misc::rapidfire_factor);
   //
   //m_last_time_scale = vars::misc::rapidfire_factor;
}

void miscellanea::fakelags() {
    //if (vars::misc::fakelag) {
    //    if (!sdk::entity::is_in_game())
    //    {
    //        if (!sdk::entity::is_packets_sending())
    //        {
    //            sdk::entity::send_packets(true);
    //        }
    //    }
    //    else {
    //        if (sdk::entity::get_choked_commands() >= 6)//vars::misc::fakelag_factor
    //        {
    //            sdk::entity::send_packets(true);
    //        }
    //        else
    //        {
    //            sdk::entity::send_packets(false);
    //        }
    //    }
    //}
}