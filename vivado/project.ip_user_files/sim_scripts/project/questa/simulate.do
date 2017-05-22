onbreak {quit -f}
onerror {quit -f}

vsim -t 1ps -pli "/cad/x_16/Vivado/2016.1/lib/lnx64.o/libxil_vsim.so" -lib xil_defaultlib project_opt

do {wave.do}

view wave
view structure
view signals

do {project.udo}

run -all

quit -force
