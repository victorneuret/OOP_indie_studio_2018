/*
** EPITECH PROJECT, 2019
** bomberman
** File description:
** TypeDetector.hpp
*/

#pragma once

namespace Engine::Utils {

    /*
     * This template can detect the type of a variable at compilation time.
     * It's useful when you are having doubts about auto or decltype deduction.
     *
     * Inspired from Scott Meyer's Effective Modern C++.
     */
    template<typename>
    class TypeDisplayer
#ifdef DEBUG
    ;
    // In order to display the type deduction at compile time, we need to force a compilation error.
#else
    {
    };

#if defined _MSC_VER
#pragma warning ("TypeDisplayer is a debug utility")
#elif defined __GNUC__
#warning TypeDisplayer is a debug utility
#endif
#endif
}
