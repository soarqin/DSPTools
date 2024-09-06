/*
 * Copyright (C) 2024, Soar Qin<soarchin@gmail.com>

 * Use of this source code is governed by an MIT-style
 * license that can be found in the LICENSE file or at
 * https://opensource.org/licenses/MIT.
 */

#pragma once

#include "mods/modentry.h"

#include <wx/wx.h>

namespace modman {

class ModInfo : public wxPanel {
public:
    ModInfo(const mods::ModEntry &entry, wxWindow *parent, wxWindowID id);

    void update();

    [[nodiscard]] inline const mods::ModEntry &entry() const { return entry_; }

private:
    const mods::ModEntry &entry_;
};

}
