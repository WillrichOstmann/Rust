bool jump = false;
bool air = false;

bool once = false;
void Misc(UINT64 TodCycle)
{
	if (Vars::Visuals::AlwaysDay) {
		mem_write(TodCycle + 0x10, 12.00f, float);
	}

	if (Vars::Misc::FakeAdmin)
		LocalPlayer.BasePlayer->FakeAdmin(4);

	if (Vars::Misc::SpiderMan) {
		if (GetAsyncKeyState(VK_MBUTTON)) {
			//cout << "VK_MBUTTON Pressed" << endl;
			LocalPlayer.BasePlayer->SetGravity(Vars::Misc::JumpValue);
			jump = true;
		}
		else if(jump) {
			LocalPlayer.BasePlayer->SetGravity(2.5f);
			jump = false;
		}
	}
	//air stuck
	if (Vars::Misc::AirStuck) {
		if (GetAsyncKeyState(VK_XBUTTON1))
		{
			LocalPlayer.BasePlayer->AirStuck(true);
			air = true;
		}
		else if(air)
		{
			air = false;
			LocalPlayer.BasePlayer->AirStuck(false);
		}
			
	}
	if (Vars::Misc::SpiderMan)
		LocalPlayer.BasePlayer->SpiderMan();
	if (!once) {
		//boost speed on water
		if (Vars::Misc::WaterBoost)
			LocalPlayer.BasePlayer->WaterBoost();

		//on aim on kastrulya
		if (Vars::Misc::AntiKastrulya)
			LocalPlayer.BasePlayer->NoBlockAiming();

		//boost speed on heavy armor
		if (Vars::Misc::NoHeavyReduct)
			LocalPlayer.BasePlayer->NoHeavyReduct();

		//spider man
		

		//remove weapon sway
		if (Vars::Misc::NoSway)
			LocalPlayer.BasePlayer->NoSway();
		once = true;
	}
	
}
