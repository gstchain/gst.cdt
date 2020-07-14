# GSTIO.CDT (Contract Development Toolkit)
## Version : 1.6.3

GSTIO.CDT is a toolchain for WebAssembly (WASM) and set of tools to facilitate contract writing for the GSTIO platform.  In addition to being a general purpose WebAssembly toolchain, [GSTIO](https://github.com/gstio/gst) specific optimizations are available to support building GSTIO smart contracts.  This new toolchain is built around [Clang 7](https://github.com/gstio/llvm), which means that GSTIO.CDT has the most currently available optimizations and analyses from LLVM, but as the WASM target is still considered experimental, some optimizations are not available or incomplete.

### Attention
GSTIO.CDT Version 1.3.x introduced quite a few breaking changes.  To have binary releases we needed to remove the concept of a core symbol from GSTIO.CDT. This meant drastic changes to symbol, asset and other types/functions that were connected to them. Since these changes would be disruptive, we decided to add as many disruptive changes needed for future contract writing, so that disruption should only occur once. Please read the **_Differences between Version 1.2.x and Version 1.3.x_** section of this readme.

### Binary Releases
GSTIO.CDT currently supports Mac OS X brew, Linux x86_64 Debian packages, and Linux x86_64 RPM packages.

**If you have previously installed GSTIO.CDT, please run the `uninstall` script (it is in the directory where you cloned GSTIO.CDT) before downloading and using the binary releases.**

#### Mac OS X Brew Install
```sh
$ brew tap gstio/gstio.cdt
$ brew install gstio.cdt
```

#### Mac OS X Brew Uninstall
```sh
$ brew remove gstio.cdt
```

#### Debian Package Install
```sh
$ wget https://github.com/gstio/gstio.cdt/releases/download/v1.6.3/gstio.cdt_1.6.3-1-ubuntu-18.04_amd64.deb
$ sudo apt install ./gstio.cdt_1.6.3-1-ubuntu-18.04_amd64.deb
```

#### Debian Package Uninstall
```sh
$ sudo apt remove gstio.cdt
```

#### RPM Package Install
```sh
$ wget https://github.com/gstio/gstio.cdt/releases/download/v1.6.3/gstio.cdt-1.6.3-1.el7.x86_64.rpm
$ sudo yum install ./gstio.cdt-1.6.3-1.el7.x86_64.rpm
```

#### RPM Package Uninstall
```sh
$ sudo yum remove gstio.cdt
```

### Guided Installation (Building from Scratch)
```sh
$ git clone --recursive https://github.com/gstio/gstio.cdt
$ cd gstio.cdt
$ ./build.sh
$ sudo ./install.sh
```

### Installed Tools
---
* gstio-cpp
* gstio-cc
* gstio-ld
* gstio-init
* gstio-abidiff
* gstio-wasm2wast
* gstio-wast2wasm
* gstio-ranlib
* gstio-ar
* gstio-objdump
* gstio-readelf

## Contributing

[Contributing Guide](./CONTRIBUTING.md)

[Code of Conduct](./CONTRIBUTING.md#conduct)

## License

[MIT](./LICENSE)

## Important

See [LICENSE](./LICENSE) for copyright and license terms.

All repositories and other materials are provided subject to the terms of this [IMPORTANT](./IMPORTANT.md) notice and you must familiarize yourself with its terms.  The notice contains important information, limitations and restrictions relating to our software, publications, trademarks, third-party resources, and forward-looking statements.  By accessing any of our repositories and other materials, you accept and agree to the terms of the notice.
