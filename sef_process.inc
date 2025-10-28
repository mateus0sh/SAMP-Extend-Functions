

#if defined _validator_inc
    #undef _validator_inc
#endif

#if defined _validator_inc_included
    #endinput
#endif
#define _validator_inc_included

#if !defined _samp_included
    #error "The `a_samp` library has not been activated. Please activate it at the beginning of your Gamemode, Ex: `#include <a_samp>`"
#endif

/*

                                                       
                                                                
                        _____ _____ _____ _____ _____ _____ _____ 
                        |  _  | __  |     |     |   __|   __|   __|
                        |   __|    -|  |  |   --|   __|__   |__   |
                        |__|  |__|__|_____|_____|_____|_____|_____|
                                                                
                ___________________________________________________________          

               Essa é a forma mais eficaz de fazer uma mini barra de loading!
 
 
 */

#define DEFAULT_TIMER (50) // Melhor

#define Progresso:%0(%1,%2) \
	forward Progress_%0(%1,Float:%2); public Progress_%0(%1,Float:%2)

forward UpdateProgress(playerid);

enum ProgressInfo
{
	p_callback[32],
	p_time,
	p_timer,
	Float:p_percent
}
new Progress_Info[MAX_PLAYERS][ProgressInfo], PlayerText:__process_td_[MAX_PLAYERS][4];


stock CreateProgress(playerid, callback[], time = 1000)
{
	CreateTDProgress(playerid);
	format(Progress_Info[playerid][p_callback], 32, "Progress_%s", callback);
	Progress_Info[playerid][p_percent] = 0;
    Progress_Info[playerid][p_time] = time;
	for(new i = 0; i < 4; i++) PlayerTextDrawShow(playerid, __process_td_[playerid][i]);
	Progress_Info[playerid][p_timer] = SetTimerEx("UpdateProgress", Progress_Info[playerid][p_time], true, "i", playerid);
	return 1;
}

public UpdateProgress(playerid)
{

	if(Progress_Info[playerid][p_percent] >= 100.0)
	{
		return KillProgress(playerid);
	}

	new string[10]; 
	format(string, sizeof(string), "%.0f%", Progress_Info[playerid][p_percent]);
	PlayerTextDrawSetString(playerid, __process_td_[playerid][2], string);
	Progress_Info[playerid][p_percent] ++;

	PlayerTextDrawTextSize(playerid, __process_td_[playerid][1], (246)+(Progress_Info[playerid][p_percent] * (1.52)), 1.0);
	PlayerTextDrawShow(playerid, __process_td_[playerid][1]);
	
	CallLocalFunction(Progress_Info[playerid][p_callback], "df", playerid, Progress_Info[playerid][p_percent]);
	return 1;
}

stock KillProgress(playerid)
{
	for(new i = 0; i < 4; i++) PlayerTextDrawHide(playerid, __process_td_[playerid][i]);
	format(Progress_Info[playerid][p_callback], 32, "");
	KillTimer(Progress_Info[playerid][p_timer]);
	Progress_Info[playerid][p_time] = 18;
	Progress_Info[playerid][p_percent] = 0;
	return 1;
}

stock CreateTDProgress(playerid)
{
	__process_td_[playerid][0] = CreatePlayerTextDraw(playerid, 322.000000, 351.000000, "_");
	PlayerTextDrawFont(playerid, __process_td_[playerid][0], 1);
	PlayerTextDrawLetterSize(playerid, __process_td_[playerid][0], 0.600000, 1.300003);
	PlayerTextDrawTextSize(playerid, __process_td_[playerid][0], 298.500000, 155.000000);
	PlayerTextDrawSetOutline(playerid, __process_td_[playerid][0], 1);
	PlayerTextDrawSetShadow(playerid, __process_td_[playerid][0], 0);
	PlayerTextDrawAlignment(playerid, __process_td_[playerid][0], 2);
	PlayerTextDrawColor(playerid, __process_td_[playerid][0], -1);
	PlayerTextDrawBackgroundColor(playerid, __process_td_[playerid][0], 255);
	PlayerTextDrawBoxColor(playerid, __process_td_[playerid][0], 245);
	PlayerTextDrawUseBox(playerid, __process_td_[playerid][0], 1);
	PlayerTextDrawSetProportional(playerid, __process_td_[playerid][0], 1);
	PlayerTextDrawSetSelectable(playerid, __process_td_[playerid][0], 0);

	__process_td_[playerid][1] = CreatePlayerTextDraw(playerid, 246.000000, 352.000000, "~b~");
	PlayerTextDrawFont(playerid, __process_td_[playerid][1], 1);
	PlayerTextDrawLetterSize(playerid, __process_td_[playerid][1], 0.254166, 1.050000);
	PlayerTextDrawTextSize(playerid, __process_td_[playerid][1], 246.000000, 18.000000);
	PlayerTextDrawSetOutline(playerid, __process_td_[playerid][1], 1);
	PlayerTextDrawSetShadow(playerid, __process_td_[playerid][1], 0);
	PlayerTextDrawAlignment(playerid, __process_td_[playerid][1], 1);
	PlayerTextDrawColor(playerid, __process_td_[playerid][1], 1687547391);
	PlayerTextDrawBackgroundColor(playerid, __process_td_[playerid][1], 255);
	PlayerTextDrawBoxColor(playerid, __process_td_[playerid][1], 1687547376);
	PlayerTextDrawUseBox(playerid, __process_td_[playerid][1], 1);
	PlayerTextDrawSetProportional(playerid, __process_td_[playerid][1], 1);
	PlayerTextDrawSetSelectable(playerid, __process_td_[playerid][1], 0);

	__process_td_[playerid][2] = CreatePlayerTextDraw(playerid, 307.000000, 352.000000, "_");
	PlayerTextDrawFont(playerid, __process_td_[playerid][2], 2);
	PlayerTextDrawLetterSize(playerid, __process_td_[playerid][2], 0.254166, 1.050000);
	PlayerTextDrawTextSize(playerid, __process_td_[playerid][2], 398.500000, 18.000000);
	PlayerTextDrawSetOutline(playerid, __process_td_[playerid][2], 0);
	PlayerTextDrawSetShadow(playerid, __process_td_[playerid][2], 1);
	PlayerTextDrawAlignment(playerid, __process_td_[playerid][2], 1);
	PlayerTextDrawColor(playerid, __process_td_[playerid][2], -1);
	PlayerTextDrawBackgroundColor(playerid, __process_td_[playerid][2], 255);
	PlayerTextDrawBoxColor(playerid, __process_td_[playerid][2], -16);
	PlayerTextDrawUseBox(playerid, __process_td_[playerid][2], 0);
	PlayerTextDrawSetProportional(playerid, __process_td_[playerid][2], 1);
	PlayerTextDrawSetSelectable(playerid, __process_td_[playerid][2], 0);

	__process_td_[playerid][3] = CreatePlayerTextDraw(playerid, 318.000000, 335.000000, "processando");
	PlayerTextDrawFont(playerid, __process_td_[playerid][3], 2);
	PlayerTextDrawLetterSize(playerid, __process_td_[playerid][3], 0.254166, 1.050000);
	PlayerTextDrawTextSize(playerid, __process_td_[playerid][3], 398.500000, 158.000000);
	PlayerTextDrawSetOutline(playerid, __process_td_[playerid][3], 0);
	PlayerTextDrawSetShadow(playerid, __process_td_[playerid][3], 1);
	PlayerTextDrawAlignment(playerid, __process_td_[playerid][3], 2);
	PlayerTextDrawColor(playerid, __process_td_[playerid][3], -1);
	PlayerTextDrawBackgroundColor(playerid, __process_td_[playerid][3], 255);
	PlayerTextDrawBoxColor(playerid, __process_td_[playerid][3], -16);
	PlayerTextDrawUseBox(playerid, __process_td_[playerid][3], 0);
	PlayerTextDrawSetProportional(playerid, __process_td_[playerid][3], 1);
	PlayerTextDrawSetSelectable(playerid, __process_td_[playerid][3], 0);
	return 1;
}


/*
	// Usage:
	
	public OnPlayerConnect(playerid)
	{
		CreateProgress(playerid, "Teste", 50); //   0.50 * 100 = (0.50ms)
	}

	Progresso:Teste(playerid, progress)
	{
		if(progress == 1){ SendClientMessage(playerid, -1, "Running"); }
		if(progress >= 100)
		{
			SendClientMessage(playerid, -1, "Finish");
		}
		return 1;
	}
*/