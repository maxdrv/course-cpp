

void Log(const char *message);  // if function does not have body means it is just declaration

// this function can not be compiled without
// declaration of function Log
// however it does not need definition write here
void logInit() {
    Log("RRRRRRun");
}