#include <chrono>
namespace Vars
{
	namespace Global
	{
		bool Panic = false;
		int ScreenHigh = 1920;
		int ScreenWidth = 1080;
		int BoneToAim = 46;//1 - body;

		int UpdateCount = 15;
	}

	namespace AimBot
	{
		bool Activate = true;
		bool VisibleCheck = false;
		bool IgnoreTeam = false;
		float Range = 100.f;
		float Fov = 150.f;
		bool noRecoil = true;
	}

	namespace Visuals
	{
		bool AlwaysDay = true;
		bool IgnoreSleepers = false;
	}

	namespace Misc
	{
		float pred = 0.f;
		bool SpiderMan = true;
		bool AntiSpread = true;
		bool FastReload = false;
		bool Automatic = false;
		bool SuperEoka = false;
		bool NoSway = false;
		bool SuperBow = false;

		bool HighJump = false;
		//float JumpValue = 1.25f;
		float JumpValue = 1.25f;
		bool WaterBoost = false;
		bool NoFall = false;
		bool AirStuck = false;
		bool AntiKastrulya = false;
		bool NoHeavyReduct = false;
		bool FakeAdmin = true;
	}
}