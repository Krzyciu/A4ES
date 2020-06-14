#include "script_component.hpp"
/*
 * Author: SzwedzikPL
 * Handles RscRadar map draw event
 */

params ["_control"];

BEGIN_COUNTER(drawRadar);

private _specialStateUnits = [];
private _playerDir = getDir ace_player;

{
  private _distance = _x distance2D ace_player;
  if (_distance < RADAR_MAX_UNIT_DISTANCE) then {
    private _opacity = linearConversion [RADAR_FADE_MIN_UNIT_DISTANCE, RADAR_MAX_UNIT_DISTANCE, _distance, 1, 0, true];
    private _icon = _x getVariable [QGVAR(icon), ""];

    // If icon doesn't match baseIcon unit is in special state
    if !(_icon isEqualTo (_x getVariable [QGVAR(baseIcon), ""])) then {
      _specialStateUnits pushBack _x;
    };

    _control drawIcon [
      _icon,
      [1, 1, 1, _opacity],
      position _x,
      18,
      18,
      (getDir _x) - _playerDir,
      ""
    ];
  };
} forEach allUnits; //DEBUG!

// redraw memberlist if units with special states changed
if !(GVAR(lastSpecialStateUnits) isEqualTo _specialStateUnits) then {
  false call FUNC(drawMemberlist);
  GVAR(lastSpecialStateUnits) = _specialStateUnits;
};

END_COUNTER(drawRadar);
