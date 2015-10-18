/*
 * Author: SzwedzikPL
 *
 * Display thermal effect on strobe
 */
#include "script_component.hpp"

if (!hasInterface) exitWith {};

params ["_strobe"];

while {!isNull  _strobe} do {
    waituntil {sleep 0.5;currentVisionMode ace_player == 2 || isNull _strobe};
    while {currentVisionMode ace_player == 2 && !isNull _strobe} do {
        private ["_l"];
        _l = "#particlesource" createVehicleLocal (getPos _strobe);
        _l attachto [_strobe, [0, 1.35, 0]];
        _l setParticleClass "MissileDARExplo";
        sleep 0.05;
        detach _l;
        deleteVehicle _l;
        sleep 0.15;
        _l = "#particlesource" createVehicleLocal (getPos _strobe);
        _l attachto [_strobe, [0, 1.35, 0]];
        _l setParticleClass "MissileDARExplo";
        sleep 0.05;
        detach _l;
        deleteVehicle _l;
        sleep 1;
    };
};