/*
 * Copyright (c) 2022 Soar Qin<soarchin@gmail.com>
 *
 * Use of this source code is governed by an MIT-style
 * license that can be found in the LICENSE file or at
 * https://opensource.org/licenses/MIT.
 */

#pragma once

#include "mods/listcfg.h"

#include "modlist.h"

#include <wx/wx.h>

namespace modman {

class MainWnd : public wxFrame {
public:
    MainWnd();

private:
    mods::ListCfg listCfg_;
    ModList *modList_;
};

}
