/*
 * Copyright (c) 2022 Soar Qin<soarchin@gmail.com>
 *
 * Use of this source code is governed by an MIT-style
 * license that can be found in the LICENSE file or at
 * https://opensource.org/licenses/MIT.
 */

#include "mainwnd.h"

#include "version.h"
#include "toppanel.h"

#include "mods/dirs.h"
#include "mods/profiles.h"

#include <wx/artprov.h>

namespace modman {

MainWnd::MainWnd() : wxFrame(nullptr, wxID_ANY, wxT("Dyson Sphere Program Mod Manager " VERSION_STR),
                             wxDefaultPosition, wxSize(600, 800)) {
    mods::dirs.Init();

    // https://thunderstore.io/c/dyson-sphere-program/api/v1/package/
    ModInfo::staticInit();
    wxToolTip::Enable(true);
    wxToolTip::SetAutoPop(5000);
    Centre();
    wxFont font(12, wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_MEDIUM, false, "Segoe UI");
    wxWindow::SetFont(font);
    auto *mainSizer = new wxBoxSizer(wxVERTICAL);
    SetSizer(mainSizer);
    auto *topPanel = new TopPanel(this);
    mainSizer->Add(topPanel, 0, wxEXPAND | wxALL, 0);
    modList_ = new ModList(this, wxID_ANY);
    mainSizer->Add(modList_, 1, wxEXPAND | wxALL, 0);

    topPanel->setOnProfileSelected([this](const std::string &profile) { onProfileChanged(profile); });
}

void MainWnd::onProfileChanged(const std::string &profile) {
    listCfg_ = modman::mods::Profiles::loadProfile(profile);
    modList_->clearMods();
    auto entryCount = listCfg_->entryCount();
    for (int i = 0; i < entryCount; ++i) {
        const auto &entry = listCfg_->entry(i);
        modList_->addMod(entry);
    }
    modList_->FitInside();
}

}
