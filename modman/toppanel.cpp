/*
 * Copyright (C) 2024, Soar Qin<soarchin@gmail.com>

 * Use of this source code is governed by an MIT-style
 * license that can be found in the LICENSE file or at
 * https://opensource.org/licenses/MIT.
 */

#include "toppanel.h"

#include "mods/profiles.h"

namespace modman {

TopPanel::TopPanel(wxWindow *parent): wxPanel(parent, wxID_ANY) {
    auto *sizer = new wxBoxSizer(wxHORIZONTAL);
    SetSizer(sizer);
    sizer->Add(new wxStaticText(this, wxID_ANY, wxT("Profile:")), 0, wxALIGN_CENTER_VERTICAL | wxALL, 5);
    mods::profiles.reload();
    wxArrayString arr;
    mods::profiles.iterate([&arr](const std::string &profile) {
        arr.Add(wxString::FromUTF8(profile));
    });
    profileList_ = new wxChoice(this, wxID_ANY, wxDefaultPosition, wxDefaultSize, arr, wxCB_SORT);
    profileList_->SetSelection(0);
    sizer->Add(profileList_, 1, wxALIGN_CENTER_VERTICAL | wxALL, 5);
}

void TopPanel::setOnProfileSelected(const std::function<void(const std::string &)> &callback) {
    callback_ = callback;
    profileList_->Bind(wxEVT_CHOICE, [this](wxCommandEvent &event) {
        callback_(profileList_->GetStringSelection().ToStdString(wxMBConvUTF8()));
    });
    auto index = profileList_->GetSelection();
    if (index != wxNOT_FOUND) {
        callback_(profileList_->GetString(index).ToStdString(wxMBConvUTF8()));
    }
}

}
