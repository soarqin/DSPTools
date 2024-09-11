/*
 * Copyright (C) 2024, Soar Qin<soarchin@gmail.com>

 * Use of this source code is governed by an MIT-style
 * license that can be found in the LICENSE file or at
 * https://opensource.org/licenses/MIT.
 */

#pragma once

#include "modentry.h"

#include <string>

namespace modman::mods {

class ListCfg {
public:
    bool load(const std::string &profile);
    bool save();

    [[nodiscard]] const std::string &profile() const { return profile_; }
    [[nodiscard]] int entryCount() const { return int(entries_.size()); }
    [[nodiscard]] const ModEntry &entry(int index) const { return entries_[index]; }
    [[nodiscard]] ModEntry &entry(int index) { return entries_[index]; }

private:
    std::string profile_;
    std::vector<ModEntry> entries_;
};

}
