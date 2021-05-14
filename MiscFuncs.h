#pragma once

void Misc(UINT64 TodCycle)
{
	if (Vars::Misc::AlwaysDay)
		safe_write(TodCycle + 0x10, Vars::FloatAntInt::TimeOfDay, float);

	if (Vars::Misc::SpiderMan)
		LocalPlayer.BasePlayer->SpiderMan();

	if (Vars::Misc::FakeAdmin)
		LocalPlayer.BasePlayer->FakeAdmin();

	if (Vars::Misc::SetGravitu)
		LocalPlayer.BasePlayer->GravituMod();
}