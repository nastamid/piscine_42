/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_print.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nastamid <nastamid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 17:56:47 by codespace         #+#    #+#             */
/*   Updated: 2024/09/30 21:21:47 by nastamid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include "libftprintf.h"


// Function to capture the output of ft_printf
char* capture_ft_printf_output(const char *format, ...)
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
void	compare_outputs(const char *format, ...)
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
	int k = 5;
	int *p = &k;
	compare_outputs("Hello %s", "I am ^^ && ** (( $$ %% string! \0 ABC");
	compare_outputs("%p", p);
	compare_outputs("%d", 5);
	compare_outputs("%c", 'a');
	compare_outputs("%x", 10);
	return (0);
}