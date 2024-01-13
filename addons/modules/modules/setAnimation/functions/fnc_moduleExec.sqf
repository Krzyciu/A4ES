#include "script_component.hpp"
/*
 * Author: Krzyciu
 * setAnimation moduleExec function
 */

params ["_unit", "_anim", "_loopAnimation", "_loopCondition"];
_unit = _unit#0;
[_unit, _anim, 2] call ace_common_fnc_doAnimation;
[QGVAR(disableAI), [_unit, ["ANIM", "AUTOTARGET", "FSM", "MOVE", "TARGET"]], _unit] call CBA_fnc_targetEvent;

private _animDoneEH = -1;
private _killedEH = -1;

if (_loopAnimation) then {
  _unit setVariable [QGVAR(loopCondition), _loopCondition];

  _animDoneEH = _unit addEventHandler ["AnimDone", {
    params ["_unit", "_anim"];
    if (!(_unit call _loopCondition)) exitWith {
      _unit call FUNC(setAnimation_removeAnim);
    };
    [_unit, _anim, 2] call ace_common_fnc_doAnimation;
  }];

  _killedEH = _unit addMPEventHandler ["MPKilled", {
    _this call FUNC(setAnimation_removeAnim);
  }];

  _unit setVariable [QGVAR(animKilledEH), _killedEH];
  _unit setVariable [QGVAR(animDoneEH), _animDoneEH];
};