/*
 * Copyright (C) 2024, Soar Qin<soarchin@gmail.com>

 * Use of this source code is governed by an MIT-style
 * license that can be found in the LICENSE file or at
 * https://opensource.org/licenses/MIT.
 */

#pragma once

#include <wx/string.h>
#include <string>

namespace modman::mods {

class Dirs {
public:
    void Init();
    [[nodiscard]] wxString GetProfileDir(const std::string &profile = "") const;
    [[nodiscard]] wxString GetCachePath(const std::string &name, const int versionNumber[3], const std::string &filename) const;

private:
    wxString baseDir_;
};

extern Dirs dirs;

}
