/*
 * Licensed under the MIT License <http://opensource.org/licenses/MIT>.
 * SPDX-License-Identifier: MIT
 * Copyright (c) 2022 https://github.com/klappdev
 *
 * Permission is hereby  granted, free of charge, to any  person obtaining a copy
 * of this software and associated  documentation files (the "Software"), to deal
 * in the Software  without restriction, including without  limitation the rights
 * to  use, copy,  modify, merge,  publish, distribute,  sublicense, and/or  sell
 * copies  of  the Software,  and  to  permit persons  to  whom  the Software  is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in all
 * copies or substantial portions of the Software.
 *
 * THE SOFTWARE  IS PROVIDED "AS  IS", WITHOUT WARRANTY  OF ANY KIND,  EXPRESS OR
 * IMPLIED,  INCLUDING BUT  NOT  LIMITED TO  THE  WARRANTIES OF  MERCHANTABILITY,
 * FITNESS FOR  A PARTICULAR PURPOSE AND  NONINFRINGEMENT. IN NO EVENT  SHALL THE
 * AUTHORS  OR COPYRIGHT  HOLDERS  BE  LIABLE FOR  ANY  CLAIM,  DAMAGES OR  OTHER
 * LIABILITY, WHETHER IN AN ACTION OF  CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE  OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 */
#pragma once

#include <functional>

namespace kl::util::property {

    template<typename T>
    class Property {
    public:
        constexpr explicit Property(const T& value) : value(value) {}
        constexpr explicit Property(T&& value) : value(std::forward<T>(value)) {}
        ~Property() = default;

        constexpr Property(const Property&) = default;
        constexpr Property(Property&&) noexcept = default;

        constexpr Property& operator=(const Property&) = default;
        constexpr Property& operator=(Property&&) noexcept = default;

        constexpr Property& operator=(const T& newValue) {
            this->value = newValue;
            return *this;
        }

        constexpr Property& operator=(T&& newValue) {
            this->value = std::forward<T>(newValue);
            return *this;
        }

        constexpr operator T() const { return get(); }
        constexpr const T& get() { return value; }

        constexpr bool operator==(const T& other) const { return value == other; }
        constexpr auto operator<=>(const T& other) const { return value <=> other; }

    private:
        T value;
    };

    template<typename T>
    class Property<T&> {
    public:
        constexpr explicit Property(T& value) : value(std::ref(value)) {}

        constexpr Property& operator=(T& newValue) {
            value.get() = newValue;
            return *this;
        }

        constexpr operator T&() const { return get(); }
        constexpr T& get() const { return value.get(); }

        constexpr bool operator==(T& other) const { return value.get() == other; }
        constexpr auto operator<=>(T& other) const { return value.get() <=> other; }

    private:
        std::reference_wrapper<T> value;
    };

    template<typename T>
    class Property<T*> {
    public:
        constexpr explicit Property(T* value) : value(std::ref(*value)) {}

        constexpr Property& operator=(T* newValue) {
            value.get() = *newValue;
            return *this;
        }

        constexpr operator T*() const { return get(); }
        constexpr T* get() const { return value.get(); }

        constexpr bool operator==(T* other) const { return value.get() == *other; }
        constexpr auto operator<=>(T* other) const { return value.get() <=> *other; }

    private:
        std::reference_wrapper<T> value;
    };
}
