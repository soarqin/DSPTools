/*
 * Copyright (C) 2024, Soar Qin<soarchin@gmail.com>

 * Use of this source code is governed by an MIT-style
 * license that can be found in the LICENSE file or at
 * https://opensource.org/licenses/MIT.
 */

#pragma once

#include <string>
#include <vector>
#include <cstdint>

namespace modman::mods {

struct ModEntry {
    std::string showName() const;

    int manifestVersion;
    std::string name;
    std::string authorName;
    std::string websiteUrl;
    std::string displayName;
    std::string description;
    std::string gameVersion;
    std::string networkMode;
    std::string packageType;
    std::string installMode;
    uint64_t installedAtTime = 0;
    std::vector<std::string> loaders;
    std::vector<std::string> dependencies;
    std::vector<std::string> incompatibilities;
    std::vector<std::string> optionalDependencies;
    std::vector<std::string> tags;
    int versionNumber[3] {};
    bool enabled = true;
    std::string icon;
};

}
