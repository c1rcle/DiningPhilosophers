#pragma once

#include <mutex>

class Fork
{
public:
    int forkIdentifier;
    int philosopherIdentifier = -1;
    std::mutex mutex;
};