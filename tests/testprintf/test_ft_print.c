/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_print.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nastamid <nastamid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 17:56:47 by codespace         #+#    #+#             */
/*   Updated: 2024/10/17 15:39:28 by nastamid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <limits.h>
#include "ft_printf.h"


// Function to capture the output of ft_printf
static char* capture_ft_printf_output(const char *format, ...)
{
    va_list args;
    char buffer[2048] = {0}; // Buffer to store captured output

    // Save the original stdout
    int saved_stdout = dup(STDOUT_FILENO);

    // Create a pipe to capture the output
    int pipefd[2];
    if (pipe(pipefd) == -1)
    {
        perror("pipe");
        return NULL;
    }

    // Redirect stdout to the write end of the pipe
    dup2(pipefd[1], STDOUT_FILENO);
    close(pipefd[1]);  // Close the write end of the pipe, it's now duplicated

    // Initialize va_list and call ft_printf
    va_start(args, format);
    vft_printf(format, args);  // Pass the format and arguments to ft_printf
    va_end(args);

    // Restore the original stdout
    fflush(stdout);
    dup2(saved_stdout, STDOUT_FILENO);
    close(saved_stdout);

    // Read the captured output from the pipe
    read(pipefd[0], buffer, sizeof(buffer) - 1);
    close(pipefd[0]);  // Close the read end of the pipe

    // Duplicate the buffer content into a heap-allocated string to return
    char *captured_output = strdup(buffer);
    return captured_output; // Remember to free this in the calling code
}

// Function to compare outputs of ft_printf and printf
static void	compare_outputs(const char *format, ...)
{
	va_list	args;

	char* ft_output;  // Buffer to hold output of ft_printf
	char std_output[2048]; // Buffer to hold output of printf
	 int ft_chars, std_chars;
	// Test ft_printf
	va_start(args, format);
	ft_output = capture_ft_printf_output(format);
	va_end(args);
	// Test printf
	va_start(args, format);
	vsnprintf(std_output, sizeof(std_output), format, args);
	va_end(args);
	// Compare outputs
	ft_chars = ft_strlen(ft_output);
	std_chars = ft_strlen(std_output);
	 if (strcmp(ft_output, std_output) == 0 && ft_chars == std_chars)
    {
        printf("\033[0;32m[PASS]\033[0m Output: %s (chars printed: %d)\n", ft_output, ft_chars);
    }
    else
    {
        printf("\033[0;31m[FAIL]\033[0m Outputs or printed character count do not match!\n");
        printf("ft_printf: %s (chars printed: %d)\n", ft_output, ft_chars);
        printf("printf:    %s (chars printed: %d)\n", std_output, std_chars);
        printf("\n");
    }
	free (ft_output);
}
int	main(void)
{
	int k = 42;
	int *p = &k;
	unsigned int u_num = 4294967295; // Largest unsigned int value

	// %c: Character tests
	compare_outputs("[Test_1] - Single character: %c", 'A');
	compare_outputs("[Test_2] - Null character: %c", '\0');
	compare_outputs("[Test_3] - Multiple characters: %c %c %c", 'A', 'B', 'C');
	compare_outputs("[Test_4] - Character with integer: %c %d", 'Z', 100);

	// %s: String tests
	compare_outputs("[Test_5] - Simple string: %s", "Hello, World!");
	compare_outputs("[Test_6] - Empty string: %s", "");
	compare_outputs("[Test_7] - String with special characters: %s", "This is a string with % and \\ characters.");
	compare_outputs("[Test_8] - String with null: %s", NULL);
	compare_outputs("[Test_9] - String with escape characters: %s", "Hello\nWorld\t!");

	// %p: Pointer tests
	compare_outputs("[Test_10] - Pointer address: %p", p);
	compare_outputs("[Test_11] - Null pointer: %p", NULL);
	compare_outputs("[Test_12] - Pointer to static variable: %p", &k);
	compare_outputs("[Test_13] - Pointer to function: %p", &main);

	// %d: Decimal number tests
	compare_outputs("[Test_14] - Positive decimal: %d", 12345);
	compare_outputs("[Test_15] - Negative decimal: %d", -12345);
	compare_outputs("[Test_16] - Zero decimal: %d", 0);
	compare_outputs("[Test_17] - INT_MAX decimal: %d", INT_MAX);
	compare_outputs("[Test_18] - INT_MIN decimal: %d", INT_MIN);
	compare_outputs("[Test_19] - Large positive decimal: %d", 2147483647);
	compare_outputs("[Test_20] - Large negative decimal: %d", -2147483647);

	// %i: Integer tests
	compare_outputs("[Test_21] - Positive integer: %i", 67890);
	compare_outputs("[Test_22] - Negative integer: %i", -67890);
	compare_outputs("[Test_23] - Zero integer: %i", 0);
	compare_outputs("[Test_24] - INT_MAX integer: %i", INT_MAX);
	compare_outputs("[Test_25] - INT_MIN integer: %i", INT_MIN);

	// %u: Unsigned integer tests
	compare_outputs("[Test_26] - Unsigned int max: %u", u_num);
	compare_outputs("[Test_27] - Unsigned zero: %u", 0);
	compare_outputs("[Test_28] - Small unsigned: %u", 42);
	compare_outputs("[Test_29] - UINT_MAX unsigned: %u", UINT_MAX);

	// %x: Hexadecimal (lowercase) tests
	compare_outputs("[Test_30] - Hexadecimal lowercase (positive): %x", 255); // Should print "ff"
	compare_outputs("[Test_31] - Hexadecimal lowercase (zero): %x", 0); // Should print "0"
	compare_outputs("[Test_31] - Hexadecimal lowercase (negative): %x", -255); // Should print "0"
	compare_outputs("[Test_32] - Hexadecimal for large number: %x", 0x12345678);
	compare_outputs("[Test_33] - Hexadecimal INT_MAX: %x", INT_MAX);
	compare_outputs("[Test_34] - Hexadecimal INT_MIN: %x", INT_MIN);
	compare_outputs("[Test_35] - Hexadecimal UINT_MAX: %x", UINT_MAX);

	compare_outputs("[Test_36] - Hexadecimal lowercase (LONG_MAX): %x", LONG_MAX);  // Should print the hexadecimal representation of LONG_MAX
	compare_outputs("[Test_37] - Hexadecimal lowercase (LONG_MIN): %x", LONG_MIN);  // Should print the hexadecimal representation of LONG_MIN
	compare_outputs("[Test_38] - Hexadecimal lowercase (ULONG_MAX): %x", ULONG_MAX);  // Should print the hexadecimal representation of ULONG_MAX
	compare_outputs("[Test_39] - Hexadecimal lowercase (9223372036854775807LL): %x", 9223372036854775807LL);  // Should print hex for largest signed 64-bit integer
	compare_outputs("[Test_40] - Hexadecimal lowercase (various large values): %x %x %x %x %x", INT_MAX, INT_MIN, LONG_MAX, LONG_MIN, ULONG_MAX);  // Mix of large, small, and negative values

	// %X: Hexadecimal (uppercase) tests
	compare_outputs("[Test_41] - Hexadecimal uppercase (positive): %X", 255); // Should print "FF"
	compare_outputs("[Test_42] - Hexadecimal uppercase (zero): %X", 0); // Should print "0"
	compare_outputs("[Test_42] - Hexadecimal uppercase (negative): %X", -255); // Should print "0"
	compare_outputs("[Test_43] - Hexadecimal uppercase for large number: %X", 0x12345678);
	compare_outputs("[Test_44] - Hexadecimal uppercase INT_MAX: %X", INT_MAX);
	compare_outputs("[Test_45] - Hexadecimal uppercase INT_MIN: %X", INT_MIN);
	compare_outputs("[Test_46] - Hexadecimal uppercase UINT_MAX: %X", UINT_MAX);

	compare_outputs("[Test_47] - Hexadecimal uppercase (LONG_MAX): %X", LONG_MAX);  // Should print the hexadecimal representation of LONG_MAX in uppercase
	compare_outputs("[Test_48] - Hexadecimal uppercase (LONG_MIN): %X", LONG_MIN);  // Should print the hexadecimal representation of LONG_MIN in uppercase
	compare_outputs("[Test_49] - Hexadecimal uppercase (ULONG_MAX): %X", ULONG_MAX);  // Should print the hexadecimal representation of ULONG_MAX in uppercase
	compare_outputs("[Test_50] - Hexadecimal uppercase (9223372036854775807LL): %X", 9223372036854775807LL);  // Uppercase hex for largest signed 64-bit integer
	compare_outputs("[Test_51] - Hexadecimal uppercase (various large values): %X %X %X %X %X", INT_MAX, INT_MIN, LONG_MAX, LONG_MIN, ULONG_MAX);  // Mix of large, small, and negative values

	// %%: Percent sign tests
	compare_outputs("[Test_52] - Single percent sign: %%");
	compare_outputs("[Test_53] - Multiple percent signs: %% %% %%");

	// Mixed format specifier tests
	compare_outputs("[Test_54] - Mixed formats: %c %s %d %p %% %x", 'X', "Testing", 42, p, 255);

	// Additional edge cases
	compare_outputs("[Test_55] - Negative value in unsigned format: %u", -1); // Should print a large unsigned number
	compare_outputs("[Test_56] - Negative pointer: %p", (void *)-1); // Undefined behavior but tested


	// %%: Percent sign tests
	compare_outputs("[Test_57] - Single percent sign: %%");
	compare_outputs("[Test_58] - Multiple percent signs: %% %% %%");

	// Mixed format specifier tests
	compare_outputs("[Test_59] - Mixed formats: %c %s %d %p %% %x", 'X', "Testing", 42, p, 255);

	// Additional edge cases
	compare_outputs("[Test_60] - Negative value in unsigned format: %u", -1); // Should print a large unsigned number
	compare_outputs("[Test_61] - Negative pointer: %p", (void *)-1); // Undefined behavior but tested

	// Long string test
	char *long_str = malloc(10000);
	for (int i = 0; i < 9999; i++) long_str[i] = 'A';
	long_str[9999] = '\0';
	compare_outputs("[Test_62] - Very long string: %s", long_str);
	free(long_str);

	// Combining specifiers
	compare_outputs("[Test_63] - Combined specifiers: %d %u %x %X", 12345, 12345U, 0xabc, 0xABC);
	compare_outputs("[Test_64] - Negative decimal with unsigned: %d %u", -1000, -1000);

	// Large value tests
	compare_outputs("[Test_65] - Large positive value: %d", 2147483647); // INT_MAX
	compare_outputs("[Test_66] - Large negative value: %d", -2147483647); // -INT_MAX
	compare_outputs("[Test_67] - Unsigned large value: %u", 4294967295U); // UINT_MAX

	// // Null strings and edge cases
	// compare_outputs("[Test_53] - Null string: %s", NULL);

	// // Special width/precision tests (optional)
	// compare_outputs("[Test_54] - Padded number with width: %10d", 42); // Optional: Field width
	// compare_outputs("[Test_55] - Negative width (left-align): %-10d", 42); // Optional: Left-align
	// compare_outputs("[Test_56] - Zero-padded width: %010d", 42); // Optional: Zero-padding

	// Escaped format specifiers
	compare_outputs("[Test_68] - Escaped format specifiers: %%d %%s %%p %%x");

	// Undefined behavior tests for ft_printf

	// %d with wrong type (string instead of int)
	compare_outputs("[UB_Test_1] - Wrong type for %%d: %d", "Hello");

	//ft_printf("[UB_Test_2] - Wrong type for %%s: %s", 42);
	// %s with wrong type (int instead of string)
	// compare_outputs("[UB_Test_2] - Wrong type for %%s: %s", 42);

	// %p with wrong type (int instead of pointer)
	compare_outputs("[UB_Test_3] - Wrong type for %%p: %p", 100);

	// Invalid pointer dereferencing
	int *invalid_ptr = (int *)0xDEADBEEF; // Invalid memory address
	compare_outputs("[UB_Test_4] - Invalid pointer address: %p", invalid_ptr);

	// Overlapping string (string that’s not properly null-terminated)
	char overlapping_str[10] = "Test";
	compare_outputs("[UB_Test_5] - Overlapping string: %s", &overlapping_str[1]);

	// Negative pointer
	compare_outputs("[UB_Test_6] - Negative pointer: %p", (void *)-1);


	return 0;
}
