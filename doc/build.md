# libseven - Building, Installation, Linking

libseven itself can be built with a standard arm-none-eabi GCC toolchain and
GNU make.

The examples require use of a devkitARM toolchain.

## Build

Using a standard toolchain:

```sh
make
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
"Linking (Global)" below.

### Makefile

```sh
make -f Makefile.dkp
sudo -E make -f Makefile.dkp install
```

Note: Windows/MSYS2 users don't need to use `sudo -E`.

### PKGBUILD

Systems that use pacman as the standard package manager
(MSYS2, Arch Linux, Manjaro, etc.) can install libseven via the provided
[PKGBUILD](./pkgbuild/PKGBUILD).

```sh
cd pkgbuild
makepkg -si
```

If you are using `dkp-pacman` instead, you need to skip the dependency checks:

```sh
cd pkgbuild
makepkg -sid
```

Note to MacOS users: The `libseven-git` PKGBUILD cannot be built on MacOS due to
an incompatibility between `makepkg` and MacOS' `sed` command. Use the makefile
installation method instead.

## Uninstallation

All installed files are contained in one directory, generally
`$DEVKITPRO/libseven`. It can simply be removed, for example,
to clean-install from the Makefile.

## Linking (Local)

This method can be used if you would like to pull in libseven as a git
submodule, or if writing examples for the project.

- Set the path to libseven in your build system, i.e. in your Makefile
- Add `$(LIBSEVEN)/include` to your include search path.
- Add `$(LIBSEVEN)/build` to your library search path.
- Add `-lseven` to your linker flags.
- Configure your build system to automatically rebuild libseven if needed.

See the [template project](../examples/template/Makefile)
for how to set this up.

## Linking (Global)

This method requires installing libseven into your devkitPRO installation.
See [Installation](#installation).

- Add `$(DEVKITPRO)/libseven/include` to your include search path.
- Add `$(DEVKITPRO)/libseven/lib` to your library search path.
- Add `-lseven` to your linker flags.

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
