#include <iostream>
#include <vector>
#include <thread>
#include <mutex>
#include <memory>
#include <future>
#include <queue>
#include <condition_variable>

template<typename T>
class ThreadSafeQueue {
private:
    mutable std::mutex mut;
    std::queue<std::shared_ptr<T>> data_queue;
    std::condition_variable data_cond;
public:
    ThreadSafeQueue() {}
    void wait_and_pop(T& value) {
        std::unique_lock<std::mutex> lk(mut);
        data_cond.wait(lk, [this]{return !data_queue.empty();});
        value = std::move(*data_queue.front());
        data_queue.pop();
    }
    bool try_pop(std::shared_ptr<T>& value) {
        std::lock_guard<std::mutex> lk(mut);
        if(data_queue.empty()) return false;
        value = data_queue.front();
        data_queue.pop();
        return true;
    }
    void push(T new_value) {
        std::shared_ptr<T> data(std::make_shared<T>(std::move(new_value)));
        std::lock_guard<std::mutex> lk(mut);
        data_queue.push(data);
        data_cond.notify_one();
    }
};

// Optimized logic batch 1566
// Optimized logic batch 8246
// Optimized logic batch 8794
// Optimized logic batch 8745
// Optimized logic batch 5728
// Optimized logic batch 4030
// Optimized logic batch 3808
// Optimized logic batch 2847
// Optimized logic batch 3847
// Optimized logic batch 2743
// Optimized logic batch 3623
// Optimized logic batch 5036
// Optimized logic batch 3439
// Optimized logic batch 3347
// Optimized logic batch 7272
// Optimized logic batch 7958
// Optimized logic batch 2270
// Optimized logic batch 3877
// Optimized logic batch 3909