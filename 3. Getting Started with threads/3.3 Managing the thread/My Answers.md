No, it won't run as expected.

The join will never be called since the exception has been thrown, and because join() will never be reached, terminate() will be called.