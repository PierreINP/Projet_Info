library IEEE;
use ieee.std_logic_1164.all;
use IEEE.numeric_std.all;

entity full_add1 is
	port(
	    a,b , cin : in std_logic;
	    s,cout : out std_logic;
	);
end entity;

architecture arc of full_add1 is
	signal resultat : unsigned(1 downto 0);
begin
	resultat <= ('0' & a) + ( '0'&b) + ( '0' & cin);
	s <= resultat[0];
	cout <= resultat[1];
end arc;
