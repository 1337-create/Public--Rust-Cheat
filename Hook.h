#pragma once

typedef void(__fastcall* SendProjectileAttack_fn)(void*, void*);
SendProjectileAttack_fn Orig_SendProjectileAttack{ };

typedef void(__fastcall* SetFlying_fn)(void*, void*);
SetFlying_fn original_setflying{};

__declspec(selectany) uintptr_t TargetSilentPlayer = NULL;

typedef bool(__fastcall* Can_Attack)(void*, void*);
inline Can_Attack Orig_CanAttack;

typedef void(__fastcall* Always_Run)(void*, void*);
inline Always_Run Orig_AlwaysRun;

typedef float(__fastcall* GetSpeed)(float* a1, float* a2);
inline GetSpeed Orig_GetSpeed;

typedef void(__fastcall* BlockSprint)(void*);
inline BlockSprint Orig_BlockSprint;

typedef uintptr_t(__fastcall* CreateProjectile)(void*, void*, Vector3, Vector3, Vector3);
inline CreateProjectile Orig_CreateProjectile{ };

typedef float(__fastcall* GetIndexedSpreadScalar)(int*, int*);
inline GetIndexedSpreadScalar Orig_GetIndexedSpreadScalar{ };

#define oAlwaysRun 0x285E60 //public bool get_IsRunning() { }
#define oCanAttack 0x28CE70 // public bool CanAttack()
#define oCreateProjectile 0x27E8A0 // private Projectile CreateProjectile(string prefabPath, Vector3 pos, Vector3 forward, Vector3 velocity) { }
#define oBlockSprint 0x28C1E0 // public virtual void BlockSprint(float duration = 0,2) { }
#define oGetSpeed 0x296940 // 	public float GetSpeed(float running, float ducking) { }
#define oGetIndexedSpreadScalar 0x36B560 // public float GetIndexedSpreadScalar(int shotIndex, int maxShots) { }



/*

inline uintptr_t __fastcall Fake_CreateProjectile(void* BaseProjectile, void* prefab_pathptr, Vector3 pos, Vector3 forward, Vector3 velocity)
{
	const uintptr_t Projectile = Orig_CreateProjectile(BaseProjectile, prefab_pathptr, pos, forward, velocity);
	if (Vars::AimBot::FatBullet)
	{
		safe_read(Projectile + 0x2C + 1, float);
	}
	return Projectile;
}

inline void __fastcall AlwaysRun(void* a1, void* a2)
{
	if (Vars::Misc::AlwaysRun)
		return;

	return Orig_AlwaysRun(a1, a2);
}






inline void __fastcall Fake_SendProjectileAttack(void* a1, void* a2)
{
	if (Vars::AimBot::EnableSilentAim)
	{
		auto* TargetPlayer = reinterpret_cast<BasePlayer*>(TargetSilentPlayer);
		if (!(TargetPlayer->GetBoneByID(spine1).x == 0 && TargetPlayer->GetBoneByID(spine1).y == 0 && TargetPlayer->GetBoneByID(spine1).z == 0))
		{
			if (TargetSilentPlayer != NULL)
			{

				const auto PlayerAttack = safe_read(reinterpret_cast<uintptr_t>(a2) + oPlayerAttack, uintptr_t);
				const auto Attack = safe_read(PlayerAttack + oAttack, uintptr_t);

				safe_write(Attack + oHitBone, 698017942, uint32_t);
				safe_write(Attack + oHitPartID, 16144115, uint32_t);
				safe_write(Attack + oHitID, safe_read(safe_read(TargetSilentPlayer + oNetworkable, uintptr_t) + oNetworkId, uint32_t), uint32_t);

				if (Vars::AimBot::ThroughWall)
				{
					safe_write(Attack + oHitNormalWorld, Vector3(0.f, -1000.f, 0.f) * -10000.f, Vector3);
				}
			}
		}
	}
	return Orig_SendProjectileAttack(a1, a2);
}

inline float __fastcall Fake_GetIndexedSpreadScalar(int* a1, int* a2)
{
	if (Vars::Misc::ShotGunTochka)
	{
		return 0;
	}
	return  Orig_GetIndexedSpreadScalar(a1, a2);
}*/
inline void __fastcall Fake_BlockSprint(void* a1)
{
	//if (Vars::Misc::JumpAiming)
		return;

	//return Orig_BlockSprint(a1);
}
inline float __fastcall Fake_GetSpeed(float* a1, float* a2)
{
	//if (Vars::Misc::SpeedHack)
	{
		return 10;
	}
	//return  Orig_GetSpeed(a1, a2);
}
inline bool __fastcall Fake_Can_Attack(void* a1, void* a2)
{
	//if (Vars::Misc::JumpAiming)
		return true;

	//return Orig_CanAttack(a1, a2);
}
void __fastcall SetFlying(void* a1, void* a2) {}

inline void CreateHook(void* Function, void** Original, void* Detour, bool autoEnable = true)
{
	if (MH_Initialize() != MH_OK && MH_Initialize() != MH_ERROR_ALREADY_INITIALIZED)
	{
		std::cout << "Failed to initialize Hook" << std::endl;
		return;
	}
	MH_CreateHook(Function, Detour, Original);
	if (autoEnable)
		MH_EnableHook(Function);
}


inline void InitHook()
{
	if (MH_Initialize() != MH_OK && MH_Initialize() != MH_ERROR_ALREADY_INITIALIZED)
	{
		std::cout << "Failed to initialize Hook" << std::endl;
		return;
	}
	CreateHook(reinterpret_cast<void*>(static_cast<uintptr_t>(g_Base + oCanAttack)), reinterpret_cast<void**>(&Orig_CanAttack), Fake_Can_Attack);
	CreateHook(reinterpret_cast<void*>(static_cast<uintptr_t>(g_Base + oBlockSprint)), reinterpret_cast<void**>(&Orig_BlockSprint), Fake_BlockSprint);
	CreateHook(reinterpret_cast<void*>(static_cast<uintptr_t>(g_Base + oGetSpeed)), reinterpret_cast<void**>(&Orig_GetSpeed), Fake_GetSpeed);
	/*CreateHook(reinterpret_cast<void*>(static_cast<uintptr_t>(GetModBase(L"GameAssembly.dll") + oSetFlying)), reinterpret_cast<void**>(&original_setflying), SetFlying);
	CreateHook(reinterpret_cast<void*>(static_cast<uintptr_t>(GetModBase(L"GameAssembly.dll") + oSendProjectileAttack)), reinterpret_cast<void**>(&Orig_SendProjectileAttack), Fake_SendProjectileAttack);
	//	CreateHook(reinterpret_cast<void*>(static_cast<uintptr_t>(GetModBase(L"GameAssembly.dll") + oCreateProjectile)), reinterpret_cast<void**>(&Orig_CreateProjectile), Fake_CreateProjectile);

	CreateHook(reinterpret_cast<void*>(static_cast<uintptr_t>(GetModBase(L"GameAssembly.dll") + oAlwaysRun)), reinterpret_cast<void**>(&Orig_AlwaysRun), AlwaysRun);
	CreateHook(reinterpret_cast<void*>(static_cast<uintptr_t>(GetModBase(L"GameAssembly.dll") + oGetIndexedSpreadScalar)), reinterpret_cast<void**>(&Orig_GetIndexedSpreadScalar), Fake_GetIndexedSpreadScalar);*/
}