In the case without execution policy:

The function call will return immediately, and the exeption is left to make its way up to the call stack, start from its englobing scope.

The program will find a suitable handler for the exception, and handle it if found.



In the case with execution policy: The "std::terminate()" will be called, and te entire program will immediately terminate.




