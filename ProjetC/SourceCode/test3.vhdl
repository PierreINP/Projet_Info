library IEEE ;
use IEEE.std_logic_1164.ALL ;
use ieee.numeric_std.all;

entity CompteurUpDown is
	port(	en,clk,resetn,Up_Down	: in STD_LOGIC; 
		count		: out STD_LOGIC_VECTOR(3 downto 0)) ; 
end CompteurUpDown; 

architecture CptUpDown of CompteurUpDown is

	variable count_int : std_logic_vector (3 downto 0):="100";
begin
	count_int := count_int - "0001";
	
process(resetn, clk)
	variable count_int : std_logic_vector (3 downto 0);
begin 
	if resetn = '0' then 
		count_int := "0000";
	elsif clk'EVENT and clk = '1' then 
		if en = '1' then
			if Up_Down ='1' then 
				if count_int ="1111" then 
					count_int := "0000";
				else 
					count_int := count_int + "0001";
				end if; 
			elsif Up_Down = '0' then 
				if count_int ="0000" then 
					count_int := "1111";
				else 
					count_int := count_int - "0001";
				end if;
			end if;
		end if;
	end if;
count <= std_logic_vector (count_int);
end process; 

count <= std_logic_vector (count_int);
end CptUpDown;
