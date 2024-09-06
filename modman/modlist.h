/*
 * Copyright (C) 2024, Soar Qin<soarchin@gmail.com>

 * Use of this source code is governed by an MIT-style
 * license that can be found in the LICENSE file or at
 * https://opensource.org/licenses/MIT.
 */

#pragma once

#include "modinfo.h"

#include <wx/wx.h>
#include <vector>

namespace modman {

class ModList : public wxScrolledWindow {
public:
    ModList(wxWindow *parent, wxWindowID id);

    int addMod(const mods::ModEntry &entry);
    void removeMod(int index);
    void updateMod(int index);
    int findMod(const std::string &name);
    void clearMods();

private:
    std::vector<ModInfo*> modList_;
};

}