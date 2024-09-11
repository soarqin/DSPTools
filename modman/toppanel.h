/*
 * Copyright (C) 2024, Soar Qin<soarchin@gmail.com>

 * Use of this source code is governed by an MIT-style
 * license that can be found in the LICENSE file or at
 * https://opensource.org/licenses/MIT.
 */

#pragma once

#include <wx/wx.h>

#include <functional>

namespace modman {

class TopPanel: public wxPanel {
public:
    explicit TopPanel(wxWindow *parent);
    void setOnProfileSelected(const std::function<void(const std::string &)> &callback);

private:
    wxChoice *profileList_;
    std::function<void(const std::string &)> callback_;
};

}