/*
 * Copyright (C) 2024, Soar Qin<soarchin@gmail.com>

 * Use of this source code is governed by an MIT-style
 * license that can be found in the LICENSE file or at
 * https://opensource.org/licenses/MIT.
 */

#include "imagecache.h"

namespace modman {

ImageCache imageCache;

wxBitmap *ImageCache::loadImage(const wxString &name) {
    auto it = cache_.find(name);
    if (it != cache_.end()) {
        return &it->second;
    }

    try {
        wxBitmap bitmap(name, wxBITMAP_TYPE_PNG);
        cache_[name] = bitmap;
        return &cache_[name];
    } catch (const std::exception &e) {
        static wxBitmap empty;
        return &empty;
    }
}

}
