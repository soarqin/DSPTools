/*
 * Copyright (C) 2024, Soar Qin<soarchin@gmail.com>

 * Use of this source code is governed by an MIT-style
 * license that can be found in the LICENSE file or at
 * https://opensource.org/licenses/MIT.
 */

#include "modinfo.h"
#include "imagecache.h"

#include "mods/dirs.h"

#include <wx/generic/statbmpg.h>
#include <wx/artprov.h>

namespace modman {

wxBitmap ModInfo::bmpPlus;
wxBitmap ModInfo::bmpMinus;

inline static wxBitmap CreateScaledArtBitmap(const wxArtID &id, const wxSize &size) {
    return wxArtProvider::GetBitmap(id, wxASCII_STR(wxART_OTHER), size);
}

void ModInfo::staticInit() {
    bmpPlus = CreateScaledArtBitmap(wxART_PLUS, wxSize(16, 16));
    bmpMinus = CreateScaledArtBitmap(wxART_MINUS, wxSize(16, 16));
}

ModInfo::ModInfo(const mods::ModEntry &entry, wxWindow *parent, wxWindowID id) : entry_(entry), wxPanel(parent, id) {
    this->SetWindowStyleFlag(wxSIMPLE_BORDER);

    auto *sizer = new wxBoxSizer(wxVERTICAL);
    SetSizer(sizer);

    auto *topSizer = new wxBoxSizer(wxHORIZONTAL);
    sizer->Add(topSizer, 1, wxEXPAND | wxALL, 2);

    wxString iconFilename = entry.icon;
    if (!wxFileExists(iconFilename)) {
        // iconFilename.Append(".old");
        iconFilename = mods::dirs.GetCachePath(entry.name, entry.versionNumber, "icon.png");
    }
    wxBitmap *image = imageCache.loadImage(iconFilename);
    auto *bitmap = new wxGenericStaticBitmap(this, wxID_ANY, *image, wxDefaultPosition, wxSize(48, 48));
    bitmap->SetScaleMode(wxStaticBitmap::Scale_AspectFill);
    topSizer->Add(bitmap, 0, wxLEFT | wxALIGN_CENTER_VERTICAL, 4);
    nameText_ = new wxStaticText(this, wxID_ANY, wxString::FromUTF8(entry.showName()));
    topSizer->Add(nameText_, 2, wxALIGN_CENTER_VERTICAL | wxLEFT, 10);
    authorText_ = new wxStaticText(this, wxID_ANY, wxString::FromUTF8(entry.authorName));
    topSizer->Add(authorText_, 1, wxALIGN_CENTER_VERTICAL, 0);
    expandButton_ = new wxBitmapButton(this, wxID_ANY, bmpPlus, wxDefaultPosition, wxSize(24, 24), wxBORDER_NONE);
    expandButton_->SetWindowStyle(expandButton_->GetWindowStyle() & ~wxTAB_TRAVERSAL);
    expandButton_->Bind(wxEVT_BUTTON, [this](wxCommandEvent &event) {
        expanded_ = !expanded_;
        update();
    });
    topSizer->Add(expandButton_, 0,  wxRIGHT | wxALIGN_CENTER_VERTICAL, 5);
    descText_ = new wxTextCtrl(this, wxID_ANY, wxString::FromUTF8(entry.description), wxDefaultPosition, wxDefaultSize, wxTE_MULTILINE | wxTE_READONLY | wxTE_NO_VSCROLL | wxNO_BORDER);
    descText_->SetMinSize(wxSize(-1, 45));
    sizer->Add(descText_, 0, wxEXPAND | wxALL, 8);

    bottomSizer_ = new wxBoxSizer(wxHORIZONTAL);
    sizer->Add(bottomSizer_, 0, wxEXPAND | wxALL, 2);
    bottomSizer_->Add(new wxButton(this, wxID_ANY, "Uninstall"), 1, wxLEFT | wxRIGHT | wxEXPAND, 10);
    bottomSizer_->Add(new wxButton(this, wxID_ANY, "Disable"), 1, wxLEFT | wxRIGHT | wxEXPAND, 10);
    auto *websiteButton = new wxButton(this, wxID_ANY, "Website");
    websiteButton->Bind(wxEVT_BUTTON, [this](wxCommandEvent &event) {
        wxLaunchDefaultBrowser(wxString::FromUTF8(entry_.websiteUrl));
    });
    bottomSizer_->Add(websiteButton, 1, wxLEFT | wxRIGHT | wxEXPAND, 10);

    update();
}

void ModInfo::update() {
    expandButton_->SetBitmap(expanded_ ? bmpMinus : bmpPlus);
    expandButton_->SetToolTip(expanded_ ? "Hide details" : "Show details");
    descText_->Show(expanded_);
    bottomSizer_->Show(expanded_);
    GetParent()->FitInside();
}

void ModInfo::updateEntry() {
}

}
