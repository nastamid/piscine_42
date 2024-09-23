/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_print.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nastamid <nastamid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 12:32:58 by nastamid          #+#    #+#             */
/*   Updated: 2024/09/23 14:00:17 by nastamid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include "libftprintf.h"  // Include your custom header

#define TEST_BUFFER_SIZE 1024

// Utility function to capture output from printf/ft_printf
char *capture_output(void (*print_func)(const char *, ...), const char *format, ...) {
    // Redirect stdout to a file
    int stdout_fd = dup(STDOUT_FILENO);
    int fd[2];
    pipe(fd);
    dup2(fd[1], STDOUT_FILENO);
    close(fd[1]);

    // Use va_list for forwarding variadic arguments
    va_list args;
    va_start(args, format);
    print_func(format, args);
    va_end(args);

    // Restore stdout and capture output
    fflush(stdout);
    dup2(stdout_fd, STDOUT_FILENO);
    close(stdout_fd);

    char *output = malloc(TEST_BUFFER_SIZE);
    read(fd[0], output, TEST_BUFFER_SIZE);
    close(fd[0]);

    return output;
}

void run_test(const char *test_name, const char *expected_output, void (*print_func)(const char *, ...), const char *format, ...) {
    char *output = capture_output(print_func, format);
    
    if (strcmp(output, expected_output) == 0) {
        printf("[PASS] %s\n", test_name);
    } else {
        printf("[FAIL] %s\n", test_name);
        printf("Expected: %s\n", expected_output);
        printf("Got     : %s\n", output);
    }

    free(output);
}

int main() {
    // Basic test for a simple string
    run_test("Test 1: Basic string", "Hello, World!\n", ft_printf, "Hello, %s!\n", "World");
    
    // Test with integers
    run_test("Test 2: Integer", "42\n", ft_printf, "%d\n", 42);

    // Test with hex numbers
    run_test("Test 3: Hexadecimal", "2a\n", ft_printf, "%x\n", 42);

    // Test with mixed inputs
    run_test("Test 4: Mixed inputs", "String: hello, Int: 123, Hex: 7b\n", ft_printf, "String: %s, Int: %d, Hex: %x\n", "hello", 123, 123);
    
    // Add more tests here as you implement different functionalities
    return 0;
}
