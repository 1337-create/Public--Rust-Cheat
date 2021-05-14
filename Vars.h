#pragma once

namespace Vars
{
	namespace Other
	{
		int Width = GetSystemMetrics(SM_CXSCREEN);
		int Height = GetSystemMetrics(SM_CYSCREEN);
	}
	
	namespace Visuals
	{
		bool HP = false;
		bool Line = false;
		bool IgnoreSliping = false;
		bool PlayerESP = false;
	}

	namespace Aim
	{
		bool AimBot = true;
		bool VisibleCheck = true;
		bool IgnoreTeam = true;
		int Range = 300;
		int BoneToAim = 46;//1 - body;
		float Fov = 120.f;
	}
	
	namespace FloatAntInt
	{
		int TimeOfDay = 12;
		float JumpValue = 2;
	}
	
	namespace Misc
	{
		bool FatBullet = false;
		bool FakeAdmin = false;
		bool automatic = false;
		bool AlwaysDay = false;
		bool SpiderMan = false;
		bool anti_spread = false;
		bool no_recoil = true;
		bool SetGravitu = false;
	}
}

