# Weaver



First, run

```
$ ./configure --disable-libglib --disable-libnet
```

Then make sure you have a compiled DPDK library with properly `RTE_SDK` variable.

```
$ cd dpdk_app && make
```

Run the following command to get it down.

```
$ ./build/procpkts -l <L> -n <N> --proc-type=auto -- -p <P> --num-procs=<NP> --proc-id=<PID>
```

* `L` the lcore id, starting from 1
* `N` num of cores, should equal to NP
* `P` the mask of ports, e.g., 0x3 (0b11) for port 0 and 1
* `NP` num of processes, should equal to `N`
* `PID` the id of the process, starting from 0

Note that you must run `NP` processes to get the forwarding function working.