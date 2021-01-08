#pragma once

#include <vector>
#include <queue>
#include <mutex>
#include <thread>
#include <functional>
#include <fstream>

template <class MESSAGE_TYPE>
class Processor {
private:
    std::vector<std::function<void(const MESSAGE_TYPE&)>> subs;
    std::queue<MESSAGE_TYPE> message_queue;
    std::mutex mutex;
    std::string file_name;
    std::ofstream file;
    Processor() {};
    bool live = true;

public:
    static Processor& Get(){    // singleton
        static Processor instance;
        return instance;
    }

    void RegisterSub(const std::function<void(const MESSAGE_TYPE&)>& sub){
        subs.push_back(sub);
    }

    void Publish(const MESSAGE_TYPE& msg){
        std::lock_guard<std::mutex> lck(mutex);
        message_queue.push(msg);
    }

    std::string FileNamer(){
        static std::string name;
        name.push_back('|');
        return name;
    }

    void Run(size_t max_size){  // starting handler
        while (live) {
            if (message_queue.size() == max_size) {
                std::string file_name = FileNamer();
                file.open(file_name);
                while (!message_queue.empty()) {
                    std::lock_guard<std::mutex> lck(mutex);
                    MESSAGE_TYPE val = message_queue.front();
                    message_queue.pop();
                    for (auto sub : subs) {
                        sub(val);
                    }
                }
                file.flush();
                file.close();
            }
            else {
                std::this_thread::yield;
            }
        }
    }

    void Kill(){
        live = false;
    }

    std::ofstream& GetFile(){
        return file;
    }
};