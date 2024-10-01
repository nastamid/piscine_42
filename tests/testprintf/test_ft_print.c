/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_print.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 17:56:47 by codespace         #+#    #+#             */
/*   Updated: 2024/10/01 11:53:12 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include "ft_printf.h"


// Function to capture the output of ft_printf
static char* capture_ft_printf_output(const char *format, ...)
{
    va_list args;
    char buffer[1024] = {0}; // Buffer to store captured output

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
	char std_output[256]; // Buffer to hold output of printf
	// Test ft_printf
	va_start(args, format);
	ft_output = capture_ft_printf_output(format);
	va_end(args);
	// Test printf
	va_start(args, format);
	vsnprintf(std_output, sizeof(std_output), format, args);
	va_end(args);
	// Compare outputs
	if (strcmp(ft_output, std_output) == 0)
	{
		 printf("\033[0;32m[PASS]\033[0m Output: %s\n", ft_output);
	}
	else
	{
		printf("\033[0;31m[FAIL]\033[0m Outputs do not match!\n");
		printf("ft_printf: %s\n", ft_output);
		printf("printf: %s\n", std_output);
		printf("\n");
	}
}

int	main(void)
{
	int k = 42;
	int *p = &k;
	unsigned int u_num = 4294967295; // Largest unsigned int value

	// Test %c: Prints a single character
	compare_outputs("Single character: %c", 'A');
	compare_outputs("Multiple characters: %c %c %c", 'A', 'B', 'C');

	// Test %s: Prints a string
	compare_outputs("Simple string: %s", "Hello, World!");
	compare_outputs("Empty string: %s", "");
	compare_outputs("String with special chars: %s", "This is a string with % and \\ characters.");

	// Test %p: Prints a pointer in hexadecimal format
	compare_outputs("Pointer address: %p", p);
	compare_outputs("Null pointer: %p", NULL);

	// Test %d: Prints a decimal number (base 10)
	compare_outputs("Positive decimal: %d", 12345);
	compare_outputs("Negative decimal: %d", -12345);
	compare_outputs("Zero decimal: %d", 0);

	// Test %i: Prints an integer in base 10 (same as %d)
	compare_outputs("Positive integer: %i", 67890);
	compare_outputs("Negative integer: %i", -67890);
	compare_outputs("Zero integer: %i", 0);

	// Test %u: Prints an unsigned decimal (base 10)
	compare_outputs("Unsigned int max: %u", u_num);
	compare_outputs("Unsigned zero: %u", 0);
	compare_outputs("Small unsigned: %u", 42);

	// Test %x: Prints a number in hexadecimal (lowercase)
	compare_outputs("Hexadecimal lowercase (positive): %x", 255); // Should print "ff"
	compare_outputs("Hexadecimal lowercase (zero): %x", 0); // Should print "0"

	// Test %X: Prints a number in hexadecimal (uppercase)
	compare_outputs("Hexadecimal uppercase (positive): %X", 255); // Should print "FF"
	compare_outputs("Hexadecimal uppercase (zero): %X", 0); // Should print "0"

	// Test %%: Prints a percent sign
	compare_outputs("Percent sign: %%");
	compare_outputs("Multiple percent signs: %% %% %%");

	// Edge cases
	compare_outputs("Mixed formats: %c %s %d %p %% %x %X", 'X', "Testing", 42, p, 255, 255);
	compare_outputs("Null string: %s", NULL);

	return 0;
}
