#include "mainwnd.h"

namespace modman {

class ModManApp : public wxApp {
public:
    bool OnInit() override {
#if !defined(NDEBUG)
        AllocConsole();
        freopen("CONIN$", "r", stdin);
        freopen("CONOUT$", "w", stdout);
        freopen("CONOUT$", "w", stderr);
#endif

        this->MSWEnableDarkMode(wxApp::DarkMode_Always);
        wxInitAllImageHandlers();
        (new MainWnd)->Show(true);
        return true;
    }
};

}

IMPLEMENT_APP(modman::ModManApp)
