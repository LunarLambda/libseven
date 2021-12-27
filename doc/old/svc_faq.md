# SVC Frequently Asked Questions

## Why are all the functions prefixed with svc?

To keep a consistent naming style. Besides, SVCs can be performance holes, so
it can be good to have a prefix to search for.

## Why no SystemCall macro?

In short, it is exceedingly difficult to provide inline definitions for SVCs
that interact correctly with the optimizer in all cases. The overhead for SVCs
is already quite large, so making them extern functions doesn't hurt
performance very much, but means calling them will *always* behave correctly.

Besides, with libseven being fully --gc-sections compatible, you only pull in
the 4-byte SVC stubs you actually use into your ROM.

## Why no standard svcDiv?

Div is already an incredibly slow function compared to faster division
implementations made by projects like [agbabi]. libseven provides a custom
implementation of the Div SVC that returns both the quotient and the remainder
in a struct, which requires some extra work to be AAPCS-compliant.

## Why no svcDivArm?

Because it's pointless. It just swaps the 2 arguments.

## What about SVC 39 and 42?

SVC 39 is the function used internally by svcHalt and svcStop. There's no real
reason to use it, and it's hard to give it a proper name.

SVC 42 is a completely undocumented function related to the sound driver
included in the BIOS. I'd be happy to include it in libseven if consensus can
be reached about what it does, if it's useful, what it should be named, so on.

[agbabi]: https://github.com/felixjones/agbabi/blob/master/source/idiv.s
