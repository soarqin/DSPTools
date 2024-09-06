/*
 * Copyright (c) 2022 Soar Qin<soarchin@gmail.com>
 *
 * Use of this source code is governed by an MIT-style
 * license that can be found in the LICENSE file or at
 * https://opensource.org/licenses/MIT.
 */

#include "mainwnd.h"
#include "version.h"

#include "mods/dirs.h"

namespace modman {

MainWnd::MainWnd() : wxFrame(nullptr, wxID_ANY, wxT("Dyson Sphere Program Mod Manager " VERSION_STR),
                             wxDefaultPosition, wxSize(500, 800)) {
    mods::dirs.Init();
    listCfg_.init(L"Default");
    listCfg_.save();

    wxToolTip::Enable(true);
    wxToolTip::SetAutoPop(500);
    Centre();
    wxFont font(12, wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_MEDIUM, false, "Segoe UI");
    wxWindow::SetFont(font);
    auto *mainSizer = new wxBoxSizer(wxVERTICAL);
    SetSizer(mainSizer);
    modList_ = new ModList(this, wxID_ANY);
    mainSizer->Add(modList_, 1, wxEXPAND | wxALL, 0);
    auto entryCount = listCfg_.entryCount();
    for (int i = 0; i < entryCount; ++i) {
        const auto &entry = listCfg_.entry(i);
        modList_->addMod(entry);
    }
    modList_->FitInside();
}

}
