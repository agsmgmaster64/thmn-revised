YogyakartaBonekaCenter1F_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, YogyakartaBonekaCenter_1F_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, CableClub_OnResume
	.byte 0

YogyakartaBonekaCenter_1F_OnTransition:
	setrespawn HEAL_LOCATION_YOGYAKARTA
	end
	
YogyakartaBonekaCenter1F_EventScript_Nurse::
	setvar VAR_0x800B, LOCALID_YOGYAKARTA_NURSE
	call Common_EventScript_JavaBnkaCenterNurse
	waitmessage
	waitbuttonpress
	release
	end
