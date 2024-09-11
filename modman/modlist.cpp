/*
 * Copyright (C) 2024, Soar Qin<soarchin@gmail.com>

 * Use of this source code is governed by an MIT-style
 * license that can be found in the LICENSE file or at
 * https://opensource.org/licenses/MIT.
 */

#include "modlist.h"

namespace modman {

ModList::ModList(wxWindow *parent, wxWindowID id) : wxScrolledWindow(parent, id) {
    auto *sizer = new wxBoxSizer(wxVERTICAL);
    SetSizer(sizer);
    SetScrollRate(0, 20);
}

int ModList::addMod(const mods::ModEntry &entry) {
    auto *modInfo = new ModInfo(entry, this, wxID_ANY);
    GetSizer()->Add(modInfo, 0, wxEXPAND | wxALL, 2);

    modList_.emplace_back(modInfo);
    return int(modList_.size()) - 1;
}

void ModList::removeMod(int index) {
    if (index < 0 || index >= modList_.size()) {
        return;
    }

    auto *modInfo = modList_[index];
    GetSizer()->Detach(modInfo);
    modInfo->Destroy();
    modList_.erase(modList_.begin() + index);
}

void ModList::updateMod(int index) {
    if (index < 0 || index >= modList_.size()) {
        return;
    }

    auto *modInfo = modList_[index];
    modInfo->updateEntry();
}

int ModList::findMod(const std::string &name) {
    auto size = int(modList_.size());
    for (int i = 0; i < size; i++) {
        const auto &entry = modList_[i]->entry();
        if (entry.name == name) {
            return i;
        }
    }
    return -1;
}

void ModList::clearMods() {
    for (auto *modInfo : modList_) {
        GetSizer()->Detach(modInfo);
        modInfo->Destroy();
    }
    modList_.clear();
}

}
