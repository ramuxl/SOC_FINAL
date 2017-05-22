
LIBRARY ieee;
USE ieee.std_logic_1164.ALL;
 
-- Uncomment the following library declaration if using
-- arithmetic functions with Signed or Unsigned values
--USE ieee.numeric_std.ALL;
 
ENTITY ECHO_TB IS
END ECHO_TB;
 
ARCHITECTURE behavior OF EM_TB IS 
 
    -- Component Declaration for the Unit Under Test (UUT)
 
    COMPONENT ECHO_MODULE
    PORT(
         rst : IN  std_logic;
         clk : IN  std_logic;
         sample_clk : IN  std_logic;
         echo_en : IN  std_logic;
         AUDIO_IN_L : IN  std_logic_vector(23 downto 0);
         AUDIO_IN_R : IN  std_logic_vector(23 downto 0);
         AUDIO_IN_L_MEM : IN  std_logic_vector(23 downto 0);
         AUDIO_IN_R_MEM : IN  std_logic_vector(23 downto 0);
         mem_rst : OUT  std_logic;
         wrt_en : OUT  std_logic;
         add_a : OUT  std_logic_vector(12 downto 0);
         add_b : OUT  std_logic_vector(12 downto 0);
         AUDIO_OUT_L : OUT  std_logic_vector(23 downto 0);
         AUDIO_OUT_R : OUT  std_logic_vector(23 downto 0)
        );
    END COMPONENT;
    

   --Inputs
   signal rst : std_logic := '0';
   signal clk : std_logic := '0';
   signal sample_clk : std_logic := '0';
   signal echo_en : std_logic := '0';
   signal AUDIO_IN_L : std_logic_vector(23 downto 0) := (others => '0');
   signal AUDIO_IN_R : std_logic_vector(23 downto 0) := (others => '0');
   signal AUDIO_IN_L_MEM : std_logic_vector(23 downto 0) := (others => '0');
   signal AUDIO_IN_R_MEM : std_logic_vector(23 downto 0) := (others => '0');

 	--Outputs
   signal mem_rst : std_logic;
   signal wrt_en : std_logic;
   signal add_a : std_logic_vector(12 downto 0);
   signal add_b : std_logic_vector(12 downto 0);
   signal AUDIO_OUT_L : std_logic_vector(23 downto 0);
   signal AUDIO_OUT_R : std_logic_vector(23 downto 0);

   -- Clock period definitions
   constant clk_period : time := 10 ns;
   constant sample_clk_period : time := 35 ns;
 
BEGIN
 
	-- Instantiate the Unit Under Test (UUT)
   uut: ECHO_MODULE PORT MAP (
          rst => rst,
          clk => clk,
          sample_clk => sample_clk,
          echo_en => echo_en,
          AUDIO_IN_L => AUDIO_IN_L,
          AUDIO_IN_R => AUDIO_IN_R,
          AUDIO_IN_L_MEM => AUDIO_IN_L_MEM,
          AUDIO_IN_R_MEM => AUDIO_IN_R_MEM,
          mem_rst => mem_rst,
          wrt_en => wrt_en,
          add_a => add_a,
          add_b => add_b,
          AUDIO_OUT_L => AUDIO_OUT_L,
          AUDIO_OUT_R => AUDIO_OUT_R
        );

   -- Clock process definitions
   clk_process :process
   begin
		clk <= '0';
		wait for clk_period/2;
		clk <= '1';
		wait for clk_period/2;
   end process;
 
   sample_clk_process :process
   begin
		sample_clk <= '0';
		wait for sample_clk_period/2;
		sample_clk <= '1';
		wait for sample_clk_period/2;
   end process;
 

   -- Stimulus process
   stim_proc: process
   begin	
		wait for clk_period/2;
     rst <= '0';
      wait for clk_period;
		rst <= '1';
		echo_en <= '1';
		wait for clk_period*20;

      wait;
   end process;

END;
