#include "script_component.hpp"

if (!isServer) exitWith {};

[QGVAR(onPlayerConnected), "onPlayerConnected", {
    TRACE_5("onPlayerConnected",_id,_name,_uid,_owner,_jip);
    if (_uid != "" && _name != "headlessclient") then {
        [format [localize LSTRING(Log_PlayerConnected), _name]] call FUNC(missionLog);
    };
}] call BIS_fnc_addStackedEventHandler;

[QGVAR(onPlayerDisconnected), "onPlayerDisconnected", {
    TRACE_5("onPlayerDisconnected",_id,_name,_uid,_owner,_jip);
    if (_uid != "" && _name != "headlessclient") then {
        [format [localize LSTRING(Log_PlayerDisconnected), _name]] call FUNC(missionLog);
    };
}] call BIS_fnc_addStackedEventHandler;

//Refresh curator points
[] call FUNC(curatorPointsLoop);
if (count allCurators > 0) then {
    [{
        {
            private _curator = _x;
            _curator addCuratorAddons (("true" configClasses (configFile >> "CfgPatches")) apply {toLower configName _x});
        } forEach allCurators;
    }, [], 2] call CBA_fnc_waitAndExecute;
};

["ace_tagCreated", {
    params ["_tag", "_color", "_object", "_unit"];
    private _nickname = _unit call EFUNC(common,getName);
    [format [localize LSTRING(Log_PlayerUsedSpray), _nickname]] call FUNC(adminLog);
}] call CBA_fnc_addEventHandler;

//Update game status in DB every 60s
//[FUNC(updateGameStatus), 60, []] call CBA_fnc_addPerFrameHandler;

//Update server status in DB
[FUNC(onEachFrame), 0, []] call CBA_fnc_addPerFrameHandler;

//Send nametag data after 2s
[FUNC(sendNametagData), [], 2] call CBA_fnc_waitAndExecute;
