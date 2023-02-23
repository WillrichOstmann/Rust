#include <string>
using namespace std;


const unsigned short Crc16Table[256] = {
0x0000, 0x1021, 0x2042, 0x3063, 0x4084, 0x50A5, 0x60C6, 0x70E7,
0x8108, 0x9129, 0xA14A, 0xB16B, 0xC18C, 0xD1AD, 0xE1CE, 0xF1EF,
0x1231, 0x0210, 0x3273, 0x2252, 0x52B5, 0x4294, 0x72F7, 0x62D6,
0x9339, 0x8318, 0xB37B, 0xA35A, 0xD3BD, 0xC39C, 0xF3FF, 0xE3DE,
0x2462, 0x3443, 0x0420, 0x1401, 0x64E6, 0x74C7, 0x44A4, 0x5485,
0xA56A, 0xB54B, 0x8528, 0x9509, 0xE5EE, 0xF5CF, 0xC5AC, 0xD58D,
0x3653, 0x2672, 0x1611, 0x0630, 0x76D7, 0x66F6, 0x5695, 0x46B4,
0xB75B, 0xA77A, 0x9719, 0x8738, 0xF7DF, 0xE7FE, 0xD79D, 0xC7BC,
0x48C4, 0x58E5, 0x6886, 0x78A7, 0x0840, 0x1861, 0x2802, 0x3823,
0xC9CC, 0xD9ED, 0xE98E, 0xF9AF, 0x8948, 0x9969, 0xA90A, 0xB92B,
0x5AF5, 0x4AD4, 0x7AB7, 0x6A96, 0x1A71, 0x0A50, 0x3A33, 0x2A12,
0xDBFD, 0xCBDC, 0xFBBF, 0xEB9E, 0x9B79, 0x8B58, 0xBB3B, 0xAB1A,
0x6CA6, 0x7C87, 0x4CE4, 0x5CC5, 0x2C22, 0x3C03, 0x0C60, 0x1C41,
0xEDAE, 0xFD8F, 0xCDEC, 0xDDCD, 0xAD2A, 0xBD0B, 0x8D68, 0x9D49,
0x7E97, 0x6EB6, 0x5ED5, 0x4EF4, 0x3E13, 0x2E32, 0x1E51, 0x0E70,
0xFF9F, 0xEFBE, 0xDFDD, 0xCFFC, 0xBF1B, 0xAF3A, 0x9F59, 0x8F78,
0x9188, 0x81A9, 0xB1CA, 0xA1EB, 0xD10C, 0xC12D, 0xF14E, 0xE16F,
0x1080, 0x00A1, 0x30C2, 0x20E3, 0x5004, 0x4025, 0x7046, 0x6067,
0x83B9, 0x9398, 0xA3FB, 0xB3DA, 0xC33D, 0xD31C, 0xE37F, 0xF35E,
0x02B1, 0x1290, 0x22F3, 0x32D2, 0x4235, 0x5214, 0x6277, 0x7256,
0xB5EA, 0xA5CB, 0x95A8, 0x8589, 0xF56E, 0xE54F, 0xD52C, 0xC50D,
0x34E2, 0x24C3, 0x14A0, 0x0481, 0x7466, 0x6447, 0x5424, 0x4405,
0xA7DB, 0xB7FA, 0x8799, 0x97B8, 0xE75F, 0xF77E, 0xC71D, 0xD73C,
0x26D3, 0x36F2, 0x0691, 0x16B0, 0x6657, 0x7676, 0x4615, 0x5634,
0xD94C, 0xC96D, 0xF90E, 0xE92F, 0x99C8, 0x89E9, 0xB98A, 0xA9AB,
0x5844, 0x4865, 0x7806, 0x6827, 0x18C0, 0x08E1, 0x3882, 0x28A3,
0xCB7D, 0xDB5C, 0xEB3F, 0xFB1E, 0x8BF9, 0x9BD8, 0xABBB, 0xBB9A,
0x4A75, 0x5A54, 0x6A37, 0x7A16, 0x0AF1, 0x1AD0, 0x2AB3, 0x3A92,
0xFD2E, 0xED0F, 0xDD6C, 0xCD4D, 0xBDAA, 0xAD8B, 0x9DE8, 0x8DC9,
0x7C26, 0x6C07, 0x5C64, 0x4C45, 0x3CA2, 0x2C83, 0x1CE0, 0x0CC1,
0xEF1F, 0xFF3E, 0xCF5D, 0xDF7C, 0xAF9B, 0xBFBA, 0x8FD9, 0x9FF8,
0x6E17, 0x7E36, 0x4E55, 0x5E74, 0x2E93, 0x3EB2, 0x0ED1, 0x1EF0
};

enum BoneList : int
{
	l_hip = 1,
	l_knee,
	l_foot,
	l_toe,
	l_ankle_scale,
	pelvis,
	penis,
	GenitalCensor,
	GenitalCensor_LOD0,
	Inner_LOD0,
	GenitalCensor_LOD1,
	GenitalCensor_LOD2,
	r_hip,
	r_knee,
	r_foot,
	r_toe,
	r_ankle_scale,
	spine1,
	spine1_scale,
	spine2,
	spine3,
	spine4,
	l_clavicle,
	l_upperarm,
	l_forearm,
	l_hand,
	l_index1,
	l_index2,
	l_index3,
	l_little1,
	l_little2,
	l_little3,
	l_middle1,
	l_middle2,
	l_middle3,
	l_prop,
	l_ring1,
	l_ring2,
	l_ring3,
	l_thumb1,
	l_thumb2,
	l_thumb3,
	IKtarget_righthand_min,
	IKtarget_righthand_max,
	l_ulna,
	neck,
	head,
	jaw,
	eyeTranform,
	l_eye,
	l_Eyelid,
	r_eye,
	r_Eyelid,
	r_clavicle,
	r_upperarm,
	r_forearm,
	r_hand,
	r_index1,
	r_index2,
	r_index3,
	r_little1,
	r_little2,
	r_little3,
	r_middle1,
	r_middle2,
	r_middle3,
	r_prop,
	r_ring1,
	r_ring2,
	r_ring3,
	r_thumb1,
	r_thumb2,
	r_thumb3,
	IKtarget_lefthand_min,
	IKtarget_lefthand_max,
	r_ulna,
	l_breast,
	r_breast,
	BoobCensor,
	BreastCensor_LOD0,
	BreastCensor_LOD1,
	BreastCensor_LOD2,
	collision,
	displacement
};

typedef struct _UncStr
{
	char stub[0x10];
	int len;
	wchar_t str[1];
} *pUncStr;

class WeaponData
{
private:
	unsigned short CRC(unsigned char pcBlock, unsigned short len)
	{
		unsigned short crc = 0xFFFF;
		while (len--)
			crc = (crc << 8) ^ Crc16Table[(crc >> 8) ^ pcBlock++];
		return crc;
	}

public:
	wchar_t* GetShortName(int* len)
	{
		UINT64 Info = mem_read((const uintptr_t)(const uintptr_t)this + 0x18, UINT64);
		pUncStr Str = ((pUncStr)mem_read(Info + 0x20, UINT64));
		int leng = mem_read((const uintptr_t)Str + 0x10, int);
		if (!leng) return nullptr;
		if (len)*len = leng;
		return Str->str;
	}
	USHORT GetNameHash() {
		int Len;
		UCHAR* ShortName = (UCHAR*)GetShortName(&Len);
		if (ShortName == nullptr) return 0;
		return CRC(mem_read((ULONG)ShortName, UCHAR), (Len * 2));
	}

	int GetUID() {
		return mem_read((const uintptr_t)this + 0x28, int); ///prefabUID
	}

	int GetID() {
		UINT64 Info = mem_read((const uintptr_t)this + 0x20, UINT64);   ///prefab id
		return mem_read(Info + 0x20, int);
	}

	void AntiSpread()
	{
		if (Vars::Misc::AntiSpread)
		{
			UINT64 Held = mem_read((const uintptr_t)(const uintptr_t)this + oHeld, UINT64);
			mem_write(Held + 0x2DC, -1.f, float);     //0x2D4                                    ///////////test offsets
			mem_write(Held + 0x2B8, -1.f, float);
		}
	}

	void FastReload()
	{
		if (Vars::Misc::FastReload)
		{
			UINT64 Held = mem_read((const uintptr_t)(const uintptr_t)this + oHeld, UINT64);
			mem_write(Held + oFastReload, 1, bool);
		}
	}

	void SetAutomatic()
	{
		if (Vars::Misc::Automatic)
		{
			UINT64 Held = mem_read((const uintptr_t)(const uintptr_t)this + oHeld, UINT64);
			mem_write(Held + oAuto, 1, bool);
		}
	}

	void SuperEoka()
	{
		if (Vars::Misc::SuperEoka)
		{
			UINT64 Held = mem_read((const uintptr_t)(const uintptr_t)this + oHeld, UINT64);
			mem_write(Held + 0x2F4, 1.f, float);                                                     //test offset
		}
	}

	void SuperBow()
	{
		if (Vars::Misc::SuperBow)
		{
			UINT64 Held = mem_read((const uintptr_t)(const uintptr_t)this + oHeld, UINT64);
			mem_write(Held + oTriggerReady, 1, bool);
			//std::cout << "bow " << mem_read(Held + 0x324, float) << std::endl;
			mem_write(Held + oArrowBack, 1.f, float);							//crossy = crash
		}
	}

	void LongHand()
	{
		//UINT64 Held = mem_read((const uintptr_t)(const uintptr_t)this + oHeld, UINT64);
		//mem_write(Held + oDistance, 4.5f, float);
	}

	void FatHand()
	{
		//UINT64 Held = mem_read((const uintptr_t)(const uintptr_t)this + oHeld, UINT64);
		//mem_write(Held + oprojectileVelocityScale, 15.f, float);
	}

	void RunOnHit()
	{
		//UINT64 Held = mem_read((const uintptr_t)(const uintptr_t)this + oHeld, UINT64);
		//mem_write(Held + 0x251, 0, int);                                               //Test offset
	}
	void SetRA() {
		if (Vars::AimBot::noRecoil)
		{
		UINT64 Held = mem_read((const uintptr_t)(const uintptr_t)this + oHeld, UINT64);
		UINT64 RecoilProperties = mem_read(Held + 0x2C0, UINT64);
		mem_write(RecoilProperties + oRecoilMinYaw, 0.f, float);
		mem_write(RecoilProperties + oRecoilMaxYaw, 0.f, float);
		mem_write(RecoilProperties + oRecoilMinPitch, 0.f, float);
		mem_write(RecoilProperties + oRecoilMaxPitch, 0.f, float);
		}
	}
	float Test() {
		//UINT64 Held = mem_read((const uintptr_t)(const uintptr_t)this + oHeld, UINT64);
		//return mem_read(Held + oTriggerReady, float);
	}
};

class BasePlayer
{
public:
	//*** base entity info ***//
	float GetHealth() {
		return mem_read((const uintptr_t)(const uintptr_t)this + oPlayerHealth, float);
	}

	const wchar_t* GetName() {
		pUncStr Str = ((pUncStr)(mem_read((const uintptr_t)(const uintptr_t)this + oPlayerName, UINT64)));
		if (!Str) return L""; return Str->str;
	}

	Vector3 GetVelocity() {
		UINT64 PlayerModel = mem_read((const uintptr_t)(const uintptr_t)this + oPlayerModel, UINT64);
		return mem_read(PlayerModel + 0x170, Vector3);
	}

	bool IsVisible() {
		if (Vars::AimBot::VisibleCheck) {
			UINT64 PlayerModel = mem_read((const uintptr_t)(const uintptr_t)this + oPlayerModel, UINT64);
			return mem_read(PlayerModel + 0x1D4, bool); // 0x1CC
		} else return true;
	}

	float GetTickTime() {
		return mem_read((const uintptr_t)(const uintptr_t)this + olastSentTickTime, float);
	}

	bool IsValid(bool LPlayer = false) {
		//std::cout << "ISvalid " <<HasFlags(16) << "  " << IsDead() << " " << GetHealth() << std::endl;
		if (!this) return false;
		float health = GetHealth();
		UINT64 steam = GetSteamID();
		//std::cout << health << " " << steam;
		if (health > 150.f || health < 0.8f) return false;
		
		
		int nums = 0;
		do{
			nums++;
			steam /= 10;
		} while (steam > 0);
		//std::cout << " " << nums << std::endl;
		if (nums != 7 /*bot*/ && nums != 17 /*player*/) return false;
		return (((LPlayer || Vars::Visuals::IgnoreSleepers) ? !HasFlags(16) : true) && !IsDead());
	}

	bool HasFlags(int Flg) {
		return (mem_read((const uintptr_t)(const uintptr_t)this + oPlayerFlags, int) & Flg);
	}

	void FakeAdmin(int Val) {
		int Flags = mem_read((const uintptr_t)this + oPlayerFlags, int);
		mem_write((const uintptr_t)this + oPlayerFlags, (Flags |= 4), int);
	}



	int GetTeamSize()
	{
		UINT64 ClientTeam = mem_read((const uintptr_t)(const uintptr_t)this + oClientTeam, UINT64); // valid
		UINT64 members = mem_read(ClientTeam + 0x28, UINT64);
		return mem_read(members + 0x18, UINT64);
	}

	Vector3 GetPosition() {
		return GetBone(GetTransform(BoneList(Vars::Global::BoneToAim)));
	}

	UINT64 IsTeamMate(int Id)
	{
		UINT64 ClientTeam = mem_read((const uintptr_t)(const uintptr_t)this + oClientTeam, UINT64);
		UINT64 members = mem_read(ClientTeam + 0x28, UINT64);
		UINT64 List = mem_read(members + 0x10, UINT64);
		UINT64 player = mem_read(List + 0x20 + (Id * 0x8), UINT64);
		return mem_read(player + 0x18, UINT64);
	}

	bool IsDead() {
		if (!(const uintptr_t)this) return true;
		return mem_read((const uintptr_t)(const uintptr_t)this + oLifestate, bool);
	}

	UINT64 GetSteamID() {
		return mem_read((const uintptr_t)(const uintptr_t)this + oSteamID, UINT64);
	}

	//*** localplayer ***//
	bool IsMenu() {
		if (!(const uintptr_t)this) return true;
		UINT64 Input = mem_read((const uintptr_t)(const uintptr_t)this + oPlayerInput, UINT64);
		return !(mem_read(Input + 0xB0, bool));
	}

	void SetVA(const Vector2& VA) {
		UINT64 Input = mem_read((const uintptr_t)(const uintptr_t)this + oPlayerInput, UINT64);
		mem_write(Input + 0x3C, VA, Vector2);
	}

	Vector2 GetVA() {
		UINT64 Input = mem_read((const uintptr_t)(const uintptr_t)this + oPlayerInput, UINT64);
		return mem_read(Input + 0x3C, Vector2);
	}

	Vector2 GetRA() {
		UINT64 Input = mem_read((const uintptr_t)this + oPlayerInput, UINT64);
		return mem_read(Input + 0x64, Vector2);
	}

	WeaponData* GetWeaponInfo(int Id) {
		UINT64 Inventory = mem_read((const uintptr_t)this + oPlayerInventory, UINT64);
		UINT64 Belt = mem_read(Inventory + 0x28, UINT64);
		UINT64 ItemList = mem_read(Belt + 0x38, UINT64);
		UINT64 Items = mem_read(ItemList + 0x10, UINT64);
		//std::cout << "item " << readz(Items + 0x20 + (Id * 0x8), UINT64) << std::endl;
		return (WeaponData*)mem_read(Items + 0x20 + (Id * 0x8), UINT64);
	}

	WeaponData* GetActiveWeapon() {
		int ActUID = mem_read((const uintptr_t)this + oActiveUID, int);
		if (!ActUID) return nullptr;
		WeaponData* ActiveWeapon;
		for (int i = 0; i < 6; i++)
			if (ActUID == (ActiveWeapon = GetWeaponInfo(i))->GetUID()) {
				//std::cout << "uid " << ActUID << std::endl;
				return ActiveWeapon;
			}

		return nullptr;
	}

	//*** PlayerFunctions ***//
	void AirStuck(bool state) {
		mem_write((const uintptr_t)this + oFrozen, state, bool);
	}

	void SpiderMan() {
		UINT64 Movement = mem_read((const uintptr_t)this + oPlayerMovement, UINT64);
		mem_write(Movement + 0xB4, 0.f, float);
		mem_write(Movement + 0xB8, 0.f, float);
	}

	void GravityFunctionSTOP()
	{
		UINT64 Movement = mem_read((const uintptr_t)this + oPlayerMovement, UINT64);
		mem_write(Movement + ogravityMultiplier, 2.5f, float);//gravityMultiplier
	}

	void WaterBoost() {
		mem_write((const uintptr_t)(const uintptr_t)this + oWaterBonus, 0.15f, float);
	}

	void NoSway() {
		mem_write((const uintptr_t)this + oNoSway, 1.f, float);
	}

	void NoBlockAiming() {
		mem_write((const uintptr_t)this + oNoBlockAiming, false, bool);
	}

	void NoHeavyReduct() {
		float Reduct = mem_read((const uintptr_t)this + oSpeedReduction, float);
		if (Reduct == 0.f) { mem_write((const uintptr_t)this + oSpeedReduction, -0.1f, float); }
		else if ((Reduct > 0.15f) && (Reduct < 0.35f)) {
			mem_write((const uintptr_t)this + oSpeedReduction, 0.15f, float);
		}
		else if (Reduct > 0.39f) {
			mem_write((const uintptr_t)this + oSpeedReduction, 0.25f, float);
		}	
	}

	void SetGravity(float val) {
		UINT64 Movement = mem_read((const uintptr_t)this + oPlayerMovement, UINT64);
		mem_write(Movement + 0x74, val, float);
	}
private:
	UINT64 GetTransform(int bone)
	{
		UINT64 player_model = mem_read((const uintptr_t)(const uintptr_t)this + oPlayerModel, UINT64);
		UINT64 multi_mesh = mem_read(player_model + 0x208, UINT64);
		UINT64 bone_dictionary = mem_read(multi_mesh + 0x28, UINT64);
		UINT64 bone_values = mem_read(bone_dictionary + 0x18, UINT64);
		UINT64 entity_bone = mem_read((bone_values + (0x30 + ((bone - 1) * 0x8))), UINT64);
		return mem_read(entity_bone + 0x10, UINT64);
	}
	struct TransformAccessReadOnly
	{
		uint64_t pTransformData;
	};

	struct TransformData
	{
		uint64_t pTransformArray;
		uint64_t pTransformIndices;
	};
	struct Matrix34
	{
		Vector4 vec0;
		Vector4 vec1;
		Vector4 vec2;
	};
	Vector3 GetBone(ULONG_PTR pTransform)
	{
		__m128 result;

		const __m128 mulVec0 = { -2.000, 2.000, -2.000, 0.000 };
		const __m128 mulVec1 = { 2.000, -2.000, -2.000, 0.000 };
		const __m128 mulVec2 = { -2.000, -2.000, 2.000, 0.000 };

		TransformAccessReadOnly pTransformAccessReadOnly = mem_read(pTransform + 0x38, TransformAccessReadOnly);
		unsigned int index = mem_read(pTransform + 0x40, unsigned int);
		TransformData transformData = mem_read(pTransformAccessReadOnly.pTransformData + 0x18, TransformData);

		if (transformData.pTransformArray && transformData.pTransformIndices)
		{
			result = mem_read(transformData.pTransformArray + 0x30 * index, __m128);
			int transformIndex = mem_read(transformData.pTransformIndices + 0x4 * index, int);
			int pSafe = 0;
			while (transformIndex >= 0 && pSafe++ < 200)
			{
				Matrix34 matrix34 = mem_read(transformData.pTransformArray + 0x30 * transformIndex, Matrix34);

				__m128 xxxx = _mm_castsi128_ps(_mm_shuffle_epi32(*(__m128i*)(&matrix34.vec1), 0x00));	// xxxx
				__m128 yyyy = _mm_castsi128_ps(_mm_shuffle_epi32(*(__m128i*)(&matrix34.vec1), 0x55));	// yyyy
				__m128 zwxy = _mm_castsi128_ps(_mm_shuffle_epi32(*(__m128i*)(&matrix34.vec1), 0x8E));	// zwxy
				__m128 wzyw = _mm_castsi128_ps(_mm_shuffle_epi32(*(__m128i*)(&matrix34.vec1), 0xDB));	// wzyw
				__m128 zzzz = _mm_castsi128_ps(_mm_shuffle_epi32(*(__m128i*)(&matrix34.vec1), 0xAA));	// zzzz
				__m128 yxwy = _mm_castsi128_ps(_mm_shuffle_epi32(*(__m128i*)(&matrix34.vec1), 0x71));	// yxwy
				__m128 tmp7 = _mm_mul_ps(*(__m128*)(&matrix34.vec2), result);

				result = _mm_add_ps(
					_mm_add_ps(
						_mm_add_ps(
							_mm_mul_ps(
								_mm_sub_ps(
									_mm_mul_ps(_mm_mul_ps(xxxx, mulVec1), zwxy),
									_mm_mul_ps(_mm_mul_ps(yyyy, mulVec2), wzyw)),
								_mm_castsi128_ps(_mm_shuffle_epi32(_mm_castps_si128(tmp7), 0xAA))),
							_mm_mul_ps(
								_mm_sub_ps(
									_mm_mul_ps(_mm_mul_ps(zzzz, mulVec2), wzyw),
									_mm_mul_ps(_mm_mul_ps(xxxx, mulVec0), yxwy)),
								_mm_castsi128_ps(_mm_shuffle_epi32(_mm_castps_si128(tmp7), 0x55)))),
						_mm_add_ps(
							_mm_mul_ps(
								_mm_sub_ps(
									_mm_mul_ps(_mm_mul_ps(yyyy, mulVec0), yxwy),
									_mm_mul_ps(_mm_mul_ps(zzzz, mulVec1), zwxy)),
								_mm_castsi128_ps(_mm_shuffle_epi32(_mm_castps_si128(tmp7), 0x00))),
							tmp7)), *(__m128*)(&matrix34.vec0));

				transformIndex = mem_read(transformData.pTransformIndices + 0x4 * transformIndex, int);
			}
		}

		return Vector3(result.m128_f32[0], result.m128_f32[1], result.m128_f32[2]);
	}
};

//Base Player
class LPlayerBase
{
public:
	BasePlayer* BasePlayer = nullptr;
	Matrix4x4* pViewMatrix = nullptr;
	bool WorldToScreen(const Vector3& EntityPos, Vector2& ScreenPos)
	{
		if (!pViewMatrix) return false;
		Vector3 TransVec = Vector3(mem_read((ULONG64)&pViewMatrix->_14, float), mem_read((ULONG64)&pViewMatrix->_24, float), mem_read((ULONG64)&pViewMatrix->_34, float));
		Vector3 RightVec = Vector3(mem_read((ULONG64)&pViewMatrix->_11, float), mem_read((ULONG64)&pViewMatrix->_21, float), mem_read((ULONG64)&pViewMatrix->_31, float));
		Vector3 UpVec = Vector3(mem_read((ULONG64)&pViewMatrix->_12, float), mem_read((ULONG64)&pViewMatrix->_22, float), mem_read((ULONG64)&pViewMatrix->_32, float));
		float w = Math::Dot(TransVec, EntityPos) + mem_read((ULONG64)&pViewMatrix->_44, float);
		if (w < 0.098f) return false;
		float y = Math::Dot(UpVec, EntityPos) + mem_read((ULONG64)&pViewMatrix->_42, float);
		float x = Math::Dot(RightVec, EntityPos) + mem_read((ULONG64)&pViewMatrix->_41, float);
		ScreenPos = Vector2((Vars::Global::ScreenWidth / 2) * (1.f + x / w), (Vars::Global::ScreenHigh / 2) * (1.f - y / w));
		return true;
	}

	
};

LPlayerBase LocalPlayer;