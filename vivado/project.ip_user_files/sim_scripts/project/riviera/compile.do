vlib work
vlib riviera

vlib riviera/xil_defaultlib
vlib riviera/xpm
vlib riviera/processing_system7_bfm_v2_0_5
vlib riviera/lib_cdc_v1_0_2
vlib riviera/proc_sys_reset_v5_0_9
vlib riviera/generic_baseblocks_v2_1_0
vlib riviera/axi_infrastructure_v1_1_0
vlib riviera/axi_register_slice_v2_1_8
vlib riviera/fifo_generator_v13_1_0
vlib riviera/axi_data_fifo_v2_1_7
vlib riviera/axi_crossbar_v2_1_9
vlib riviera/blk_mem_gen_v8_3_2
vlib riviera/axi_lite_ipif_v3_0_3
vlib riviera/interrupt_control_v3_1_3
vlib riviera/axi_gpio_v2_0_10
vlib riviera/axi_protocol_converter_v2_1_8

vmap xil_defaultlib riviera/xil_defaultlib
vmap xpm riviera/xpm
vmap processing_system7_bfm_v2_0_5 riviera/processing_system7_bfm_v2_0_5
vmap lib_cdc_v1_0_2 riviera/lib_cdc_v1_0_2
vmap proc_sys_reset_v5_0_9 riviera/proc_sys_reset_v5_0_9
vmap generic_baseblocks_v2_1_0 riviera/generic_baseblocks_v2_1_0
vmap axi_infrastructure_v1_1_0 riviera/axi_infrastructure_v1_1_0
vmap axi_register_slice_v2_1_8 riviera/axi_register_slice_v2_1_8
vmap fifo_generator_v13_1_0 riviera/fifo_generator_v13_1_0
vmap axi_data_fifo_v2_1_7 riviera/axi_data_fifo_v2_1_7
vmap axi_crossbar_v2_1_9 riviera/axi_crossbar_v2_1_9
vmap blk_mem_gen_v8_3_2 riviera/blk_mem_gen_v8_3_2
vmap axi_lite_ipif_v3_0_3 riviera/axi_lite_ipif_v3_0_3
vmap interrupt_control_v3_1_3 riviera/interrupt_control_v3_1_3
vmap axi_gpio_v2_0_10 riviera/axi_gpio_v2_0_10
vmap axi_protocol_converter_v2_1_8 riviera/axi_protocol_converter_v2_1_8

vlog -work xil_defaultlib -v2k5 -sv "+incdir+../../../ipstatic/axi_infrastructure_v1_1/hdl/verilog" "+incdir+../../../ipstatic/processing_system7_bfm_v2_0/hdl" "+incdir+../../../ipstatic/axi_infrastructure_v1_1/hdl/verilog" "+incdir+../../../ipstatic/processing_system7_bfm_v2_0/hdl" \
"/cad/x_16/Vivado/2016.1/data/ip/xpm/xpm_cdc/hdl/xpm_cdc.sv" \
"/cad/x_16/Vivado/2016.1/data/ip/xpm/xpm_memory/hdl/xpm_memory_base.sv" \
"/cad/x_16/Vivado/2016.1/data/ip/xpm/xpm_memory/hdl/xpm_memory_dpdistram.sv" \
"/cad/x_16/Vivado/2016.1/data/ip/xpm/xpm_memory/hdl/xpm_memory_dprom.sv" \
"/cad/x_16/Vivado/2016.1/data/ip/xpm/xpm_memory/hdl/xpm_memory_sdpram.sv" \
"/cad/x_16/Vivado/2016.1/data/ip/xpm/xpm_memory/hdl/xpm_memory_spram.sv" \
"/cad/x_16/Vivado/2016.1/data/ip/xpm/xpm_memory/hdl/xpm_memory_sprom.sv" \
"/cad/x_16/Vivado/2016.1/data/ip/xpm/xpm_memory/hdl/xpm_memory_tdpram.sv" \

vcom -work xpm -93 \
"/cad/x_16/Vivado/2016.1/data/ip/xpm/xpm_VCOMP.vhd" \

vlog -work processing_system7_bfm_v2_0_5 -v2k5 "+incdir+../../../ipstatic/axi_infrastructure_v1_1/hdl/verilog" "+incdir+../../../ipstatic/processing_system7_bfm_v2_0/hdl" "+incdir+../../../ipstatic/axi_infrastructure_v1_1/hdl/verilog" "+incdir+../../../ipstatic/processing_system7_bfm_v2_0/hdl" \
"../../../ipstatic/processing_system7_bfm_v2_0/hdl/processing_system7_bfm_v2_0_arb_wr.v" \
"../../../ipstatic/processing_system7_bfm_v2_0/hdl/processing_system7_bfm_v2_0_arb_rd.v" \
"../../../ipstatic/processing_system7_bfm_v2_0/hdl/processing_system7_bfm_v2_0_arb_wr_4.v" \
"../../../ipstatic/processing_system7_bfm_v2_0/hdl/processing_system7_bfm_v2_0_arb_rd_4.v" \
"../../../ipstatic/processing_system7_bfm_v2_0/hdl/processing_system7_bfm_v2_0_arb_hp2_3.v" \
"../../../ipstatic/processing_system7_bfm_v2_0/hdl/processing_system7_bfm_v2_0_arb_hp0_1.v" \
"../../../ipstatic/processing_system7_bfm_v2_0/hdl/processing_system7_bfm_v2_0_ssw_hp.v" \
"../../../ipstatic/processing_system7_bfm_v2_0/hdl/processing_system7_bfm_v2_0_sparse_mem.v" \
"../../../ipstatic/processing_system7_bfm_v2_0/hdl/processing_system7_bfm_v2_0_reg_map.v" \
"../../../ipstatic/processing_system7_bfm_v2_0/hdl/processing_system7_bfm_v2_0_ocm_mem.v" \
"../../../ipstatic/processing_system7_bfm_v2_0/hdl/processing_system7_bfm_v2_0_intr_wr_mem.v" \
"../../../ipstatic/processing_system7_bfm_v2_0/hdl/processing_system7_bfm_v2_0_intr_rd_mem.v" \
"../../../ipstatic/processing_system7_bfm_v2_0/hdl/processing_system7_bfm_v2_0_fmsw_gp.v" \
"../../../ipstatic/processing_system7_bfm_v2_0/hdl/processing_system7_bfm_v2_0_regc.v" \
"../../../ipstatic/processing_system7_bfm_v2_0/hdl/processing_system7_bfm_v2_0_ocmc.v" \
"../../../ipstatic/processing_system7_bfm_v2_0/hdl/processing_system7_bfm_v2_0_interconnect_model.v" \
"../../../ipstatic/processing_system7_bfm_v2_0/hdl/processing_system7_bfm_v2_0_gen_reset.v" \
"../../../ipstatic/processing_system7_bfm_v2_0/hdl/processing_system7_bfm_v2_0_gen_clock.v" \
"../../../ipstatic/processing_system7_bfm_v2_0/hdl/processing_system7_bfm_v2_0_ddrc.v" \
"../../../ipstatic/processing_system7_bfm_v2_0/hdl/processing_system7_bfm_v2_0_axi_slave.v" \
"../../../ipstatic/processing_system7_bfm_v2_0/hdl/processing_system7_bfm_v2_0_axi_master.v" \
"../../../ipstatic/processing_system7_bfm_v2_0/hdl/processing_system7_bfm_v2_0_afi_slave.v" \
"../../../ipstatic/processing_system7_bfm_v2_0/hdl/processing_system7_bfm_v2_0_processing_system7_bfm.v" \

vlog -work xil_defaultlib -v2k5 "+incdir+../../../ipstatic/axi_infrastructure_v1_1/hdl/verilog" "+incdir+../../../ipstatic/processing_system7_bfm_v2_0/hdl" "+incdir+../../../ipstatic/axi_infrastructure_v1_1/hdl/verilog" "+incdir+../../../ipstatic/processing_system7_bfm_v2_0/hdl" \
"../../../../project.srcs/sources_1/bd/project/ip/project_processing_system7_0_0/sim/project_processing_system7_0_0.v" \

vcom -work lib_cdc_v1_0_2 -93 \
"../../../ipstatic/lib_cdc_v1_0/hdl/src/vhdl/cdc_sync.vhd" \

vcom -work proc_sys_reset_v5_0_9 -93 \
"../../../ipstatic/proc_sys_reset_v5_0/hdl/src/vhdl/upcnt_n.vhd" \
"../../../ipstatic/proc_sys_reset_v5_0/hdl/src/vhdl/sequence_psr.vhd" \
"../../../ipstatic/proc_sys_reset_v5_0/hdl/src/vhdl/lpf.vhd" \
"../../../ipstatic/proc_sys_reset_v5_0/hdl/src/vhdl/proc_sys_reset.vhd" \

vcom -work xil_defaultlib -93 \
"../../../../project.srcs/sources_1/bd/project/ip/project_rst_processing_system7_0_100M_0/sim/project_rst_processing_system7_0_100M_0.vhd" \
"../../../../project.srcs/sources_1/bd/project/ipshared/cyril_ip/zed_audio_v1_0/hdl/i3c2.vhd" \
"../../../../project.srcs/sources_1/bd/project/ipshared/cyril_ip/zed_audio_v1_0/hdl/adau1761_configuraiton_data.vhd" \
"../../../../project.srcs/sources_1/bd/project/ipshared/cyril_ip/zed_audio_v1_0/hdl/i2s_data_interface.vhd" \
"../../../../project.srcs/sources_1/bd/project/ipshared/cyril_ip/zed_audio_v1_0/hdl/i2c.vhd" \
"../../../../project.srcs/sources_1/bd/project/ipshared/cyril_ip/zed_audio_v1_0/hdl/ADAU1761_interface.vhd" \
"../../../../project.srcs/sources_1/bd/project/ipshared/cyril_ip/zed_audio_v1_0/hdl/clocking.vhd" \
"../../../../project.srcs/sources_1/bd/project/ipshared/cyril_ip/zed_audio_v1_0/hdl/adau1761_izedboard.vhd" \
"../../../../project.srcs/sources_1/bd/project/ipshared/cyril_ip/zed_audio_v1_0/hdl/audio_top.vhd" \
"../../../../project.srcs/sources_1/bd/project/ip/project_zed_audio_0_0/sim/project_zed_audio_0_0.vhd" \
"../../../../project.srcs/sources_1/bd/project/ipshared/xilinx.com/xlconstant_v1_1/xlconstant.vhd" \
"../../../../project.srcs/sources_1/bd/project/ip/project_xlconstant_0_0/sim/project_xlconstant_0_0.vhd" \
"../../../../project.srcs/sources_1/bd/project/hdl/project.vhd" \
"../../../../project.srcs/sources_1/bd/project/ipshared/xilinx.com/my_axi_audio_v1_0/hdl/MY_AXI_AUDIO_v1_0_S00_AXI.vhd" \
"../../../../project.srcs/sources_1/bd/project/ipshared/xilinx.com/my_axi_audio_v1_0/hdl/MY_AXI_AUDIO_v1_0.vhd" \
"../../../../project.srcs/sources_1/bd/project/ip/project_MY_AXI_AUDIO_0_0/sim/project_MY_AXI_AUDIO_0_0.vhd" \
"../../../../project.srcs/sources_1/bd/project/ipshared/tsotnep/volume_pregain_v1_0/src/MultiplierFP.vhd" \
"../../../../project.srcs/sources_1/bd/project/ipshared/tsotnep/volume_pregain_v1_0/src/AmplifierFP.vhd" \
"../../../../project.srcs/sources_1/bd/project/ipshared/tsotnep/volume_pregain_v1_0/src/Volume_Pregain_Top_Module.vhd" \
"../../../../project.srcs/sources_1/bd/project/ipshared/tsotnep/volume_pregain_v1_0/hdl/Volume_Pregain_v1_0_S00_AXI.vhd" \
"../../../../project.srcs/sources_1/bd/project/ipshared/tsotnep/volume_pregain_v1_0/hdl/Volume_Pregain_v1_0.vhd" \
"../../../../project.srcs/sources_1/bd/project/ip/project_Volume_Pregain_0_0/sim/project_Volume_Pregain_0_0.vhd" \
"../../../../project.srcs/sources_1/bd/project/ipshared/tsotnep/filter_iir_v1_0/src/Multiplier.vhd" \
"../../../../project.srcs/sources_1/bd/project/ipshared/tsotnep/filter_iir_v1_0/src/IIR_Biquad_II_v3.vhd" \
"../../../../project.srcs/sources_1/bd/project/ipshared/tsotnep/filter_iir_v1_0/src/Filter_Top_Level.vhd" \
"../../../../project.srcs/sources_1/bd/project/ipshared/tsotnep/filter_iir_v1_0/hdl/FILTER_IIR_v1_0_S00_AXI.vhd" \
"../../../../project.srcs/sources_1/bd/project/ipshared/tsotnep/filter_iir_v1_0/hdl/FILTER_IIR_v1_0.vhd" \
"../../../../project.srcs/sources_1/bd/project/ip/project_FILTER_IIR_0_0/sim/project_FILTER_IIR_0_0.vhd" \
"../../../../project.srcs/sources_1/bd/project/ip/project_FILTER_IIR_0_1/sim/project_FILTER_IIR_0_1.vhd" \
"../../../../project.srcs/sources_1/bd/project/ip/project_Volume_Pregain_0_1/sim/project_Volume_Pregain_0_1.vhd" \

vlog -work generic_baseblocks_v2_1_0 -v2k5 "+incdir+../../../ipstatic/axi_infrastructure_v1_1/hdl/verilog" "+incdir+../../../ipstatic/processing_system7_bfm_v2_0/hdl" "+incdir+../../../ipstatic/axi_infrastructure_v1_1/hdl/verilog" "+incdir+../../../ipstatic/processing_system7_bfm_v2_0/hdl" \
"../../../ipstatic/generic_baseblocks_v2_1/hdl/verilog/generic_baseblocks_v2_1_carry_and.v" \
"../../../ipstatic/generic_baseblocks_v2_1/hdl/verilog/generic_baseblocks_v2_1_carry_latch_and.v" \
"../../../ipstatic/generic_baseblocks_v2_1/hdl/verilog/generic_baseblocks_v2_1_carry_latch_or.v" \
"../../../ipstatic/generic_baseblocks_v2_1/hdl/verilog/generic_baseblocks_v2_1_carry_or.v" \
"../../../ipstatic/generic_baseblocks_v2_1/hdl/verilog/generic_baseblocks_v2_1_carry.v" \
"../../../ipstatic/generic_baseblocks_v2_1/hdl/verilog/generic_baseblocks_v2_1_command_fifo.v" \
"../../../ipstatic/generic_baseblocks_v2_1/hdl/verilog/generic_baseblocks_v2_1_comparator_mask_static.v" \
"../../../ipstatic/generic_baseblocks_v2_1/hdl/verilog/generic_baseblocks_v2_1_comparator_mask.v" \
"../../../ipstatic/generic_baseblocks_v2_1/hdl/verilog/generic_baseblocks_v2_1_comparator_sel_mask_static.v" \
"../../../ipstatic/generic_baseblocks_v2_1/hdl/verilog/generic_baseblocks_v2_1_comparator_sel_mask.v" \
"../../../ipstatic/generic_baseblocks_v2_1/hdl/verilog/generic_baseblocks_v2_1_comparator_sel_static.v" \
"../../../ipstatic/generic_baseblocks_v2_1/hdl/verilog/generic_baseblocks_v2_1_comparator_sel.v" \
"../../../ipstatic/generic_baseblocks_v2_1/hdl/verilog/generic_baseblocks_v2_1_comparator_static.v" \
"../../../ipstatic/generic_baseblocks_v2_1/hdl/verilog/generic_baseblocks_v2_1_comparator.v" \
"../../../ipstatic/generic_baseblocks_v2_1/hdl/verilog/generic_baseblocks_v2_1_mux_enc.v" \
"../../../ipstatic/generic_baseblocks_v2_1/hdl/verilog/generic_baseblocks_v2_1_mux.v" \
"../../../ipstatic/generic_baseblocks_v2_1/hdl/verilog/generic_baseblocks_v2_1_nto1_mux.v" \

vlog -work axi_infrastructure_v1_1_0 -v2k5 "+incdir+../../../ipstatic/axi_infrastructure_v1_1/hdl/verilog" "+incdir+../../../ipstatic/processing_system7_bfm_v2_0/hdl" "+incdir+../../../ipstatic/axi_infrastructure_v1_1/hdl/verilog" "+incdir+../../../ipstatic/processing_system7_bfm_v2_0/hdl" \
"../../../ipstatic/axi_infrastructure_v1_1/hdl/verilog/axi_infrastructure_v1_1_axi2vector.v" \
"../../../ipstatic/axi_infrastructure_v1_1/hdl/verilog/axi_infrastructure_v1_1_axic_srl_fifo.v" \
"../../../ipstatic/axi_infrastructure_v1_1/hdl/verilog/axi_infrastructure_v1_1_vector2axi.v" \

vlog -work axi_register_slice_v2_1_8 -v2k5 "+incdir+../../../ipstatic/axi_infrastructure_v1_1/hdl/verilog" "+incdir+../../../ipstatic/processing_system7_bfm_v2_0/hdl" "+incdir+../../../ipstatic/axi_infrastructure_v1_1/hdl/verilog" "+incdir+../../../ipstatic/processing_system7_bfm_v2_0/hdl" \
"../../../ipstatic/axi_register_slice_v2_1/hdl/verilog/axi_register_slice_v2_1_axic_register_slice.v" \
"../../../ipstatic/axi_register_slice_v2_1/hdl/verilog/axi_register_slice_v2_1_axi_register_slice.v" \

vlog -work fifo_generator_v13_1_0 -v2k5 "+incdir+../../../ipstatic/axi_infrastructure_v1_1/hdl/verilog" "+incdir+../../../ipstatic/processing_system7_bfm_v2_0/hdl" "+incdir+../../../ipstatic/axi_infrastructure_v1_1/hdl/verilog" "+incdir+../../../ipstatic/processing_system7_bfm_v2_0/hdl" \
"../../../ipstatic/fifo_generator_v13_1/simulation/fifo_generator_vlog_beh.v" \

vcom -work fifo_generator_v13_1_0 -93 \
"../../../ipstatic/fifo_generator_v13_1/hdl/fifo_generator_v13_1_rfs.vhd" \

vlog -work fifo_generator_v13_1_0 -v2k5 "+incdir+../../../ipstatic/axi_infrastructure_v1_1/hdl/verilog" "+incdir+../../../ipstatic/processing_system7_bfm_v2_0/hdl" "+incdir+../../../ipstatic/axi_infrastructure_v1_1/hdl/verilog" "+incdir+../../../ipstatic/processing_system7_bfm_v2_0/hdl" \
"../../../ipstatic/fifo_generator_v13_1/hdl/fifo_generator_v13_1_rfs.v" \

vlog -work axi_data_fifo_v2_1_7 -v2k5 "+incdir+../../../ipstatic/axi_infrastructure_v1_1/hdl/verilog" "+incdir+../../../ipstatic/processing_system7_bfm_v2_0/hdl" "+incdir+../../../ipstatic/axi_infrastructure_v1_1/hdl/verilog" "+incdir+../../../ipstatic/processing_system7_bfm_v2_0/hdl" \
"../../../ipstatic/axi_data_fifo_v2_1/hdl/verilog/axi_data_fifo_v2_1_axic_fifo.v" \
"../../../ipstatic/axi_data_fifo_v2_1/hdl/verilog/axi_data_fifo_v2_1_fifo_gen.v" \
"../../../ipstatic/axi_data_fifo_v2_1/hdl/verilog/axi_data_fifo_v2_1_axic_srl_fifo.v" \
"../../../ipstatic/axi_data_fifo_v2_1/hdl/verilog/axi_data_fifo_v2_1_axic_reg_srl_fifo.v" \
"../../../ipstatic/axi_data_fifo_v2_1/hdl/verilog/axi_data_fifo_v2_1_ndeep_srl.v" \
"../../../ipstatic/axi_data_fifo_v2_1/hdl/verilog/axi_data_fifo_v2_1_axi_data_fifo.v" \

vlog -work axi_crossbar_v2_1_9 -v2k5 "+incdir+../../../ipstatic/axi_infrastructure_v1_1/hdl/verilog" "+incdir+../../../ipstatic/processing_system7_bfm_v2_0/hdl" "+incdir+../../../ipstatic/axi_infrastructure_v1_1/hdl/verilog" "+incdir+../../../ipstatic/processing_system7_bfm_v2_0/hdl" \
"../../../ipstatic/axi_crossbar_v2_1/hdl/verilog/axi_crossbar_v2_1_addr_arbiter_sasd.v" \
"../../../ipstatic/axi_crossbar_v2_1/hdl/verilog/axi_crossbar_v2_1_addr_arbiter.v" \
"../../../ipstatic/axi_crossbar_v2_1/hdl/verilog/axi_crossbar_v2_1_addr_decoder.v" \
"../../../ipstatic/axi_crossbar_v2_1/hdl/verilog/axi_crossbar_v2_1_arbiter_resp.v" \
"../../../ipstatic/axi_crossbar_v2_1/hdl/verilog/axi_crossbar_v2_1_crossbar_sasd.v" \
"../../../ipstatic/axi_crossbar_v2_1/hdl/verilog/axi_crossbar_v2_1_crossbar.v" \
"../../../ipstatic/axi_crossbar_v2_1/hdl/verilog/axi_crossbar_v2_1_decerr_slave.v" \
"../../../ipstatic/axi_crossbar_v2_1/hdl/verilog/axi_crossbar_v2_1_si_transactor.v" \
"../../../ipstatic/axi_crossbar_v2_1/hdl/verilog/axi_crossbar_v2_1_splitter.v" \
"../../../ipstatic/axi_crossbar_v2_1/hdl/verilog/axi_crossbar_v2_1_wdata_mux.v" \
"../../../ipstatic/axi_crossbar_v2_1/hdl/verilog/axi_crossbar_v2_1_wdata_router.v" \
"../../../ipstatic/axi_crossbar_v2_1/hdl/verilog/axi_crossbar_v2_1_axi_crossbar.v" \

vlog -work xil_defaultlib -v2k5 "+incdir+../../../ipstatic/axi_infrastructure_v1_1/hdl/verilog" "+incdir+../../../ipstatic/processing_system7_bfm_v2_0/hdl" "+incdir+../../../ipstatic/axi_infrastructure_v1_1/hdl/verilog" "+incdir+../../../ipstatic/processing_system7_bfm_v2_0/hdl" \
"../../../../project.srcs/sources_1/bd/project/ip/project_xbar_0/sim/project_xbar_0.v" \

vcom -work xil_defaultlib -93 \
"../../../../project.srcs/sources_1/bd/project/ipshared/xilinx.com/xlconcat_v2_1/xlconcat.vhd" \
"../../../../project.srcs/sources_1/bd/project/ip/project_xlconcat_0_0/sim/project_xlconcat_0_0.vhd" \
"../../../../project.srcs/sources_1/bd/project/ipshared/xilinx.com/mixer_v1_0/mixer.vhd" \
"../../../../project.srcs/sources_1/bd/project/ip/project_mixer_0_0/sim/project_mixer_0_0.vhd" \
"../../../../project.srcs/sources_1/bd/project/ip/project_xlconcat_1_0/sim/project_xlconcat_1_0.vhd" \
"../../../../project.srcs/sources_1/bd/project/ip/project_xlconcat_2_0/sim/project_xlconcat_2_0.vhd" \

vlog -work blk_mem_gen_v8_3_2 -v2k5 "+incdir+../../../ipstatic/axi_infrastructure_v1_1/hdl/verilog" "+incdir+../../../ipstatic/processing_system7_bfm_v2_0/hdl" "+incdir+../../../ipstatic/axi_infrastructure_v1_1/hdl/verilog" "+incdir+../../../ipstatic/processing_system7_bfm_v2_0/hdl" \
"../../../../project.srcs/sources_1/bd/project/ip/project_ZedboardOLED_0_0_2/src/charLib/blk_mem_gen_v8_3_2/simulation/blk_mem_gen_v8_3.v" \
"../../../../project.srcs/sources_1/bd/project/ip/project_ZedboardOLED_0_0_2/src/charLib/sim/charLib.v" \

vlog -work xil_defaultlib -v2k5 "+incdir+../../../ipstatic/axi_infrastructure_v1_1/hdl/verilog" "+incdir+../../../ipstatic/processing_system7_bfm_v2_0/hdl" "+incdir+../../../ipstatic/axi_infrastructure_v1_1/hdl/verilog" "+incdir+../../../ipstatic/processing_system7_bfm_v2_0/hdl" \
"../../../../project.srcs/sources_1/bd/project/ipshared/tamu.edu/zedboardoled_v1_0/src/SpiCtrl.v" \
"../../../../project.srcs/sources_1/bd/project/ipshared/tamu.edu/zedboardoled_v1_0/src/Delay.v" \
"../../../../project.srcs/sources_1/bd/project/ipshared/tamu.edu/zedboardoled_v1_0/hdl/ZedboardOLED_v1_0_S00_AXI.v" \
"../../../../project.srcs/sources_1/bd/project/ipshared/tamu.edu/zedboardoled_v1_0/hdl/ZedboardOLED_v1_0.v" \
"../../../../project.srcs/sources_1/bd/project/ip/project_ZedboardOLED_0_0_2/sim/project_ZedboardOLED_0_0.v" \

vcom -work axi_lite_ipif_v3_0_3 -93 \
"../../../ipstatic/axi_lite_ipif_v3_0/hdl/src/vhdl/ipif_pkg.vhd" \
"../../../ipstatic/axi_lite_ipif_v3_0/hdl/src/vhdl/pselect_f.vhd" \
"../../../ipstatic/axi_lite_ipif_v3_0/hdl/src/vhdl/address_decoder.vhd" \
"../../../ipstatic/axi_lite_ipif_v3_0/hdl/src/vhdl/slave_attachment.vhd" \
"../../../ipstatic/axi_lite_ipif_v3_0/hdl/src/vhdl/axi_lite_ipif.vhd" \

vcom -work interrupt_control_v3_1_3 -93 \
"../../../ipstatic/interrupt_control_v3_1/hdl/src/vhdl/interrupt_control.vhd" \

vcom -work axi_gpio_v2_0_10 -93 \
"../../../ipstatic/axi_gpio_v2_0/hdl/src/vhdl/gpio_core.vhd" \
"../../../ipstatic/axi_gpio_v2_0/hdl/src/vhdl/axi_gpio.vhd" \

vcom -work xil_defaultlib -93 \
"../../../../project.srcs/sources_1/bd/project/ip/project_axi_gpio_0_0_1/sim/project_axi_gpio_0_0.vhd" \
"../../../../project.srcs/sources_1/bd/project/ip/project_axi_gpio_1_0/sim/project_axi_gpio_1_0.vhd" \

vlog -work xil_defaultlib -v2k5 "+incdir+../../../ipstatic/axi_infrastructure_v1_1/hdl/verilog" "+incdir+../../../ipstatic/processing_system7_bfm_v2_0/hdl" "+incdir+../../../ipstatic/axi_infrastructure_v1_1/hdl/verilog" "+incdir+../../../ipstatic/processing_system7_bfm_v2_0/hdl" \
"../../../../project.srcs/sources_1/bd/project/ip/project_blk_mem_gen_0_0/sim/project_blk_mem_gen_0_0.v" \
"../../../../project.srcs/sources_1/bd/project/ip/project_blk_mem_gen_0_1/sim/project_blk_mem_gen_0_1.v" \

vcom -work xil_defaultlib -93 \
"../../../../project.srcs/sources_1/bd/project/ipshared/xilinx.com/echo_module_v1_0/hdl/ECHO_MODULE.vhd" \
"../../../../project.srcs/sources_1/bd/project/ipshared/xilinx.com/echo_module_v1_0/hdl/ECHO_MODULE_v1_0_S00_AXI.vhd" \
"../../../../project.srcs/sources_1/bd/project/ipshared/xilinx.com/echo_module_v1_0/hdl/ECHO_MODULE_v1_0.vhd" \
"../../../../project.srcs/sources_1/bd/project/ip/project_ECHO_MODULE_0_1/sim/project_ECHO_MODULE_0_1.vhd" \

vlog -work axi_protocol_converter_v2_1_8 -v2k5 "+incdir+../../../ipstatic/axi_infrastructure_v1_1/hdl/verilog" "+incdir+../../../ipstatic/processing_system7_bfm_v2_0/hdl" "+incdir+../../../ipstatic/axi_infrastructure_v1_1/hdl/verilog" "+incdir+../../../ipstatic/processing_system7_bfm_v2_0/hdl" \
"../../../ipstatic/axi_protocol_converter_v2_1/hdl/verilog/axi_protocol_converter_v2_1_a_axi3_conv.v" \
"../../../ipstatic/axi_protocol_converter_v2_1/hdl/verilog/axi_protocol_converter_v2_1_axi3_conv.v" \
"../../../ipstatic/axi_protocol_converter_v2_1/hdl/verilog/axi_protocol_converter_v2_1_axilite_conv.v" \
"../../../ipstatic/axi_protocol_converter_v2_1/hdl/verilog/axi_protocol_converter_v2_1_r_axi3_conv.v" \
"../../../ipstatic/axi_protocol_converter_v2_1/hdl/verilog/axi_protocol_converter_v2_1_w_axi3_conv.v" \
"../../../ipstatic/axi_protocol_converter_v2_1/hdl/verilog/axi_protocol_converter_v2_1_b_downsizer.v" \
"../../../ipstatic/axi_protocol_converter_v2_1/hdl/verilog/axi_protocol_converter_v2_1_decerr_slave.v" \
"../../../ipstatic/axi_protocol_converter_v2_1/hdl/verilog/axi_protocol_converter_v2_1_b2s_simple_fifo.v" \
"../../../ipstatic/axi_protocol_converter_v2_1/hdl/verilog/axi_protocol_converter_v2_1_b2s_wrap_cmd.v" \
"../../../ipstatic/axi_protocol_converter_v2_1/hdl/verilog/axi_protocol_converter_v2_1_b2s_incr_cmd.v" \
"../../../ipstatic/axi_protocol_converter_v2_1/hdl/verilog/axi_protocol_converter_v2_1_b2s_wr_cmd_fsm.v" \
"../../../ipstatic/axi_protocol_converter_v2_1/hdl/verilog/axi_protocol_converter_v2_1_b2s_rd_cmd_fsm.v" \
"../../../ipstatic/axi_protocol_converter_v2_1/hdl/verilog/axi_protocol_converter_v2_1_b2s_cmd_translator.v" \
"../../../ipstatic/axi_protocol_converter_v2_1/hdl/verilog/axi_protocol_converter_v2_1_b2s_b_channel.v" \
"../../../ipstatic/axi_protocol_converter_v2_1/hdl/verilog/axi_protocol_converter_v2_1_b2s_r_channel.v" \
"../../../ipstatic/axi_protocol_converter_v2_1/hdl/verilog/axi_protocol_converter_v2_1_b2s_aw_channel.v" \
"../../../ipstatic/axi_protocol_converter_v2_1/hdl/verilog/axi_protocol_converter_v2_1_b2s_ar_channel.v" \
"../../../ipstatic/axi_protocol_converter_v2_1/hdl/verilog/axi_protocol_converter_v2_1_b2s.v" \
"../../../ipstatic/axi_protocol_converter_v2_1/hdl/verilog/axi_protocol_converter_v2_1_axi_protocol_converter.v" \

vlog -work xil_defaultlib -v2k5 "+incdir+../../../ipstatic/axi_infrastructure_v1_1/hdl/verilog" "+incdir+../../../ipstatic/processing_system7_bfm_v2_0/hdl" "+incdir+../../../ipstatic/axi_infrastructure_v1_1/hdl/verilog" "+incdir+../../../ipstatic/processing_system7_bfm_v2_0/hdl" \
"../../../../project.srcs/sources_1/bd/project/ip/project_auto_pc_0_1/sim/project_auto_pc_0.v" \

vlog -work xil_defaultlib "glbl.v"

