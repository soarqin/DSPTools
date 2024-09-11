/*
 * Copyright (C) 2024, Soar Qin<soarchin@gmail.com>

 * Use of this source code is governed by an MIT-style
 * license that can be found in the LICENSE file or at
 * https://opensource.org/licenses/MIT.
 */

#include "profiles.h"

#include "dirs.h"
#include <wx/dir.h>

namespace modman::mods {

Profiles profiles;

void Profiles::reload() {
    wxDir dir(wxString::FromUTF8(dirs.GetProfileDir("")));
    wxString subdir;
    for (bool cont = dir.GetFirst(&subdir, wxString(), wxDIR_DIRS | wxDIR_HIDDEN);
         cont; cont = dir.GetNext(&subdir)) {
        profiles_.push_back(subdir.ToStdString(wxMBConvUTF8()));
    }
}

void Profiles::iterate(const std::function<void(const std::string &)> &callback) const {
    for (const auto &profile: profiles_) {
        callback(profile);
    }
}

std::shared_ptr<ListCfg> Profiles::loadProfile(const std::string &profile) {
    auto listCfg = std::make_shared<ListCfg>();
    if (!listCfg->load(profile)) {
        return nullptr;
    }
    return listCfg;
}

}
