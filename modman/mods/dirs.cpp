/*
 * Copyright (C) 2024, Soar Qin<soarchin@gmail.com>

 * Use of this source code is governed by an MIT-style
 * license that can be found in the LICENSE file or at
 * https://opensource.org/licenses/MIT.
 */

#include "dirs.h"

#include <wx/stdpaths.h>

namespace modman::mods {

Dirs dirs;

void Dirs::Init() {
    wxStandardPaths &stdpaths = wxStandardPaths::Get();
    baseDir_ = stdpaths.GetUserConfigDir().Append(L"\\r2modmanPlus-local\\DysonSphereProgram\\profiles\\");
}

std::wstring Dirs::GetProfileDir(const std::wstring &profile) const {
    return baseDir_ + profile + L'\\';
}

}
