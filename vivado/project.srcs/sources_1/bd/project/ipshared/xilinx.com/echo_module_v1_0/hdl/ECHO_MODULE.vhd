
library IEEE;
use IEEE.STD_LOGIC_1164.ALL;
use ieee.numeric_std.all;
--use ieee.std_logic_arith.all;


entity ECHO_MODULE is
	generic(BITWIDTH: integer := 24;
				ADDRESSWIDTH: integer := 14);
	port(rst, clk, sample_clk, echo_en: in std_logic;
		AUDIO_IN_L: in std_logic_vector(BITWIDTH -1 downto 0);
		AUDIO_IN_R: in std_logic_vector(BITWIDTH -1 downto 0);
		AUDIO_IN_L_MEM: in std_logic_vector(BITWIDTH-1 downto 0);
		AUDIO_IN_R_MEM: in std_logic_vector(BITWIDTH-1 downto 0);
		mem_rst, wrt_en: out std_logic;
		add_a, add_b: out std_logic_vector(ADDRESSWIDTH -1 downto 0);
		AUDIO_OUT_L: out std_logic_vector(BITWIDTH -1 downto 0);
		AUDIO_OUT_R: out std_logic_vector(BITWIDTH -1 downto 0)
		);
end ECHO_MODULE;

architecture RTL of ECHO_MODULE is
signal wrt_ptr, rd_ptr: unsigned(ADDRESSWIDTH -1 downto 0) := (others => '0');
begin
	process(clk)
		begin
			if rising_edge(clk) then
				if (rst = '0') then
					wrt_ptr <= (others => '0');
					rd_ptr <= (others => '0');
				else
					if (echo_en = '0') then
						mem_rst <= '1';
						wrt_en <= '0';
						wrt_ptr <= (others => '0');
						rd_ptr <= (others => '0');
					elsif(wrt_ptr = rd_ptr)then
						rd_ptr <= wrt_ptr +1;
						
					else
					   mem_rst <= '0';
                       wrt_en <= '1';
					   if (sample_clk = '1') then
							add_a <= std_logic_vector(wrt_ptr);
							wrt_ptr <= ((wrt_ptr + 1) mod 16384);--16384
							rd_ptr <= ((rd_ptr + 1) mod 16384);
							add_b <= std_logic_vector(rd_ptr);
						end if;
						
					end if;
				end if;
			end if;
	end process;
	AUDIO_OUT_L <= std_logic_vector (unsigned(AUDIO_IN_L) + unsigned(AUDIO_IN_L_MEM));
	AUDIO_OUT_R <= std_logic_vector (unsigned(AUDIO_IN_R) + unsigned(AUDIO_IN_R_MEM));
end RTL;