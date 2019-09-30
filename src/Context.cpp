#include "include/Context.h"

Context::Context(State* state)
{
    this->state = state;
}

void Context::StateChanged()
{
    state->act();
}

Context::~Context()
{
}