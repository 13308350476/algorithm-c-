#include <iostream>
#include <unistd.h>
#include <queue>
#include <thread>
#include <mutex>
#include <condition_variable>
#include <future>
using namespace std;
deque<packaged_task<void()> > tasks;
mutex mylock;
queue<int> que;
condition_variable con;

class guard {
    public:
        guard(thread &_t):t(_t){};
        ~guard(){
            if(t.joinable()){
                t.join();
            }
        }
        guard(thread const&) = delete;
        guard& operator=(const guard&) = delete;
    private:
        thread &t;
};

void prepare(){
    cout << "prepare:" << endl;
    for(int i=0;i<10;i++){
        sleep(1);
        int item = i;
        lock_guard<mutex> lk(mylock);
        que.push(i);
        cout << "creat:" << i << endl;
        con.notify_one();
    }
}

void comsum(){
    cout << "comsum:" << endl;
    while (1)
    {
        sleep(5);
        unique_lock<mutex> lk(mylock);
        con.wait(lk,[]{return !que.empty();});
        int data = que.front();
        que.pop();
        lk.unlock();
        cout << "comsuem:" << data << endl;
        if(data == 9) {
            break;
        }
    }
}

int main(){
    thread t1(prepare);
    thread t2(comsum);
    guard prep(t1);
    guard coms1(t2);

}