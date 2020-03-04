//
// Created by xmly on 2019/5/28.
//

#include <future>
#include <thread>
#include <iostream>

int main11(){
    std :: packaged_task < int () > task ([]() { return 7;}) ;
    std :: future <int > result = task.get_future (); // 在一个线程中执行task
    std :: thread ( std :: move ( task )). detach (); std :: cout << " Waiting ... ";
    result.wait();
    std :: cout << " Done !" << std :: endl << " Result is " << result .get () << std::endl;
}