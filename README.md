## Statistical modules for [Ascent-beta](https://github.com/AnyarInc/ascent-beta) architecture

#### Why statistical modules specifically for Ascent?
The goal of this library is not to rewrite the already excellent distribution generators that are provided in the [random](http://www.cplusplus.com/reference/random/) standard template library.
Rather, these modules provide a wrapper to standard C++ generators so that they are easier and safer to use within Ascent's numerical integration.

Consideration must be made for how to apply time-based distributions, and some numerical methods evaluate the same points in time multiple times.

These statistical modules are designed to work with the addManipulator method in Ascent. See the included example.

As manipulators, statistical modules can be applied as discrete or continuous signals.
