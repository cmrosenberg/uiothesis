# Files for "Leveraging DTrace for Runtime Verification"

This repository holds the code and data discussed in my master's thesis
"Leveraging DTrace for Runtime Verification" (forthcoming).

[Thesis document (PDF)](rosenberg_msc.pdf)

The repository is sorted according to the appendix in the thesis:

## Example scripts
* A.1 - [A generic `graphviz2dtrace`-generated script](A/explainscript.d)

## Code for the stack case study
* B.1 - [The faulty stack implementation](B/B.1/stack.c)
* B.2 - [The generated monitor](B/B.2/monitor.d)
* B.3 - [Stack running *x* iterations](B/B.3/stack_xiter.c)
* B.4 - [Stack with printf statements](B/B.4/stack_xiter_printf.c)
* B.4.1 - [Monitor for stack with printf statements](B/B.4/monitor.c)
* B.5 - [Stack with static probes](B/B.5/stack_xiter.c)
* B.5.1 - [Monitor for stack with static probes](B/B.5/monitor.d)
* B.5.2 - [Probe specification script for stack with static probes](B/B.5/probes.d)
* B.5.3 - [Generated probe header file for stack with static probes](B/B.5/probes.h)

## Code for the web server/database case study
* C.1 - [The Node.js web server](C/C.1/server.js)
* C.2 - [The database schema](C/C.2/database_schema.sql)
* C.3 - [Generated monitor using counters](C/C.3/monitor.d)
* C.3 - [Generated monitor using counters](C/C.3/monitor.d)

The `graphviz2dtrace` source code is available from the [dedicated graphviz2dtrace repository](https://github.com/cmrosenberg/graphviz2dtrace).
The version listed in the master's thesis is [release 0.1](https://github.com/cmrosenberg/graphviz2dtrace/releases/tag/0.1).

## System specifications

### Hardware

All code and sample runs have been run on a MacBook Pro (Retina, 13-inch, Late 2013) with the following specs:

```
  Model Name:   MacBook Pro
  Model Identifier: MacBookPro11,1
  Processor Name:   Intel Core i5
  Processor Speed:  2,4 GHz
  Number of Processors: 1
  Total Number of Cores:    2
  L2 Cache (per Core):  256 KB
  L3 Cache: 3 MB
  Memory:   8 GB
```

### Operating System

All code and sample runs have been run on Mac OS X El Capitan Version 10.11.4 with [System Integrity Protection](https://developer.apple.com/library/mac/documentation/Security/Conceptual/System_Integrity_Protection_Guide/ConfiguringSystemIntegrityProtection/ConfiguringSystemIntegrityProtection.html) turned off to enable DTrace and all of its features.

### DTrace

```shell
$ dtrace -V
dtrace: Sun D 1.12.1
```

### C compiler

```shell
$ clang --version
Apple LLVM version 7.3.0 (clang-703.0.31)
Target: x86_64-apple-darwin15.4.0
Thread model: posix
InstalledDir: /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin
```

### Node.js

Node.js is compiled with [homebrew](http://brew.sh/).

```shell
$ node --version
v5.5.0
```

### PostgreSQL

PostgreSQL is compiled with [homebrew](http://brew.sh/) with the `--with-dtrace` flag set.

```shell
$ postgres --version
postgres (PostgreSQL) 9.5.0
```

## License

All code in this repository is distributed with the [MIT license](https://opensource.org/licenses/MIT), see `LICENSE`.
