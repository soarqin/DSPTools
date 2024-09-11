/*
 * Copyright (C) 2024, Soar Qin<soarchin@gmail.com>

 * Use of this source code is governed by an MIT-style
 * license that can be found in the LICENSE file or at
 * https://opensource.org/licenses/MIT.
 */

#include "listcfg.h"

#include "dirs.h"

#include <intrin.h>
#define C4CORE_SINGLE_HDR_DEFINE_NOW
#include <c4core.hpp>
#define RYML_USE_ASSERT 1
#define RYML_SINGLE_HDR_DEFINE_NOW
#define RYML_DEFAULT_CALLBACK_USES_EXCEPTIONS 1
#include <ryml.hpp>

#include <fstream>
#include <filesystem>

namespace modman::mods {

static std::string getFileContent(const wxString &path) {
    std::filesystem::path p(path.ToStdWstring());
    std::ifstream ifs(p);
    if (!ifs) {
        return {};
    }
    return std::string {std::istreambuf_iterator<char>(ifs), std::istreambuf_iterator<char>()};
}

bool ListCfg::load(const std::string &profile) {
    profile_ = profile;
    entries_.clear();

    auto content = getFileContent(dirs.GetProfileDir(profile) + "mods_alt.yml");
    if (content.empty()) {
        content = getFileContent(dirs.GetProfileDir(profile) + "mods.yml");
        if (content.empty()) return false;
    }
    auto tree = ryml::parse_in_arena(content.c_str());
    for (const auto &node: tree.rootref()) {
        ModEntry entry;
        try {
            node["manifestVersion"] >> entry.manifestVersion;
            node["name"] >> entry.name;
            node["authorName"] >> entry.authorName;
            node["websiteUrl"] >> entry.websiteUrl;
            node["displayName"] >> entry.displayName;
            node["description"] >> entry.description;
            node["gameVersion"] >> entry.gameVersion;
            node["networkMode"] >> entry.networkMode;
            node["packageType"] >> entry.packageType;
            node["dependencies"] >> entry.dependencies;
            node["incompatibilities"] >> entry.incompatibilities;
            node["optionalDependencies"] >> entry.optionalDependencies;
            auto versionNode = node["versionNumber"];
            versionNode[0] >> entry.versionNumber[0];
            versionNode[1] >> entry.versionNumber[1];
            versionNode[2] >> entry.versionNumber[2];
            node["enabled"] >> entry.enabled;
            node["icon"] >> entry.icon;
            try { node["installMode"] >> entry.installMode; } catch (...) {}
            try { node["loaders"] >> entry.loaders; } catch (...) {}
            try { node["installedAtTime"] >> entry.installedAtTime; } catch (...) {}
            try { node["tags"] >> entry.tags; } catch (...) {}
        } catch (const std::exception &e) {
            continue;
        }
        entries_.push_back(entry);
    }
    return true;
}

bool ListCfg::save() {
    ryml::Tree tree;
    auto root = tree.rootref();
    root |= ryml::SEQ;
    for (const auto &entry: entries_) {
        auto node = root.append_child();
        node |= ryml::MAP;
        node["manifestVersion"] << entry.manifestVersion;
        node["name"] << entry.name;
        node["authorName"] << entry.authorName;
        node["websiteUrl"] << entry.websiteUrl;
        node["displayName"] << entry.displayName;
        node["description"] << entry.description;
        node["gameVersion"] << entry.gameVersion;
        node["networkMode"] << entry.networkMode;
        node["packageType"] << entry.packageType;
        node["installMode"] << entry.installMode;
        node["installedAtTime"] << entry.installedAtTime;
        node["loaders"] << entry.loaders;
        node["dependencies"] << entry.dependencies;
        node["incompatibilities"] << entry.incompatibilities;
        node["optionalDependencies"] << entry.optionalDependencies;
        auto versionNode = node["versionNumber"];
        versionNode |= ryml::SEQ;
        versionNode[0] << entry.versionNumber[0];
        versionNode[1] << entry.versionNumber[1];
        versionNode[2] << entry.versionNumber[2];
        node["enabled"] << entry.enabled;
        node["icon"] << entry.icon;
        node["tags"] << entry.tags;
    }
    std::filesystem::path p((dirs.GetProfileDir(profile_) + "mods_alt.yml").ToStdWstring());
    std::ofstream ofs(p);
    if (!ofs) return false;
    ofs << tree;
    return true;
}

}
