/*
 * Copyright (C) 2024, Soar Qin<soarchin@gmail.com>

 * Use of this source code is governed by an MIT-style
 * license that can be found in the LICENSE file or at
 * https://opensource.org/licenses/MIT.
 */

#include "modentry.h"

#include <fmt/format.h>

namespace modman::mods {

std::string ModEntry::showName() const {
    return fmt::format("{} {}.{}.{}", displayName.empty() ? name : displayName, versionNumber[0], versionNumber[1], versionNumber[2]);
}

}
