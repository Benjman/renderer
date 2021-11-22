[Text]  Alignment
[Text]  Kerning
[Text]  Line gap
[Text]  calculated widths filling to max-widths not correct (try wrapping a line with 128 size text, then smaller)
[Text]  Text generator shouldn't be allocating buffers, the buffer owner should.

[Vert Attrib]   offset should accept a size_t, and the opengl call casts it to a void*. Currently everyone creating attributes has to make the cast.

[All]   Get rid of all `init()` methods to follow RAII better. Constructors should handle this stuff.
[All]   Comb through code to put `const` and `noexcept` where applicable.
