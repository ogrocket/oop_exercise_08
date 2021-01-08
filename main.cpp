#include <iostream>
#include <queue>
#include <ctime>
#include <sstream>

#include "factory.hpp"
#include "processor.hpp"

void menu() ;

using proc_t = Processor<std::shared_ptr<Figure>>;

int main(int argc, char* argv[]) {

        if (std::stoi(argv[1]) <= 0) {
                std::cout << "Invalid size of buffer\n";
                return 1;
        }

        size_t buf_size = std::stoul(argv[1]);

        proc_t::Get().RegisterSub([](const std::shared_ptr<Figure> fig) {       //add subscriber
                fig->Print();
                });

        proc_t::Get().RegisterSub([](const std::shared_ptr<Figure> fig) {
                fig->Printf(proc_t::Get().GetFile());
                });

        std::thread thread([buf_size]() {       //start handler
                proc_t::Get().Run(buf_size);
                });

        menu();

        int variant;

        while (true){
                std::cin >> variant;
                if (variant == 0){
                        proc_t::Get().Kill();
                        break;
                }
                std::shared_ptr<Figure> f = Factory::Create(variant);
                proc_t::Get().Publish(f);
                std::cout << "Figure added\n";
        }

        thread.join();

        return 0;
}

void menu() {
        std::cout << "1. Add triangle\n";
        std::cout << "2. Add rectangle\n";
        std::cout << "3. Add square\n";
        std::cout << "0. Exit\n";
}