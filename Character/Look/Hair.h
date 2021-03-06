//	This file is part of the continued Journey MMORPG client
//	Copyright (C) 2015-2019  Daniel Allendorf, Ryan Payton
//
//	This program is free software: you can redistribute it and/or modify
//	it under the terms of the GNU Affero General Public License as published by
//	the Free Software Foundation, either version 3 of the License, or
//	(at your option) any later version.
//
//	This program is distributed in the hope that it will be useful,
//	but WITHOUT ANY WARRANTY; without even the implied warranty of
//	MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
//	GNU Affero General Public License for more details.
//
//	You should have received a copy of the GNU Affero General Public License
//	along with this program.  If not, see <https://www.gnu.org/licenses/>.
#pragma once

#include "../../Graphics/Texture.h"
#include "BodyDrawInfo.h"

namespace ms {
class Hair {
public:
    enum Layer {
        NONE,
        DEFAULT,
        BELOWBODY,
        OVERHEAD,
        SHADE,
        BACK,
        BELOWCAP,
        NUM_LAYERS
    };

    Hair(int32_t hairid, const BodyDrawInfo &drawinfo);

    void draw(Stance::Id stance,
              Layer layer,
              uint8_t frame,
              const DrawArgument &args) const;

    const std::string &get_name() const;

    const std::string &getcolor() const;

private:
    std::unordered_map<uint8_t, Texture> stances_[Stance::Id::LENGTH]
                                                 [Layer::NUM_LAYERS];
    std::string name_;
    std::string color_;

    static const std::unordered_map<std::string, Layer> layers_by_name_;
};
}  // namespace ms