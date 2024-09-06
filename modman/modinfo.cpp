/*
 * Copyright (C) 2024, Soar Qin<soarchin@gmail.com>

 * Use of this source code is governed by an MIT-style
 * license that can be found in the LICENSE file or at
 * https://opensource.org/licenses/MIT.
 */

#include "modinfo.h"

#include <wx/statline.h>
#include <wx/generic/statbmpg.h>

namespace modman {

ModInfo::ModInfo(const mods::ModEntry &entry, wxWindow *parent, wxWindowID id) : entry_(entry), wxPanel(parent, id) {
    this->SetWindowStyleFlag(wxSIMPLE_BORDER);

    auto *sizer = new wxBoxSizer(wxVERTICAL);
    SetSizer(sizer);

    auto *topSizer = new wxBoxSizer(wxHORIZONTAL);
    sizer->Add(topSizer, 1, wxEXPAND | wxALL, 2);

    sizer->Add(new wxStaticLine(this), 0, wxEXPAND | wxALL, 2);

    auto *bottomSizer = new wxBoxSizer(wxHORIZONTAL);
    sizer->Add(bottomSizer, 1, wxEXPAND | wxALL, 2);

    auto *bitmap = new wxGenericStaticBitmap(this, wxID_ANY, wxBitmap(entry.icon, wxBITMAP_TYPE_PNG), wxDefaultPosition, wxSize(48, 48));
    bitmap->SetScaleMode(wxStaticBitmap::Scale_AspectFill);
    topSizer->Add(bitmap, 0, wxLEFT | wxALIGN_CENTER_VERTICAL, 4);
    topSizer->Add(new wxStaticText(this, wxID_ANY, entry.showName()), 2, wxALIGN_CENTER_VERTICAL | wxLEFT, 10);
    topSizer->Add(new wxStaticText(this, wxID_ANY, entry.authorName), 1, wxALIGN_CENTER_VERTICAL, 0);
    bottomSizer->Add(new wxButton(this, wxID_ANY, "Uninstall"), 1, wxEXPAND, 0);
    bottomSizer->Add(new wxButton(this, wxID_ANY, "Disable"), 1, wxEXPAND, 0);
    bottomSizer->Add(new wxButton(this, wxID_ANY, "Website"), 1, wxEXPAND, 0);

    this->FitInside();
}

void ModInfo::update() {
}

}
