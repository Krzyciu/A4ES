#include "script_component.hpp"
/*
 * Author: Krzyciu
 * setAnimation removeAnim function
 */

params ["_unit"];

private _animDoneEH = _unit getVariable [QGVAR(animDoneEH), -1];
_unit removeEventHandler ["AnimDone", _animDoneEH];

private _killedEH = _unit getVariable [QGVAR(animKilledEH), -1];
_unit removeMPEventHandler ["MPKilled", _killedEH];