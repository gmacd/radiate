// TODO C++-ify

#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <signal.h>
#include <execinfo.h>
#include <unistd.h>

namespace radiate {

    int addr2line(char const * const program_name, void const * const addr);
    void posix_print_stack_trace();
    [[noreturn]] void handleSigSegv(int sig);

    // Resolve symbol name and source location given the path to the executable and an address
    int addr2line(char const * const program_name, void const * const addr)
    {
        char addr2line_cmd[512] = {0};

        // Have addr2line map the address to the relent line in the code
        #ifdef __APPLE__
            // Apple does things differently...
            sprintf(addr2line_cmd,"xcrun atos -o %.256s %p", program_name, addr); 
        #else
            sprintf(addr2line_cmd,"addr2line -f -p -e %.256s %p", program_name, addr); 
        #endif

        // This will print a nicely formatted string specifying the function and
        // source line of the address
        return system(addr2line_cmd);
    }

    #define MAX_STACK_FRAMES 64
    static void *stack_traces[MAX_STACK_FRAMES];

    void posix_print_stack_trace()
    {
        int numFrames = backtrace(stack_traces, MAX_STACK_FRAMES);
        char **messages = backtrace_symbols(stack_traces, numFrames);

        for (int i = 0; i < numFrames; ++i)
            printf("%s\n", messages[i]);

        printf("\nStacktrace with line numbers (gdb is more accurate!):\n\n");

        // Skip the first couple stack frames (as they are this function and our
        // handler) and also skip the last frame as it's (always?) junk.
        for (int i = 0; i < (numFrames - 1); ++i)
        {
            if (addr2line("src/cs6", stack_traces[i]) != 0)
                printf("  error determining line # for: %s\n", messages[i]);
        }
        if (messages)
            free(messages);
    }

    // Stacktrace on SIGSEGV
    void handleSigSegv(int sig)
    {
        fprintf(stderr, "\nError: signal %d:\n", sig);
        posix_print_stack_trace();
        exit(1);
    }

    void csRegisterSignalHandlers()
    {
        signal(SIGSEGV, handleSigSegv);
    }

    void Logf(const char* fmt, ...)
    {
        va_list args;
        va_start(args, fmt);
        vprintf(fmt, args);
        va_end(args);
    }
}
