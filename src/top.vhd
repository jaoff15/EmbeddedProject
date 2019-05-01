library ieee;
use ieee.std_logic_1164.all;
use ieee.numeric_std.all;
use ieee.std_logic_unsigned.all;


entity top is
    port ( clk          : in  std_logic := '0';
           row          : out std_logic_vector(7 downto 0);
           red          : out std_logic_vector(7 downto 0); 
           green        : out std_logic_vector(7 downto 0);
           blue         : out std_logic_vector(7 downto 0);
           Vaux14_0_v_n : in STD_LOGIC;
           Vaux14_0_v_p : in STD_LOGIC;
           Vaux15_0_v_n : in STD_LOGIC;
           Vaux15_0_v_p : in STD_LOGIC;
           Vaux7_0_v_n : in STD_LOGIC;
           Vaux7_0_v_p : in STD_LOGIC;
           Vaux6_0_v_n : in STD_LOGIC;
           Vaux6_0_v_p : in STD_LOGIC      
        );
end top;

architecture Behavioral of top is

    component led_matrix is
        port( 
            clk     : in  std_logic;
            row     : out std_logic_vector(7 downto 0);
            red     : out std_logic_vector(7 downto 0);
            green   : out std_logic_vector(7 downto 0);
            blue    : out std_logic_vector(7 downto 0);
            Vaux14_0_v_n : in STD_LOGIC;
            Vaux14_0_v_p : in STD_LOGIC;
            Vaux15_0_v_n : in STD_LOGIC;
            Vaux15_0_v_p : in STD_LOGIC;
            Vaux7_0_v_n : in STD_LOGIC;
            Vaux7_0_v_p : in STD_LOGIC;
            Vaux6_0_v_n : in STD_LOGIC;
            Vaux6_0_v_p : in STD_LOGIC
            );
    end component;

begin

led_matrix0: led_matrix
port map(
    clk         => clk,
    row         => row,
    red         => red,
    green       => green,
    blue        => blue,
    Vaux14_0_v_n        => Vaux14_0_v_n,
    Vaux14_0_v_p        => Vaux14_0_v_p,
    Vaux15_0_v_n        => Vaux15_0_v_n,
    Vaux15_0_v_p        => Vaux15_0_v_p,
    Vaux7_0_v_n         => Vaux7_0_v_n,
    Vaux7_0_v_p         => Vaux7_0_v_p,
    Vaux6_0_v_n         => Vaux6_0_v_n,
    Vaux6_0_v_p         => Vaux6_0_v_p
    );



end Behavioral;