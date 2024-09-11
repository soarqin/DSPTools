/*
 * Copyright (C) 2024, Soar Qin<soarchin@gmail.com>

 * Use of this source code is governed by an MIT-style
 * license that can be found in the LICENSE file or at
 * https://opensource.org/licenses/MIT.
 */

#pragma once

#include "mods/modentry.h"

#include <wx/wx.h>
#include <wx/statline.h>

namespace modman {

class ModInfo : public wxPanel {
public:
    static void staticInit();
    ModInfo(const mods::ModEntry &entry, wxWindow *parent, wxWindowID id);

    void update();
    void updateEntry();

    [[nodiscard]] inline const mods::ModEntry &entry() const { return entry_; }

private:
    const mods::ModEntry &entry_;
    bool expanded_ = false;

    wxStaticText *nameText_ = nullptr, *authorText_ = nullptr;
    wxTextCtrl *descText_ = nullptr;
    wxButton *expandButton_ = nullptr;
    wxSizer *bottomSizer_ = nullptr;

    static wxBitmap bmpPlus;
    static wxBitmap bmpMinus;
};

}
