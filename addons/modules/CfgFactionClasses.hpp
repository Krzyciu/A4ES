class CfgFactionClasses {
    class GVAR(base) {
        displayName = "A3CS";
        priority = 10;
        side = 7;
    };
    class GVAR(AI): GVAR(base) {
        displayName = "A3CS AI";
    };
    class GVAR(effects): GVAR(base) {
        displayName = "A3CS Efekty";
    };
    class GVAR(map): GVAR(base) {
        displayName = "A3CS Mapa";
    };
};
