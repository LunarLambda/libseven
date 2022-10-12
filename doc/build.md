# libseven - Building, Installation, Linking

libseven itself can be built with a standard arm-none-eabi GCC toolchain and
GNU make.

## Build

Using a standard toolchain:

```sh
make
```

Or with meson:

```sh
meson --cross-file gba.txt build-meson
meson compile -C build-meson
```

Using a devkitARM toolchain:

```sh
make -f Makefile.dkp
```

If you get the message `please set DEVKITPRO in your environment`, make sure
your shell sources `/etc/profile.d/devkit-env.sh`.

## Installation

You can install libseven globally, into an existing devkitPRO installation.
This can make it easier to integrate into projects, see
"Linking" below.

### Makefile

```sh
make -f Makefile.dkp
sudo -E make -f Makefile.dkp install
```

Note: Windows/MSYS2 users don't need to use `sudo -E`.

## Uninstallation

All installed files are contained in one directory, generally
`$DEVKITPRO/libseven`. It can simply be removed, for example,
to clean-install from the Makefile.

## Linking

This method can be used if you would like to pull in libseven as a git
submodule, or if writing examples for the project.

- Set the path to libseven in your build system, i.e. in your Makefile
- Add `$(LIBSEVEN)/include` to your include search path.
- Add `$(LIBSEVEN)/lib` to your library search path.
- Add `-lseven` to your linker flags.

See the [template project](../examples/template/Makefile)
for how to set this up.

If using the devkitARM provided Makefiles, this will look like this:

```makefile
#---------------------------------------------------------------------------------
# any extra libraries we wish to link with the project
#---------------------------------------------------------------------------------
LIBS	:= -lmm -lseven


#---------------------------------------------------------------------------------
# list of directories containing libraries, this must be the top level containing
# include and lib
#---------------------------------------------------------------------------------
LIBDIRS	:=	$(DEVKITPRO)/libseven
```
