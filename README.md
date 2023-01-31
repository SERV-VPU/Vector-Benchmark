This benchmark is adapted from the AVA NN_functions benchmark (https://github.com/AI-Vector-Accelerator/NN_software)

# Vector-Benchmark
There are four versions of the same benchmark program in this repository, two designed to be run using the Spike RISC-V ISA simulator, and two designed to be run on our vector accelerated SERV.

For both Spike and SERV there is a version which does not utilise vector instructions, and a version that does utilise vector instructions. The Spike benchmarks are separate because our SERV implementation uses a custom _printf() function instead of the standard printf(). Functionally though all versions of the benchmark should be the same.

----

To run the Spike benchmarks:

Navigate to  
```Vector-Benchmark/Spike/Basic/riscV_build/```  
or  
```Vector-Benchmark/Spike/Vectorised/riscV_build/```  

And run the following command:  
` $ make spike `

This will compile and run the benchmark in Spike, It is assumed that Spike is in the $PATH, and the RISC-V proxy kernel binary is located in  
`/opt/riscv/riscv32-unknown-elf/bin`  
and was compiled with the  
`--with-arch=rv32imv`  
option.


-----

To compile the benchmarks for the SERV (The vectorised version requires our version of the SERV to run):

Navigate to  
```Vector-Benchmark/Basic```  
or  
```Vector-Benchmark/Vectorised```

and run the following command:  
` $ make hex `

This will produce a hex file called "nnalgo.hex" which assuming a valid FuseSoc/Verilator environment with our SERV and VPU, and the MDU (https://github.com/zeeshanrafique23/mdu) can be run with the following command:

` $ fusesoc run --target=verilator_tb --flag=vpu --flag=mdu servant --uart_baudrate=91000 --firmware=nnalgo.hex --memsize=6400000 `