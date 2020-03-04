//
// Created by xmly on 2020/1/3.
//

#ifndef CLEARNING_SHAREDMEMORYDISPATCHER_H
#define CLEARNING_SHAREDMEMORYDISPATCHER_H

#include <csignal>
#include <memory>

using namespace std;

class SharedMemoryDispatcher {
public:
    void operator()(int *p);
    shared_ptr<int> getSharedIntMemory(int);
};

#endif //CLEARNING_SHAREDMEMORYDISPATCHER_H
