#include "script_component.hpp"
class CfgPatches
{
    class ADDON
    {
        units[] = {};
        weapons[] = {};
        requiredVersion = REQUIRED_VERSION;
        requiredAddons[] = {"a3cs_main"};
        version = A3CS_VERSION;
        versionStr = QUOTE(A3CS_VERSION);
        versionAr[] = A3CS_VERSION_ARRAY;
        author[] = {"SzwedzikPL", "ACE3 Team"};
        authorUrl = "http://arma3coop.pl";
    };
};

class Extended_PreInit_EventHandlers {
    class ADDON {
        init = QUOTE(call COMPILE_FILE(XEH_preInit));
    };
};
class Extended_Init_EventHandlers {
    class CAManBase {
        class GVAR(handleRating) {
            init = QUOTE(_this call FUNC(handleRating));
        };
    };
};
class Extended_Respawn_EventHandlers {
    class CAManBase {
        class GVAR(handleRating) {
            respawn = QUOTE(_this call FUNC(handleRating));
        };
    };
};

//Disable Assemble/Disassemble static's
class CfgActions {
    class None;
    class Assemble: None {show = 0;};
    class DisAssemble: None {show = 0;};
};