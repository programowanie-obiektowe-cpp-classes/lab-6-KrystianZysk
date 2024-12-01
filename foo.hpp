#pragma once

#include "Human.hpp"

#include <list>
#include <vector>
#include <algorithm>

std::vector<char> foo(std::list<Human>& people) {
    std::for_each(people.begin(), people.end(), [](Human& person) {
        person.birthday();
    });

    std::vector<char> v;
    v.reserve(people.size());

    std::transform(people.rbegin(), people.rend(), std::back_inserter(v), [](const Human& person) {
        return person.isMonster() ? 'n' : 'y';
    });
    
    return v;
}