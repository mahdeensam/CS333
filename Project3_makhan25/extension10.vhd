-- Task 1

-- Variable declarations
signal x : integer := 5;
signal y : real := 10.5;
signal z : string(1 to 13) := "Hello, VHDL!";

-- Block scoping
process
    variable blockVar : integer := 100;
begin
    if true then
        report "BlockVar: " & integer'image(blockVar); -- Output: 100
    end if;
end process;
-- -- Uncommenting the next line would result in an error
-- report "BlockVar: " & integer'image(blockVar); -- Error: blockVar is not defined

-- Function scoping
procedure myFunction is
    functionVar : integer := 200;
begin
    report "FunctionVar: " & integer'image(functionVar); -- Output: 200
end myFunction;
myFunction;
-- -- Uncommenting the next line would result in an error
-- report "FunctionVar: " & integer'image(functionVar); -- Error: functionVar is not defined

-- Module scoping
package MyModule is
    variable moduleVar : integer := 300;
    procedure printModuleVar;
end MyModule;

package body MyModule is
    procedure printModuleVar is
    begin
        report "ModuleVar: " & integer'image(moduleVar); -- Output: 300
    end printModuleVar;
end MyModule;

-- -- Uncommenting the next line would result in an error
-- report "ModuleVar: " & integer'image(MyModule.moduleVar); -- Error: moduleVar is not exported

-- Global scoping
constant globalVar : integer := 400;
begin
    report "GlobalVar: " & integer'image(globalVar); -- Output: 400
end;

-- Task 2

-- Binary search function
function binarySearch(arr : in integer_vector; target : in integer) return integer is
    variable left : integer := 1;
    variable right : integer := arr'length;
    variable mid : integer;
begin
    while left <= right loop
        mid := left + ((right - left) / 2);
        if arr(mid) = target then
            return mid;
        elsif arr(mid) < target then
            left := mid + 1;
        else
            right := mid - 1;
        end if;
    end loop;
    return -1; -- Target not found
end binarySearch;

-- Example usage
variable numbers : integer_vector(1 to 10) := (2, 4, 6, 8, 10, 12, 14, 16, 18, 20);
variable target : integer := 12;
variable result : integer;

begin
    result := binarySearch(numbers, target);
    if result /= -1 then
        report "Target " & integer'image(target) & " found at index " & integer'image(result);
    else
        report "Target " & integer'image(target) & " not found in the array";
    end if;
end;

-- Task 3

-- Basic built-in types
constant num : integer := 10;
constant dbl : real := 3.14;
constant bool : boolean := true;
constant chr : character := 'A';
constant str : string(1 to 13) := "Hello, VHDL!";

-- Aggregate types

-- Tuples (Not directly representable in VHDL)

-- Arrays
type integer_array is array(integer range <>) of integer;
variable arr : integer_array(1 to 5) := (1, 2, 3, 4, 5);

-- Dictionaries (Not directly representable in VHDL)

-- Custom types (Not directly representable in VHDL)

-- Operators (Only selected operators for demonstration)
variable a : integer := 10;
variable b : integer := 3;
variable c : real := 10.5;
variable d : real := 3.2;
variable e : string(1 to 5) := "Hello";
variable f : string(1 to 5) := "World";

begin
    report "a + b = " & integer'image(a + b); -- Output: 13
    report "a - b = " & integer'image(a - b); -- Output: 7
    report "c + d = " & real'image(c + d); -- Output: 13.7
    report "c - d = " & real'image(c - d); -- Output: 7.3
    report "e & ', ' & f = " & e & ", " & f; -- Output: Hello, World
end;
