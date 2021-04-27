
class Extended_PreStart_EventHandlers {
    delete tfw_radios_rf3080;

    class ADDON {
        init = QUOTE(call COMPILE_FILE(XEH_preStart));
    };
};

class Extended_PreInit_EventHandlers {
    delete tfw_radios_rf3080;

    class ADDON {
        init = QUOTE(call COMPILE_FILE(XEH_preInit));
    };
};

class Extended_PostInit_EventHandlers {
    delete tfw_radios_rf3080;

    class ADDON {
        init = QUOTE(call COMPILE_FILE(XEH_postInit));
    };
};

class Extended_Init_EventHandlers {
	class CAManBase {
		delete tfw_radios_rf3080;
	};
	class tfw_rf3080Object {
		delete tfw_radios_rf3080;
	};
};

class Extended_InitPost_EventHandlers {
	class tfw_rf3080Object {
		class ADDON {
			clientInit = QUOTE(_this call FUNC(addMobileAntenna));
            serverInit = QUOTE(_this call FUNC(initMobileAntennaServer));
		};
	};
};
class Extended_Deleted_EventHandlers {
	class tfw_rf3080Object {
		ADDON = QUOTE(_this call FUNC(deleteMobileAntenna));
	};
};
