class CfgVehicles {
    class StaticShip;
    class a3cs_lhd: StaticShip {
        scope = 2;
        scopeCurator = 0;
        author = "$STR_A3_Bohemia_Interactive";
        displayName = CSTRING(DisplayName);
        model = "\a3\weapons_f\empty";
        vehicleClass = "Submerged";
        editorCategory = "EdCat_Default";
        editorSubcategory  = "EdSubcat_Default";
        icon = PATHTOF(data\lhd_ca.paa);
        mapsize = 250;
        destrType = 0;
        featureSize = 100;
        class Eventhandlers {
            init = QUOTE(_this call FUNC(initLHD));
        };
    };
};