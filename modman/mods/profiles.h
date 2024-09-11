/*
 * Copyright (C) 2024, Soar Qin<soarchin@gmail.com>

 * Use of this source code is governed by an MIT-style
 * license that can be found in the LICENSE file or at
 * https://opensource.org/licenses/MIT.
 */

#pragma once

#include "listcfg.h"
#include <vector>
#include <functional>
#include <memory>

namespace modman::mods {

class Profiles {
public:
    void reload();
    void iterate(const std::function<void(const std::string &)> &callback) const;

    static std::shared_ptr<ListCfg> loadProfile(const std::string &profile);

private:
    std::vector<std::string> profiles_;
};

extern Profiles profiles;

}
