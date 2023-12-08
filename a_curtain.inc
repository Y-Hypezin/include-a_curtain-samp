// - - - - - - - - : datas


// (C) Copyright by zHypezinXzL(R)

// @include      : a_curtain
// @version      : ( 1 )
// @infoV        : ( 1.2.3.1 ) : discriminator.define(s).function(s).codchange(s) - note: if the information from a new update is repeated in this version, discriminator(version) ++
// @github       : https://github.com/zHypezinXzL
// @date         : 7th dec. 2023

// @author       : zHypezinXzL
// @contributors : pushline
// @sent by      : zHypezinXzL
// @codelock     : this code is open for modifications, but it is necessary to have my credits!

// @comments     : -


// - - - - - - - - : include


// custom include-guard to ensure we don't duplicate
#if (defined _INC_a_curtain)
    // for because it is already defined in another environment
    #endinput 
#endif

// define the include (indentifier)
#define _INC_a_curtain

// Port to open.mp and loads default variables as INVALID_PLAYER_TEXT_DRAW. (If they are using samp-stdlib)
#tryinclude <open.mp>

#if (!defined _INC_open_mp)
    #include <a_samp>
#endif


// - - - - - - - - : callbacks


forward OnPlayerUpdateCurtain (
    playerid,
    time,
    permanence,
    curtainid,
    bool: invert,
    progress
);

forward OnPlayerCurtainClosed (
    playerid,
    curtainid
);


// - - - - - - - - : natives


/// functions
/// native ShowPlayerCurtain(playerid, time, curtainid, permanence = 500);
/// native HidePlayerCurtain(playerid);
/// native DoesCurtainExists(playerid);
/// native IsCurtainExists(playerid);

/// Callbacks
/// OnPlayerUpdateCurtain(playerid, time, permanence, curtainid, bool: invert, progress)
/// OnPlayerCurtainClosed(playerid, curtainid)


// - - - - - - - - : defines


#if !defined INVALID_PLAYER_TEXT_DRAW
    #define INVALID_PLAYER_TEXT_DRAW (PlayerText:0xFFFF)
#endif

#if !defined INVALID_PLAYER_3DTEXT_ID
    #define INVALID_PLAYER_3DTEXT_ID (PlayerText:0xFFFF)
#endif


// - - - - - - - - : variables


static stock 
    PlayerText: ___curtain_td_var_ [MAX_PLAYERS] [1]
;


// - - - - - - - - : functions


stock bool: DoesCurtainExists(
    playerid
) {
    return 
        ((___curtain_td_var_ [playerid] [0] != INVALID_PLAYER_TEXT_DRAW) ? (true) : (false))
    ;
}
// v1.0.2.0 function (adapt to the old function)
#define IsCurtainExist DoesCurtainExists

stock HidePlayerCurtain (
    playerid
) {
    if (IsPlayerConnected (playerid) && !IsPlayerNPC (playerid)) {
        if (DoesCurtainExists (playerid)) {
            PlayerTextDrawDestroy (playerid, ___curtain_td_var_ [playerid] [0]);
            ___curtain_td_var_ [playerid] [0] = INVALID_PLAYER_TEXT_DRAW;
            return 
                1
            ;
        }
    }
    return
        0
    ;
}

stock ShowPlayerCurtain (
    playerid,
    time,
    curtainid,
    permanence = 500
) {
    if (IsPlayerConnected (playerid) && !IsPlayerNPC (playerid) && time) {
        if (!DoesCurtainExists (playerid)) {
            ___curtain_td_var_ [playerid] [0] = CreatePlayerTextDraw (playerid, 316.000000, -77.000000, "_");
            PlayerTextDrawFont (playerid, ___curtain_td_var_ [playerid] [0], 1);
            PlayerTextDrawLetterSize (playerid, ___curtain_td_var_ [playerid] [0], 1.529166, 65.600013);
            PlayerTextDrawTextSize (playerid, ___curtain_td_var_ [playerid] [0], 298.500000, 875.000000);
            PlayerTextDrawSetOutline (playerid, ___curtain_td_var_ [playerid] [0], 1);
            PlayerTextDrawSetShadow (playerid, ___curtain_td_var_ [playerid] [0], 0);
            PlayerTextDrawAlignment (playerid, ___curtain_td_var_ [playerid] [0], 2);
            PlayerTextDrawColor (playerid, ___curtain_td_var_ [playerid] [0], -1);
            PlayerTextDrawBackgroundColor (playerid, ___curtain_td_var_ [playerid] [0], 255);
            // adaptations for open-mp
            #if (!defined _INC_open_mp)
                PlayerTextDrawBoxColor (playerid, ___curtain_td_var_ [playerid] [0], 0);
            #else
                PlayerTextDrawBoxColour (playerid, ___curtain_td_var_ [playerid] [0], 0);
            #endif
            PlayerTextDrawUseBox (playerid, ___curtain_td_var_ [playerid] [0], 1);
            PlayerTextDrawSetProportional (playerid, ___curtain_td_var_ [playerid] [0], 1);
            PlayerTextDrawSetSelectable (playerid, ___curtain_td_var_ [playerid] [0], 0);
            PlayerTextDrawShow (playerid, ___curtain_td_var_ [playerid] [0]);

            CallLocalFunction ("OnPlayerUpdateCurtain", "iiiiii", playerid, time, permanence, curtainid, false, 1);
            return 
                1
            ;
        }
    }
    return 
        0
    ;
}


// - - - - - - - - : hookbacks


public OnGameModeInit (

) {
    print ("                                                                                   ");
    print (" Loading include: a_curtain.inc                                                    ");
    print ("                                                                                   ");
    print ("- - - - - - - - - - :                                                              ");
    print ("                                                                                   ");
    print ("   (C) Copyright by zHypezinXzL (R)                                                ");
    print ("                                                                                   ");
    print ("    @include      : a_curtain                                                      ");
    print ("    @version      :( 1 )                                                           ");
    print ("    @infoV        :( 1.2.3.1 )                                                     ");
    print ("    @date         : 7th dec. 2023                                                  ");
    print ("                                                                                   ");
    print ("    @author       : zHypezinXzL                                                    ");
    print ("    @contributors : pushline                                                       ");
    print ("    @sent by      : zHypezinXzL                                                    ");
    print ("    @team         : Hyped                                                          ");
    print ("                                                                                   ");
    print ("- - - - - - - - - - :                                                              ");
    print ("                                                                                   ");
    print (" >> a_curtain included v.1 (1.2.3.1)                                               ");
    print (" Loaded.                                                                           ");
    print ("                                                                                   ");

    #if (defined __OnGameModeInit_a_cur)
        return 
            __OnGameModeInit_a_cur (

            )
        ;
    #else 
        return 
            1
        ;
    #endif
}

public OnPlayerConnect (
    playerid
) {
    ___curtain_td_var_ [playerid] [0] = INVALID_PLAYER_TEXT_DRAW;

    #if (defined __OnPlayerConnect_a_cur)
        return 
            __OnPlayerConnect_a_cur (
                playerid
            )
        ;
    #else 
        return 
            1
        ;
    #endif
}

public OnPlayerDisconnect (
    playerid,
    reason
) {
    HidePlayerCurtain (playerid);

    #if (defined __OnPlayerDisconnect_a_cur)
        return 
            __OnPlayerDisconnect_a_cur (
                playerid,
                reason
            )
        ;
    #else 
        return 
            1
        ;
    #endif
}

public OnPlayerUpdateCurtain (
    playerid,
    time,
    permanence,
    curtainid,
    bool: invert,
    progress
) {
    if (DoesCurtainExists (playerid)) {
        if (invert) {
            if (!progress) {
                HidePlayerCurtain (playerid);
            } else {
                // adaptations for open-mp
                #if (!defined _INC_open_mp)
                    PlayerTextDrawBoxColor (playerid, ___curtain_td_var_ [playerid] [0], progress);
                #else
                    PlayerTextDrawBoxColour (playerid, ___curtain_td_var_ [playerid] [0], progress);
                #endif
                PlayerTextDrawShow (playerid, ___curtain_td_var_ [playerid] [0]);

                // If u get `warning 239: literal array/string passed to a non-const parameter` using pawn compiler 3.10.10
                // Two options to fix it
                // 1 - Install pawn-stdlib and samp-stdlib updated (not the ones from the releases on github)
                // 2 - Go on a_samp and before the funcname[] in SetTimer(Ex) add const.              
                SetTimerEx ("OnPlayerUpdateCurtain", ((time / 2) / 255), false, "iiiiii", playerid, time, permanence, curtainid, invert, (progress - 1));
            }
        } else {
            if (progress == 256) {
                // adaptations for open-mp
                #if (!defined _INC_open_mp)
                    PlayerTextDrawBoxColor (playerid, ___curtain_td_var_ [playerid] [0], 255);
                #else
                    PlayerTextDrawBoxColour (playerid, ___curtain_td_var_ [playerid] [0], 255);
                #endif
                PlayerTextDrawShow (playerid, ___curtain_td_var_ [playerid] [0]);

                // Calling just OnPlayerCurtainClosed will fail cause it REQUIRES for the user to create the public in their gamemode.
                // CallLocalFunction prevents the error: "error 004: function "OnPlayerCurtainClosed" is not implemented".
                CallLocalFunction ("OnPlayerCurtainClosed", "ii", playerid, curtainid);

                SetTimerEx ("OnPlayerUpdateCurtain", permanence, false, "iiiiii", playerid, time, permanence, curtainid, true, 254);
            } else {
                // adaptations for open-mp
                #if (!defined _INC_open_mp)
                    PlayerTextDrawBoxColor (playerid, ___curtain_td_var_ [playerid] [0], progress);
                #else
                    PlayerTextDrawBoxColour (playerid, ___curtain_td_var_ [playerid] [0], progress);
                #endif
                PlayerTextDrawShow (playerid, ___curtain_td_var_ [playerid] [0]);

                SetTimerEx ("OnPlayerUpdateCurtain", ((time / 2) / 255), false, "iiiiii", playerid, time, permanence, curtainid, invert, (progress + 1));
            }
        }
    }

    #if (defined __OnPlayerUpdateCurtain_a_cur)
        return 
            __OnPlayerUpdateCurtain_a_cur (
                playerid,
                time,
                permanence,
                curtainid,
                invert,
                progress
            )
        ;
    #else 
        return 
            1
        ;
    #endif
}


// - - - - - - - - : hooks 


#if (defined _ALS_OnGameModeInit)
    #undef OnGameModeInit
#else
    #define _ALS_OnGameModeInit
#endif

#if (defined _ALS_OnPlayerConnect)
    #undef OnPlayerConnect
#else
    #define _ALS_OnPlayerConnect
#endif

#if (defined _ALS_OnPlayerDisconnect)
    #undef OnPlayerDisconnect
#else
    #define _ALS_OnPlayerDisconnect
#endif

#if (defined _ALS_OnPlayerUpdateCurtain)
    #undef OnPlayerUpdateCurtain
#else
    #define _ALS_OnPlayerUpdateCurtain
#endif


// - - - - - - - - : + + +


#define OnGameModeInit __OnGameModeInit_a_cur

#define OnPlayerConnect __OnPlayerConnect_a_cur

#define OnPlayerDisconnect __OnPlayerDisconnect_a_cur

#define OnPlayerUpdateCurtain __OnPlayerUpdateCurtain_a_cur


// - - - - - - - - : + + +


#if (defined __OnGameModeInit_a_cur)
	forward __OnGameModeInit_a_cur (

    );
#endif

#if (defined __OnPlayerConnect_a_cur)
	forward __OnPlayerConnect_a_cur (
        playerid
    );
#endif

#if (defined __OnPlayerDisconnect_a_cur)
	forward __OnPlayerDisconnect_a_cur (
        playerid,
        reason
    );
#endif

#if (defined __OnPlayerUpdateCurtain_a_cur)
	forward __OnPlayerUpdateCurtain_a_cur (
        playerid,
        time,
        permanence,
        curtainid,
        bool: invert,
        progress
    );
#endif


// - - - - - - - - : end