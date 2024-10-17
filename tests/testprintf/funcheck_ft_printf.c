/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   funcheck_ft_printf.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nastamid <nastamid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 14:38:15 by nastamid          #+#    #+#             */
/*   Updated: 2024/10/17 15:41:01 by nastamid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stddef.h>
#include <limits.h>
#include <stdlib.h>

int main ()
{
   int k = 42;
	int *p = &k;
	unsigned int u_num = 4294967295; // Largest unsigned int value

	// %c: Character tests
	ft_printf("[Test_1] - Single character: %c", 'A');
	ft_printf("[Test_2] - Null character: %c", '\0');
	ft_printf("[Test_3] - Multiple characters: %c %c %c", 'A', 'B', 'C');
	ft_printf("[Test_4] - Character with integer: %c %d", 'Z', 100);

	// %s: String tests
	ft_printf("[Test_5] - Simple string: %s", "Hello, World!");
	ft_printf("[Test_6] - Empty string: %s", "");
	ft_printf("[Test_7] - String with special characters: %s", "This is a string with % and \\ characters.");
	ft_printf("[Test_8] - String with null: %s", NULL);
	ft_printf("[Test_9] - String with escape characters: %s", "Hello\nWorld\t!");

	// %p: Pointer tests
	ft_printf("[Test_10] - Pointer address: %p", p);
	ft_printf("[Test_11] - Null pointer: %p", NULL);
	ft_printf("[Test_12] - Pointer to static variable: %p", &k);
	ft_printf("[Test_13] - Pointer to function: %p", &main);

	// %d: Decimal number tests
	ft_printf("[Test_14] - Positive decimal: %d", 12345);
	ft_printf("[Test_15] - Negative decimal: %d", -12345);
	ft_printf("[Test_16] - Zero decimal: %d", 0);
	ft_printf("[Test_17] - INT_MAX decimal: %d", INT_MAX);
	ft_printf("[Test_18] - INT_MIN decimal: %d", INT_MIN);
	ft_printf("[Test_19] - Large positive decimal: %d", 2147483647);
	ft_printf("[Test_20] - Large negative decimal: %d", -2147483647);

	// %i: Integer tests
	ft_printf("[Test_21] - Positive integer: %i", 67890);
	ft_printf("[Test_22] - Negative integer: %i", -67890);
	ft_printf("[Test_23] - Zero integer: %i", 0);
	ft_printf("[Test_24] - INT_MAX integer: %i", INT_MAX);
	ft_printf("[Test_25] - INT_MIN integer: %i", INT_MIN);

	// %u: Unsigned integer tests
	ft_printf("[Test_26] - Unsigned int max: %u", u_num);
	ft_printf("[Test_27] - Unsigned zero: %u", 0);
	ft_printf("[Test_28] - Small unsigned: %u", 42);
	ft_printf("[Test_29] - UINT_MAX unsigned: %u", UINT_MAX);

	// %x: Hexadecimal (lowercase) tests
	ft_printf("[Test_30] - Hexadecimal lowercase (positive): %x", 255); // Should print "ff"
	ft_printf("[Test_31] - Hexadecimal lowercase (zero): %x", 0); // Should print "0"
	ft_printf("[Test_31] - Hexadecimal lowercase (negative): %x", -255); // Should print "0"
	ft_printf("[Test_32] - Hexadecimal for large number: %x", 0x12345678);
	ft_printf("[Test_33] - Hexadecimal INT_MAX: %x", INT_MAX);
	ft_printf("[Test_34] - Hexadecimal INT_MIN: %x", INT_MIN);
	ft_printf("[Test_35] - Hexadecimal UINT_MAX: %x", UINT_MAX);

	ft_printf("[Test_36] - Hexadecimal lowercase (LONG_MAX): %x", LONG_MAX);  // Should print the hexadecimal representation of LONG_MAX
	ft_printf("[Test_37] - Hexadecimal lowercase (LONG_MIN): %x", LONG_MIN);  // Should print the hexadecimal representation of LONG_MIN
	ft_printf("[Test_38] - Hexadecimal lowercase (ULONG_MAX): %x", ULONG_MAX);  // Should print the hexadecimal representation of ULONG_MAX
	ft_printf("[Test_39] - Hexadecimal lowercase (9223372036854775807LL): %x", 9223372036854775807LL);  // Should print hex for largest signed 64-bit integer
	ft_printf("[Test_40] - Hexadecimal lowercase (various large values): %x %x %x %x %x", INT_MAX, INT_MIN, LONG_MAX, LONG_MIN, ULONG_MAX);  // Mix of large, small, and negative values

	// %X: Hexadecimal (uppercase) tests
	ft_printf("[Test_41] - Hexadecimal uppercase (positive): %X", 255); // Should print "FF"
	ft_printf("[Test_42] - Hexadecimal uppercase (zero): %X", 0); // Should print "0"
	ft_printf("[Test_42] - Hexadecimal uppercase (negative): %X", -255); // Should print "0"
	ft_printf("[Test_43] - Hexadecimal uppercase for large number: %X", 0x12345678);
	ft_printf("[Test_44] - Hexadecimal uppercase INT_MAX: %X", INT_MAX);
	ft_printf("[Test_45] - Hexadecimal uppercase INT_MIN: %X", INT_MIN);
	ft_printf("[Test_46] - Hexadecimal uppercase UINT_MAX: %X", UINT_MAX);

	ft_printf("[Test_47] - Hexadecimal uppercase (LONG_MAX): %X", LONG_MAX);  // Should print the hexadecimal representation of LONG_MAX in uppercase
	ft_printf("[Test_48] - Hexadecimal uppercase (LONG_MIN): %X", LONG_MIN);  // Should print the hexadecimal representation of LONG_MIN in uppercase
	ft_printf("[Test_49] - Hexadecimal uppercase (ULONG_MAX): %X", ULONG_MAX);  // Should print the hexadecimal representation of ULONG_MAX in uppercase
	ft_printf("[Test_50] - Hexadecimal uppercase (9223372036854775807LL): %X", 9223372036854775807LL);  // Uppercase hex for largest signed 64-bit integer
	ft_printf("[Test_51] - Hexadecimal uppercase (various large values): %X %X %X %X %X", INT_MAX, INT_MIN, LONG_MAX, LONG_MIN, ULONG_MAX);  // Mix of large, small, and negative values

	// %%: Percent sign tests
	ft_printf("[Test_52] - Single percent sign: %%");
	ft_printf("[Test_53] - Multiple percent signs: %% %% %%");

	// Mixed format specifier tests
	ft_printf("[Test_54] - Mixed formats: %c %s %d %p %% %x", 'X', "Testing", 42, p, 255);

	// Additional edge cases
	ft_printf("[Test_55] - Negative value in unsigned format: %u", -1); // Should print a large unsigned number
	ft_printf("[Test_56] - Negative pointer: %p", (void *)-1); // Undefined behavior but tested


	// %%: Percent sign tests
	ft_printf("[Test_57] - Single percent sign: %%");
	ft_printf("[Test_58] - Multiple percent signs: %% %% %%");

	// Mixed format specifier tests
	ft_printf("[Test_59] - Mixed formats: %c %s %d %p %% %x", 'X', "Testing", 42, p, 255);

	// Additional edge cases
	ft_printf("[Test_60] - Negative value in unsigned format: %u", -1); // Should print a large unsigned number
	ft_printf("[Test_61] - Negative pointer: %p", (void *)-1); // Undefined behavior but tested

	// Combining specifiers
	ft_printf("[Test_63] - Combined specifiers: %d %u %x %X", 12345, 12345U, 0xabc, 0xABC);
	ft_printf("[Test_64] - Negative decimal with unsigned: %d %u", -1000, -1000);

	// Large value tests
	ft_printf("[Test_65] - Large positive value: %d", 2147483647); // INT_MAX
	ft_printf("[Test_66] - Large negative value: %d", -2147483647); // -INT_MAX
	ft_printf("[Test_67] - Unsigned large value: %u", 4294967295U); // UINT_MAX

	// // Null strings and edge cases
	// ft_printf("[Test_53] - Null string: %s", NULL);

	// // Special width/precision tests (optional)
	// ft_printf("[Test_54] - Padded number with width: %10d", 42); // Optional: Field width
	// ft_printf("[Test_55] - Negative width (left-align): %-10d", 42); // Optional: Left-align
	// ft_printf("[Test_56] - Zero-padded width: %010d", 42); // Optional: Zero-padding

	// Escaped format specifiers
	ft_printf("[Test_68] - Escaped format specifiers: %%d %%s %%p %%x");

	//Undefined behavior tests for ft_printf

	//%d with wrong type (string instead of int)
	ft_printf("[UB_Test_1] - Wrong type for %%d: %d", "Hello");

	// %s with wrong type (int instead of string)
	//ft_printf("[UB_Test_2] - Wrong type for %%s: %s", 42);

	// %p with wrong type (int instead of pointer)
	ft_printf("[UB_Test_3] - Wrong type for %%p: %p", 100);

	// Invalid pointer dereferencing
	int *invalid_ptr = (int *)0xDEADBEEF; // Invalid memory address
	ft_printf("[UB_Test_4] - Invalid pointer address: %p", invalid_ptr);

	// Overlapping string (string that’s not properly null-terminated)
	char overlapping_str[10] = "Test";
	ft_printf("[UB_Test_5] - Overlapping string: %s", &overlapping_str[1]);

	// Negative pointer
	ft_printf("[UB_Test_6] - Negative pointer: %p", (void *)-1);


}