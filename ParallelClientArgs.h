#ifndef SOLIDPROJECT_EX2_PARALLELCLIENTARGS_H
#define SOLIDPROJECT_EX2_PARALLELCLIENTARGS_H

class ParallelClientArgs {
    int port;
public:
    ParallelClientArgs(int port1) { port = port1; }
    int getPort() { return port; }
};

#endif //SOLIDPROJECT_EX2_PARALLELCLIENTARGS_H
