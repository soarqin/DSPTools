/*
 * Copyright (C) 2024, Soar Qin<soarchin@gmail.com>

 * Use of this source code is governed by an MIT-style
 * license that can be found in the LICENSE file or at
 * https://opensource.org/licenses/MIT.
 */

#pragma once

#include <string>

namespace modman::mods {

class Dirs {
public:
    void Init();
    [[nodiscard]] std::wstring GetProfileDir(const std::wstring &profile) const;

private:
    std::wstring baseDir_;
};

extern Dirs dirs;

}
