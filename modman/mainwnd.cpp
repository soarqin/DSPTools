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
                             wxDefaultPosition, wxSize(800, 450)) {
    mods::dirs.Init();
    listCfg_.init(L"Default");
    listCfg_.save();

    wxToolTip::Enable(true);
    wxToolTip::SetAutoPop(500);
    Centre();
    wxWindow::SetBackgroundColour(wxColour(243, 243, 243));
    wxFont font(12, wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_MEDIUM, false, "Segoe UI");
    wxWindow::SetFont(font);
    auto *mainSizer = new wxBoxSizer(wxVERTICAL);
    SetSizer(mainSizer);
    list_ = new wxListBox(this, wxID_ANY, wxDefaultPosition, wxDefaultSize, 0, nullptr, wxLB_SINGLE);
    mainSizer->Add(list_, 1, wxEXPAND | wxALL, 5);
    auto entryCount = listCfg_.entryCount();
    for (int i = 0; i < entryCount; ++i) {
        const auto &entry = listCfg_.entry(i);
        list_->Append(entry.showName());
    }
}

MainWnd::~MainWnd() = default;

}
