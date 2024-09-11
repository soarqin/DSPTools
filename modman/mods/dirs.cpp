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
    baseDir_ = wxString::Format(R"(%s\r2modmanPlus-local\DysonSphereProgram)", stdpaths.GetUserConfigDir());
}

wxString Dirs::GetProfileDir(const std::string &profile) const {
    if (profile.empty()) {
        return wxString::Format(R"(%s\profiles\)", baseDir_);
    }
    return wxString::Format(R"(%s\profiles\%s\)", baseDir_, wxString::FromUTF8(profile));
}

wxString Dirs::GetCachePath(const std::string &name, const int versionNumber[3], const std::string &filename) const {
    return wxString::Format(R"(%s\cache\%s\%d.%d.%d\%s)", baseDir_, wxString::FromUTF8(name), versionNumber[0], versionNumber[1], versionNumber[2], wxString::FromUTF8(filename));
}

}
