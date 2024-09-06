#include "mainwnd.h"

namespace modman {

class ModManApp : public wxApp {
public:
    bool OnInit() override {
        AllocConsole();
        freopen("CONIN$", "r", stdin);
        freopen("CONOUT$", "w", stdout);
        freopen("CONOUT$", "w", stderr);

        wxInitAllImageHandlers();
        (new MainWnd)->Show(true);
        return true;
    }
};

}

IMPLEMENT_APP(modman::ModManApp)
