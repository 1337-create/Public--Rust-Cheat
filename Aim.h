
float GetBulletSpeed()
{
    switch (LocalPlayer.BasePlayer->GetActiveWeapon()->GetItemID())
    {
	case 0:
		return 0.f;

	case 0x77E9:
		return 420.26f;
		break;

	case 0xCFA1:
		return 656.26f;
		break;

	case 0x573C:
		return 420.05f;
		break;

	case 0x6A09:
		return 960.05f;
		break;

	case 0x7983:
	case 0xE5EA:
	case 0x79C4:
		return 340.05f;
		break;

	case 0xE97D:
		return 192.05f;
		break;

	case 0x3511:
		return 190.05f;
		break;

	case 0x67DA:
		return 260.05f;
		break;

	case 0x62E5:
		return 260.05f;
		break;

	case 0x3146:
		return 250.05f;
		break;

	case 0x6B1:
		return 260.05f;
		break;

	case 0x5A9F:
		return 60.10f;
		break;

	case 0xC196:
		return 60.10f;
		break;

	case 0xB0A0:
		return 95.05f;
		break;

	case 0x746A:
		return 125.05f;
		break;

	default:
		return 250.05f;
	}
}

float AimFov(BasePlayer* Entity)
{
	Vector2 ScreenPos;
	if (!LocalPlayer.WorldToScreen(Entity->GetBoneByID(), ScreenPos)) return 1000.f;
	return Math::Calc2D_Dist(Vector2(Vars::Other::Width / 2, Vars::Other::Height / 2), ScreenPos);
}

Vector3 Prediction(const Vector3& LP_Pos, BasePlayer* Player, BoneList Bone)
{
	Vector3 BonePos = Player->GetBoneByID();
	float Dist = Math::Calc3D_Dist(LP_Pos, BonePos);

	if (Dist > 0.001f) {
		float BulletTime = Dist / GetBulletSpeed();
		Vector3 vel = Player->GetVelocity();
		Vector3 PredictVel = vel * BulletTime * 0.75f;
		BonePos += PredictVel; BonePos.y += (4.905f * BulletTime * BulletTime);
	} return BonePos;
}

void Normalize(float& Yaw, float& Pitch) {
	if (Pitch < -89) Pitch = -89;
	else if (Pitch > 89) Pitch = 89;
	if (Yaw < -360) Yaw += 360;
	else if (Yaw > 360) Yaw -= 360;
}

void AimBotTarget(BasePlayer* player)
{
	Vector3 Local = LocalPlayer.BasePlayer->GetBoneByID();
	Vector3 PlayerPos = player->GetBoneByID();
	PlayerPos = Prediction(Local, player, BoneList(Vars::Aim::BoneToAim));
	//std::cout << "target predicted " << PlayerPos.x << " " << PlayerPos.y << " " << PlayerPos.z << std::endl;
	Vector2 AngleToAim = Math::CalcAngle(Local, PlayerPos);
	Normalize(AngleToAim.y, AngleToAim.x);
	if (isnan(AngleToAim.x) || isnan(AngleToAim.y))
		return;
	LocalPlayer.BasePlayer->SetVA(AngleToAim);


	/*std::cout << "Gototarget " << "x: " << AngleToAim.x << " " << AngleToAim.y << " Distance: " << Math::Calc3D_Dist(LocalPlayer.BasePlayer->GetBoneByID(), player->GetBoneByID()) << " Fov: " << AimFov(player) << std::endl;*/

	Normalize(AngleToAim.y, AngleToAim.x);
	LocalPlayer.BasePlayer->SetVA(AngleToAim);
}

void Aim(BasePlayer* player)
{
	if (!player) return;

	if (!LocalPlayer.BasePlayer->IsMenu() && Vars::Aim::AimBot)
	{
		//if (GetAsyncKeyState(VK_RBUTTON)) {
			//std::cout << "Players " << player->GetSteamID() << std::endl;
			//WeaponData* ActWeapon = LocalPlayer.BasePlayer->GetActiveWeapon();
		AimBotTarget(player);
		//}
	}
}


