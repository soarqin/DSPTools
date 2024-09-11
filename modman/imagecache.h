/*
 * Copyright (C) 2024, Soar Qin<soarchin@gmail.com>

 * Use of this source code is governed by an MIT-style
 * license that can be found in the LICENSE file or at
 * https://opensource.org/licenses/MIT.
 */

#pragma once

#include <wx/bitmap.h>
#include <wx/string.h>

#include <unordered_map>
#include <string>

namespace modman {

class ImageCache {
public:
    wxBitmap *loadImage(const wxString &name);

private:
    std::unordered_map<wxString, wxBitmap> cache_;
};

extern ImageCache imageCache;

}
