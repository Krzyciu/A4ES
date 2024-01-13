#include "script_component.hpp"
/*
 * Author: Krzyciu
 * setAnimation moduleExec function
 */

params ["_units", "_anim", "_loopAnimation", "_loopCondition"];

private _animDoneEH = -1;
private _killedEH = -1;

{
  [_x, _anim, 2] call ace_common_fnc_doAnimation;
  [QGVAR(disableAI), [_x, ["ANIM", "AUTOTARGET", "FSM", "MOVE", "TARGET"]], _x] call CBA_fnc_targetEvent;

  if (_loopAnimation) then {
    _x setVariable [QGVAR(loopCondition), _loopCondition];

    _animDoneEH = _x addEventHandler ["AnimDone", {
      params ["_unit", "_anim", "_loopCondition"];
      if (!(_unit call _loopCondition)) exitWith {
        _unit call FUNC(setAnimation_removeAnim);
      };
      [_unit, _anim, 2] call ace_common_fnc_doAnimation;
    }];

    _killedEH = _x addMPEventHandler ["MPKilled", {
      _this call FUNC(setAnimation_removeAnim);
    }];

    _x setVariable [QGVAR(animKilledEH), _killedEH];
    _x setVariable [QGVAR(animDoneEH), _animDoneEH];
  };
} forEach _units;