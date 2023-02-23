void WeaponPatch(WeaponData* Weapon)
{
	int Id = 0;
	if (Weapon) Id = Weapon->GetID();
	if (!Id) return;

	//for (DWORD64 val : semiautomatic) {
		//if (Id == val) {
			Weapon->SetRA();
			Weapon->FastReload();
			Weapon->AntiSpread();
			Weapon->SetAutomatic();
			return;
		//}
	//}
	for (DWORD64 val : meele) {
		if (Id == val) {
			Weapon->FatHand();
			Weapon->LongHand();
			Weapon->RunOnHit();
			return;
		}
	}
	for (DWORD64 val : automatic) {
		if (Id == val) {
			Weapon->SetRA();
			Weapon->FastReload();
			Weapon->AntiSpread();
			return;
		}
	}
	if (Id == bow) {
		//Weapon->SuperBow();
		return;
	}
	if (Id == eoka) {
		Weapon->SuperEoka();
		return;
	}
}
float GetFov(BasePlayer* Entity, BoneList Bone) {
	Vector2 ScreenPos;
	if (!LocalPlayer.WorldToScreen(Entity->GetPosition(), ScreenPos)) return 1000.f;
	return Math::Calc2D_Dist(Vector2(Vars::Global::ScreenWidth / 2, Vars::Global::ScreenHigh / 2), ScreenPos);
}

float GetBulletSpeed()
{
	switch (LocalPlayer.BasePlayer->GetActiveWeapon()->GetID())
	{
		case 1796682209: //smg
			return 240.f;
		case 1588298435: //bolt
			return 656.25f;
		case -778367295: //l96
			return 1125.f;
		case 28201841: //m39
			return 469.f;
		case 1953903201: //nailgun
			return 50.f;
		case 649912614: //revolver
			return 300.f;
		case 818877484: //p250
			return 300.f;
		case -1367281941: //waterpipe, 250-green ammo, 100-other
			return 100.f;
		case -765183617: //double barrel, 250-green ammo, 100-other
			return 100.f; 
		case -1812555177: //lr300
			return 375.f;
		case -852563019: //m92
			return 300.f;
		case -1123473824: //grenade launcher, shotgun - 250, other - 100
			return 100.f;
		case 442886268: //rocket launcher, unknown
			return 250.f;
		case -904863145: //semiautomatic rifle
			return 375.f;
		case -41440462: //spas12, 250-green ammo, 100-other
			return 100.f;
		case 1545779598: //ak47
			return 375.f;
		case 1443579727: //bow, 80-high speed arrow, 40 - fire arrow, 50 - normal
			return 50.f;
		case -75944661: //eoka, 250-green ammo, 100-other
			return 100.f;
		case 1318558775: //mp5a4
			return 240.f;
		case 795371088: //pomp shotgun, 250-green ammo, 100-other
			return 100.f;
		case 1965232394: //crossbow, 75 - normal, 120-high velocity, 60 - fire
			return 75.f;
		case -2069578888:
			return 488.f;
		case 1373971859: //python
			return 300.f;
		case -1758372725: //tompson
			return 300.f;
		default:
			return 250.f;
	}
}

Vector3 Prediction(const Vector3& LP_Pos, BasePlayer* Player, BoneList Bone)
{
	Vector3 BonePos = Player->GetPosition();
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

void GoToTarget(BasePlayer* player)
{
	Vector3 Local = LocalPlayer.BasePlayer->GetPosition();
	Vector3 PlayerPos = Prediction(Local, player, BoneList(Vars::Global::BoneToAim));
	Vector2 Offset = Math::CalcAngle(Local, PlayerPos) - LocalPlayer.BasePlayer->GetVA();
	Normalize(Offset.y, Offset.x);
	Vector2 AngleToAim = LocalPlayer.BasePlayer->GetVA() + Offset;

	Normalize(AngleToAim.y, AngleToAim.x);
	if (isnan(AngleToAim.x) || isnan(AngleToAim.y) || GetFov(player, BoneList(47)) > Vars::AimBot::Fov)
		return;
	std::cout << "Gototarget " << "x: " << AngleToAim.x << " " << AngleToAim.y << " Distance: " << 0 << " Fov: " << GetFov(player, BoneList(47)) << std::endl;

	LocalPlayer.BasePlayer->SetVA(AngleToAim);
}

void Aim(BasePlayer* AimEntity)
{
	if (AimEntity && !LocalPlayer.BasePlayer->IsMenu()) {
			GoToTarget(AimEntity);
	}
}